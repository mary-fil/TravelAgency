// EOOP Premilinary project
// Maria Filocha 310884

#include <stdio.h> 
#include <iostream>
#include <cstring>

#include "agency.h"
#include "employee.h"
// #include "client.h"
// #include "trip.h"

using namespace std;

int main()
{
    //creating TRAVEL AGENCIES
    TravelAgency *agency1 = new TravelAgency((char*)"TravelAgency1");
    TravelAgency *agency2 = new TravelAgency((char*)"TravelAgency2");
    TravelAgency *agency3 = new TravelAgency((char*)"TravelAgency3");

    //creating EMPLOYEES
    Employee *employee1 = new Employee((char*)"EmployeeName1", (char*)"EmployeeSurname1");
    Employee *employee2 = new Employee((char*)"EmployeeName2", (char*)"EmployeeSurname2");
    Employee *employee3 = new Employee((char*)"EmployeeName3", (char*)"EmployeeSurname3");
    Employee *employee4 = new Employee((char*)"EmployeeName4", (char*)"EmployeeSurname4");
    Employee *employee5 = new Employee((char*)"EmployeeName5", (char*)"EmployeeSurname5");
    Employee *employee6 = new Employee((char*)"EmployeeName6", (char*)"EmployeeSurname6");
    Employee *employee7 = new Employee((char*)"EmployeeName7", (char*)"EmployeeSurname7");
    
    //creating CLIENTS
    Client *client1 = new Client((char*)"ClientName1", (char*)"ClientSurname1");
    Client *client2 = new Client((char*)"ClientName2", (char*)"ClientSurname2");
    Client *client3 = new Client((char*)"ClientName3", (char*)"ClientSurname3");
    Client *client4 = new Client((char*)"ClientName4", (char*)"ClientSurname4");

    //hiring EMPLOYEES
    agency1->hire_employee(employee1);
    agency1->hire_employee(employee2);

    agency2->hire_employee(employee3);
    agency2->hire_employee(employee4);
    agency2->hire_employee(employee5);

    agency3->hire_employee(employee6);
    agency3->hire_employee(employee7);

    //printing list of EMPLOYEES
    cout << endl;
    agency1->print_employees();
    agency2->print_employees();
    agency3->print_employees();

    //creating TRIPS 
    Trip *trip1 = agency1->create_trip((char*)"Country1");
    Trip *trip2 = agency1->create_trip((char*)"Country2");
    Trip *trip3 = agency1->create_trip((char*)"Country3");
    Trip *trip4 = agency2->create_trip((char*)"Country4");
    Trip *trip5 = agency2->create_trip((char*)"Country5");
    Trip *trip6 = agency2->create_trip((char*)"Country6");
    Trip *trip7 = agency3->create_trip((char*)"Country7");
    Trip *trip8 = agency3->create_trip((char*)"Country8");
    Trip *trip9 = agency3->create_trip((char*)"Country9");

    //printing list of TRIPS
    agency1->print_trips();
    agency2->print_trips();
    agency3->print_trips();

    cout << "//-------NORMAL CASES--------//" << endl << endl;

    //client buys trips
    cout << "#1. Client1 buys trip1 and trip2 from TravelAgency1." << endl;
    client1->buy_trip(agency1, trip1);
    client1->buy_trip(agency1, trip2);
    client1->print_trips();

    //deleting TRIPS
    cout << "#2. Deleting trip2 from TravelAgency1. Client 1 is informed about deleting trip he purchased." << endl << endl;
    agency1->delete_trip(&trip2);
    agency1->print_trips();
    client1->print_trips();

    //firing employees
    cout << "#3. Firing employee3 from TravelAgency2: " << endl << endl;
    agency2->fire_employee(employee3);
    agency2->print_employees();

    //employee leaves
    cout << "#4. Employee7 leaves TravelAgency3: " << endl << endl;
    employee7->leave(agency3);
    agency3->print_employees();

    //client2 buys 2 trips and cancels one
    cout << endl << "#5. Client2 buys trip5 from agency2 and trip7 from agency3: " << endl << endl;
    client2->buy_trip(agency2, trip5);
    client2->buy_trip(agency3, trip7);
    client2->print_trips();
    trip5->printParticipants();
    trip7->printParticipants();
    cout << "then cancels trip7: " << endl << endl;
    client2->cancel_trip(agency3, trip7);
    client2->print_trips();
    trip7->printParticipants();

    cout << "#6. Trip7 is bought by more than one person: " << endl << endl;
    client3->buy_trip(agency3, trip7);
    client4->buy_trip(agency3, trip7);
    trip7->printParticipants();

    cout << "//--------CORNER CASES---------//" << endl << endl;

    //objects for testing
    TravelAgency *test_agency1 = new TravelAgency((char*)"TestAgency1");
    TravelAgency *test_agency2 = new TravelAgency((char*)"TestAgency2");
    TravelAgency *test_agency3 = new TravelAgency((char*)"TestAgency3");

    Employee *test_employee1 = new Employee((char*)"TestEmployeeName1", (char*)"TestEmployeeSurname1");
    Employee *test_employee2 = new Employee((char*)"TestEmployeeName2", (char*)"TestEmployeeSurname2");
    Employee *test_employee3 = new Employee((char*)"TestEmployeeName3", (char*)"TestEmployeeSurname3");
    Employee *test_employee4 = new Employee((char*)"TestEmployeeName4", (char*)"TestEmployeeSurname4");
    Employee *test_employee5 = new Employee((char*)"TestEmployeeName5", (char*)"TestEmployeeSurname5");
    Employee *test_employee6 = new Employee((char*)"TestEmployeeName6", (char*)"TestEmployeeSurname6");

    Client *test_client = new Client((char*)"TestClientName", (char*)"TestClientSurname");

    //agency has 0 employees and tries to perform an action 
    cout << "#1. TestAgency1 has 0 employees and tries to perform an action of creating a trip: " << endl << endl;
    test_agency1->create_trip((char*)"TestCountry3");
    //text warning should pop 

    //agency tries to hire more than 3 employees
    cout << endl << "#2. TestAgency1 tries to hire more than 3 employees: " << endl << endl;
    test_agency1->hire_employee(test_employee1);
    test_agency1->hire_employee(test_employee2);
    test_agency1->hire_employee(test_employee3);
    test_agency1->hire_employee(test_employee4);
    test_agency1->print_employees();
    //text warning should pop

    //agency tries to hire an employee that is already hired in any agency
    cout << "#3. TestAgency2 tries to hire an employee that is already hired in any agency: " << endl << endl;
    test_agency2->hire_employee(test_employee1);
    //text warning should pop

    //agency tries to fire an employee that is not in this agency
    cout << endl << "#4. TestAgency2 tries to fire an employee that is not in this agency: " << endl << endl;
    test_agency2->hire_employee(test_employee5);
    test_agency2->fire_employee(test_employee1);
    //text warning should pop

    //agency tries to fire an employee when it has only 1 employee
    cout << endl << endl << "#5. TestAgency1 tries to fire an employee when it has only 1 employee: " << endl << endl;
    test_agency1->fire_employee(test_employee2);
    test_agency1->fire_employee(test_employee3);
    test_agency1->fire_employee(test_employee1);
    //text warning should pop

    //client tries to buy a trip when the agency has no employees, but it created a trip before firing everyone.
    cout << endl << "#6. TestAgency2 has an employee, it creates a test_trip1, then fires an employee so it has 0 employees. Client tries to buy test_trip1 when the agency has no employees." << endl << endl;
    Trip *test_trip1 = test_agency2->create_trip((char*)"TestCountry1");
    test_agency2->print_trips();
    test_agency2->fire_employee(test_employee5);
    test_client->buy_trip(test_agency2, test_trip1);

    //agency tries to delete a trip that is in another agency
    cout << endl << "#7. TestAgency3 tries to delete a trip that is in another agency: " << endl << endl;
    test_agency1->hire_employee(test_employee1);
    test_agency1->hire_employee(test_employee2);
    Trip *test_trip2 = test_agency1->create_trip((char*)"TestCountry2");
    test_agency3->hire_employee(test_employee6);
    test_agency3->delete_trip(&test_trip2);

    //agency prints a list of trips when it does not have any
    cout << endl << "#8. TestAgency3 tries to print a list of trips when it does not have any: " << endl << endl;
    test_agency3->print_trips();
    //text warning should pop

    //employee tries to leave when he is not employed
    cout << endl << "#9. Test_employee4 tries to leave when he is not employed: " << endl << endl;
    test_employee4->leave(test_agency1);
    //text warning should pop

    //client tries to cancel a trip which he did not bought
    cout << endl  << endl << "#10. Test_client tries to cancel a trip which he did not bought: " << endl << endl;
    test_client->cancel_trip(test_agency1, test_trip2);
    //text warning should pop

    //client tries to print list of trips when he does not have any
    cout << endl << "#11. Test_client tries to print list of trips when he does not have any: " << endl << endl;
    test_client->print_trips();
    //text warning should pop

    //testing destructor of class employee
    cout << endl << "#12. Testing destructor of class employee. Deleting test_employee2: " << endl << endl;
    delete test_employee2;
    test_agency1->print_employees();

    //testing destructor of class client
    cout << "#13. Testing destructor of class client. Deleting test_client: " << endl << endl;
    test_client->buy_trip(test_agency1, test_trip2);
    test_trip2->printParticipants();
    delete test_client;
    test_trip2->printParticipants();
    
    //testing destructor of class trip
    cout << "#14. Testing destructor of class trip. Deleting test_trip2: " << endl << endl;  
    test_agency1->print_trips();
    test_agency1->delete_trip(&test_trip2);     //in function delete_trip destructor of trip is called
    test_agency1->print_trips();

    //testing destructor of class agency
    cout << endl << "#15. Testing destructor of class agency. Deleting test_agency4: " << endl << endl;  
    TravelAgency *test_agency4 = new TravelAgency((char*)"TestAgency4");
    Employee *test_employee7 = new Employee((char*)"TestEmployeeName7", (char*)"TestEmployeeSurname7");
    Client *test_client1 = new Client((char*)"TestClientName1", (char*)"TestClientSurname1");
    test_agency4->hire_employee(test_employee7);
    Trip *test_trip4 = test_agency4->create_trip((char*)"TestCountry4");
    cout << "before deliting: " << endl;
    test_agency4->print_trips();
    test_client1->buy_trip(test_agency4, test_trip4);
    test_client1->print_trips();

    delete test_agency4;
    cout << "after deliting" << endl << "client should not have any trips: " << endl;
    test_client1->print_trips();
    cout << endl << "Test_employee7 should be not have an employer now: \t" << test_employee7->returnEmployer() << endl;
    cout << "Test_agency4 should be not have a name: \t\t" << test_agency4->returnName() << endl;
    cout << "Test_trip4 should be not have a destination: \t\t" <<test_trip4->returnCountry() << endl << endl;

    //unemployed employee tries to leave an agency
    cout << "#16. Unemployed employee tries to leave an agency: " << endl << endl; 
    test_employee7->leave(test_agency3);

    // Trip *trip1 = agency1->create_trip((char*)"France");
    // Trip *trip2 = agency1->create_trip((char*)"Italy");
    // agency1->print_trips();

    // cout << trip2->returnCountry() << endl;
    // agency1->delete_trip(&trip2);
    // cout << trip2 << endl;

    // agency1->print_trips();

    // //funkcja umie usunac tylko pierwsza dodana wycieczke?

    // client1->buy_trip(agency1, trip2);
    // client1->print_trips();

    // //trip2->printParticipants();

    // client1->cancel_trip(agency1, trip2);
    // client1->print_trips();

    //trip2->printParticipants();

}