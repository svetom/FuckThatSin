/*
 * main.cpp
 *
 *  Created on: 22.11.2014
 *      Author: Svetozár
 */


#include "simlib.h"
#include "crossroads.h"
#include "cars.h"
#include "stats.h"
#include <time.h>


int main()
{
	RandomSeed(time(0));
	srand(time(0));

	Init(0,3600);

	initCrossroads ( );
	initSemaphores  ( );

	( new StateOfCrossroads )->Activate ( );
	( new carGenenerator )->Activate ( );

	Run ( );

	statistics.printStats ( );
	while (1);
	return 0;
}
