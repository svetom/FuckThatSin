/*
 * stats.h
 *
 *  Created on: 22.11.2014
 *      Author: Svetozár
 */

#ifndef STATS_H_
#define STATS_H_



class stats
{
public:
	double maxFront;
	double maxTime;
	void maxTimeFunc ( double val );
	void maxFrontFunc ( double val );
	void printStats ( );

};

extern stats statistics;

#endif /* STATS_H_ */
