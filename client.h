// EOOP Premilinary project
// Maria Filocha 310884

#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "trip.h"
#include "agency.h"
using namespace std;

class TravelAgency;
class Trip;

class Client
{
    private:

    char *name;
    char *surname;
    struct Trip_part
    {
        Trip *trip;
        Trip_part *next;
    };
    Trip_part *head_trip = nullptr;

    public:
    Client(char* name, char* surname);
    ~Client();

    void buy_trip(TravelAgency *agency, Trip *trip);
    void cancel_trip(TravelAgency *agency, Trip *trip);
    void print_trips();
    const char* returnName() const;
    const char* returnSurname() const;
};

#endif  //CLIENT_H_INCLUDED