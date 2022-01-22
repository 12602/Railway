#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

struct Train
{
    char train_no[30];
    char from[30];
    char to[30];
    int  fac_fare;
    int sec_fare;
};
struct Passenger
{
    char p_name[30];
    char g;
    char train_no[30];
    char p_class;
    char address[30];
    int age;
    int ticketno;
    //mobile no is of 10 digit and  1 to store 0;terminating char so  size is 11;
    char mob_no[11];
    int ticketCount;
};
typedef struct Train Train;
typedef struct Passenger Passenger;
char* oneTicket();
int enterChoice();
void addTrains();
void viewTrains();
int bookTicket(Passenger);
int *getTicket(char *);
void viewTicket();
void viewAllBookings();
void searchTrainNo();
void searchTicketNo();
int cancelTicket();
Passenger *getPassengerDetails();
int cancelTrain();
int checkMobileNumber(char *);
int checkTrainNumber(char *trainNO);

#endif // TRAIN_H_INCLUDED
