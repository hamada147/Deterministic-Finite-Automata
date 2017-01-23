#ifndef DFA_H
#define DFA_H
#pragma once
#include <string>
#include <list>
#include "Transition.h"
using namespace std;

/**
 * Deterministic finite automaton
 * the main class which will be called to answer whither the
 * input was accepted or not and handel all the transitions
 * 
 */

class DFA {
	public:
		// constractor
		/**
		 * @list<string> Q: is a list of all the states {Q0, Q1, Q2, Q3, ...}
		 * @list<char> Sigma: is a list of all the allowed letters in it
		 * @list<Transition> Delta: is a list of all the transitions made in it
		 * @list<string> FinalState: is a list of all the final states in it
		 * @string Q0: is the name of the start state in it
		 *
		 */
		DFA(list<string> q, list<char> sigma, list<Transition> delta, string q0, list<string> finalstate);
		// destructor
		~DFA();
		// check if the input was accepted or not
		void Accepts(string input);
	private:
		list<string> Q; // is a list of all the states {Q0, Q1, Q2, Q3, ...}
		list<char> Sigma; // is a list of all the allowed letters in it
		list<Transition> Delta; // is a list of all the transitions made in it
		list<string> FinalState; // is a list of all the final states in it
		string Q0; // is the name of the start state in it
};
#endif // !DFA_H