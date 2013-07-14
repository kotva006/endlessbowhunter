#include <stdlib.h>
#include <iostream>

#include "Initialize.h"
#include "Utility.h"


// Random number things
int RANDOM_LOWEST  = 1;
int RANDOM_HIGHEST = 500;
int RANGE = (RANDOM_HIGHEST - RANDOM_LOWEST) + 1;

int RANDOM_SPAWN_POINT_LOWEST  = 0;
int RANDOM_SPAWN_POINT_HIGHEST = WINDOW_X;
int SPAWN_RANGE = (RANDOM_SPAWN_POINT_HIGHEST - RANDOM_SPAWN_POINT_LOWEST) + 1;

void Collision::collision(std::vector<Animal*> *animalVector, std::vector<Arrow*> *arrowVector) {
	
	this->life = 0;
	this->score = 0;
	int i, j;
	
	for (i = 0; i < animalVector->size(); i++) {
		for (j = 0; j < arrowVector->size(); j++) {

			if ((*animalVector)[i]->getPosition().x - animal_1CenterX < (*arrowVector)[j]->getPosition().x &&
			    (*animalVector)[i]->getPosition().x + animal_1CenterX > (*arrowVector)[j]->getPosition().x &&
				(*animalVector)[i]->getPosition().y - animal_1CenterY < (*arrowVector)[j]->getPosition().y &&
				(*animalVector)[i]->getPosition().y + animal_1CenterY > (*arrowVector)[j]->getPosition().y ){
					
					(*animalVector)[i]->health -= (*arrowVector)[j]->damage;
					arrowVector->erase(arrowVector->begin() + j);

					if ((*animalVector)[i]->health <= 0) {
						this->score += (*animalVector)[i]->score;
					    animalVector->erase(animalVector->begin() + i);
					}
			}
		}
	}
	return;
}

void Collision::personCollision(std::vector<Animal*> *animalVector, sf::Vector2f personPos) {

	this->life = 0;
	int i;

	for (i = 0; i < animalVector->size(); i++) {
		if ((*animalVector)[i]->getPosition().x - animal_1CenterX < personPos.x &&
			    (*animalVector)[i]->getPosition().x + animal_1CenterX > personPos.x &&
				(*animalVector)[i]->getPosition().y - animal_1CenterY < personPos.y &&
				(*animalVector)[i]->getPosition().y + animal_1CenterY > personPos.y ){
					animalVector->erase(animalVector->begin() + i);
					this->life += 1;
		}
	}
}


int random(int inTime) {
	int random_int = RANDOM_LOWEST + int(RANGE*rand()/(RAND_MAX + 1.0f));
	if (inTime < 60) {
	    if (random_int <= 2) {
		    return RANDOM_SPAWN_POINT_LOWEST + int(SPAWN_RANGE*rand()/(RAND_MAX+1.0f));
	    }
	}
	else if (inTime < 120) {
	    if (random_int <= 2.5) {
		    return RANDOM_SPAWN_POINT_LOWEST + int(SPAWN_RANGE*rand()/(RAND_MAX+1.0f));
	    }
	}
	else if (inTime < 180) {
	    if (random_int <= 3.5) {
		    return RANDOM_SPAWN_POINT_LOWEST + int(SPAWN_RANGE*rand()/(RAND_MAX+1.0f));
	    }
	}
	else {
	    if (random_int <= 5) {
		    return RANDOM_SPAWN_POINT_LOWEST + int(SPAWN_RANGE*rand()/(RAND_MAX+1.0f));
	    }
	}
	return -1;
}

