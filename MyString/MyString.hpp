#pragma once
#include <string> //  nie korzystajmy ze stringow
#include <iostream>

class MyString {
	char* arr;
	//int length;
public:
	MyString();
	MyString(char* input);
	void print();
	MyString append(char* input);
	void appendToSame(char* input);
	MyString append(MyString input);
	void appendToSame(MyString input);
	MyString firstWord();
	~MyString();

}; 
