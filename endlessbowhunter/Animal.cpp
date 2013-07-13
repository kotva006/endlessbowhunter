#define _USE_MATH_DEFINES

#include "Animal.h"
#include "Initialize.h"


//TODO make animals move towards person at all times
void Animal::move(sf::Vector2f personPos) {
	this->setOrigin(animal_1CenterX, animal_1CenterY);
	if (this->getPosition().x < personPos.x) {
		float newRadiansAngle = atan2f(
			                           personPos.y - this->getPosition().y,
									   personPos.x - this->getPosition().x);
		this->movement = sf::Vector2f(cosf(newRadiansAngle)*this->speed, sinf(newRadiansAngle)*this->speed);
		this->setRotation((1 * (newRadiansAngle * 180.0f) / M_PI) - 90.0f);
	} else {
		float newRadiansAngle = atan2f(
			                           personPos.y - this->getPosition().y,
									   this->getPosition().x - personPos.x);
		this->movement = sf::Vector2f(-cosf(newRadiansAngle)*this->speed, sinf(newRadiansAngle)*this->speed);
		this->setRotation((-1*(newRadiansAngle * 180.0f) / M_PI) + 90.0f);
	}
	this->setPosition(this->getPosition() + this->movement);
	this->setTexture(animalTextures[this->type - 1]);
	return;
}

void Animal::setHealth(int inTime) {
	if (inTime < 60)
		this->health = 10;
	else if (inTime < 120)
		this->health = 20;
	else if (inTime < 180)
		this->health = 30;
	else
		this->health = (10 * (inTime % 100)) + 30;
	return;
}

void Animal::setSpeed(int inTime) {
	if (inTime < 60)
		this->speed = 1;
	else if (inTime < 120)
		this->speed = 1.3;
	else if (inTime < 180)
		this->speed = 1.6;
	else
		this->speed = 2;
	return;
}

void Animal::setScore(int inTime) {
	if (inTime < 60)
		this->score = 10;
	else if (inTime < 120)
		this->score = 20;
	else if (inTime < 180)
		this->score = 30;
	else
		this->score = (10 * (inTime % 100)) + 30;
	return;
}