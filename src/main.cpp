#include "3d-engine/world/world.hpp"
#include "3d-engine/animations/anim.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


int main(){   
    std::vector<mesh*> meshes;


    sf::Clock deltime;
    float nt = 1;
    float lt = 0;
    float* dt = new float(nt/lt);

    camera cam(vec2(1200, 800), 7, trform3());
    cam.clip_forward = 30;
    cam.lengh = 5;

    trform3 tr;
    tr.pos = vec3f(0, -100, 0); // position
    tr.rot = vec3f(0, 180, 0);
    tr.scl = vec3f(10,10,10); // scale
    mesh* test = new mesh;// make cube mesh
    load_obj_file("../obj/terrain-minecraft.obj", *test); // all object files in dir ../obj/ ~90% from 3dzavr sfml
    test->trform = tr;
    trform3 tr2;
    tr2.pos = vec3f(0, 0, 0); // position
    tr2.rot = vec3f(0, 180, 0);
    tr2.scl = vec3f(20,20,20); // scale
    mesh* test2 = new mesh;// make cube mesh
    load_obj_file_with_norm("../obj/monkey/green/monkey.obj", "../obj/monkey/green/monkey.mtl", *test2);
    test2->trform = tr2;

    meshes.push_back(test2);
    meshes.push_back(test);

    float angle;

    add_animation(&test2->trform.rot.y, 540, 1000); //rotate mesh on 1000 ticks(he dont use deltatime)

    sf::RenderWindow window(sf::VideoMode(1200, 800), "loading..."); //create window
    sf::Mouse::setPosition(sf::Vector2i(window.getSize().x/2, window.getSize().y/2), window);

    window.setFramerateLimit(60); // set limit fps
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        
        // calculating fps
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


        cam.draw(window, meshes ,sf::Color(0,0,0,0)); //draw meshes;

        update_animations();
        window.display();
    }
    test->clear(); //clear mesh from memory
    test2->clear();
    return 0;
}

