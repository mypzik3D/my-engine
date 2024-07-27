#include "3d-engine/world/world.hpp"
#include "3d-engine/animations/anim.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>



int main(){
    sf::Clock deltime;
    float nt = 1;
    float lt = 0;
    float* dt = new float(nt/lt);
    trform3 posit;
    camera cam(vec2(800, 600), 7, posit);

    trform3 tr;
    tr.pos = vec3f(0, 0, 50); // position
    tr.rot = vec3f(30, 0, 0);
    tr.scl = vec3f(10,10,10); // scale
    mesh test;// make cube mesh
    load_obj_file("../obj/monkey.obj", test); // all object files in dir ../obj/ ~90% from 3dzavr sfml
    test.trform = tr;
    float angle;

    add_animation(&test.trform.rot.y, 360, 1000); //rotate mesh on 1000 ticks(he dont use deltatime)

    sf::RenderWindow window(sf::VideoMode(800, 600), "loading..."); //create window
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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right)){
            cam.trform.rot.y+=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left)){
            cam.trform.rot.y-=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)){
            cam.trform.rot.x+=1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Down)){
            cam.trform.rot.x-=1;
        }
        //       window  mesh  fill color             outline color
        cam.draw(window, test, sf::Color(170,150,218),sf::Color(249,247,247)); //draw mesh;

        update_animations();
        window.display();
    }
    test.clear(); //clear mesh from memory
    return 0;
}

