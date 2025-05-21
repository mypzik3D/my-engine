#include "../mesh/mesh.hpp"
#include <SFML/Graphics.hpp>

class camera{
    public:
        camera(vec2 windsize, vec2 windpos, float lengh, trform3 trform);
        camera(vec2 size, float lengh, trform3 trform);
    	camera();
	trform3 trform;
    	vec2 size{0,0};
        vec2 pos{0,0};
        float clip_forward=10;
	float lengh;
	void draw(sf::RenderWindow& window, std::vector<mesh*> meshes, sf::Color outline);
};
