#include <stdio.h>
#include <stdlib.h>
#include"Train.h"
#include"conio2.h"
int main()
{

    static Passenger *P;


    int k,i,j,ch;

    for(;;)
        {
            clrscr();
    ch=enterChoice();


if(ch==10)
{
    gotoxy(32,22);
    textcolor(LIGHTRED);
    printf("You choose to quit!");
    getch();
    return 0;
}
else if(ch>=1&&ch<=9)
{
    switch(ch)

{
case 1:
    viewTrains();
    break;
case 2:
P=getPassengerDetails();
if(P!=NULL)
{
    int ch=bookTicket(*P);
    if(ch==-1)
    {
        gotoxy(1,22);

        textcolor(RED);
        printf("Booking Failed!!!");
        getch();
    }
    else
        {
            textcolor(GREEN);
            gotoxy(1,21);
            printf("Ticket Succesfully Booked!!!");
            gotoxy(1,22);
            printf("Ticket No:%d",ch);
        printf("\nPress any key to go back to the main screen");

         getch();
}
}
    break;
case 3:
    viewTicket();
    break;
case 4:
    searchTicketNo();
    break;
case 5:
    viewAllBookings();
    break;
case 6:
    addTrains();
    break;
case 7:
     k=cancelTicket();
    if(k==1)
    {
        gotoxy(22,12);
        textcolor(GREEN);
        printf("Ticket Cancelled Succesfully!!");
        getch();
    }
    else if(k==2)
    {
         gotoxy(22,12);
        textcolor(GREEN);
        printf("Sorry!Error in deletion");
        getch();
    }
    else
    {
         gotoxy(22,12);
        textcolor(GREEN);
        printf("No record found!!");
        getch();

    }

    break;
case 8:
    k=cancelTrain();
    if(k==1)
    {
        gotoxy(22,12);
        textcolor(GREEN);
        printf("Train Cancelled Succesfully!!");
        getch();
    }
    else if(k==2)
    {
         gotoxy(22,12);
        textcolor(GREEN);
        printf("Sorry!Error in deletion");
        getch();
    }
    else
    {
         gotoxy(22,12);
        textcolor(GREEN);
        printf("No record found!!");
        getch();

    }
    break;
case 9:
    searchTrainNo();
    break;
}
}
else
{
    gotoxy(32,22);
    textcolor(LIGHTRED);
    printf("Wrong Choice! Try Again!!!");
    getch();
    gotoxy(32,22);
    printf("\t\t\t\t\t");
    gotoxy(1,15);
    printf("\t\t\t");
    continue;

}
}

}

