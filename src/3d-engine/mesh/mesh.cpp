#include "mesh.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

triangle::triangle(){
}
mesh::mesh(){
}
dot::dot(vec3f pos){
    this->pos = pos; 
}

triangle* mesh::add_triangle(vec3f pos1, vec3f pos2, vec3f pos3){
    triangle* tri = new triangle;
    dot* dts[3] = {
        new dot{pos1},
        new dot{pos2},
        new dot{pos3}
    };
    for(int i = 0; i < 3; i++){
        bool flag = false;
        for(int a = 0; a < dots.size(); a++){
            if(dts[i]->pos == dots.at(a)->pos){
                delete(dts[i]);
                dts[i] = dots.at(a);
                flag = true;
                break;
            }
        }
        if(!flag)
            dots.push_back(dts[i]);
    }

    tri->dots[0] = dts[0];
    tri->dots[1] = dts[1];
    tri->dots[2] = dts[2];
    triangles.push_back(tri);
    return tri;
}

triangle* mesh::add_triangle(dot* pos1, dot* pos2, dot* pos3){
    triangle* tri = new triangle;
    tri->dots[0] = pos1;
    tri->dots[1] = pos2;
    tri->dots[2] = pos3;
    triangles.push_back(tri);
    return tri;
}

triangle* mesh::add_triangle(vec3f pos1, vec3f pos2, vec3f pos3, vec3f norm){
    triangle* tri = new triangle;
    dot* dts[3] = {
        new dot{pos1},
        new dot{pos2},
        new dot{pos3}
    };  
    for(int i = 0; i < 3; i++){
        bool flag = false;
        for(int a = 0; a < dots.size(); a++){
            if(dts[i]->pos == dots.at(a)->pos){
                delete(dts[i]);
                dts[i] = dots.at(a);
                flag = true;
                break;
            }
        }
        if(!flag)
            dots.push_back(dts[i]);
    }

    tri->dots[0] = dts[0];
    tri->dots[1] = dts[1];
    tri->dots[2] = dts[2];
    tri->normal = norm;
    triangles.push_back(tri);
    return tri;
}

void mesh::calc_dots(){
    for(int i = 0; i < dots.size(); i++){
        dots.at(i)->glpos = calc_dot_global(this->trform, dots.at(i)->pos); 
    }
    for(int i = 0; i < triangles.size(); i++){
       triangles.at(i)->glnorm = calc_dot_global(this->trform, triangles.at(i)->normal)-trform.pos;
    }
}
void mesh::clear(){
    for(int i = 0; i < triangles.size(); i++){
        delete(triangles.at(i));
    }
    for(int a = 0; a < dots.size(); a++){
        delete(dots.at(a));
    }
}

mesh cube(float size, vec3f offset, trform3 trform){
    mesh cube;
    cube.trform = trform;
    cube.add_triangle(
        vec3f(0,size,0)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,0,0)-offset,
        vec3f(0,0,1)
    );
    cube.add_triangle(
        vec3f(size,0,0)-offset,
        vec3f(0,size,0)-offset,
        vec3f(size,size,0)-offset,
        vec3f(0,0,1)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(0,0,size)-offset,
        vec3f(0,0,-1)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,0,size)-offset,
        vec3f(0,0,-1)
    );

    cube.add_triangle(
        vec3f(0,0,size)-offset,
        vec3f(0,size,0)-offset,
        vec3f(0,0,0)-offset,
        vec3f(0,1,0)
    );
    cube.add_triangle(
        vec3f(0,size,0)-offset,
        vec3f(0,0,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,1,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,size,0)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,-1,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,-1,0)
    );

    cube.add_triangle(
        vec3f(0,0,size)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,0,0)-offset,
        vec3f(1,0,0)
    );
    cube.add_triangle(
        vec3f(size,0,0)-offset,
        vec3f(0,0,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(1,0,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,size,0)-offset,
        vec3f(0,size,0)-offset,
        vec3f(-1,0,0)
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,size,0)-offset,
        vec3f(-1,0,0)
    );
    printf("> created cube mesh\n");
    return cube;
}
void load_obj_file(const std::string& filename, mesh& mesh) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char type;
        iss >> type;
        if (type == 'v') {
            float x, y, z;
            iss >> x >> y >> z;
            mesh.dots.push_back(new dot(vec3f(x, y, z)));
        } else if (type == 'f') {
            int dot1, dot2, dot3;
            iss >> dot1 >> dot2 >> dot3;
            mesh.add_triangle(mesh.dots.at(dot1 - 1), mesh.dots.at(dot2 - 1), mesh.dots.at(dot3 - 1)); // OBJ индексы начинаются с 1
        }
    }
}
