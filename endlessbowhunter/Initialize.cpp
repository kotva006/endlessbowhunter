#include "Settings.h"
#include "Initialize.h"


const std::string PICTURE_PATH = SOURCE_PATH + "\\Pictures";
const std::string SOUND_PATH   = SOURCE_PATH + "\\Sound\\";
const std::string FONT_PATH    = SOURCE_PATH + "\\Fonts\\";
const std::string ARROW_PATH   = PICTURE_PATH + "\\Arrows\\";
const std::string ANIMAL_PATH  = PICTURE_PATH + "\\Animals\\";
const std::string PERSON_PATH  = PICTURE_PATH + "\\Person\\";
const std::string CROSSHAIR_PATH = PICTURE_PATH + "\\Crosshairs\\";

int WINDOW_X = 800;
int WINDOW_Y = 800;
bool REDRAW  = true;
const std::string WINDOW_TITLE = "Endless Bow Hunter Experience";
const int personCenterX = 25;
const int personCenterY = 25;
const int arrowCenterX  = 5;
const int arrowCenterY  = 8;
const int animal_1CenterX = 25;
const int animal_1CenterY = 25;

// Movements

int BASE_MOVE_SPEED = 2;

//Textures

sf::Texture personTexture;
sf::Texture crossHairTexture;
sf::Texture arrowTexture;
sf::Texture animalTexture;

// Sprites

sf::Sprite person;
sf::Sprite crossHair;
sf::Sprite arrow;
sf::Sprite animal;

// Fonts

sf::Font scoreFont;

// Texts

sf::Text scoreText;

// Time

sf::Clock fpsClock;

Initialize *initialize() {
	Initialize *init = new Initialize();

	if (!personTexture.loadFromFile(PERSON_PATH + "person_1.png")){
		init->error = "Could not load person PNG";
		init->status = false;
		return init;
	}
	if (!crossHairTexture.loadFromFile(CROSSHAIR_PATH + "crosshair_1.png")) {
		init->error = "Could not load crosshair PNG";
		init->status = false;
		return init;
	}
	if (!arrowTexture.loadFromFile(ARROW_PATH + "arrow_1.png")) {
		init->error = "Could not load arrow PNG";
		init->status = false;
		return init;
	}
	if (!animalTexture.loadFromFile(ANIMAL_PATH + "animal_1.png")) {
		init->error = "Could not load animal1 PNG";
		init->status = false;
		return init;
	}
	if (!scoreFont.loadFromFile(FONT_PATH + "CaviarDreams.ttf")) {
		init->error = "Could not load main font";
		init->status = false;
		return init;
	}

	personTexture.setSmooth(true);
    personTexture.setRepeated(false);
	
	crossHairTexture.setSmooth(true);
    crossHairTexture.setRepeated(false);

	arrowTexture.setSmooth(true);
    arrowTexture.setRepeated(false);
	
	animalTexture.setSmooth(true);
    animalTexture.setRepeated(false);

	person.setTexture(personTexture);
	person.setOrigin(sf::Vector2f(personCenterX, personCenterY));
	person.setPosition(sf::Vector2f(WINDOW_X/2, WINDOW_Y-(personCenterY)));
	
	crossHair.setTexture(crossHairTexture);
	crossHair.setOrigin(sf::Vector2f(25,25));
	crossHair.setPosition(sf::Vector2f(WINDOW_X/2,WINDOW_Y/2));

	arrow.setTexture(arrowTexture);
	arrow.setOrigin(sf::Vector2f(arrowCenterX,arrowCenterY));

	animal.setTexture(animalTexture);
	animal.setOrigin(sf::Vector2f(animal_1CenterX,animal_1CenterY));

	scoreText.setFont(scoreFont);
	scoreText.setPosition(5,5);
	scoreText.setColor(sf::Color::White);
	scoreText.setCharacterSize(20);


	init->status = true;
	return init;
}