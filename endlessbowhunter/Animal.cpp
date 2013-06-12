#define _USE_MATH_DEFINES

#include "Animal.h"
#include "Initialize.h"


//TODO make animals move towards person at all times
void Animal::move(sf::Vector2f personPos) {
	this->setOrigin(animal_1CenterX, animal_1CenterY);
	if (this->getPosition().x < personPos.x) {
		float newRadiansAngle = atan2f(personPos.y - this->movement.y,
			                         personPos.x - this->movement.x);
		this->movement = sf::Vector2f(cosf(newRadiansAngle)*this->speed, sinf(newRadiansAngle)*this->speed);
		this->setRotation((1 * (newRadiansAngle * 180.0f) / M_PI) - 90.0f);
	} else {
		float newRadiansAngle = atan2f(personPos.y - this->movement.y,
				                     this->movement.x - personPos.x);
		this->movement = sf::Vector2f(-cosf(newRadiansAngle)*this->speed, sinf(newRadiansAngle)*this->speed);
		this->setRotation((-1*(newRadiansAngle * 180.0f) / M_PI) + 90.0f);
	}
	this->setPosition(this->getPosition() + this->movement);
	this->setTexture(animalTextures[this->type - 1]);
	return;
}