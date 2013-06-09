
#include <SFML/Graphics.hpp>

class Arrow {
public:
	Arrow() {};
	~Arrow() {};
	void move() {};
	int damage;
	int type;
	sf::Vector2f position;
	sf::Vector2f movement;
} ;
