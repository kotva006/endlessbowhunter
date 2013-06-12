#include "Settings.h"
#include "Initialize.h"

// Movements

int BASE_MOVE_SPEED = 2;

//Textures

sf::Texture personTexture;
sf::Texture crossHairTexture;
std::vector<sf::Texture> arrowTextures;
std::vector<sf::Texture> animalTextures;

// Sprites

sf::Sprite person;
sf::Sprite crossHair;
//sf::Sprite arrow;
//sf::Sprite animal;

// Fonts

sf::Font scoreFont;

// Texts

sf::Text scoreText;
int scoreFontSize = 20;

// Time

sf::Clock fpsClock;

Initialize *initialize() {
	Initialize *init = new Initialize();

	if (!personTexture.loadFromFile(PERSON_PATH + (std::string) "person_1.png")){
		init->error = "Could not load person PNG";
		init->status = false;
		return init;
	}
	if (!crossHairTexture.loadFromFile(CROSSHAIR_PATH + (std::string) "crosshair_1.png")) {
		init->error = "Could not load crosshair PNG";
		init->status = false;
		return init;
	}

	//TODO set up enumerated type for each type of arrow and easily use them
	int i = 0;
	sf::Texture stuff;
	arrowTextures.push_back(stuff);
	for (i = 0; i < 1; i++) {
	    if (!arrowTextures[i].loadFromFile(ARROW_PATH + (std::string) "arrow_1.png")) {
		    init->error = "Could not load arrow PNG";
		    init->status = false;
		    return init;
	    }
		arrowTextures[i].setSmooth(true);
        arrowTextures[i].setRepeated(false);
	}

	//TODO set up enumerated type for the variety of animals
	animalTextures.push_back(stuff);
	for (i = 0; i < 1; i++) {
	    if (!animalTextures[i].loadFromFile(ANIMAL_PATH + (std::string) "animal_1.png")) {
		    init->error = "Could not load animal1 PNG";
		    init->status = false;
		    return init;
		}
		animalTextures[i].setSmooth(true);
		animalTextures[i].setRepeated(false);
	}
	if (!scoreFont.loadFromFile(FONT_PATH + (std::string) "CaviarDreams.ttf")) {
		init->error = "Could not load main font";
		init->status = false;
		return init;
	}

	personTexture.setSmooth(true);
    personTexture.setRepeated(false);
	
	crossHairTexture.setSmooth(true);
    crossHairTexture.setRepeated(false);
	
	person.setTexture(personTexture);
	person.setOrigin(sf::Vector2f(personCenterX, personCenterY));
	person.setPosition(sf::Vector2f(WINDOW_X/2, WINDOW_Y-(personCenterY)));
	
	crossHair.setTexture(crossHairTexture);
	crossHair.setOrigin(sf::Vector2f(crossHairCenterX,crossHairCenterY));
	crossHair.setPosition(sf::Vector2f(WINDOW_X/2,WINDOW_Y/2));

	scoreText.setFont(scoreFont);
	scoreText.setPosition(5,5);
	scoreText.setColor(sf::Color::White);
	scoreText.setCharacterSize(scoreFontSize);


	init->status = true;
	return init;
}