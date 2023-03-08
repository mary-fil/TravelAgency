//EOOP Premilinary project
// Maria Filocha 310884

#ifndef AGENCY_H_INCLUDED
#define AGENCY_H_INCLUDED

const int MAX_NUM_OF_EMPLOYEES = 3;

#include "employee.h"
#include "trip.h"
using namespace std;

class Employee;
class Trip;

class TravelAgency
{
    private:
    
    char *name;
    int number_of_employees = 0;

    struct Employee_part
    {
        Employee *employee;
        Employee_part *next;
    };
    Employee_part *head_employee = nullptr;

    struct Trip_part
    {
        Trip *trip;
        Trip_part *next;
    };
    Trip_part *head_trip = nullptr;

    public:
    TravelAgency(char *name);
    ~TravelAgency();

    void hire_employee(Employee *employee);
    void fire_employee(Employee *employee);
    Trip* create_trip(char *country);
    bool is_trip_in_agency(Trip *trip);
    void delete_trip(Trip **trip);
    void print_employees();
    void print_trips();
    const char* returnName() const;
    const int returnNumberOfEmployees() const;

};

#endif  //AGENCY_H_INCLUDED
