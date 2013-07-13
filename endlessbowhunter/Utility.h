#ifndef UTILITY_H
#define UTILITY_H

#include "Animal.h"
#include "Arrow.h"
#include <vector>
// Defines the functions for the Utility of the game

//TODO define collision

// This is a class for handling the various collisions

class Collision {
public:
	Collision()
	    : score(0), life(0) {};
	~Collision(){};
	int score;
	int life;
	void collision(std::vector<Animal*>*, std::vector<Arrow*>*);
	void personCollision(std::vector<Animal*>*, sf::Vector2f);
} ;


int random(int);

#endif