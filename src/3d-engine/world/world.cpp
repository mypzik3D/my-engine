#include "world.hpp"
#include <math.h>
#include <iostream>

camera::camera(vec2 windsize, float lengh, trform3 trform){
    this->size = windsize;
    this->lengh = lengh;
    this->trform=trform;
}
camera::camera(){}

vec3f calc_to_camera_pos(vec3f position, camera cam){
    vec3f pos = calc_dot_local(cam.trform, position);
    return pos;	
}
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
        msh.dots.at(i)->cmpos = calc_dot_local(cam.trform, msh.dots.at(i)->glpos); 
    }
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


void camera::draw(sf::RenderWindow& window, mesh mesh, sf::Color fill, sf::Color outline){ 
    mesh.calc_dots();
    calc_local_dots(mesh, *this);
    std::vector<triangle*> tris = mesh.triangles;
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

        vec3f pos_dot1 = tris.at(at)->dots[0]->cmpos;
        vec3f pos_dot2 = tris.at(at)->dots[1]->cmpos;
        vec3f pos_dot3 = tris.at(at)->dots[2]->cmpos;

        if(pos_dot1.z <= this->clip_forward && pos_dot2.z <= this->clip_forward && pos_dot3.z <= this->clip_forward){
            tris.erase(tris.begin()+at);
            continue;
        }else{
            draw_triangle(window,pos_dot1,pos_dot2,pos_dot3,outline,fill,*this);
            tris.erase(tris.begin()+at);
        }


            //if(pos_dot1.z > 0 || pos_dot2.z > 0 || pos_dot3.z > 0){
            
        //}
    }
}
