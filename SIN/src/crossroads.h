/*
 * crossroads.h
 *
 *  Created on: 22.11.2014
 *      Author: Svetozár
 */

#ifndef CROSSROADS_H_
#define CROSSROADS_H_

#include "simlib.h"
#include "signals.h"
#include <vector>





class LogicOfCrossroads : public Event
{
public:
    double time;
	void Behavior();
};

class StateOfCrossroads : public Event
{
public:
    LogicOfCrossroads logicObj;
	void Behavior ( );
};


class RegSignal : public Process
{
public:
	RegSignal();
	int mySem;
	void sendSignalGUI ( SINGAL_TO_GUI signal );
	void Behavior ( );
};

void  initCrossroads ( );

extern Facility sems[  ];
extern Facility crossroadsSems[ ];
extern RegSignal crossroadsRedSignals [ ];
extern std :: vector <int> crossroadsActive;
extern std :: vector <int> crossroadsNumOfCars;


#endif /* CROSSROADS_H_ */
