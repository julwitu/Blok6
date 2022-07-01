#pragma once
enum class TypeOfEmployment{ B2B, UZ, UoP};

class University {
	static int costsOfEmployees;
};

class Employee {
protected:
	TypeOfEmployment typeOfEmpl;
	int monthlyPay;
public:
	Employee(TypeOfEmployment _typeOfEmpl);
	virtual bool isTeachingStaff() = 0;
	virtual void setPayment() = 0;
	virtual double getCostOfEmployee();
};

class Professor : public Employee {
public:
	Professor(TypeOfEmployment _typeOfEmpl);
	bool isTeachingStaff() override;
	void setPayment() override;
	double getCostOfEmployee() override;
};

class Lecturer : public Employee {
public:
	Lecturer(TypeOfEmployment _typeOfEmpl);
	bool isTeachingStaff() override;
	void setPayment() override;
	double getCostOfEmployee() override;
};

class Assistant : public Employee {
public:
	Assistant(TypeOfEmployment _typeOfEmpl);
	bool isTeachingStaff() override;
	void setPayment() override;
	double getCostOfEmployee() override;
};

class Keeper : public Employee {
public:
	Keeper(TypeOfEmployment _typeOfEmpl);
	bool isTeachingStaff() override;
	void setPayment() override;
	double getCostOfEmployee() override;
};

class Guard : public Employee {
public:
	Guard(TypeOfEmployment _typeOfEmpl);
	bool isTeachingStaff() override;
	void setPayment() override;
	double getCostOfEmployee() override;
};