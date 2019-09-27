#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include "vlist.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count=0, vector size is 9.
//Description: Constructs an instance of a vlist object. 
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist() 
{
	cout << "Default Constructor Invoked" << endl;
	int count = 9; //initial capacity
	DB.reserve(count); //setting the initial capacity of DB to 9
		
}
//////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object. 
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist & Org) 
{
	*this = Org;
	cout << "Copy Constructor Invoked" << endl;
}
///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object. 
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::~vlist() 
{
	while (!DB.empty())
	{
		DB.pop_back();
	}
	cout << "Destructor Invoked" << endl;
}

bool vlist::Is_Empty() { return DB.empty(); }

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Search
//Precondition: A vlist object has been declared and the key has been initialized to a proper value.
//Postcondition : The location of the key has been determined.
//Description: The location of the key is returned, otherwise a message is printed to the screen
//stating that it could not be found.
///////////////////////////////////////////////////////////////////////////////////////////////
vector<string>::iterator vlist::Search(const string & key)
{
	bool found = false;
	vector<string>::iterator v = DB.begin();
	while (v < DB.end() || found == false)
	{
		if (*v == key)
		{
			found = true;
			cout << "Item found: " << key << endl;
			break;
		}
		v++;
	}
	if (found == true)
	{
		return v;
	}
} 

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Insert
//Precondition: A vlist object has been declared and key has been initialized to a proper value.
//Postcondition : Key has been inserted in the array.
//Description: A new string has been added to the array.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::Insert(const string & key)
{
	if (Is_Empty())//adding key to an empty array
	{
		DB.push_back(key);
	}
	else
	{
		vector<string>::iterator v;
		v = upper_bound(DB.begin(), DB.end(), key);
		DB.insert(v, 1, key);
	}
	return;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Remove
//Precondition: A vlist object has been declared and key has been initialized to a proper value.
//Postcondition: The passed key is removed from the array.
//Description : Removes key from the vector if it is there.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::Remove(const string & key) 
{
	if (!Is_Empty())
	{
		vector<string>::iterator v; //iterator to point at key
		v = Search(key);//searching for key
		DB.erase(v);//erasing the content at which it points
	}
	else
	{
		cout << "Item not found: " << key << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Print
//Precondition:  The content of the array has not been displayed
//Postcondition: The content of the array has been displayed.
//Description: Displays the content of the array on the screen.
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::Print() 
{
	if (!Is_Empty())
	{
		vector<string>::const_iterator v;
		for (v = DB.begin(); v != DB.end(); v++)
		{
			cout << *v << endl;
		}
	}
	else { cout << "The array is empty!" << endl; }
}
