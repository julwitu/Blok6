#include "University.hpp"
 int University::costsOfEmployees = 0;

Employee::Employee(TypeOfEmployment _typeOfEmpl) : typeOfEmpl(_typeOfEmpl)
{
}

double Employee::getCostOfEmployee()
{
	if (TypeOfEmployment::B2B) {
		monthlyPay*
	}
	else if (TypeOfEmployment::UoP) {

	}
	else {

	}
}

Professor::Professor(TypeOfEmployment _typeOfEmpl) : Employee(_typeOfEmpl)
{
}

bool Professor::isTeachingStaff()
{
	return true;
}

void Professor::setPayment()
{
	if (typeOfEmpl == TypeOfEmployment::B2B) {
		monthlyPay = 60 * 40 * 4;
	}
	else if (typeOfEmpl == TypeOfEmployment::UoP) {
		monthlyPay = 8700.0;
	}
}

Lecturer::Lecturer(TypeOfEmployment _typeOfEmpl) : Employee(_typeOfEmpl)
{
}

bool Lecturer::isTeachingStaff()
{
	return true;
}

void Lecturer::setPayment()
{
	if (typeOfEmpl == TypeOfEmployment::UoP) {
		monthlyPay = 6000.0;
	}
}

Assistant::Assistant(TypeOfEmployment _typeOfEmpl) : Employee(_typeOfEmpl)
{
}

bool Assistant::isTeachingStaff()
{
	return true;
}

Keeper::Keeper(TypeOfEmployment _typeOfEmpl) : Employee(_typeOfEmpl)
{
}

bool Keeper::isTeachingStaff()
{
	return false;
}

Guard::Guard(TypeOfEmployment _typeOfEmpl) : Employee(_typeOfEmpl)
{
}

bool Guard::isTeachingStaff()
{
	return false;
}
