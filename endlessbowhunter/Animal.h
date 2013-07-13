
#ifndef ANIMAL_H
#define ANIMAL_H

#include <SFML/Graphics.hpp>


class Animal : public sf::Sprite {
public:
	Animal() {};
	Animal(sf::Vector2f p, int h, int t)
		: type(t), score(10) 
	    {this->setPosition(p);
	     this->setHealth(h);
	     this->setSpeed(h);
	     this->setScore(h);};
	~Animal() {};
	void move(sf::Vector2f);
	void setHealth(int);
	void setSpeed(int);
	void setScore(int);
	int health;
	int type;
	int score;
	int speed;
	sf::Vector2f movement;
} ;

#endif