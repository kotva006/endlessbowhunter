#define _USE_MATH_DEFINES


#include "Arrow.h"
#include "Initialize.h"

// Arrow Damages

int BASE_ARROW_DAMAGE = 10;

void Arrow::move(sf::Vector2f personPos) {
	this->setOrigin(arrowCenterX, arrowCenterY);
	if(this->firstMove) {
		this->firstMove = false;
		if (this->movement.x < personPos.x) {
			float newRadiansAngle = atan2f(personPos.y - this->movement.y,
				                         personPos.x - this->movement.x);
			this->movement = sf::Vector2f(cosf(newRadiansAngle)*10, sinf(newRadiansAngle)*10);
			this->setRotation((1 * (newRadiansAngle * 180.0f) / M_PI) - 90.0f);
		} else {
			float newRadiansAngle = atan2f(personPos.y - this->movement.y,
					                     this->movement.x - personPos.x);
		    this->movement = sf::Vector2f(-cosf(newRadiansAngle)*10, sinf(newRadiansAngle)*10);
			this->setRotation((-1*(newRadiansAngle * 180.0f) / M_PI) + 90.0f);
		}
		this->setPosition(personPos);
		this->damage   = BASE_ARROW_DAMAGE;
		this->setTexture(arrowTextures[this->type - 1]);
		return;
	} else {
		this->movement.y = this->movement.y - .0781;
		this->setPosition(this->getPosition() - this->movement);
		return;
	}
}