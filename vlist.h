#pragma once
//******************************************************************************
// Name:  Daniel Caballero      Z#: z23439643
// Instructor: Dr. Bullard      Class: Data Structures
// Term: Summer 2018
// Assignment #7: vlist
// Due Date: Julty 14, 2018     Due Time: 11:00PM
// Points: 100 
// Description: This program accesses your C++ language skills.
// After completing this assignment you will be able to perform the following:
// (1) Manage a vector(allocate and de-allocate memory, insert inorder, remove, etc).
// (2) Implement a default constructor and a copy constructor.
// (3) Implement an insert function to add a string, in order, into a vector
// (4) Implement a remove function to delete a string from a vector 
//******************************************************************************

#include<string>
#include<vector>

using namespace std;

#ifndef vlist_H
#define vlist_H

class vlist
{
public:
	vlist();                //default constructor
	vlist(const vlist  &);  //copy constructor
	~vlist();               //destructor
	bool Is_Empty();         //returns true if empty; else false
	vector<string>::iterator Search(const string &); //returns the location of the string in the dynamic array
	void Insert(const string & key); //adds a key to dynamic array 
	void Remove(const string & key); //removes the passedkey from the vector if it is there
	void Print(); //Print every string in the vector

private:
	vector<string> DB;  //vector
};
#endif