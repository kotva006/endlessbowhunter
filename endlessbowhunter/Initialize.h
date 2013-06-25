#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Settings.h"

#define PICTURE_PATH     SOURCE_PATH "/Pictures"
#define SOUND_PATH       SOURCE_PATH "/Sound"
#define FONT_PATH        SOURCE_PATH "/Fonts/"
#define ARROW_PATH       PICTURE_PATH "/Arrows/"
#define ANIMAL_PATH      PICTURE_PATH "/Animals/"
#define PERSON_PATH      PICTURE_PATH "/Person/"
#define CROSSHAIR_PATH   PICTURE_PATH "/Crosshairs/"

//  Game Values

#define WINDOW_X 800
#define WINDOW_Y 800
#define WINDOW_TITLE "Endless Bow Hunter Experience"
#define personCenterX 25
#define personCenterY 25
#define crossHairCenterX 2.5
#define crossHairCenterY 2.5
#define arrowCenterX  5
#define arrowCenterY 8
#define animal_1CenterX 25
#define animal_1CenterY 25

#define SCORE_STRING "Score: " 


// Person Values
extern int BASE_MOVE_SPEED;

// Textures

extern sf::Texture personTexture;
extern sf::Texture crossHairTexture;
extern std::vector<sf::Texture> arrowTextures;
extern std::vector<sf::Texture> animalTextures;

// Sprites

extern sf::Sprite person;
extern sf::Sprite crossHair;

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




