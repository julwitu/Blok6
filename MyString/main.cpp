#include <iostream>
#include "MyString.hpp"

int main() {

	MyString empty;
	empty.print();

	MyString alaMaKota((char*)"Ala ma kota");
	alaMaKota.print();

	MyString alaMaKotaAKotMa = alaMaKota.append((char*)", a kot ma");
	alaMaKotaAKotMa.print();

	char arr[] = { 'A', 'l', 'e', '\0' };
	MyString ale(arr);
	ale.print();
	MyString full = alaMaKotaAKotMa.append(ale);
	full.print();

}