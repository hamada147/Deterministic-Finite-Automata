#include <string>
#include <iostream>
#include "Transition.h"
#include "DFA.h"
using namespace std;

/*
	// for Q1
	// COPY THAT
	string Q0 = "q0"; // start state
	string q[] = { "q0", "q1", "q2", "q3", "q4", "q5" }; // the exisiting state
	char s[] = { 'a', 'b', 'c' }; // the existing letters
	Transition t[] =
	{
	Transition("q0", 'a', "q1"),
	Transition("q0", 'b', "q2"),
	Transition("q0", 'c', "q4"),
	Transition("q1", 'a', "q1"),
	Transition("q1", 'b', "q5"),
	Transition("q1", 'c', "q3"),
	Transition("q2", 'a', "q5"),
	Transition("q2", 'b', "q2"),
	Transition("q2", 'c', "q3"),
	Transition("q3", 'a', "q5"),
	Transition("q3", 'b', "q5"),
	Transition("q3", 'c', "q5"),
	Transition("q4", 'a', "q5"),
	Transition("q4", 'b', "q5"),
	Transition("q4", 'c', "q4"),
	}; // all exisint transitions
	string f[] = { "q3", "q4" }; // the final states

	// for Q2
	// COPY THAT
	string Q0 = "q0"; // start state
	string q[] = { "q0", "q1", "q2", "q3" }; // the exisiting state
	char s[] = { 'a', 'b' }; // the existing letters
	Transition t[] =
	{
	Transition("q0", 'a', "q1"),
	Transition("q0", 'b', "q0"),
	Transition("q1", 'a', "q1"),
	Transition("q1", 'b', "q2"),
	Transition("q2", 'a', "q1"),
	Transition("q2", 'b', "q3"),
	Transition("q3", 'a', "q1"),
	Transition("q3", 'b', "q0")
	}; // all exisint transitions
	string f[] = { "q3" }; // the final states
*/

void main()
{
	// main data decleration

	// this part is to be edited in order to change from machine to another
	// PASTE HERE
	string Q0 = "q0"; // start state
	string q[] = { "q0", "q1", "q2", "q3", "q4", "q5" }; // the exisiting state
	char s[] = { 'a', 'b', 'c' }; // the existing letters
	Transition t[] =
	{
		Transition("q0", 'a', "q1"),
		Transition("q0", 'b', "q2"),
		Transition("q0", 'c', "q4"),
		Transition("q1", 'a', "q1"),
		Transition("q1", 'b', "q5"),
		Transition("q1", 'c', "q3"),
		Transition("q2", 'a', "q5"),
		Transition("q2", 'b', "q2"),
		Transition("q2", 'c', "q3"),
		Transition("q3", 'a', "q5"),
		Transition("q3", 'b', "q5"),
		Transition("q3", 'c', "q5"),
		Transition("q4", 'a', "q5"),
		Transition("q4", 'b', "q5"),
		Transition("q4", 'c', "q4"),
	}; // all exisint transitions
	string f[] = { "q3", "q4" }; // the final states

	/*this part don't change no matter what*/

	list<string> Q; // list of the states
	list<char> Sigma; // list of the letters
	list<Transition> Delta; // list of all avilable transitions
	list<string> FinalState; // list of all final states

	list<string>::iterator it1 = Q.begin(); // an iterator to save the states from the array to the list
	for (int i = 0, arraySize = sizeof(q)/sizeof(q[0]); i < arraySize; i++)
	{
		Q.insert(it1, q[i]); // inserting it into the list
	}

	list<char>::iterator it2 = Sigma.begin(); // an iterator to save the letters from the array to the list
	for (int i = 0, arraySize = sizeof(s) / sizeof(s[0]); i < arraySize; i++)
	{
		Sigma.insert(it2, s[i]); // inserting it into the list
	}

	list<Transition>::iterator it3 = Delta.begin(); // an iterator to save the letters from the array to the list
	for (int i = 0, arraySize = sizeof(t) / sizeof(t[0]); i < arraySize; i++)
	{
		Delta.insert(it3, t[i]); // inserting it into the list
	}
	
	list<string>::iterator it4 = FinalState.begin();
	for (int i = 0, arraySize = sizeof(f) / sizeof(f[0]); i < arraySize; i++)
	{
		FinalState.insert(it4, f[i]); // inserting it into the list
	}

	// TEST #1 on the whole system
	DFA x = DFA(Q, Sigma, Delta, Q0, FinalState);
	// test cases
	x.Accepts("aaaabc");
	system("PAUSE");
}