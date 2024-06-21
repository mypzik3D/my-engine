#include "mesh.hpp"
#include <vector>
#include <iostream>

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
void mesh::calc_dots(){
    for(int i = 0; i < dots.size(); i++){
        dots.at(i)->glpos = calc_dot_global(this->trform, dots.at(i)->pos); 
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
        vec3f(0,0,0)-offset
    );
    cube.add_triangle(
        vec3f(size,0,0)-offset,
        vec3f(0,size,0)-offset,
        vec3f(size,size,0)-offset
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(0,0,size)-offset
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,0,size)-offset
    );

    cube.add_triangle(
        vec3f(0,0,size)-offset,
        vec3f(0,size,0)-offset,
        vec3f(0,0,0)-offset
    );
    cube.add_triangle(
        vec3f(0,size,0)-offset,
        vec3f(0,0,size)-offset,
        vec3f(0,size,size)-offset
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,size,0)-offset,
        vec3f(size,0,0)-offset
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,0,size)-offset,
        vec3f(size,0,0)-offset
    );

    cube.add_triangle(
        vec3f(0,0,size)-offset,
        vec3f(size,0,0)-offset,
        vec3f(0,0,0)-offset
    );
    cube.add_triangle(
        vec3f(size,0,0)-offset,
        vec3f(0,0,size)-offset,
        vec3f(size,0,size)-offset
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(size,size,0)-offset,
        vec3f(0,size,0)-offset
    );
    cube.add_triangle(
        vec3f(size,size,size)-offset,
        vec3f(0,size,size)-offset,
        vec3f(0,size,0)-offset
    );
    printf("> created cube mesh\n");
    return cube;
}

