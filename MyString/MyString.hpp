#pragma once
#include <string> //  nie korzystajmy ze stringow
#include <iostream>

class MyString {
	char* arr;

public:
	MyString();
	MyString(char* input);
	MyString(const MyString& other);
	void print();
	MyString append(char* input);
	void appendToSame(char* input);
	MyString append(MyString input);
	void appendToSame(MyString input);
	MyString firstWord();
	virtual ~MyString();

}; 
