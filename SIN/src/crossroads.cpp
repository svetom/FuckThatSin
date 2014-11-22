/*
 * crossroads.cpp
 *
 *  Created on: 22.11.2014
 *      Author: Svetozár
 */


#include <vector>
#include <iostream>
#include "simlib.h"
#include "cars.h"
#include "crossroads.h"
#include "stats.h"

#define NUM_OF_SEMS 10
#define PERIOD 240
#define RED 0
#define GREEN 1

/**
 * vektor semaforov
 */
Facility sems[ NUM_OF_SEMS ];
Facility crossroadsSems [ NUM_OF_SEMS ];
//RegSignal crossroadsRedSignals [ NUM_OF_SEMS ];
int currentSemIndex;
std :: vector <int> crossroadsActive;
std :: vector <int> crossroadsNumOfCars;


void setRedSignal ( std :: vector <int> vec)
{
	for ( int i = 0 ; i < NUM_OF_SEMS ; i ++ )
	{
		if ( crossroadsActive[ i ] == GREEN )
		{

		}
		else
		{
			currentSemIndex = i;
			( new RegSignal  )->Activate();
		}
	}
}

/**
 *
 */
void LogicOfCrossroads::Behavior()
{
	static long long changeDir;

	if 		( ( changeDir%PERIOD )== 0 )
	{
		crossroadsActive [ 0 ] = GREEN;
		crossroadsActive [ 1 ] = GREEN;
		crossroadsActive [ 2 ] = GREEN;
		crossroadsActive [ 3 ] = RED;
		crossroadsActive [ 4 ] = RED;
		crossroadsActive [ 5 ] = RED;
		crossroadsActive [ 6 ] = RED;
		crossroadsActive [ 7 ] = RED;
		crossroadsActive [ 8 ] = RED;
		crossroadsActive [ 9 ] = RED;

	}
	else if ( ( changeDir%PERIOD ) == 60)
	{
		crossroadsActive [ 0 ] = RED;
		crossroadsActive [ 1 ] = RED;
		crossroadsActive [ 2 ] = RED;
		crossroadsActive [ 3 ] = GREEN;
		crossroadsActive [ 4 ] = GREEN;
		crossroadsActive [ 5 ] = RED;
		crossroadsActive [ 6 ] = RED;
		crossroadsActive [ 7 ] = RED;
		crossroadsActive [ 8 ] = RED;
		crossroadsActive [ 9 ] = RED;
	}
	else if ( ( changeDir%PERIOD ) == 120 )
	{
		crossroadsActive [ 0 ] = RED;
		crossroadsActive [ 1 ] = RED;
		crossroadsActive [ 2 ] = RED;
		crossroadsActive [ 3 ] = RED;
		crossroadsActive [ 4 ] = RED;
		crossroadsActive [ 5 ] = GREEN;
		crossroadsActive [ 6 ] = GREEN;
		crossroadsActive [ 7 ] = GREEN;
		crossroadsActive [ 8 ] = RED;
		crossroadsActive [ 9 ] = RED;
	}
	else if ( ( changeDir%PERIOD ) == 180)
	{
		crossroadsActive [ 0 ] = RED;
		crossroadsActive [ 1 ] = RED;
		crossroadsActive [ 2 ] = RED;
		crossroadsActive [ 3 ] = RED;
		crossroadsActive [ 4 ] = RED;
		crossroadsActive [ 5 ] = RED;
		crossroadsActive [ 6 ] = RED;
		crossroadsActive [ 7 ] = RED;
		crossroadsActive [ 8 ] = GREEN;
		crossroadsActive [ 9 ] = GREEN;
	}



	if ( changeDir%(PERIOD/4) == 0)
	{
		setRedSignal ( crossroadsActive );

		std::cout << "************************\n";
		std::cout << "Time" << Time << "\n";
		for ( int i = 0 ; i < NUM_OF_SEMS ; i ++ )
		{
			std::cout << "Semafor " << i << " "<< crossroadsActive[i] << " Pocet: " << semaphoresQueue.semQueue[i] << " bussy " << crossroadsSems[i].Busy() << "\n";
			statistics.maxFrontFunc ( semaphoresQueue.semQueue[i]  );
		}
		std::cout << "************************\n";
	}

	changeDir++;
}



/**
 * generator ktory kazdu jednu casovu jednotku skontroluje stav
 * krizovatky tj zavola logiku ktora rozhoduje ako budu spustene
 * jednotlive semafory
 */
void StateOfCrossroads :: Behavior()
{
	logicObj.Behavior();
	Activate(Time+1);
}

void RegSignal :: Behavior ( )
{

	this->Priority = HIGHEST_PRIORITY;
	std::cout << "Semafor stopnuty" << mySem << " \n";
	Seize (  sems [ mySem ], HIGHEST_PRIORITY );
	Wait( PERIOD/4  - 1);
	Release (  sems [ mySem ] );
	std::cout << "Semafor uvolneny" << mySem << " \n";

}

RegSignal :: RegSignal ( )
{
	mySem = currentSemIndex;
}


void  initCrossroads ( )
{

	for ( int i = 0 ; i < NUM_OF_SEMS ; i ++ )
	{
		//crossroadsRedSignals [ i ].mySem = i;
		crossroadsActive.push_back( 0 );
	}

}
