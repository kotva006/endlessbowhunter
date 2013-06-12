
#include <SFML/Graphics.hpp>

class Arrow : public sf::Sprite {
public:
	Arrow() {};
	Arrow(sf::Vector2f mousePos, float p, int t)
		:movement(mousePos),power(p),type(t),firstMove(true){};
	~Arrow() {};
	void move(sf::Vector2f);
	int damage;
	int type;
	float power;
	bool firstMove;
	float angle;
	sf::Vector2f movement;
} ;
