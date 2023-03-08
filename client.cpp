// EOOP Premilinary project
// Maria Filocha 310884

#include "client.h"
#include "string.h"
#include "iostream"
using namespace std;

Client::Client(char* name, char* surname)
{
    this->name = new char[strlen(name) + 1];
    this->surname = new char[strlen(surname) + 1];

    strcpy(this->name, name);
    strcpy(this->surname, surname);
}

Client::~Client()
{
    Client::Trip_part *current_node = Client::head_trip;

    while(current_node)
    {
        current_node = current_node->next;
        Client::head_trip->trip->removeParticipant(this);
        delete Client::head_trip;
        Client::head_trip = current_node;
    }
    this->head_trip = nullptr;

    delete[] this->name;
    delete[] this->surname;
}

void Client::buy_trip(TravelAgency *agency, Trip *trip)
{   
    if(agency->returnNumberOfEmployees() == 0)
    {
        cout << "This agency doesn't have any employees. You can only cancel your trips. Purchase disabled." << endl;
        return;
    }
    if(agency->is_trip_in_agency(trip))
    {
        Client::Trip_part *new_trip = new Client::Trip_part;

        new_trip->trip = trip;
        new_trip->next = Client::head_trip;

        Client::head_trip = new_trip;

        trip->addParticipant(this);
    }
    else
    {
        cout << "This agency does not offer this trip. Purchase disabled." << endl;
    }

}

void Client::cancel_trip(TravelAgency *agency, Trip *trip)
{
    if(Client::head_trip == nullptr)
    {
        cout << "This client does not have any trips purchased. He cannot cancel anything." << endl;
        return;
    }

    Client::Trip_part *current_node = Client::head_trip;
    Client::Trip_part *previous_node = nullptr;

    while(current_node != nullptr)
    {
        if(current_node->trip->returnAgency() == trip->returnAgency() && current_node->trip->returnCountry() == trip->returnCountry())
        {
            if(previous_node != nullptr)
            {
                previous_node->next = current_node->next;
            }
            else
            {
                Client::head_trip = current_node->next;
            }

            trip->removeParticipant(this);

            delete current_node;
            break;
            
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

void Client::print_trips()
{
    Client::Trip_part *current_node = Client::head_trip;
    
    if(current_node == nullptr)
    {
        cout << "This client does not have any trips purchased."<<endl;
        return;
    }

    int i = 1;
    cout << "List of purchased trips by: " << this->returnName() << " " << returnSurname() << endl;
    while(current_node != nullptr)
    {
        cout << i << ". " << current_node->trip->returnCountry() << endl;
        current_node = current_node->next;
    }

    cout << endl;
}

const char* Client::returnName() const
{
    return this->name;
}

const char* Client::returnSurname() const
{
    return this->surname;
}