/*
 * cars.cpp
 *
 *  Created on: 22.11.2014
 *      Author: Svetozár
 */

#include "defs.h"
#include "cars.h"
#include "crossroads.h"
#include "stats.h"
#include <math.h>
#include <iostream>

semaphores semaphoresQueue ;



int Car :: ID = 0 ;

/**
 * ktorou drahou cez semafor auto pojde
 * @return
 */
int Car :: getSem ( void )
{
	return trunc ( Random ( ) * 10 );
}

void Car :: sendSignalGUI ( SINGAL_TO_GUI signal )
{
	switch ( signal )
	{
		case comming:
			break;
	}

}


void Car :: Behavior ( )
{
	this->Priority = LOWEST_PRIORITY;
	myId = Car :: idGen ( );
	mySem = getSem ( );
	arrival = Time;
	mySemState =  & crossroadsActive [ mySem ];

	//std::cout << " Cas " << Time  <<  " Sem auto prislo " << mySem << " Prichod " << Time << "\n";
	mySemPtr = sems [ mySem ];
	semaphoresQueue.incSem ( mySem );

	sendSignalGUI ( comming );

	sendSignalGUI ( waitingOnSem );


	Seize (  sems [ mySem ], LOWEST_PRIORITY );
	Wait( 2 );
	Release (  sems [ mySem ] );

	semaphoresQueue.decSem ( mySem );

	statistics.maxTimeFunc( Time - arrival );
	std::cout << " Cas " << Time  <<  " Sem auto preslo " << mySem << " Prichod " << Time << " Dlzka " << Time - arrival << " " << crossroadsActive [ mySem ] << " \n";


	sendSignalGUI ( leaving );
}


int Car :: idGen ( )
{
	return Car::ID++;
}

void carGenenerator::Behavior (  )
{

	int num = round ( Random()  );
	for ( int i = 0; i < num ; i++)
	{
		(new Car)->Activate();
	}

	Activate(Time+Exponential(1));
}


void initSemaphores ( void )
{
	int i = 0 ;
	for ( i = 0; i < 10 ; i++)
	{
		semaphoresQueue.semQueue.push_back(0);
	}
}

void semaphores::incSem ( int index )
{
	semQueue[index]++;
}


void semaphores::decSem ( int index )
{
	semQueue[index]--;
}

