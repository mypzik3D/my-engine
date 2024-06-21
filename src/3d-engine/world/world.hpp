#include "../mesh/mesh.hpp"
#include <SFML/Graphics.hpp>

class camera{
    public:
    	camera();
	trform3 trform;
    	vec2 size{0,0};
	float lenght;
	void draw(sf::RenderWindow& window, mesh cube, sf::Color fill = sf::Color(186,215,223, 200), sf::Color outline = sf::Color::White);

};
