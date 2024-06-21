#include "world.hpp"
#include <math.h>
#include <iostream>

camera::camera(){
}
vec2f calc_to_camera_pos(vec3f& pos, camera cam){
    vec2f ret(0,0);

    double a = (pos.x*cam.size.x)/((pos.z*cam.size.x/2)/cam.lenght);
    ret.x = a;

    a = (pos.y*cam.size.y)/((pos.z*cam.size.y/2)/cam.lenght);
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

    for(int i = 0; i < cube.triangles.size(); i++){	
        vec2f pos_dot1 = calc_to_camera_pos(cube.triangles.at(i)->dots[0]->glpos, *this);
        vec2f pos_dot2 = calc_to_camera_pos(cube.triangles.at(i)->dots[1]->glpos, *this);
        vec2f pos_dot3 = calc_to_camera_pos(cube.triangles.at(i)->dots[2]->glpos, *this);

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
        
        window.draw(lin1, 2, sf::Lines);
        window.draw(lin2, 2, sf::Lines);
        window.draw(lin3, 2, sf::Lines);

        window.draw(polygon, 3, sf::PrimitiveType::TriangleFan);
    }
}
