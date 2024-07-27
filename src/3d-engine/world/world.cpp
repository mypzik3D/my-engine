#include "world.hpp"
#include <math.h>
#include <iostream>

camera::camera(vec2 windsize, float lengh, trform3 trform){
    this->size = windsize;
    this->lengh = lengh;
    this->trform=trform;
}
camera::camera(){}

vec2f calc_to_camera_pos(vec3f position, camera cam){
    vec2f ret(0,0);
    vec3f pos = calc_dot_local(cam.trform, position);
    double a = (pos.x*cam.size.x)/((pos.z*cam.size.x/2)/cam.lengh);
    ret.x = a;

    a = (pos.y*cam.size.y)/((pos.z*cam.size.y/2)/cam.lengh);
    ret.y = a;
    return ret;	
}
sf::Vector2f wind_cords(sf::Vector2u size, vec2f cord, float coef = 50){
    sf::Vector2f pos(0, 0);
    pos.x = size.x/2+cord.x*coef;
    pos.y = size.y/2+cord.y*coef*(-1);
    return pos;
}

void camera::draw(sf::RenderWindow& window, mesh cube, sf::Color fill, sf::Color outline){ 
    cube.calc_dots();
    std::vector<triangle*> tris = cube.triangles;
    float maxz=0;
    float at=0;
    while(tris.size() != 0){
        at=0;
        maxz = 0;
        for(int i = 0; i < tris.size(); i++){

            if(maxz < (tris.at(i)->dots[0]->glpos.z+tris.at(i)->dots[1]->glpos.z+tris.at(i)->dots[2]->glpos.z)/3){
                maxz = (tris.at(i)->dots[0]->glpos.z+tris.at(i)->dots[1]->glpos.z+tris.at(i)->dots[2]->glpos.z)/3;
                at = i;
            }
        }
        vec2f pos_dot1 = calc_to_camera_pos(tris.at(at)->dots[0]->glpos, *this);
        vec2f pos_dot2 = calc_to_camera_pos(tris.at(at)->dots[1]->glpos, *this);
        vec2f pos_dot3 = calc_to_camera_pos(tris.at(at)->dots[2]->glpos, *this);

        sf::Vertex lin1[2] = {
            sf::Vertex(wind_cords(window.getSize(), pos_dot1), outline),
            sf::Vertex(wind_cords(window.getSize(), pos_dot2), outline),
        };
        sf::Vertex lin2[2] = {
            sf::Vertex(wind_cords(window.getSize(), pos_dot2), outline),
            sf::Vertex(wind_cords(window.getSize(), pos_dot3), outline),
        };
        sf::Vertex lin3[2] = {
            sf::Vertex(wind_cords(window.getSize(), pos_dot3), outline),
            sf::Vertex(wind_cords(window.getSize(), pos_dot1), outline),
        };

        sf::Vertex polygon[3] = {
            sf::Vertex(wind_cords(window.getSize(), pos_dot1), fill),
            sf::Vertex(wind_cords(window.getSize(), pos_dot2), fill),
            sf::Vertex(wind_cords(window.getSize(), pos_dot3), fill),
        };
        window.draw(polygon, 3, sf::PrimitiveType::TriangleFan);
        tris.erase(tris.begin()+at);
        window.draw(lin1, 2, sf::Lines);
        window.draw(lin2, 2, sf::Lines);
        window.draw(lin3, 2, sf::Lines);
    }
}
