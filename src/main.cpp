#include "3d-engine/world/world.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

void get_vector(vec3f vec){
    std::cout << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]" << std::endl;
}
void get_trform(trform3 tr){
    std::cout << "position[" << tr.pos.x << ", " << tr.pos.y << ", " << tr.pos.z << "]" << std::endl;
    std::cout << "rotation[" << tr.rot.x << ", " << tr.rot.y << ", " << tr.rot.z << "]" << std::endl;
    std::cout << "scale   [" << tr.scl.x << ", " << tr.scl.y << ", " << tr.scl.z << "]" << std::endl;
}
float a = 0;

int main(){



    camera cam;
    cam.lenght = 10;
    cam.size = vec2(800, 600);
    trform3 tr;
    tr.pos = vec3f(0, 0, 150);
    mesh mesh = cube(20,vec3f(10,10,10),tr);


    mesh.calc_dots();

    sf::RenderWindow window(sf::VideoMode(800, 600), "3d, real 3d!");
    window.setFramerateLimit(75);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        window.clear();

        a+=1;
        mesh.trform.rot.z = a;
        //mesh.trform.rot.x = a;
        get_trform(mesh.trform);

        cam.draw(window, mesh, sf::Color(0,0,0,0));
        window.display();
    }
    mesh.clear();
    return 0;
}

