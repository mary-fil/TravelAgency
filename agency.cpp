// EOOP Premilinary project
// Maria Filocha 310884

#include "agency.h"
#include "string.h"
#include "iostream"
using namespace std;

TravelAgency::TravelAgency(char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->number_of_employees = 0;
}

TravelAgency::~TravelAgency()
{
    TravelAgency::Employee_part *current_node = TravelAgency::head_employee;

    while(current_node)
    {
        current_node = current_node->next;
        TravelAgency::head_employee->employee->setEmployer(nullptr);
        delete TravelAgency::head_employee;
        TravelAgency::head_employee = current_node;
    }
    this->head_employee = nullptr;

    TravelAgency::Trip_part *current_node2 = TravelAgency::head_trip;

    while(current_node2)
    {
        this->delete_trip(&(current_node2->trip));
        current_node2 = current_node2->next;

        TravelAgency::head_trip = current_node2;
    }

    this->head_trip = nullptr;

    delete[] this->name;
}

void TravelAgency::hire_employee(Employee *employee)
{
    if(this->number_of_employees == MAX_NUM_OF_EMPLOYEES)
    {
        cout << "This agency cannot employ more employees. Maximal number of employees is reached."<<endl;
        return;
    }

    if(employee->returnEmployer() != nullptr)
    {
        cout << "This employee is already employeed, agency cannot employ him." << endl;
        return;
    }
    
    employee->setEmployer(this);
    this->number_of_employees++;

    TravelAgency::Employee_part *new_employee = new TravelAgency::Employee_part;

    new_employee->employee = employee;
    new_employee->next = TravelAgency::head_employee;

    TravelAgency::head_employee = new_employee;
}

void TravelAgency::fire_employee(Employee *employee)
{
    if(TravelAgency::head_employee == nullptr)
    {
        cout << "This agency does not have any employees. It cannot fire anyone." << endl;
        return;
    }

    TravelAgency::Employee_part *current_node = TravelAgency::head_employee;
    TravelAgency::Employee_part *previous_node = nullptr;

    int is_in_Agency = 0;

    while(current_node != nullptr)
    {
        if(current_node->employee->returnName() == employee->returnName() && current_node->employee->returnSurname() == employee->returnSurname())
        {
            is_in_Agency++;
            if(previous_node != nullptr)
            {
                previous_node->next = current_node->next;
            }
            else
            {
                TravelAgency::head_employee = current_node->next;
            }

            delete current_node;

            employee->setEmployer(nullptr);

            if(this->number_of_employees > 0)
            {
                this->number_of_employees--;
                break;
            }

        }

        previous_node = current_node;
        current_node = current_node->next;
    }

    if(this->number_of_employees == 0)
    {
         cout << "After this action agency does not have any employees. It won't operate again until hiring new employee." << endl;
    }

    if(is_in_Agency == 0)
    {
        cout << "This employee is not employeed in this agency. He cannot be fired.";
    }
}

void TravelAgency::print_employees()
{
    if(this->number_of_employees == 0)
    {
        cout << "This agency does not have any employees."<<endl;
        return;
    }

    TravelAgency::Employee_part *current_node = TravelAgency::head_employee;

    int i = 1;
    cout << "List of employees of " << this->returnName() << ":"  << endl;
    while(current_node != nullptr)
    {
        cout << "employee nr " << i << ". : " << current_node->employee->returnName() << " " << current_node->employee->returnSurname() << endl;
        current_node = current_node->next;
        i++;
    }

    cout << endl;
}

Trip* TravelAgency::create_trip(char *country)
{
    if(this->number_of_employees > 0)
    {
        Trip *trip = new Trip(this, country);

        TravelAgency::Trip_part *new_trip = new TravelAgency::Trip_part;

        new_trip->trip = trip;
        new_trip->next = TravelAgency::head_trip;

        TravelAgency::head_trip = new_trip;

        return trip;
    }
    else
    {
        cout << "Agency cannot create a trip if it does not have any employees." << endl;
        return nullptr;
    }
    
}

void TravelAgency::delete_trip(Trip **trip)
{   
    if(this->is_trip_in_agency(*trip) == false)
    {
        cout << "This trip is not in this agency." << endl;
        return;
    }
    if(TravelAgency::head_trip == nullptr)
    {
        cout << "This agency does not have any trips." << endl;
        return;
    }

    TravelAgency::Trip_part *current_node = TravelAgency::head_trip;
    TravelAgency::Trip_part *previous_node = nullptr;

    while(current_node != nullptr)
    {
        if(current_node->trip->returnCountry() == (*trip)->returnCountry())
        {
            
            if(previous_node != nullptr)
            {
                previous_node->next = current_node->next;
            }
            else
            {
                TravelAgency::head_trip = current_node->next;
            }

            delete *trip;
            delete current_node;
            break;
        }

        previous_node = current_node;
        current_node = current_node->next;
    }

}

void TravelAgency::print_trips()
{
    TravelAgency::Trip_part *current_node = TravelAgency::head_trip;
    
    if(current_node == nullptr)
    {
        cout << "This agency does not have any trips."<<endl;
        return;
    }

    int i = 1;
    cout << "List of trips offered by " << this->returnName() << ":"  << endl;
    while(current_node != nullptr)
    {
        cout << i << ". " << current_node->trip->returnCountry() << endl;
        current_node = current_node->next;
        i++;
    }

    cout << endl;
}

bool TravelAgency::is_trip_in_agency(Trip *trip)
{
    TravelAgency::Trip_part *current_node = TravelAgency::head_trip;

    while(current_node != nullptr)
    {
        if(current_node->trip->returnCountry() == trip->returnCountry())
        {
            return true;
        }

        current_node = current_node->next;
    }

    return false;
}

const char* TravelAgency::returnName() const
{
    return this->name;
}

const int TravelAgency::returnNumberOfEmployees() const
{
    return this->number_of_employees;
}