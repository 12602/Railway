#include<stdio.h>
#include"Train.h"
#include"conio2.h"

int  enterChoice()
 {
     static int ch;
     int i;
     for(;;)
    {
        textcolor(RED);
        gotoxy(32,1);
        printf("RAILWAY RESERVATION SYSTEM");
        gotoxy(1,2);
        textcolor(WHITE);
        for(i=0;i<80;i++)
            printf("%c",247);
            gotoxy(1,5);
        textcolor(LIGHTMAGENTA);
        printf("SELECT AN OPTION");
        gotoxy(1,7);
        textcolor(LIGHTCYAN);
        printf("1- View Trains");
        gotoxy(1,8);

        printf("2- Book Ticket");

        gotoxy(1,9);

        printf("3- View Ticket");

        gotoxy(1,10);

        printf("4- Search Ticket No");

        gotoxy(1,11);

        printf("5- View All Bookings");
        gotoxy(1,12);

        printf("6- Add Trains ");

        gotoxy(1,13);

        printf("7- Cancel Ticket");
        gotoxy(1,14);
        textcolor(RED);
        printf("8- Cancel Trains");
        gotoxy(1,15);
        textcolor(GREEN);
        printf("9- Search Train Number");
        gotoxy(1,16);
        textcolor(RED);
        printf("10- Quit");

        for(;;)
        {
             gotoxy(1,18);
        textcolor(LIGHTGREEN);
        printf("Enter choice:");
        textcolor(WHITE);
            scanf("%d",&ch);
        return ch;
        }
        }
        }




void addTrains()
{
    clrscr();
char ch;
        Train T;
FILE *fp;
              fp=fopen("alltrains.bin","ab+");
              do{
                    clrscr();
                    gotoxy(1,3);
              textcolor(RED);
              printf("Enter train no:");
              textcolor(WHITE);
              fflush(stdin);
              gets(T.train_no);
              textcolor(RED);
               gotoxy(1,4);
              printf("From:");
              textcolor(WHITE);
                fflush(stdin);
              gets(T.from);
              textcolor(RED);
               gotoxy(1,5);
              printf("To:");
              textcolor(WHITE);
                fflush(stdin);
              gets(T.to);
              textcolor(RED);
               gotoxy(1,6);
              printf("First Ac fare:");
              textcolor(WHITE);

              scanf("%d",&T.fac_fare);
              textcolor(RED);
               gotoxy(1,7);
              printf("Enter Second AC FARE:");
              textcolor(WHITE);
              scanf("%d",&T.sec_fare);
              gotoxy(1,10);
              textcolor(GREEN);
              printf("DO YOU WANT TO ADD MORE TRAINS(Y OR N):");
              textcolor(WHITE);
              scanf(" %c",&ch);
              fwrite(&T,sizeof(T),1,fp);
              if(ch=='N'||ch=='n')
                break;

              }while(1);

            printf("Train saved successfully\n");
		fclose(fp);



}
void viewTrains()
{
    int i;
    clrscr();
    textcolor(YELLOW);
    gotoxy(1,1);
    printf("TRAIN NO");
    gotoxy(15,1);
    printf("FROM");
    gotoxy(40,1);
    printf("TO");
     gotoxy(55,1);
    printf("FIRST AC");
     gotoxy(70,1);
    printf("SECOND AC");
   gotoxy(1,2);
   textcolor(WHITE);
   for(i=0;i<80;i++)
    printf("%c",247);
    FILE *fp;
    fp=fopen("alltrains.bin","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("No train present!!");
        getch();
        return NULL;
    }
    Train T;
    int row=3;
    textcolor(LIGHTGRAY);
    while(fread(&T,sizeof(T),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%s",T.train_no);
        gotoxy(15,row);
        printf("%s",T.from);
        gotoxy(40,row);
        printf("%s",T.to);
        gotoxy(55,row);
        printf("%d",T.fac_fare);
        gotoxy(70,row);
        printf("%d",T.sec_fare);
   row++;
    }

    gotoxy(1,row+2);
    textcolor(WHITE);
    printf("Press any key to go back to main menu..");
    getch();
    fclose(fp);


}
Passenger * getPassengerDetails()
{
    char train_no[30];
    Train T;
              char mob_no[15];
                  FILE *fp;
    fp=fopen("alltrains.bin","rb");
      static Passenger P;
fseek(fp,0,SEEK_END);
int n=ftell(fp)/sizeof(P);
int temp;
if(n!=0)
{

    fseek(fp,-sizeof(P),SEEK_END);
    fread(&temp,sizeof(temp),1,fp);
    temp++;

}
P.ticketno=temp;



    if(fp==NULL)
    {
        printf("No train found!");
        getch();
        return NULL;
    }

    clrscr();

    gotoxy(65,1);
    textcolor(WHITE);
    printf("Press 0 to exit");
    textcolor(YELLOW);
    gotoxy(1,2);

    printf("Enter Passenger name:");
    textcolor(WHITE);
    fflush(stdin);
    fgets(P.p_name,30,stdin);
    char *pos;

    pos=strchr(P.p_name,'\n');
    if(pos!=NULL)
        *pos='\0';
        if(strcmp(P.p_name,"0")==0)
        {
            textcolor(RED);
            gotoxy(22,22);
            printf("You choose to quit!");
            getch();
            gotoxy(22,22);
            printf("\t\t\t\t\t");
            return -1;
        }
        while(1)
            {
                textcolor(YELLOW);
        gotoxy(1,3);
        printf("Enter your Gender(M or F):");
        textcolor(WHITE);
        scanf(" %c",&P.g);
        if(P.g==48)
            {
                textcolor(RED);
                gotoxy(22,22);
                printf("You choose to quit!!");
                getch();
                gotoxy(22,22);
            printf("\t\t\t\t\t");
            return -1;
            }
        if(P.g=='M'||P.g=='F')
            break;
        else
        {
            textcolor(RED);
            gotoxy(1,25);
            printf("Error! Gender should be M or F (in uppercase)");
            getch();
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,3);
        printf("\t\t\t\t");
        continue;

        }


            }

            int found=1;
            while(1)
                {
               gotoxy(1,4);
            textcolor(YELLOW);
            printf("Enter Train No:");
            fflush(stdin);

            textcolor(WHITE);
            fgets(train_no,30,stdin);

        pos=strchr(train_no,'\n');
        if(pos!=NULL)
            *pos='\0';
            if(strcmp(train_no,"0")==0)
        {
            gotoxy(22,22);
            textcolor(RED);
            printf("You choose to quit!");
            getch();
            gotoxy(22,22);
            printf("\t\t\t\t\t");
            return -1;
        }
         int ch=checkTrainNumber(train_no);
         if(ch==0)
         {
                    textcolor(RED);
                    gotoxy(1,12);
                    printf("Error ! Invalid Train No!!!");
                    getch();
                    gotoxy(1,12);
                    printf("\t\t\t\t\t\t");
                    gotoxy(1,4);
                    printf("\t\t\t\t\t");
                    continue;

             }
         else
            break;
        }





            while(1)
                {
            gotoxy(1,5);
            textcolor(YELLOW);
            printf("Enter Travelling Class(First AC-F ,Second Ac-S):");
            textcolor(WHITE);
            scanf(" %c",&P.p_class);

//ascii of 0 is 48 so we compare it with 48;
            if(P.p_class==48)
            {
                textcolor(RED);
                gotoxy(22,22);
                printf("You choose to quit!!");
                getch();
                gotoxy(22,22);
                printf("\t\t\t\t\t");
                return -1;
            }
            if(P.p_class=='F'||P.p_class=='S')
                break;
            else
            {
                textcolor(RED);
            gotoxy(1,25);
            printf("Error! Class should be S or F (in uppercase)");
            getch();
        gotoxy(1,25);
        printf("\t\t\t\t\t\t\t");
        gotoxy(1,5);
        printf("\t\t\t\t\t\t");
        continue;
            }
                }
            textcolor(YELLOW);
            gotoxy(1,6);
            printf("Enter Address:");
            fflush(stdin);
            textattr(WHITE);
            fgets(P.address,30,stdin);
            pos=strchr(P.address,'\n');
            if(pos!=NULL)
                *pos='\0';
                if(strcmp(P.address,"0")==0)
        {
            gotoxy(22,22);
            textcolor(RED);
            printf("You choose to quit!");
            getch();
            gotoxy(22,22);
            printf("\t\t\t\t\t");
            return -1;
        }
        while(1)
            {
                gotoxy(1,7);
                textcolor(YELLOW);
                printf("Enter Age:");
                textcolor(WHITE);
                scanf("%d",&P.age);
                if(P.age>0)
                    break;
                else if(P.age==0)
                {
                    textcolor(RED);
                     gotoxy(22,22);
            printf("You choose to quit!");
            getch();
            gotoxy(22,22);
            printf("\t\t\t\t\t");
            return -1;

                }
                else if(P.age<0)
                {
                    textcolor(RED);
                     gotoxy(22,22);
            printf("Error age should be positive!");
            getch();
            gotoxy(22,22);
            printf("\t\t\t\t\t");
            gotoxy(1,7);
            printf("\t\t\t\t\t\t");
            continue;

                }

            }
                while(1)
                    {

              gotoxy(1,8);
              textcolor(YELLOW);
              printf("Enter Mobile No:");
              fflush(stdin);
              textcolor(WHITE);

              fgets(mob_no,15,stdin);
              pos=strchr(mob_no,'\n');
              if(pos!=NULL)
                *pos='\0';
              if(strcmp(mob_no,"0")==0)
              {
                  textcolor(RED);
                     gotoxy(1,22);
            printf("You choose to quit!!!");
            getch();
            gotoxy(22,22);
            printf("\t\t\t\t\t");
        return -1;


              }
              int ch=checkMobileNumber(mob_no);
              if(ch==1)
                break;
              else if(ch==0)
              {
                  textcolor(RED);
                     gotoxy(1,22);
            printf("Invalid mobile number!Please try again!!!");
            getch();
            gotoxy(1,22);
            printf("\t\t\t\t\t");
            gotoxy(1,8);
            printf("\t\t\t\t\t\t");
            continue;

              }
        }
        strcpy(P.mob_no,mob_no);
             strcpy(P.train_no,train_no);
  fclose(fp);
        return &P;
}









int checkMobileNumber(char *mobileno)
{

    if(strlen(mobileno)!=10)
    {

        return 0;
    }
    for(int i=0;i<10;i++)
    {
    if(isdigit(*mobileno)==0)
               return 0;
        mobileno++;

    }
    return 1;
}



int checkTrainNumber(char *trainNo)
{
    FILE *fp=fopen("alltrains.bin","rb");
static Train T;
    if(fp==NULL)
    {
        printf("Sorry!No Train available!!!");
        getch();
        return -1;
    }
            int found=0;
            while(fread(&T,sizeof(T),1,fp)==1)
            {
                if(strcmp(T.train_no,trainNo)==0)
                {
                   found=1;
                    break;
                }

            }
                if(found==0)
               {
                   fclose(fp);

                   return 0;
               }

                else

                    {
                 fclose(fp);
              return 1;

            }

}

int getBookedTicketCount(char *trainNo,char classNo)
{
    FILE *fp;
    fp=fopen("allbookings.bin","rb");
    if(fp==NULL)
        return 0;
    int found=0;
    Passenger P;
    while(fread(&P,sizeof(P),1,fp)==1)
    {
        if(strcmp(&P.train_no,trainNo)==0 &&P.p_class==classNo)
        {
            ++found;

        }
    }
    fclose(fp);
    return found;
}
int lastTicketNo()
{
    FILE *fp;
    fp=fopen("allbookings.bin","rb+");
    if(fp==NULL)
        return 0;
static Passenger P;
    fseek(fp,-1*sizeof(P),SEEK_END);
    fread(&P,sizeof(P),1,fp);
    fclose(fp);
return P.ticketno;

}
int bookTicket(Passenger P)
{
    int k=getBookedTicketCount(P.train_no,P.p_class);
    if(k==5)
    {
        printf("All seats full in train no:%s and class:%c ",P.train_no,P.p_class);
        getch();
        return -1;
    }
    P.ticketno=lastTicketNo();

    ++P.ticketno;
int count=0;
    FILE *fp;
    fp=fopen("allbookings.bin","ab");
    if(fp==NULL)
    {
        count++;

        printf("Soory!can't open the file");
        getch();
        return 0;

    }
    P.ticketCount=
    fwrite(&P,sizeof(P),1,fp);

    fclose(fp);
    return P.ticketno;

}


int cancelTicket()
{
    clrscr();
      gotoxy(65,2);
    textcolor(WHITE);
    printf("Press 0 to exit");
    FILE *fp1,*fp2;
    fp1=fopen("allbookings.bin","rb");
    if(fp1==NULL)
    {
        textcolor(RED);
        printf("No  Bookings done yet!!!!");
        getch();
        fclose(fp1);
        return -1;
    }
    fp2=fopen("temp.bin","wb");

    gotoxy(32,1);
    textcolor(RED);
    printf("CANCEL TICKET ");

    gotoxy(1,3);
    textcolor(RED);
    int t;
    printf("Enter ticket no which you want to Cancel:");
    textcolor(WHITE);
    scanf("%d",&t);
    if(t==0)
    {
        gotoxy(22,12);
        textcolor(RED);
        printf("You choose to quit!");
        getch();
        return -1;
    }
    Passenger P;
    int found=0;
    while(fread(&P,sizeof(P),1,fp1)==1)
    {
        if(P.ticketno!=t)
            fwrite(&P,sizeof(P),1,fp2 );
            else
                found=1;
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    remove("temp.bin");
    else
    {
        int result;
        result=remove("allbookings.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","allbookings.bin");
        if(result!=0)
            return 2;
    }
return found;
}

void viewAllBookings()
{
   clrscr();
    FILE *fp;
    fp=fopen("allbookings.bin","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("Error!No record found!!");
        getch();
        return ;

    }
    Passenger P;
    gotoxy(1,1);
    printf("TIC_NO");
    gotoxy(10,1);
    printf("PASSENGER NAME");
    gotoxy(25,1);
    printf("TRAIN NO");
    printf("%s",P.train_no);
    gotoxy(40,1);
    printf("AGE");
    gotoxy(45,1);
    printf("ADDRESS");
    gotoxy( 60,1);
    printf("CLASS");
    gotoxy(70,1);
    printf("MOB_NUMBER");
    int i;
    gotoxy(1,2);
    textcolor(WHITE);
    for(i=0;i<80;i++)
    printf("%c",247);
        textcolor(LIGHTCYAN);
    int row=3;
    while(fread(&P,sizeof(P),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%d",P.ticketno);
        gotoxy(10,row);
        printf("%s",P.p_name);
        gotoxy(25,row);


        printf("%s",P.train_no);
        gotoxy(40,row);
        printf("%d",P.age);
        gotoxy(45,row);
        printf("%s",P.address);
        gotoxy(60,row);
        printf("%c",P.p_class);
        gotoxy(70,row);
        printf("%s",P.mob_no);
        row++;


    }
    getch();
    fclose(fp);
}

void   searchTicketNo()
{
    clrscr();
    gotoxy(32,1);
    int t;
    textcolor(GREEN);
    printf("RAILWAY MANAGEMENT SYSTEM");
    gotoxy(60,2);
    textcolor(WHITE);
    printf("Press 0 to exit!!");
textcolor(RED);
    gotoxy(1,3);
    printf("Enter Ticket Number:");
    textcolor(WHITE);
    scanf("%d",&t);
    if(t==0)
    {
        textcolor(RED);
        gotoxy(22,12);
        printf("You choose to quit!!");
        getch();
        return 0;
    }
    Passenger P;
    FILE *fp;
    fp=fopen("allbookings.bin","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        gotoxy(22,12);
        printf("NO record exist!!!");
        getch();
    }
     gotoxy(1,5);
    printf("TIC_NO");
    gotoxy(10,5);
    printf("PASSENGER NAME");
    gotoxy(25,5);
    printf("TRAIN NO");
    printf("%s",P.train_no);
    gotoxy(40,5);
    printf("AGE");
    gotoxy(45,5);
    printf("ADDRESS");
    gotoxy( 60,5);
    printf("CLASS");
    gotoxy(70,5);
    printf("MOB_NUMBER");
    int i;
    gotoxy(1,6);
    textcolor(WHITE);
    for(i=0;i<80;i++)
    printf("%c",247);
        textcolor(LIGHTCYAN);
    int row=7;

    textcolor(RED);
    while(fread(&P,sizeof(P),1,fp)==1)
    {
        if(P.ticketno==t)
            {
        gotoxy(1,row);
        printf("%d",P.ticketno);
        gotoxy(10,row);
        printf("%s",P.p_name);
        gotoxy(25,row);


        printf("%s",P.train_no);
        gotoxy(40,row);
        printf("%d",P.age);
        gotoxy(45,row);
        printf("%s",P.address);
        gotoxy(60,row);
        printf("%c",P.p_class);
        gotoxy(70,row);
        printf("%s",P.mob_no);
        row++;

            }
    }
    fclose(fp);

    gotoxy(1,row+5);
textcolor(WHITE);
printf("Press any key to go back!!!");
    getch();

}
int cancelTrain()
{
    clrscr();
    char train[30];
gotoxy(32,1);
printf("RAILWAY MANAGEMWNT SYSTEM");
gotoxy(1,3);
textcolor(GREEN);
printf("ENTER TRAIN NUMBER WHICH YOU WANT TO CANCEL:");
textcolor(WHITE);
fflush(stdin);
gets(train);
Train T;
FILE *fp1;
fp1=fopen("alltrains.bin","rb");
FILE *fp2;
fp2=fopen("temp.bin","wb");
if(fp1==NULL)
{
    gotoxy(32,12);
    textcolor(RED);
    printf("No!trains found!!");
    getch();
    return 2;
}
int found=0;
while(fread(&T,sizeof(T),1,fp1)==1)
{
    if(strcmp(train,T.train_no)!=0)
    {
        fwrite(&T,sizeof(T),1,fp2);
    }

    else
        {
            found=1;
            }
}
fclose(fp1);
    fclose(fp2);
    if(found==0)
    remove("temp.bin");
    else
    {
        int result;
        result=remove("alltrains.bin");
        if(result!=0)
            return 2;
        result=rename("temp.bin","alltrains.bin");
        if(result!=0)
            return 2;
    }
return found;



}


void viewTicket()
{
     clrscr();
    FILE *fp;
    fp=fopen("allbookings.bin","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        printf("Error!No record found!!");
        getch();
        return ;

    }
    Passenger P;
    gotoxy(1,1);
    printf("TIC_NO");
    gotoxy(10,1);
    printf("PASSENGER NAME");
    gotoxy(25,1);
    printf("TRAIN NO");
    printf("%s",P.train_no);
    gotoxy(35,1);
    printf("AGE");
    gotoxy(40,1);
    printf("ADDRESS");
    gotoxy( 60,1);
    printf("CLASS");
    gotoxy(70,1);
    printf("MOB_NUMBER");
    int i;
    gotoxy(1,2);
    textcolor(WHITE);
    for(i=0;i<80;i++)
    printf("%c",247);
        textcolor(LIGHTCYAN);
    int row=3;
    while(fread(&P,sizeof(P),1,fp)==1)
    {
        gotoxy(1,row);
        printf("%d",P.ticketno);
        gotoxy(10,row);
        printf("%s",P.p_name);
        gotoxy(25,row);
        printf("%s",P.train_no);
        gotoxy(35,row);
        printf("%d",P.age);
        gotoxy(40,row);
       // printf("%s",P.address);
//Displaying linewise output because length of string is greater it cover the whole page width

    int k;
    //displaying 15 char first
    for(k=0;k<15;k++)
         printf("%c",P.address[k]);
         //if str is greater than 15 display more on new line
         if(strlen(P.address)>15)
         {
             gotoxy(40,row+1);
             for(k=15;k<30;k++)
         printf("%c",P.address[k]);

         }


        gotoxy(60,row);
        printf("%c",P.p_class);
        gotoxy(70,row);
        printf("%s",P.mob_no);
        row=row+5;


    }
    getch();
    fclose(fp);
}
void searchTrainNo()
{
 clrscr();
    gotoxy(32,1);
    char  t[30];
    textcolor(GREEN);
    printf("RAILWAY MANAGEMENT SYSTEM");
    gotoxy(60,2);
    textcolor(WHITE);
    printf("Press 0 to exit!!");
textcolor(RED);
    gotoxy(1,3);
    printf("Enter Train Number:");
    textcolor(WHITE);
    fflush(stdin);
    scanf("%s",t);
    if(strcmp(t,"0")==0)
    {
        textcolor(RED);
        gotoxy(22,12);
        printf("You choose to quit!!");
        getch();
        return 0;
    }
    Train T;
    FILE *fp;
    fp=fopen("alltrains.bin","rb");
    if(fp==NULL)
    {
        textcolor(RED);
        gotoxy(22,12);
        printf("NO record exist!!!");
        getch();
    }
     gotoxy(1,5);
    printf("TRAIN NO");
    gotoxy(15,5);
    printf("FROM");
    gotoxy(35,5);
    printf("To");

    gotoxy(55,5);
    printf("F_AC_FAIR");
    gotoxy(70,5);
    printf("SEC_AC_FAIR");

    int i;
    gotoxy(1,6);
    textcolor(WHITE);
    for(i=0;i<80;i++)
    printf("%c",247);
        textcolor(LIGHTCYAN);
    int row=7;

    textcolor(RED);
    while(fread(&T,sizeof(T),1,fp)==1)
    {
        if(strcmp(T.train_no,t)==0)
            {
        gotoxy(1,row);
        printf("%s",T.train_no);
        gotoxy(15,row);
        printf("%s",T.from);
        gotoxy(35,row);


        printf("%s",T.to);
        gotoxy(55,row);
        printf("%d",T.fac_fare);
        gotoxy(70,row);
        printf("%d",T.sec_fare);

        row++;


    }
    }
    fclose(fp);
gotoxy(1,row+5);
textcolor(WHITE);
printf("Press any key to go back!!!");
    getch();

}
