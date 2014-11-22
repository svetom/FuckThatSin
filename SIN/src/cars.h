/*
 * cars.h
 *
 *  Created on: 22.11.2014
 *      Author: Svetozár
 */

#ifndef CARS_H_
#define CARS_H_

#include <vector>
#include "simlib.h"
#include "signals.h"


class Car : public Process
{
public:
	static int ID;
	int myId;
	int mySem;
	double arrival;
	Facility * mySemPtr;
	int * mySemState;
	int getSem ( void );
	void sendSignalGUI ( SINGAL_TO_GUI signal );
	void Behavior ( );
	int idGen ();
};

class carGenenerator : public Event
{
	void Behavior (  );
};

class semaphores
{
public:
	void incSem ( int index);
	void decSem ( int index);
	std::vector <int> semQueue;
};

void initSemaphores ( void );

extern semaphores semaphoresQueue ;

#endif /* CARS_H_ */
