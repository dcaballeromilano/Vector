#include <iostream>
#include <string>
#include "vlist.h"

using namespace std;

int main() 
{

	//Testing default constructor
	cout << "Test1:Testing the default constructor for string\n\n"; 
	vlist String_List;
	cout << endl;
	//Testing functionality for string list
	cout << "Test2: Testing Insert \n\n";
	String_List.Insert("Hello");
	String_List.Insert("Zebra");
	String_List.Insert("Good_Bye");
	String_List.Insert("Space");
	String_List.Insert("No_One");
	String_List.Print();
	cout << endl;
	cout << "Test 3: Testing copy constructor for string \n\n";
	vlist Copied_String = String_List;
	cout << endl;
	Copied_String.Print();
	cout << endl;
	cout << "Test 4: Testing Remove for string \n";
	cout << "Testing Search and IsEmpty also\n\n";
	String_List.Remove("Zebra");
	String_List.Remove("Good_Bye");
	String_List.Remove("Hello");
	String_List.Remove("No_One");
	String_List.Remove("Space");
	String_List.Remove("Hello");
	cout << endl;
	cout << "When leave main destructor will be called" << endl;

	return 0;
}