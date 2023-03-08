// EOOP Premilinary project
// Maria Filocha 310884

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "agency.h"
using namespace std;

class TravelAgency;

class Employee
{
    private:

    char *name;
    char *surname;
    TravelAgency *agency = nullptr;

    public:
    Employee(char *name, char *surname);
    ~Employee();

    void leave(TravelAgency *agency);
    void setEmployer(TravelAgency *agency); 
    const char* returnName() const;
    const char* returnSurname() const;
    TravelAgency* returnEmployer();
};

#endif  //EMPLOYEE_H_INCLUDED