#include <stdlib.h>
#include <iostream>


// Random number things
int RANDOM_LOWEST  = 1;
int RANDOM_HIGHEST = 100;
int RANGE = (RANDOM_HIGHEST - RANDOM_LOWEST) + 1;


bool random() {
	int random_int = RANDOM_LOWEST + int(RANGE*rand()/(RAND_MAX + 1.0f));
	if (random_int <= 2) {
		std::cout << "Random: " << random_int << std::endl;
		return true;
	}
	return false;
}
