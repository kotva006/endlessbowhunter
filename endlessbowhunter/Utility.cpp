#include <stdlib.h>

#include "Initialize.h"


// Random number things
int RANDOM_LOWEST  = 1;
int RANDOM_HIGHEST = 500;
int RANGE = (RANDOM_HIGHEST - RANDOM_LOWEST) + 1;

int RANDOM_SPAWN_POINT_LOWEST  = 0;
int RANDOM_SPAWN_POINT_HIGHEST = WINDOW_X;
int SPAWN_RANGE = (RANDOM_SPAWN_POINT_HIGHEST - RANDOM_SPAWN_POINT_LOWEST) + 1;


int random() {
	int random_int = RANDOM_LOWEST + int(RANGE*rand()/(RAND_MAX + 1.0f));
	if (random_int <= 2) {
		return RANDOM_SPAWN_POINT_LOWEST + int(SPAWN_RANGE*rand()/(RAND_MAX+1.0f));
	}
	return -1;
}

