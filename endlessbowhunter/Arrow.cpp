#define _USE_MATH_DEFINES


#include "Arrow.h"
#include "Initialize.h"

// Arrow Damages

int BASE_ARROW_DAMAGE = 10;

// This function changes the arrows velocity and angle

void Arrow::move(sf::Vector2f personPos) {
	this->setOrigin(arrowCenterX, arrowCenterY);
	if(this->firstMove) {
		this->firstMove = false;

		// here this->movement is the position of the mouse

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

		//Update the position and angle of the arrow as it travesl using vector math
		// tempPosition is used to determine where the arrow is going to change the angle as the
		// veolcity vector changes
		sf::Vector2f tempPosition = sf::Vector2f(this->getPosition() - this->movement);
		if (this->movement.x < 0) {
			float newRadiansAngle = atan2f(this->getPosition().y - tempPosition.y,
				                         this->getPosition().x - tempPosition.x);
			this->setRotation((1 * (newRadiansAngle * 180.0f) / M_PI) - 90.0f);
		} else {
			float newRadiansAngle = atan2f(this->getPosition().y - tempPosition.y,
					                     tempPosition.x - this->getPosition().x);
			this->setRotation((-1 * (newRadiansAngle * 180.0f) / M_PI) + 90.0f);
		}
		this->movement.y = this->movement.y - .0731;
		this->setPosition(this->getPosition() - this->movement);
		return;
	}
}