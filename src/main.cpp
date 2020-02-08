/*
 * main.cpp
 *
 *  Created on: 31 Jan 2020
 *      Author: hossam
 */

/*	TOPICS:
 *	->	Comments
 *	->	Includes
 *	->	Functions
 *	->	Classes
 *		->	Inheritance
 *	->	Variables
 *	->	Data Types
 *		->	Native
 *		->	Non-native
 *	->	Type Modifiers
 *	->	Arithmetics
 *	->	Compound Assignment
 *	->	Concatenation
 *	->	Casting
 *	->	Operators
 *		->	Comparison
 *		->	Logical
 *		->	Bitwise
 *	->	Arrays
 *	->	Flow Control
 *		->	Conditional Statements
 *		->	Loops
 *		->	Nesting
 *	->	Function Calls
 *	->	Files Handling
 *	->	Exception Handling
 *	->	Pointers
 *	->	References
 *	->	Object Oriented Programming
 * */

// COMMENTS
//=========
// This is a single line (in-line) comment
/*
 * This is
 * called a
 * multi-line (block)
 * comment
 * */

// INCLUDES
//=========

/* programmes always use some utilities,
 * which are within different files that need
 * to be included to be able to use those utils */

// global headers
// for input/output access
#include <iostream>

// for dealing with vectors
#include <vector>

// for dealing with strings
#include <string>

// for dealing with files
#include <fstream>

// user defined header
#include "functions.h"

// loading the standard name space
using namespace std;

// FUNCTIONS
//==========

// AKA: subroutines
/* functions could be defined before usage scope -namely main-,
 * or just declared before it, then defined afterwards
 * or elsewhere.
 * functions are great for code reusability */

/* function syntax:
 * <modifier> <return_type> <function_identifier>(<parameter_list>)
 * { <body_of_function> } */
// parameters are also called attributes

/* modifiers:
 * static: limit the visibility of the function to the current file */

/* return type:
 * any data type: void, bool, char, int, float, double, string, class */

int
add2Numbers(int u32Operand0,
		int u32Operand1 = 0)	/* any attribute can have a default value,
												so on calling the function with this argument missing,
												the default value is then used instead,
												but the default value attributes MUST always be last in parameter list */
{
	return (u32Operand0 + u32Operand1);
}
// this type of functions, having default value must always be defined, not declared then defined


/* function overloading:
 * the same function identifier could be used for different functions:
 * having different parameter list,
 * having different return type, or both */

// declaration: function prototype
float
add2Numbers(float, float);

/* recursive functions:
 * functions that call itself within itself, while having a terminating condition,
 * otherwise, it will run indefinitely */
unsigned int
u32Factorial(unsigned int);

// CLASSES
//========

// object oriented programming

/* a good practice is to have the class name starting with a capital letter */
class Animal
{
	/* access modifiers: keywords that control the access scope of properties
	 * and methods, to apply encapsulation
	 * protected: accessible only inside object code, and can be inherited*/
	// private:	accessible only inside the object code, and can't be inherited
	private:
		int s32Height;
		int s32Weight;
		string strName;

		/* static property: within classes means one instance of the variable
		 * shared with all objects of the class */
		static int s32NumberOfAnimals;

	// public: accessible from any scope, common with methods
	public:
		// setters & getters: methods to set and get properties of object
		int getHeight(void) const {
			return s32Height;
		}

		void setHeight(int height) {
			this->s32Height = height;
		}

		const string& getName(void) const {
			return strName;
		}

		void setName(const string &name) {
			this->strName = name;
		}

		int getWeight(void) const {
			return s32Weight;
		}

		void setWeight(int weight) {
			this->s32Weight = weight;
		}

		// method prototype
		void setAll(int, int, string);

		// virtual methods
		/* used with methods in the base class (superclass), which will
		 * be overridden by subclasses, for ensuring polymorphism, as
		 * passing by reference could cast the subclass leading to
		 * not overriding */
		virtual void
		makeSound(void)
		{
			cout << "Animal says Grrr!\n" << endl;
		}

		void
		getFamily(void)
		{
			cout << "We are animals\n" << endl;
		}

		/* constructors: methods to instantiate an object of the class,
		 * they are always public */
		/* empty constructor: unless there is any other constructors present;
		 * this is implicitly defined, also known as default constructor */
		Animal(void);

		// overloading in action
		// non empty constructors: used with values to initialise the object's properties
		Animal(int, int, string);

		/* destructors: to safely delete the object after its lifetime */
		~Animal(void);

		/* static method: method that does not need an instance of the object
		 * to be used; they work solely with static properties */
		static int
		getS32NumberOfAnimals(void)
		{
			return s32NumberOfAnimals;
		}

		void toString(void);
};

/* accessing members of class outside its body is done using access operator '::' */
int Animal::s32NumberOfAnimals = 0;

// INHERITANCE
//------------

/* inheritance is the act of passing attributes & methods of a class, called superclass
 * to another class, called subclass (superclass: parent class/subclass: child class) */
class Dog : public Animal
{
	private:
		string strSound = "Woof";

	public:
		const string&
		getSound(void) const
		{
			return strSound;
		}

		Dog(int, int, string, string);

		Dog(void) : Animal(){};	// calling superclass constructor

		/* overriding: same method name, with same attributes but
		 * inside a subclass */
		void toString(void);

		void
		makeSound(void)
		{
			cout << "Dog says Woof!\n" << endl;
		}
};

void
vWhatClassAreYou(Animal *);

class GermanShepard : public Dog
{
	public:
		void
		makeSound(void)
		{
			cout << "Animal says Guten Morgen\n" << endl;
		}

		void
		getDerived(void)
		{
			cout << "I am an animal & a dog\n" << endl;
		}

};

class Cat : public Animal
{
	public:
		void
		makeSound(void)
		{
			cout << "Cat says Meow!\n" << endl;
		}
};

// Capability class

// ABSTRACT CLASS
//---------------

/* a class created only to be inherited, and has only virtual methods */

class Car
{
	public:
		virtual int
		getNumWheels(void) = 0;
		virtual int
		getNumDoors(void) = 0;
};

class StationWagon : public Car
{
	public:
		int
		getNumWheels(void)
		{
			cout << "Station wagon has 4 wheels\n" << endl;
			return 0;
		}
		int
		getNumDoors(void)
		{
			cout << "Station wagon has 4 doors\n" << endl;
			return 0;
		}

		StationWagon(){};
		~StationWagon();
};



//______________________________________________

// the starting point of execution is always the "main" function
int
main(void)
{
	// output to the console syntax
	cout << "Hello World!" << endl;	// endl sends a new line: "\n"
	std::cout << "Another way to access namespace" << std::endl;
	// cout is the default output stream (the screen)
	// cin is the default input stream (the keyboard)
	//_______________________________________________
	// VARIABLES
	//==========

	/* variables always start with a letter, upper or lower case
	 * can contain upper/lower case letters, underscores, numbers
	 * can never contain spaces, hyphens, or special characters */

	/* variables have scope & lifetime:
	 * scope: the context in which the variable is seen and used
	 * lifetime: the time the variable remains in the memory */

	/* global variables:
	 * variables defined outside all functions scopes, accessible to
	 * all scopes, unless defined as static, then accessible only to
	 * the file where declaration occurred */

	/* local variables:
	 * variables defined within function body, or bodies of if, for, while,
	 * do-while, or switch statements. each statement's scope ends by
	 * its boundaries  */

	/* a new scope can be defined by simply creating a block between
	 * 2 braces { <new_scope> }  */

	//_____________________________________________________________________
	// DATA TYPES
	//=======================
	// NATIVE DATA TYPES
	//------------------

	/* char: stores characters (ASCII codes 0:255), or integers
	 * with 1 byte precision*/
	char s8Grade = 'A';	// characters are contained within single quotes ''
	// each statement in C++ must end in a ';'

	/* bool: stores boolean values (true, false); on declaring variables
	 * of this data type, it is recommended to be named as Yes/No question*/
	bool isNotIntoxicated = true;	// true: converges either to 1 or !0; false: 0
	// this is called definition = declaration + assignment

	// int: whole numbers, usually at precision of 4 bytes
	unsigned int u32MyAge = 25;

	// float: floating point numbers, at precision of 4 bytes
	float fltHeightCm = 174.0;

	// double: can contain floating point numbers, with 8 byte precision
	const double dblPI = 3.14159;

	cout << "Pi = " << dblPI << endl;

	// NON NATIVE DATA TYPES
	//----------------------

	// string: array of characters
	string sNumberGussed;	// string is actually a class
	string strUserName;

	cout << "Please, state your name: ";

	/* read user input, normally almost any input can
	 * be stored in a string so no need for try-catch */
	getline(cin, strUserName);

	cout << "Hello " << strUserName << '!' << endl;

	double dblEulerNumber = .57721;
	string strEulerNumber;

	cout << "What is Euler's constant?: ";

	try
	{
		cin >> strEulerNumber;	// cin reads up to the next white space (space, new line)

		if (stod(strEulerNumber) == dblEulerNumber)	// this is bad practice
		{
			cout << "You are right\n" << endl;
		}
		else
		{
			cout << "You are mistaken\n" << endl;
		}
	}
	catch (exception ex)
	{
		cout << ex.what() << endl;
	}

	// string methods

	// get string length (size)
	cout << strUserName.size() << endl;

	// check if a string is empty
	cout << strUserName.empty() << endl;

	// appending: adding to the end of a string
	cout << strUserName.append(" substring") << endl;

	// strings cannot be compared by usual comparison operator
	cout << strUserName.compare("Reda") << endl;
	/* output of compare is not true or false, but values to determine where the first
	 * difference lie in alphabetical order; if the strings are the same; the result is
	 * 0, if the main string compared has a character that precedes the string compared
	 * against; the result is -1, if the main string compared has a character that
	 * succeeds the string compared against; the result is 1*/
	cout << strUserName.compare(strUserName) << endl;

	// assigning a string
	cout <<  strUserName.assign(strUserName + " Khair") << endl;
	// assign(string <string_to_assign>)

	// getting a substring
	cout << strUserName.assign(strUserName, 0, 6) << endl;
	// assign(string <full_string>, int <starting_index>, int <length_of_substring>)

	// get index of start of substring
	cout << strUserName.find("am", 0) << endl;
	// find(string <substring_to_find>, int <starting_index_of_search>)

	// inserting a substring at a specific index
	cout << strUserName.insert(6, "-") << endl;
	// insert(int <position>, string <substring>)

	// erasing certain length
	cout << strUserName.erase(6, 1) << endl;
	// erase(int <erase_index>, int <erase_length>)

	// replacing certain length
	cout << strUserName.replace(0, 6, "Reda") << endl;
	/* replace(int <start_index>, int <replace_length>,
	 * string <string_to_replace_with>) */
	//************************************************
	// vectors: basically like arrays, with changeable size

	vector<int> vtrLotteryNumberVector(10);
	// this is a vector of integers of size 10
	int u32LotterNumberArray[5] = {4, 13, 14, 24, 34};

	// vector methods
	// filling the vector
	vtrLotteryNumberVector.insert(vtrLotteryNumberVector.begin(),	// set insert at beginning
			// begin(void): returns address of first element in vector
			u32LotterNumberArray,	// address of 1st element in array
			u32LotterNumberArray+3);	// dereferencing to position 4
	// insert(int <start_address_vector>, int <start_address>, int <end_address>)

	cout << vtrLotteryNumberVector.at(2) << endl; // printing what lies at 3rd index
	// at(int <index>)

	vtrLotteryNumberVector.insert(vtrLotteryNumberVector.begin() + 5, 44);
	// insert(int <start_address_vector>, <data_type> <value_to_add>)

	cout << vtrLotteryNumberVector.at(5) << endl;

	// add a new value to the end of the vector
	vtrLotteryNumberVector.push_back(64);
	// push_back(<data_type> <value_to_push>)

	cout << vtrLotteryNumberVector.back() << endl;	// returns the last element
	// back(void): return last element

	// remove last element
	vtrLotteryNumberVector.pop_back();
	// pop_back(void): removes last element

	cout << vtrLotteryNumberVector.front() << endl; // returns first element
	// front(void): returns first element

	// check emptiness of vector
	cout << vtrLotteryNumberVector.empty() << endl;
	// empty(void): returns true if the vector is empty

	// get size of vector
	cout << vtrLotteryNumberVector.size() << endl;
	// size(void): returns length of vector
	//____________________________________________
	// TYPE MODIFIERS
	//===============

	/* const: indicates that the value of the variable can't be
	 * explicitly altered, otherwise an exception occurs*/

	/* signed: "default" indicates that the the variable can hold
	 * either a +ve or -ve values */

	// unsigned: indicates that the variable can only hold +ve values

	// short: used to request half the size of the data type

	// long: used to request double the size of the data type

	/* static: with variables has different usages:
	 * ->	within function body: changes the local variable's lifetime
	 * to be the time of the programme
	 * ->	within a file:	limits the global variable's/function's scope
	 * to be the file that it is in it */

	cout << "bool\t\t" << sizeof(bool) << endl
			<< "char\t\t" << sizeof(char) << endl
			<< "int\t\t" <<  sizeof(int) << endl
			<< "float\t\t" << sizeof(float) << endl
			<< "double\t\t" << sizeof(double) << endl;

	// sizeof: operator to return size of variables and data type

	/* signed data types variables when exceed their limit in either direction
	 * they change sign as a result of overflow*/
	int u32LongestInteger = 2147483647;

	cout << u32LongestInteger << endl;	// this outputs 2147483647

	u32LongestInteger += 1;	// overflow occurs
	// this is called assignment

	cout << u32LongestInteger << endl;	// outputs: -2147483648
	//________________________________
	// ARITHMETICS
	//============

	/* basic arithmetic operation such as addition '+', subtraction '-',
	 * multiplication, division, modulus
	 * non basic arithmetic: increment '++', decrement '--'
	 * */
	cout << "5 + 2 = " << (5 + 2) << endl;
	cout << "5 - 2 = " << (5 - 2) << endl;
	cout << "5 * 2 = " << (5 * 2) << endl;
	/* division is called integer division; it returns integer values
	 * on dividing integers */
	cout << "5 / 2 = " << (5 / 2) << endl;
	// to obtain floating point result, one of the results must be floating point
	cout << "5 / 2.0 = " << (5 / 2.0) << endl;	//
	cout << "5 % 2 = " << (5 % 2) << endl;

	// pre-increment: incrementing occurs before using the value prefix
	cout << ++u32MyAge << endl;	// outputs 26, as the value is incremented first

	// post-increment: incrementing occurs after the usage of the value suffix/postfix
	cout << u32MyAge-- << endl;	/* outputs 26, as the value is used first then
									decremented */
	/* operator precedence:
	 * 1)	::
	 * 2)	suffix++/postfix--, (functional_casting), function_call(), subscript[],
	 * 		access.modifiers-> (dot & arrow)
	 * 3)	++prefix/--, -unary plus/minus, !logical_not/~bitwise_not, (c_like_casting),
	 * 		*dereference, &address, sizeof(), new/new[] 'dynamic allocation',
	 * 		delete/delete[] 'dynamic deallocation'
	 * 4)	.*\->* pointer to member
	 * 5)	*, /, %
	 * 6)	+, -
	 * 7)	<< >>
	 * 8)	<, <=, >, >=
	 * 9)	==, !=
	 * 10)	&
	 * 11)	^
	 * 12)	|
	 * 13)	&&
	 * 14)	||
	 * 15)	ternary? true:false, throw 'throw operator', = 'assignment',
	 * 		+=,-=,*=,/=,%=,>>=,<<=,&=,^=,|=
	 * 16)	, 'comma'*/
	//_________________________
	// COMPOUND ASSIGNMENT
	//====================

	// +=:	addition assignment
	// -=:	subtraction assignment
	// *=:	multiplication assignment
	// /=:	division assignment
	// %=:	modulus assignment
	// &=:	bitwise AND assignment
	// |=:	bitwise OR assignment
	// ^=:	bitwise XOR assignment
	// <<=, >>=: bitwise shift assignment

	cout << (fltHeightCm += 0.2) << endl;
	//___________________________________
	// CONCATENATION
	//==============

	// concatenate is gluing 2 or more string together, in C++ it is easy as addition
	char u8Happy[6] = "Happy";
	string strBirthday = " Birthday";

	cout << u8Happy + strBirthday << endl;
	//____________________________________
	// CASTING
	//========

	// casting is changing the data type of a value, it can cause loss of precision
	cout << "4 / 5 = " << (4 / 5) << endl;	// this is integer division
	// explicit casting
	cout << "4 / 5 = " << ((float)(4) / 5) << endl;	// casting 4 from int to float
	//_____________________________________________
	// OPERATORS
	//==========
	// COMPARISON
	//-----------

	// ==:	is equal
	// !=:	not equal
	// <:	less than
	// >:	greater than
	// <=:	less than or equal
	// >=:	greater than or equal

	// LOGICAL
	//--------

	// &&:	AND
	// ||:	OR
	// !:	NOT

	// BITWISE
	//--------

	// &:	bitwise AND
	// |:	bitwise OR
	// ^:	bitwise XOR
	// ~:	bitwise NOT
	//_____________________________________________
	// ARRAYS
	//=======

	// storage for homogeneous data types
	// declaring an array requires size for the array
	unsigned int u32Primes[5];
	// this is declaration, the array now contains garbage values
	/* this is definition, arrays could be initialised instead of
	 * simply configure their size */
	unsigned int u32PowersOfTwo[] = {1, 2, 4, 8, 16, 32, 64,
			128, 256, 512, 1024, 2048, 4096};
	/* arrays could be auto-filled by determining the size
	 * and providing less values than it */
	int s32AutoFilled[10] = {100};	// the rest of the array is filled with 0's

	// indexing starts at 0
	cout << u32Primes[0] << endl;	// prints the first element in the array

	/* multidimensional arrays: arrays of arrays,
	 * requires at the sizes of all the dimensions, except the first */
	unsigned char u8FullName[2][7] = {
			"Hossam",
			"Khair"};
	/* in char arrays, null terminator is added to the end of each string and thus
	 * must be taken into consideration while dealing with storage in variables */

	cout << u8FullName[0] << endl << u8FullName[1] << endl << u8FullName[1][2] << endl;

	/* any value in an array can be accessed,
	 * modified (unless declared const), by subscripts,
	 * each subscript is for the dimension that meets it */
	//_________________________________________________________________________________
	// FLOW CONTROL
	//=============

	// CONDITIONAL STATEMENTS
	//-----------------------

	/* it is not recommended trying conditionals with floating number values because
	 * of the precision issue */
	unsigned int u32MinimumAcceptableAge = 16;

	// if statement
	if((u32MyAge >= 1) && (u32MyAge < u32MinimumAcceptableAge))
	{
		cout << "You cannot drive\n" << endl;
	}
	else if (!isNotIntoxicated)
	{
		cout << "You can't drive" << endl;
	}
	else
	{
		cout << "You can drive! :)" << endl;
	}

	// switch statement: useful for limited possibilities, works only with integer types
	switch(s8Grade)
	{
		case 'D':
			cout << "You are a failure\n" << endl;
			break;	// used to break out "end" the scope of the context (loops, if, switch)
		case 'C':
		case 'B':
			cout << "You can do better yet\n" << endl;
			/* the missing break statement will cause all the statements to be
			 * executed all the way till it either meets a break statement
			 * or it reaches the end of the switch statement */
			break;
		case 'A':
			cout << "Excellent" << endl;
			break;
		default:
			cout << "You missed the exam\n" << endl;
	}

	// ternary operator: (condition)? <statement_if_true>: <statement_if_false>
	cout << ((5 >= 2)? 5 : 2) << endl;

	// LOOPS
	//-------

	// for loop: for a known number of repetitions
	/* for(<initialisation>; <loop_condition>; <increment_decrement>)
	 * { <statements_to_repeat> } */
	for (int s32Index = 0; s32Index < 10; s32Index++)
	{
		cout << s32Index << ' ';
	}

	cout << endl;

	// while loop: for unknown number of repetitions
	/* while(condition)
	 * { <statements_to_repeat>
	 * 	 <condition_update> } */
	unsigned int u32RandomNumber = (rand() % 100) + 1;
	while (u32RandomNumber != 100)
	{
		cout << u32RandomNumber << ", ";
		u32RandomNumber = (rand() % 100) + 1;
	}

	cout << endl;

	// while loops can work for known number of times
	u32RandomNumber = 0;
	while (u32RandomNumber < 10)
	{
		cout << u32RandomNumber++ << ' ';
	}

	cout << endl;

	// do {} while loop: like while but at least runs once
	do
	{
		cout << "Guess a number between 1 & 10: ";

		/* when dealing with user input, there could be chance
		 * of having exceptions, so use try-catch block */
		try
		{
		// reads line from stream, cin is keyboard stream
		getline(cin, sNumberGussed);

		// stoi: string to integer
		u32RandomNumber = stoi(sNumberGussed);

		// stod: string to double

		cout << u32RandomNumber << endl;

		}
		catch (exception ex)
		{
			cout << "That was not a number\n" << ex.what() << endl;
		}
	} while(u32RandomNumber != 4);

	cout << "You win!" << endl;

	// infinite loops
	// for(;;) {}
	// while(1) {}
	// while(true) {}

	// NESTING
	//--------

	// nesting is creating elements inside of elements of same kind

	// nested for
	for (int s32Row = 0; s32Row < 2; s32Row++)
	{
		for (int s32Column = 0; s32Column < 7; s32Column++)
		{
			cout << u8FullName[s32Row][s32Column];
			// trying to access a non-existing index causes a runtime error
		}
		cout << endl;
	}
	//____________
	// FUNCTION CALLS
	//===============

	// use the function identifier followed by arguments within parenthesis
	cout << add2Numbers(1) << endl;

	cout << add2Numbers((float)1.2,(float) 0.9) << endl;

	cout << "3! = " << u32Factorial(3) << endl;
	//_________________________________
	// FILES HANDLING
	//===============

	// files can either be text files (using ASCII characters) or binary (using bytes)

	string strQuote = "One apple a day, keeps the doctor away!\n";

	// creating an output file stream
	ofstream outputStream("quote.txt");
	// text file, in the same directory, to use a different directory use paths

	if(!outputStream)	// failure to create/open file stream
	{
		cout << "Error opening file\n" << endl;
		return -1;	// to indicate a problem
	}
	else		// success opening/creating file stream
	{
		// writing to the file
		outputStream << strQuote << endl;
		// this way writes the file, removes whatever might be there

		// streams must always be closed at the end of their usage
		outputStream.close();
	}

	// open file stream for appending
	ofstream outputStreamAppending("quote.txt", ios::app);	// app is short for appending

	/* options can be:
	 * ios::app:		to append
	 * ios::trunc:		default
	 * ios::out:		open file for output
	 * ios::in:			open file for input
	 * ios::binary:	open file as binary */

	// always check the file stream had no error
	if(!outputStreamAppending)
	{
		cout << "Error opening file\n" << endl;
		return -1;
	}
	else
	{
		outputStreamAppending << strUserName << endl;

		outputStreamAppending.close();
	}

	// opening files for input
	ifstream inputStream("quote.txt");

	// check if stream is opened
	if(!inputStream)
	{
		cout << "Error opening file\n" << endl;
		return -1;
	}
	else
	{
		// a file could be read 1 character after the next, which means a loop
		for (int u32Index = 0; !inputStream.eof(); u32Index++)	// eof: end of file
		{
			inputStream.get(s8Grade);
			// get(char <character_variable>): returns the next character in the stream

			cout << s8Grade;
		}

		cout << endl;

		// remember to close the stream
		inputStream.close();
	}
	//________________
	// EXCEPTION HANDLING
	//====================

	// exception is  a runtime error, that must be accounted for and handled to avoid crashing of programme
	int s32Zero = 0.0;

	// division by zero exception handling
	try
	{
		if (s32Zero != 0)
		{
			cout << (2 / s32Zero) << endl;
		}
		else
		{
			// exception can happen or can be created; using throw statement
			throw(s32Zero);	// throws the integer number
		}

	}
	catch (int s32Number)	// handling the error by catching what was thrown
	{
		cout << s32Number << " is not valid for division" << endl;
	}
	//_____________________________________________
	// POINTERS
	//==========

	// pointers hold addresses, and have fixed size regardless of the address they hold

	// reference operator: &<variable>, to obtain the address of the <variable>
	// dereference operator: *<address>, to obtain the value at the specified <address>
	cout << "User name is located at " << &strUserName << endl;
	// prints the memory address of strUserName

	/* pointers are used to convoy the actual reference, to be able to affect the actual variable
	 * instead of sending the value of such variable */

	// pointer declaration: <data_type>* <pointer_identifier>;
	unsigned int * ptrU32MyAge = &u32MyAge;

	cout << "My age is stored at location " << ptrU32MyAge << endl
			<< "My age value is " << *ptrU32MyAge << endl;
	// *<pointer> is called dereference to access the data at the location

	// arrays identifiers are actually constant pointers to sequenced data
	unsigned int * ptrU32PowerOfTwo = u32PowersOfTwo;
	// since u32Primes is an array identifier, there is no need to dereference it
	// pointers, unless declared const, can be incremented to point at different locations in memory
	for (int s32Index = 0; s32Index <= 12; s32Index++)
	{
		cout << "Address: " << ptrU32PowerOfTwo << "\tValue: " << *ptrU32PowerOfTwo << endl;
		ptrU32PowerOfTwo++; // each time pointer is incremented it points at a new location
	}

	cout << endl;

	// pointers can be referenced as arrays
	ptrU32PowerOfTwo -= 13;

	cout << "Address: " << ptrU32PowerOfTwo << "\tValue: " << ptrU32PowerOfTwo[0] << endl;

	// arrays also can be referenced as pointers

	cout << "Address: " << (u32PowersOfTwo + 2 )<< "\tValue: " << *(u32PowersOfTwo + 2) << endl;
	/* careful on using dereferencing, *(<address> + <offset>) is different from (*<address> + <offset>)
	 * the earlier gets the location after offset then prints the value in that location,
	 * the latter gets the location, then increments the value at that location */

	vDecrementMe(&u32MyAge);

	cout << "I am " << u32MyAge << " years old!" << endl;
	//_________________________________________
	// REFERENCES
	//=============

	// it is used to hold the same reference of some variable, no need for dereference or whatsoever
	// references must always be initialised, unlike pointers
	unsigned int & refU32MyAge = u32MyAge;

	++refU32MyAge;

	cout << "Today I am " << u32MyAge << " years old!\n";

	vResetMe(refU32MyAge);

	cout << "Age : " << u32MyAge << endl;

	refU32MyAge = u32RandomNumber;
	//___________________________________________________
	// OBJECT ORIENTED PROGRAMMING: OOP
	Animal fred;	// empty constructor

	fred.setHeight(33);
	fred.setWeight(10);
	fred.setName("Fred");

	fred.toString();

	Animal tom(36, 15, "Tom");	// non-empty constructor

	tom.toString();

	Dog spot(38, 16, "Spot", "Woof");

	// use scope operator '::' to access static methods & properties
	cout << "Number of animals is " << Animal::getS32NumberOfAnimals() << endl;

	cout << spot.getSound() << endl;

	spot.toString();

	// to call a superclass method from a subclass use scope operator '::'
	spot.Animal::toString();

	Animal * ptrAnimal = new Animal();
	Dog * ptrDog = new Dog();

	ptrAnimal -> makeSound();
	ptrDog -> makeSound();

	ptrAnimal = &spot;

	GermanShepard max;

	Animal * ptrGShepard = &max;

	ptrDog -> makeSound();

	ptrDog -> getFamily();

	ptrGShepard -> getFamily();

	ptrGShepard -> makeSound();

	Animal * ptrCat = new Cat;

	ptrCat -> makeSound();

	Car * stationWagon = new StationWagon();

	stationWagon -> getNumWheels();

	// return statement; required on using anything other than void for function declaration
	return 0;
}

// definition
float
add2Numbers(float fltOperand0,
		float fltOperand1)
{
	return (fltOperand0 + fltOperand1);
}

unsigned int
u32Factorial(unsigned int u32Number)
{
	if (u32Number == 2)
	{
		return u32Number;
	}
	else
	{
		return (u32Number * u32Factorial(u32Number - 1));
	}
}

// method definitions

void
Animal::setAll(int height,
		int weight,
		string name) {
	this->s32Height = height;
	this->s32Weight = weight;
	this->strName = name;

	Animal::s32NumberOfAnimals++;

}

Animal::Animal(int s32Height,
		int s32Weight,
		string strName) {
	this->s32Height = s32Height;
	this->s32Weight = s32Weight;
	this->strName = strName;

	Animal::s32NumberOfAnimals++;
}

Animal::~Animal() {
	cout << "Animal " << this -> strName << " destroyed\n" << endl;
}

Animal::Animal() {
	Animal::s32NumberOfAnimals++;
}

void
Animal::toString(void) {
	cout << this -> strName << " is " << this -> s32Height
			<< " cms tall and " << this -> s32Weight
			<< " kgs in weight" << endl;
}

Dog::Dog(int s32Height,
		int s32Weight,
		string strName,
		string strBark) : Animal(s32Height, s32Weight, strName)	// calling the superclass constructor
{
	this -> strSound = strBark;
}

void
Dog::toString(void)
{
	/* since the properties in the superclass were private;
	 * getters & setters are used */
	cout << this -> getName() << " is " << this -> getHeight()
			<< " cms tall & " << this -> getWeight()
			<< " kgs in weight & says " << getSound() << endl;
}

void
vWhatClassAreYou(Animal * animal)
{
	animal -> makeSound();
	/* if this method is not virtual, each time animal's
	 * implementation of the method will be called whether
	 * the argument is an animal object or an object of a
	 * subclass of animal */
}



