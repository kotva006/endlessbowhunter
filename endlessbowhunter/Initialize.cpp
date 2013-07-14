#include "Settings.h"
#include "Initialize.h"

// Movements

int BASE_MOVE_SPEED = 3;

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
sf::Text timeText;
sf::Text livesText;
sf::Text titleText;
sf::Text instructionsText;
sf::Text gameOver;
sf::Text finalScore;

int topFontSize = 20;
int titleFontSize = 50;
int instructionFontSize = 20;

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
	scoreText.setCharacterSize(topFontSize);
	scoreText.setString(SCORE_STRING);

	timeText.setFont(scoreFont);
	timeText.setPosition(WINDOW_X/2, 5);
	timeText.setColor(sf::Color::White);
	timeText.setCharacterSize(topFontSize);
	timeText.setString(TIME_STRING);

	livesText.setFont(scoreFont);
	livesText.setPosition(WINDOW_X - 75, 5);
	livesText.setColor(sf::Color::White);
	livesText.setCharacterSize(topFontSize);
	livesText.setString(LIVES_STRING);

	titleText.setFont(scoreFont);
	titleText.setPosition(WINDOW_X / 2 - 100, 150);
	titleText.setColor(sf::Color::White);
	titleText.setCharacterSize(titleFontSize);
	titleText.setString(TITLE_STRING);

	instructionsText.setFont(scoreFont);
	instructionsText.setPosition(WINDOW_X / 2 - 80, 400);
	instructionsText.setColor(sf::Color::White);
	instructionsText.setCharacterSize(instructionFontSize);
	instructionsText.setString(INSTRUCTIONS_STRING);

	gameOver.setFont(scoreFont);
	gameOver.setPosition(WINDOW_X / 2 - 100, 150);
	gameOver.setColor(sf::Color::White);
	gameOver.setCharacterSize(titleFontSize);
	gameOver.setString(END_GAME_STRING);

	finalScore.setFont(scoreFont);
	finalScore.setPosition(WINDOW_X / 2 - 80, 400);
	finalScore.setColor(sf::Color::White);
	finalScore.setCharacterSize(instructionFontSize);
	finalScore.setString(FINAL_SCORE_STRING);

	init->status = true;
	return init;
}