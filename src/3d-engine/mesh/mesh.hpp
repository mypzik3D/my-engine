#include "../vector/vector.hpp"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
class dot{
    public:
        vec3f pos{0,0,0};
        vec3f glpos{0,0,0};
        vec3f cmpos{0,0,0};
        dot(vec3f pos);
};

class triangle{
    public:
        dot* dots[3];
        vec3f normal;
        vec3f glnorm;
        vec3f cmnorm;
        sf::Color color;
    	triangle();
};

class mesh{
    private:
        trform3 old;
        vec3f ofx;
        vec3f ofy;
        vec3f ofz;
    public:
	trform3 trform;
        std::vector<dot*> dots;
	std::vector<triangle*> triangles;
	
	void calc_dots();
	triangle* add_triangle(vec3f pos1, vec3f pos2, vec3f pos3);
	triangle* add_triangle(vec3f pos1, vec3f pos2, vec3f pos3, vec3f norm);
        triangle* add_triangle(vec3f pos1, vec3f pos2, vec3f pos3, vec3f norm, sf::Color color);
	triangle* add_triangle(dot* pos1, dot* pos2, dot* pos3, vec3f norm, sf::Color color);
	triangle* add_triangle(dot* pos1, dot* pos2, dot* pos3, sf::Color color);
	triangle* add_triangle(dot* pos1, dot* pos2, dot* pos3);
        void del_triangle(int index);
        void del_triangle(triangle& triangle);
        
        void clear();
	mesh();
};
mesh cube(float size, vec3f offset, trform3 trform);
void load_obj_file(const std::string& filename, mesh& mesh, sf::Color color = sf::Color(170,150,218));
void load_obj_norm_mtl_tri(const std::string& filename, const std::string& mtlname, mesh& mesh, sf::Color defcol= sf::Color(170,150,218));
