// EOOP Premilinary project
// Maria Filocha 310884

#include "trip.h"
#include "string.h"
#include "iostream"
using namespace std;

Trip::Trip(TravelAgency *agency, char *country)
{
    this->country = new char[strlen(country) + 1];
    strcpy(this->country, country);
    this->setAgency(agency);
}

void Trip::setAgency(TravelAgency *agency)
{
    this->agency = agency;
}

const char* Trip::returnCountry() const
{
    return this->country;
}

TravelAgency* Trip::returnAgency()
{
    return this->agency;
}

void Trip::addParticipant(Client *participant)
{
    Trip::Participants_part *new_participant = new Trip::Participants_part;

    new_participant->patricipant = participant;
    new_participant->next = Trip::head_participant;

    Trip::head_participant = new_participant;
}

void Trip::removeParticipant(Client *participant)
{
    if(Trip::head_participant == nullptr)
    {
        cout << "This trip does not have any participants. It cannot remove anyone." << endl;
        return;
    }

    Trip::Participants_part *current_node = Trip::head_participant;
    Trip::Participants_part *previous_node = nullptr;

    while(current_node != nullptr)
    {
        if(current_node->patricipant->returnName() == participant->returnName() && current_node->patricipant->returnSurname() == participant->returnSurname())
        {
            if(previous_node != nullptr)
            {
                previous_node->next = current_node->next;
            }
            else
            {
                Trip::head_participant = current_node->next;
            }

            delete current_node;
            break;
            
        }

        previous_node = current_node;
        current_node = current_node->next;
    }
}

void Trip::printParticipants()
{
    Trip::Participants_part *current_node = Trip::head_participant;
    
    if(current_node == nullptr)
    {
        cout << "Trip to " << this->returnCountry() << " does not have any participants."<<endl;
        return;
    }

    int i = 1;
    cout << "List of participants of trip to " << this->returnCountry() << ": "<< endl;
    while(current_node != nullptr)
    {
        cout << i << ". " << current_node->patricipant->returnName() << " " << current_node->patricipant->returnSurname() << endl;
        current_node = current_node->next;
    }

    cout << endl;
}

Trip::~Trip()
{
    Trip::Participants_part *current_node = Trip::head_participant;

    while(current_node)
    {
        current_node = current_node->next;
        Trip::head_participant->patricipant->cancel_trip(this->returnAgency(), this);
        delete Trip::head_participant;
        Trip::head_participant = current_node;
    }
    this->head_participant = nullptr;

    //  Trip *a = this;
    // //  cout << this << endl;
    // //  cout << a << endl;
    // //  cout << &a << endl;
    // this->returnAgency()->delete_trip(&a);
    delete[] this->country;
}