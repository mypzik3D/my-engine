#include "../../../src/3d-engine/world/world.hpp"
#include "../../../src/3d-engine/animations/anim.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

#define OUTLINE sf::Color(0,0,0,255)

int main(){   
    std::vector<mesh*> meshes;

    sf::Clock deltime;
    float nt = 1;
    float lt = 0;
    float* dt = new float(nt/lt);
    //create camera
    trform3 campos;
    campos.pos = vec3f(0,0,-20);
    camera cam(vec2(1200, 800), 7, campos);
    cam.clip_forward = 1;
    cam.lengh = 5;


    //transform for mesh
    trform3 tr;
    tr.scl = vec3f(20,20,20);
    tr.rot = vec3f(0,0,0);
    tr.pos = vec3f(0,0,100);
    //create mesh;
    mesh* test = new mesh;
    test->trform = tr;
    load_obj_file("../obj/cube.obj",*test); //input your object file dir

    //add mesh to massive
    meshes.push_back(test);

    add_animation(&test->trform.rot.y, 360, 400);
    add_animation(&test->trform.rot.z, 360, 400);

    sf::RenderWindow window(sf::VideoMode({1200, 800}), "loading..."); //create window
    sf::Mouse::setPosition(sf::Vector2i(window.getSize().x/2, window.getSize().y/2), window);

    window.setFramerateLimit(60); // set limit fps
    while (window.isOpen()){
        while (const std::optional event = window.pollEvent())
            if (event->is<sf::Event::Closed>())
                window.close();
        
        // calculating fps
        window.clear(sf::Color::White);
        nt = deltime.restart().asSeconds();
        float fps =(1.f/nt-lt);
        window.setTitle("3D, real 3D! [FPS:"+std::to_string((int)fps)+"]"); //rename window title
        *dt = nt/lt*1000;
        lt = nt;

        // movement
        sf::Vector2i mpos = sf::Mouse::getPosition(window);
        vec2 offset(mpos.x-(window.getSize().x/2), mpos.y-(window.getSize().y/2));
        sf::Mouse::setPosition(sf::Vector2i(window.getSize().x/2, window.getSize().y/2), window);
        
        cam.trform.rot.y+=offset.x*0.1;
        cam.trform.rot.x+=offset.y*-0.1;
     
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)){
            cam.trform.pos.x+=sin((M_PI/180)*(cam.trform.rot.y))*4;
            cam.trform.pos.z+=cos((M_PI/180)*(cam.trform.rot.y))*4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)){
            cam.trform.pos.x-=sin((M_PI/180)*(cam.trform.rot.y))*4;
            cam.trform.pos.z-=cos((M_PI/180)*(cam.trform.rot.y))*4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)){
            cam.trform.pos.x+=sin((M_PI/180)*(cam.trform.rot.y+90))*4;
            cam.trform.pos.z+=cos((M_PI/180)*(cam.trform.rot.y+90))*4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)){
            cam.trform.pos.x-=sin((M_PI/180)*(cam.trform.rot.y+90))*4;
            cam.trform.pos.z-=cos((M_PI/180)*(cam.trform.rot.y+90))*4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space)){
            cam.trform.pos.y+=4;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::C)){
            cam.trform.pos.y-=4;
        }


        cam.draw(window, meshes ,OUTLINE); //draw massive;
        update_animations();
        window.display();
    }
    for(int i = 0; i < meshes.size(); i++){
        meshes.at(i)->clear();
    }
    return 0;
}

