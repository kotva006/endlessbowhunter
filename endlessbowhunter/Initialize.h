#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "Settings.h"
#include <SFML/Graphics.hpp>


extern const std::string PICTURE_PATH;
extern const std::string SOUND_PATH;
extern const std::string FONT_PATH;
extern const std::string ARROW_PATH;
extern const std::string ANIMAL_PATH;
extern const std::string PERSON_PATH;
extern const std::string CROSSHAIR_PATH;


//  Game Values
extern int WINDOW_X;
extern int WINDOW_Y;
extern bool REDRAW;
extern const std::string WINDOW_TITLE;
extern const int personCenterX;
extern const int personCenterY;
extern const int arrowCenterX;
extern const int arrowCenterY;
extern const int animal_1CenterX;
extern const int animal_1CenterY;

// Person Values
extern int BASE_MOVE_SPEED;

// Textures

extern sf::Texture personTexture;
extern sf::Texture crossHairTexture;
extern sf::Texture arrowTexture;
extern sf::Texture animalTexture;

// Sprites

extern sf::Sprite person;
extern sf::Sprite crossHair;
extern sf::Sprite arrow;
extern sf::Sprite animal;

// Fonts

extern sf::Font scoreFont;

// Texts

extern sf::Text scoreText;

// Time

extern sf::Clock fpsClock;

class Initialize {
public:
	Initialize() {};
	~Initialize() {};
	std::string error;
	bool status;
} ;

Initialize *initialize();
#endif




