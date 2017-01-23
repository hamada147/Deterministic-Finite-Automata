#ifndef TRANSITION_H
#define TRANSITION_H
#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
 * Transition class
 * this class is only here to describe the each transition in the DFA
 * each transtion has its start state, its end state and its token aka(letter)
 *
 */

class Transition {
	public:
		// constractor
		/**
		 * @string StartState: the start state of this transition
		 * @char Token: the letter that is being taken from state to another
		 * @string EndState: the end state of this transition
		 *
		 */
		Transition(string startState, char token, string endState);
		// destructor
		~Transition();
		// all get functions have the const value for protection
		// so no one would be able to change the value
		string getStartState() const;
		string getEndState() const;
		char getToken() const;
		// the same as toString function
		string toString();
		// overloading the cout << operator to work as toString() function
		// and since it has been identified as a friend it will have access
		// to private members
		friend ostream &operator << (ostream &strm, const Transition &obj);
	private:
		// setting the main variables as private so no one would have access to them
		// except from the get functions
		string StartState; // the start state of this transition
		char Token; // the letter that is being taken from state to another
		string EndState; // the end state of this transition
		// the set function are also private because we don't want to change any of them
		// except inside the class functions
		void setStartState(string);
		void setEndState(string);
		void setToken(char);
};
#endif // !TRANSITION_H