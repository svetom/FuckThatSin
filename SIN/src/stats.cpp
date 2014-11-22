/*
 * stats.cpp
 *
 *  Created on: 22.11.2014
 *      Author: Svetozár
 */

#include <iostream>
#include "stats.h"

stats statistics;


void stats :: maxTimeFunc ( double val )
{
	if ( maxTime < val ) maxTime = val;
}

void stats :: maxFrontFunc ( double val )
{
	if ( maxFront < val ) maxFront = val;
}


void stats :: printStats ( )
{
	std :: cout << "_______________________________\n";
	std :: cout << "Maximalna dlzka fronty: " << maxFront << " aut\n";
	std :: cout << "Maximalna dlzka cakania: " << maxTime << " sec.\n";
	std :: cout << "_______________________________\n";
}

