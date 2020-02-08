/*
 * functions.cpp
 *
 *  Created on: 8 Feb 2020
 *      Author: hossam
 */

// SOURCE FILES
//=============

// files that contain your code that you might want to reuse


#include "functions.h"

using namespace std;

void
vDecrementMe(unsigned int * ptrU32Integer)
{
	cout << "The current number: " << *ptrU32Integer << endl;
	--ptrU32Integer[0];
}


void
vResetMe(unsigned int & refU32Integer)
{
	refU32Integer = 0;
}
