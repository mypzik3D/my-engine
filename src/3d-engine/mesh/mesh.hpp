#pragma once
#include "../vector/vector.hpp"
#include <vector>
#include <memory>

class dot{
    public:
        vec3f pos{0,0,0};
        vec3f glpos{0,0,0};
        dot(vec3f pos);
};

class triangle{
    public:
        dot* dots[3];
        vec3f normal{0,0,0};
    	triangle();
};

class mesh{
    public:
	trform3 trform;
        std::vector<dot*> dots;
	std::vector<triangle*> triangles;
	
	void calc_dots();
	triangle* add_triangle(vec3f pos1, vec3f pos2, vec3f pos3);
        void del_triangle(int index);
        void del_triangle(triangle& triangle);
        
        void clear();
	mesh();
};
mesh cube(float size, vec3f offset, trform3 trform);
