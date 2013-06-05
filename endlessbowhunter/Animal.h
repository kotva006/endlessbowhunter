
#include <SFML/Graphics.hpp>

class Animal {
public:
	Animal() {};
	~Animal() {};
	int health;
	int type;
	sf::Vector2f position;
	sf::Vector2f movement;
} ;