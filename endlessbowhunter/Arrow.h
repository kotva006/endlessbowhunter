
#include <SFML/Graphics.hpp>

class Arrow {
public:
	Arrow() {};
	Arrow(sf::Vector2f mousePos, sf::Vector2f per, float p)
		: movement(mousePos), personPos(per), power(p), firstMove(true) {} ;
	~Arrow() {};
	void move();
	int damage;
	int type;
	float power;
	bool firstMove;
	float angle;
	sf::Vector2f position;
	sf::Vector2f movement;
	sf::Vector2f personPos;
} ;
