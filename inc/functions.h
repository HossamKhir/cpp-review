/*
 * functions.h
 *
 *  Created on: 8 Feb 2020
 *      Author: hossam
 */

// HEADER FILES
//=============
/* for modularity, the code could be split to files,
 * the files could be used when requested,
 * the structure used is to put declarations in header files:
 * files with extension '.h', and the definitions in source files:
 * files with extension '.c' or '.cpp'*/

//________________________________________________________________
// GUARDS
//=======

// to avoid errors from multiple inclusions, the guards are used
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/* header files hold:
 * 	includes
 * 	functions prototypes */

// includes
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// functions prototypes
void
vDecrementMe(unsigned int *);

void
vResetMe(unsigned int &);

#endif /* FUNCTIONS_H_ */
