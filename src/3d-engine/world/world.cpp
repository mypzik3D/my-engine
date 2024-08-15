#include "world.hpp"
#include <math.h>
#include <iostream>

camera::camera(vec2 windsize, float lengh, trform3 trform){
    this->size = windsize;
    this->lengh = lengh;
    this->trform=trform;
}
camera::camera(){}

sf::Vector2f to_draw(sf::Vector2u size, vec3f pos, camera cam, float coef = 50){
    vec2f ret(0,0);
    double a = (pos.x*cam.size.x)/((pos.z*cam.size.x/2)/cam.lengh);
    ret.x = a;
    a = (pos.y*cam.size.y)/((pos.z*cam.size.y/2)/cam.lengh);
    ret.y = a;
    sf::Vector2f posit(0, 0);
    posit.x = size.x/2+ret.x*coef;
    posit.y = size.y/2+ret.y*coef*(-1);
    return posit;
}

void calc_local_dots(mesh msh, camera cam){
    for(int i = 0; i < msh.dots.size(); i++){
        msh.dots.at(i)->cmpos = calc_dot_local(cam.trform, msh.dots.at(i)->glpos-cam.trform.pos); 
    }
   /* 
   // if(cam.trform.old.pos != trform.pos || old.rot != trform.pos || old.scl != trform.scl){
        vec3f x(1,0,0),y(0,1,0),z(0,0,1);
        vec3f ofx = calc_dot_local(cam.trform, x);
        vec3f ofy = calc_dot_local(cam.trform, y);
        vec3f ofz = calc_dot_local(cam.trform, z);
    //}
    for(int i = 0; i < msh.dots.size(); i++){
        vec3f rp = msh.dots.at(i)->glpos-cam.trform.pos;
        msh.dots.at(i)->cmpos = (ofx*rp.x+ofy*rp.y+ofz*rp.z)/cam.trform.scl;
    }
*/
}

void draw_triangle(sf::RenderWindow& window, vec3f pos_dot1, vec3f pos_dot2, vec3f pos_dot3, sf::Color outline, sf::Color fill, camera cam){    
        sf::Vertex lin1[2] = {
            sf::Vertex(to_draw(window.getSize(), pos_dot1, cam), outline),
            sf::Vertex(to_draw(window.getSize(), pos_dot2, cam), outline),
        };
        sf::Vertex lin2[2] = {
            sf::Vertex(to_draw(window.getSize(), pos_dot2, cam), outline),
            sf::Vertex(to_draw(window.getSize(), pos_dot3, cam), outline),
        };
        sf::Vertex lin3[2] = {
            sf::Vertex(to_draw(window.getSize(), pos_dot3, cam), outline),
            sf::Vertex(to_draw(window.getSize(), pos_dot1, cam), outline),
        };

        sf::Vertex polygon[3] = {
            sf::Vertex(to_draw(window.getSize(), pos_dot1, cam), fill),
            sf::Vertex(to_draw(window.getSize(), pos_dot2, cam), fill),
            sf::Vertex(to_draw(window.getSize(), pos_dot3, cam), fill),
        };
        window.draw(polygon, 3, sf::PrimitiveType::TriangleFan);
        window.draw(lin1, 2, sf::Lines);
        window.draw(lin2, 2, sf::Lines);
        window.draw(lin3, 2, sf::Lines);
}


void camera::draw(sf::RenderWindow& window, std::vector<mesh*> meshes, sf::Color outline){
    std::vector<triangle*> tris;
    for(int i = 0; i < meshes.size(); i++){
        meshes.at(i)->calc_dots(this->trform.pos);
        calc_local_dots(*meshes.at(i), *this);
        for(int j = 0; j < meshes.at(i)->triangles.size(); j++){
            tris.push_back(meshes.at(i)->triangles.at(j));
        }
    }


    float maxz=0;
    float at=0;
    while(tris.size() != 0){
        at=0;
        maxz = 0;
        for(int i = 0; i < tris.size(); i++){
            if(maxz < (tris.at(i)->dots[0]->cmpos.z+tris.at(i)->dots[1]->cmpos.z+tris.at(i)->dots[2]->cmpos.z)/3){
                maxz = (tris.at(i)->dots[0]->cmpos.z+tris.at(i)->dots[1]->cmpos.z+tris.at(i)->dots[2]->cmpos.z)/3;
                at = i;
            }
        }
        vec3f pos_dot[3];
        pos_dot[0] = tris.at(at)->dots[0]->cmpos;
        pos_dot[1] = tris.at(at)->dots[1]->cmpos;
        pos_dot[2] = tris.at(at)->dots[2]->cmpos;

        vec3f ang1 = norm(this->trform.pos-(tris.at(at)->dots[0]->glpos+tris.at(at)->dots[1]->glpos+tris.at(at)->dots[2]->glpos)/3);
        vec3f ang2 = tris.at(at)->glnorm;

        float ang = tris.at(at)->cmang.x;
        float ancos = tris.at(at)->cmang.y;

        sf::Color s = tris.at(at)->color;
        float r=s.r,g=s.g,b=s.b;
        r-=ang;
        g-=ang;
        b-=ang;
        if(r < 0)
            r = 0;
        else if(r > 255)
            r = 255;
        if(g < 0)
            g = 0;
        else if(g > 255)
            g = 255;
        if(b < 0)
            b = 0;
        else if(b > 255)
        b = 255;

        if(ancos < 0){
            tris.erase(tris.begin()+at);
            continue;
        }

        if(pos_dot[0].z <= this->clip_forward && pos_dot[1].z <= this->clip_forward && pos_dot[2].z <= this->clip_forward){
            tris.erase(tris.begin()+at);
            continue;
        }else if(pos_dot[0].z <= this->clip_forward && pos_dot[1].z <= this->clip_forward  || pos_dot[1].z <= this->clip_forward && pos_dot[2].z <= this->clip_forward  || pos_dot[2].z <= this->clip_forward && pos_dot[0].z <= this->clip_forward){
            int dfront, nf1, nf2;
            if(pos_dot[0].z  > this->clip_forward){dfront = 0; nf1 = 1; nf2 = 2;}
            if(pos_dot[1].z  > this->clip_forward){dfront = 1; nf1 = 0; nf2 = 2;}
            if(pos_dot[2].z  > this->clip_forward){dfront = 2; nf1 = 0; nf2 = 1;}
            vec3f betwd[2];

            float coef = (this->clip_forward-pos_dot[dfront].z)/(pos_dot[nf1].z-pos_dot[dfront].z);
            betwd[0].x = (pos_dot[nf1].x-pos_dot[dfront].x)*coef+pos_dot[dfront].x;
            betwd[0].y = (pos_dot[nf1].y-pos_dot[dfront].y)*coef+pos_dot[dfront].y;
            betwd[0].z = (pos_dot[nf1].z-pos_dot[dfront].z)*coef+pos_dot[dfront].z;
            coef = (this->clip_forward-pos_dot[dfront].z)/(pos_dot[nf2].z-pos_dot[dfront].z);
            betwd[1].x = (pos_dot[nf2].x-pos_dot[dfront].x)*coef+pos_dot[dfront].x;
            betwd[1].y = (pos_dot[nf2].y-pos_dot[dfront].y)*coef+pos_dot[dfront].y;
            betwd[1].z = (pos_dot[nf2].z-pos_dot[dfront].z)*coef+pos_dot[dfront].z;
    
            draw_triangle(window,betwd[0],pos_dot[dfront],betwd[1], outline, sf::Color(r,g,b,s.a), *this);
            
            tris.erase(tris.begin()+at);
            continue;
        }else if(pos_dot[0].z <= this->clip_forward || pos_dot[1].z <= this->clip_forward  || pos_dot[2].z <= this->clip_forward){
            int dfront, nf1, nf2;
            if(pos_dot[0].z  <= this->clip_forward){dfront = 0; nf1 = 1; nf2 = 2;}
            if(pos_dot[1].z  <= this->clip_forward){dfront = 1; nf1 = 0; nf2 = 2;}
            if(pos_dot[2].z  <= this->clip_forward){dfront = 2; nf1 = 0; nf2 = 1;}
            vec3f betwd[2];

            float coef = (this->clip_forward-pos_dot[dfront].z)/(pos_dot[nf1].z-pos_dot[dfront].z);
            betwd[0].x = (pos_dot[nf1].x-pos_dot[dfront].x)*coef+pos_dot[dfront].x;
            betwd[0].y = (pos_dot[nf1].y-pos_dot[dfront].y)*coef+pos_dot[dfront].y;
            betwd[0].z = (pos_dot[nf1].z-pos_dot[dfront].z)*coef+pos_dot[dfront].z;
            coef = (this->clip_forward-pos_dot[dfront].z)/(pos_dot[nf2].z-pos_dot[dfront].z);
            betwd[1].x = (pos_dot[nf2].x-pos_dot[dfront].x)*coef+pos_dot[dfront].x;
            betwd[1].y = (pos_dot[nf2].y-pos_dot[dfront].y)*coef+pos_dot[dfront].y;
            betwd[1].z = (pos_dot[nf2].z-pos_dot[dfront].z)*coef+pos_dot[dfront].z;
    
            draw_triangle(window,pos_dot[nf1],pos_dot[nf2],betwd[0], outline, sf::Color(r,g,b,s.a), *this);
            draw_triangle(window,betwd[0],pos_dot[nf2],betwd[1], outline, sf::Color(r,g,b,s.a), *this);

            tris.erase(tris.begin()+at);
            continue;
        }else{
            draw_triangle(window,pos_dot[0],pos_dot[1],pos_dot[2], outline, sf::Color(r,g,b,s.a), *this);
            tris.erase(tris.begin()+at);
        }
    }
}
