#pragma once
//Projekt zyskow salony beauty, ktory posiada masazystke, manicurzystke i fryzjerke. Kazda z nich posiada klientki, ktore placa inna cene kazdej osobie z oblugi.
enum class Profession{HairDresser, Messeuse, Manicurist};

class BeautySalon {
protected:
	static int gains;
};

class Employee {
public:
	Employee(Profession _prof);
};

class Masseuse : public Employee {

};

class Manicurist : public Employee{

};

class Customer {

};