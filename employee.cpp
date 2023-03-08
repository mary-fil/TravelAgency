// EOOP Premilinary project
// Maria Filocha 310884

#include "employee.h"
#include "string.h"
#include "iostream"
using namespace std;

Employee::Employee(char *name, char *surname)
{
    this->name = new char[strlen(name) + 1];
    this->surname = new char[strlen(surname) + 1];

    strcpy(this->name, name);
    strcpy(this->surname, surname);
}

Employee::~Employee()
{
    this->leave(this->returnEmployer());
    delete[] this->name;
    delete[] this->surname;
}

void Employee::setEmployer(TravelAgency *agency)
{
    this->agency = agency;
}

TravelAgency* Employee::returnEmployer()
{
    return this->agency;
}

const char* Employee::returnName() const
{
    return this->name;
}

const char* Employee::returnSurname() const
{
    return this->surname;
}

void Employee::leave(TravelAgency *agency)
{
    agency->fire_employee(this);
}