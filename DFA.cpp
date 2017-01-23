#include "DFA.h"
#include <string>
#include "Transition.h"
using namespace std;

DFA::DFA(list<string> q, list<char> sigma, list<Transition> delta, string q0, list<string> finalstate)
{
	// setting the main data
	Q0 = q0;
	Q = list<string>(q);
	Sigma = list<char>(sigma);
	Delta = list<Transition>(delta);
	FinalState = list<string>(finalstate);
}

DFA::~DFA()
{
	// clearing all the variables after finishing with each one of them
	// memory managment
	Q0.clear();
	Q.clear();
	Sigma.clear();
	Delta.clear();
	FinalState.clear();
}

void DFA::Accepts(string input)
{
	string currentState = Q0; // setting at the begging the start state
	string steps = ""; // contain all the steps taken so far
	// the first loop go through the input string
	for (int i = 0, inputSize = input.length(); i < inputSize; i++)
	{
		// get the letter
		char letter = input.at(i);
		bool found = false; // use to know if we found a transition or not duing the for loop
		// search all transitions for a one that have the same start state and same letter
		for (list<Transition>::iterator it = Delta.begin(); it != Delta.end(); it++)
		{
			if (it->getStartState() == currentState && it->getToken() == letter)
			{
				found = true;
				currentState = it->getEndState();
				steps += it->toString();
				break;
			}
		}
		if (!found)
		{
			// if there was no transition at all print the following instead
			if (steps.length() == 0)
			{
				steps = "This was the first transition and it failed\n";
			}
			// print that the input is wrong regarding this states
			// then print the steps taken so far if there was any
			cout << steps << "No transitions for current state and letter" << endl;
			return; // in order to exist the program
		}
	}
	// now check and see if the current state is one of the final states
	bool correct = false;
	for (list<string>::iterator it = FinalState.begin(); it != FinalState.end(); it++)
	{
		if (currentState == *it)
		{
			correct = true;
			break;
		}
	}
	if (correct) 
	{
		cout << "CORRECT" << endl << steps;
	}
	else
	{
		cout << "FAILED" << endl << steps;
	}
}
