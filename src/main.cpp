#include "3d-engine/world/world.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>



int main(){
    camera cam(vec2(800, 600), 7, trform3());

    trform3 tr;
    tr.pos = vec3f(0, 0, 150);
    tr.rot = vec3f(0,60,30);
    mesh test = cube(20,vec3f(10,10,10),tr);


    sf::RenderWindow window(sf::VideoMode(800, 600), "3d, real 3d!");
    window.setFramerateLimit(75);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();
        cam.draw(window, test, sf::Color(0,0,0,0));
        window.display();
    }
    test.clear();
    return 0;
}

