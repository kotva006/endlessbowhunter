
#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Initialize.h"
#include "Arrow.h"
#include "Animal.h"
#include "Utility.h"


int main() {

	Initialize * init = initialize();
	if(!init->status){
		std::cout << "There was an error loading resources." << std::endl;
		std::cout << "Error: " << init->error << std::endl;
		std::cin >> init->error;
		return 1;
	}
    
	sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), WINDOW_TITLE);
	window.setMouseCursorVisible(true);

	int moveSpeed = BASE_MOVE_SPEED;
	bool REDRAW = true;
	bool canClick = true;
	int score = 0;
	int i, j = 0;

	std::vector<Arrow*> arrowVector = std::vector<Arrow*>();
	std::vector<Animal*> animalVector = std::vector<Animal*>();

	Collision *col = new Collision();

	std::cout << RAND_MAX + 1<< std::endl;
	srand((unsigned int) time(0));

	while(window.isOpen()) {

		sf::Event event;
		sf::Time elapsed = fpsClock.getElapsedTime();

		while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if ((elapsed.asMilliseconds() % 1000) >= 10) {
			REDRAW = true;
			fpsClock.restart();
		}

		if (!canClick && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
			canClick = true;

		if (REDRAW && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
			       || sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
			if (person.getPosition().x >= personCenterX) {
			    person.move(-moveSpeed, 0);
			}
		}

		if (REDRAW && (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
			       || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
			if (person.getPosition().x <= WINDOW_X - personCenterX) { 
			    person.move(moveSpeed, 0);
			}
		}

		if (canClick && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			arrowVector.push_back(new Arrow((sf::Vector2f) 
				             sf::Mouse::getPosition(window), 1, 1));
			canClick = false;
		}
		
		if (REDRAW) {
			int randomInt = random();
			if (randomInt !=-1) {
				animalVector.push_back(
				    new Animal(sf::Vector2f(randomInt, 0), 20, 1, 1));
			}

			col->collision(&animalVector, &arrowVector);

			REDRAW = false;
			window.clear();

			scoreText.setString(SCORE_STRING + (std::string) std::to_string(score += col->score)); 

			for (i = 0; i < arrowVector.size(); i++) {
				arrowVector[i]->move(person.getPosition());
				window.draw(*arrowVector[i]);
			}

			for (i = 0; i < animalVector.size(); i++) {
				animalVector[i]->move(person.getPosition());
				window.draw(*animalVector[i]);
			}

			crossHair.setPosition((sf::Vector2f) sf::Mouse::getPosition(window));

		    window.draw(person);
		    window.draw(crossHair);
			window.draw(scoreText);
		    window.display();
		}
	}

	


	return 0;
}