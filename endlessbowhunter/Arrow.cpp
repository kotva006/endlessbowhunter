#define _USE_MATH_DEFINES

#include "Arrow.h"

// Arrow Damages

int BASE_ARROW_DAMAGE = 10;

void Arrow::move() {

	if(this->firstMove) {
		this->firstMove = false;
		if (this->movement.x < this->personPos.x) {
			float newRadiansAngle = atan2f(this->personPos.y - this->movement.y,
				                         this->personPos.x - this->movement.x);
			this->movement = sf::Vector2f(cosf(newRadiansAngle)*10, sinf(newRadiansAngle)*10);
			this->angle = (1 * (newRadiansAngle * 180.0f) / M_PI) - 90.0f;
		} else {
			float newRadiansAngle = atan2f(this->personPos.y - this->movement.y,
					                     this->movement.x - this->personPos.x);
		    this->movement = sf::Vector2f(-cosf(newRadiansAngle)*10, sinf(newRadiansAngle)*10);
			this->angle = (-1*(newRadiansAngle * 180.0f) / M_PI) + 90.0f;
		}
		this->position = personPos;
		this->damage   = BASE_ARROW_DAMAGE;
		return;
	} else {
		this->movement.y = this->movement.y - .0781;
		this->position = this->position - this->movement;
		return;
	}
}