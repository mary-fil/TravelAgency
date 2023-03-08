// EOOP Premilinary project
// Maria Filocha 310884

#ifndef TRIP_H_INCLUDED
#define TRIP_H_INCLUDED

#include "client.h"
#include "agency.h"
using namespace std;

class TravelAgency;
class Client;

class Trip
{
    private:

    char *country;
    TravelAgency *agency;
    struct Participants_part
    {
        Client *patricipant;
        Participants_part *next;
    };
    Participants_part *head_participant = nullptr;

    public:
    Trip(TravelAgency *agency, char *country);
    ~Trip();

    void addParticipant(Client *participant);
    void removeParticipant(Client *participant);
    void setAgency(TravelAgency *agency);
    TravelAgency *returnAgency();   
    const char* returnCountry() const;
    void printParticipants();
};

#endif  //TRIP_H_INCLUDED