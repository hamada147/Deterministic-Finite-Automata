#include "Transition.h"
#include <string>
#include <iostream>
using namespace std;
// constractor
Transition::Transition(string startState, char token, string endState)
{
	// setting the data
	StartState = startState;
	Token = token;
	EndState = endState;
}
// destructor
Transition::~Transition()
{
	// clearing all the variables after finishing with each one of them
	// memory managment
	StartState.clear();
	Token = (char)0;
	EndState.clear();
}
// the get functions
string Transition::getStartState() const
{
	return StartState;
}

string Transition::getEndState() const
{
	return EndState;
}

char Transition::getToken() const
{
	return Token;
}
string Transition::toString()
{
	return "({" + StartState + "}, {" + Token + "}) => {" + EndState + "}\n";
}
// the set functions
void Transition::setStartState(string newStartState)
{
	StartState = newStartState;
}

void Transition::setEndState(string newEndState)
{
	EndState = newEndState;
}

void Transition::setToken(char newToken)
{
	Token = newToken;
}
// the overloading cout operator 
ostream & operator<<(ostream & strm, const Transition & obj)
{
	strm << "({" + obj.StartState + "}, {" + obj.Token + "}) => {" + obj.EndState + "}";
	return strm;
}