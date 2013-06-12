
#include <SFML/Graphics.hpp>


class Animal : public sf::Sprite {
public:
	Animal() {};
	Animal(sf::Vector2f p, int h, int s, int t)
		: health(h), speed(s), type(t), firstCall(true) 
	    {this->setPosition(p);};
	~Animal() {};
	void move(sf::Vector2f);
	int health;
	int type;
	int speed;
	bool firstCall;
	sf::Vector2f movement;
} ;