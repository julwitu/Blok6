#include "MyString.hpp"

MyString::MyString()
{
	this->arr = new char[1];
	this->arr[0] = '\0';
}

MyString::MyString(char* input)
{
	int length = std::strlen(input);
	this->arr = new char[length + 1];
	for (int i = 0; i < length; i++) {
		arr[i] = input[i];
	}
	arr[length] = '\0';
	//skopiowac input -> arr, na koncu dopisac 0
//memcpy, strcpy - z ANSI C; albo petla for
//praca do wykonania ....

}

MyString::MyString(const MyString& other)
{
	this->arr = new char[std::strlen(other.arr)];
	for (int i = 0; i < std::strlen(other.arr); i++) {
		this->arr[i] = other.arr[i];
	}
	this->arr[std::strlen(other.arr)] = '\0';
}

void MyString::print()
{
	std::cout << arr;
	// alternatywna wersja 
	// for (int i = 0; i < strlen(arr); i++){
	// std::cout << arr[i] << " " ;
	std::cout << std::endl;
}

MyString MyString::append(char* input)
{
	//oblicz length z inputu
	// stworz nowa tablice dlugosci arr lengt+input length
	// przekopiuj wartosci najpierw od arr do dlugosci arr a pozniej druga petla od dlugosci arr do input length od inputu
	int length1 = std::strlen(arr);
	int length2 = std::strlen(input);
	int length3 = length1 + length2;
	char* newArr = new char[length3 + 1];
	for (int i = 0; i < length1; i++) {
		newArr[i] = arr[i];
	}
	for (int i = 0; i < length2; i++) {
		newArr[i + length1] = input[i];
	}
	newArr[length3] = '\0';
	// MyString x(newArr)
	// return x
	return MyString(newArr);
}

MyString MyString::append(MyString input)
{
	MyString result = this->append(input.arr); // wywoluje metode append (z lini wyzej) na obiekcie
	//	MyString full = alaMaKotaAKotMa.append(ale); <- wklejone pogladowo z main. Nie moze znalezc sie w tym miejscu w kodzie!
	return result;
}

MyString MyString::firstWord()
{
	int length = 0;
	for (int i = 0; i < std::strlen(arr); i++) {
		if (arr[i] == ' ') {
			length = i;
			break;
		}
	}
	char* newArr = new char[length];
	for (int i = 0; i < length; i++) {
		newArr[i] = arr[i];
		std::cout << newArr[i]; 
	}	
	std::cout << std::endl;

	return MyString(newArr);
}

MyString::~MyString()
{
	delete[] arr;
	arr = nullptr;

}
