/*
Project       : Flight Management System
Version       : 1.0
Developed By  : Parth and Prateek
*/
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//Constant character declaration
const char TL=218,TR=191,BL=192,BR=217,HL=196,VL=179;

char Menu[][15]={ "Flight   ","Find     ","Utility  ","Quit     "};
char S1Menu[][15]={"Add      ","View     ","Edit     ",
		   "Remove   ","Main Menu"};
char S2Menu[][15]={"Flightnumber","Originalcity",
		   "Final city  ","Main Menu   "};
char S3Menu[][15]={"Reserve  ","Cancel   ","Main Menu"};


//GENERAL FUNCTIONS PROTOTYPES
void DispCh(int C,int R,char Ch);
void DispCh(int C,int R,char Ch[]);
void Color(int TC,int TB);
void Recta(int C1,int R1,int C2,int R2);
int  VMenu(int C,int R,char Men[][15],int Noo);
int  HMenu(int C,int R,char Men[][15],int Noo);
//MAIN CLASS
struct PASSENGER
{
  char Name[20];
  char Gender;
  char Mobile[15];
  char Email[20];
};
class FLIGHT
{
    int FNO;
    char FROM[20], TO[20], DATE[12],DTIME[10], ATIME[10];
    int FARE;
    PASSENGER P[5];
  public:
    FLIGHT();
    int Getfno(){return FNO;}
    char* Getoc(){return FROM;}
    char* Getfc(){return TO;}
    void Schedule();
    int Cancel(int);
    int RFno(){return FNO;}
    char* RDate(){return DATE;}
    void Display(int i)
    {
      char STRFNO[10], STRFARE[10];
      sprintf(STRFNO,"%d",FNO);
      sprintf(STRFARE,"%d",FARE);

      DispCh(2,i,STRFNO);
      DispCh(14,i,FROM);
      DispCh(28,i,TO);
      DispCh(38,i,DTIME);
      DispCh(50,i,ATIME);
      DispCh(62,i,DATE);
      DispCh(74,i,STRFARE);
    }
    int Booking();
    void EditFno()
    {
      gotoxy(2,19);
      cprintf("Enter new Flight No: ");
      cin>>FNO;
    }
    void EditFrom()
    {
      gotoxy(2,19);
      cprintf("Enter new From: ");
      gets(FROM);
    }
    void EditTo()
    {
      gotoxy(2,19);
      cprintf("Enter new To: ");
      gets(TO);
    }
    void EditDtime()
    {
      gotoxy(2,19);
      cprintf("Enter new Dep Time: ");
      gets(DTIME);
    }
    void EditAtime()
    {
      gotoxy(2,19);
      cprintf("Enter new Arr Time: ");
      gets(ATIME);
    }
    void EditFare()
    {
      gotoxy(2,19);
      cprintf("Enter new Fare: ");
      cin>>FARE;
    }
   int Book();
};
FLIGHT::FLIGHT()
{
  for (int I=0;I<10;I++)
  {
    P[I].Name[0]='\0';
    P[I].Gender=' ';
    P[I].Mobile[0]='\0';
    P[I].Email[0]='\0';
  }
}

void FLIGHT::Schedule()
{
      DispCh(15,6 ,"Flight No.    :");gotoxy(30,6);cin>>FNO;
      DispCh(15,7 ,"From          :");gotoxy(30,7);gets(FROM);
      DispCh(15,8 ,"To            :");gotoxy(30,8);gets(TO);
      DispCh(15,9 ,"Date          :");gotoxy(30,9);gets(DATE);
      DispCh(15,10,"Departure Time:");gotoxy(30,10);gets(DTIME);
      DispCh(15,11,"Arrival Time  :");gotoxy(30,11);gets(ATIME);
      DispCh(15,12,"Fare          :");gotoxy(30,12);cin>>FARE;
      Color(WHITE,BLACK);
      for (int I=0;I<5;I++)
	P[I].Name[0]='\0';
      DispCh(15,15,"Flight Added.");
}
int FLIGHT::Booking()
{
  int Booked=0;
  for (int I=0;!Booked && I<5;I++)
  {
    if (P[I].Name[0]=='\0')
    {
      cout<<"[---Queen Fisher Airlines ---]"<<endl;
      cout<<"[---   Flight Booking     ---]"<<endl;

      DispCh(15,12,"Flight No.    :");gotoxy(30,12);cout<<FNO<<endl;
      DispCh(15,13,"From          :");gotoxy(30,13);cout<<FROM<<endl;
      DispCh(15,14,"To            :");gotoxy(30,14);cout<<TO<<endl;
      DispCh(15,15,"Date          :");gotoxy(30,15);cout<<DATE<<endl;
      DispCh(15,16,"Departure Time:");gotoxy(30,16);cout<<DTIME<<endl;
      DispCh(15,17,"Arrival Time  :");gotoxy(30,17);cout<<ATIME<<endl;
      DispCh(15,18,"Fare          :");gotoxy(30,18);cout<<FARE<<endl;
      DispCh(15,19,"Name          :");gotoxy(30,19);gets(P[I].Name);
      DispCh(15,20,"Gender [M/F]  :");gotoxy(30,20);cin>>P[I].Gender;
      DispCh(15,21,"Mobile        :");gotoxy(30,21);gets(P[I].Mobile);
      DispCh(15,22,"Email         :");gotoxy(30,22);gets(P[I].Email);
      DispCh(15,23,"Seat No       :");gotoxy(30,23);cout<<I+1<<endl;
      DispCh(2,24,"Thank You for travelling QueenFisher Airlines");
      DispCh(2,25,"Your Seat has been Booked ... Happy Journey....");
      Booked++;
    }
   }
   return Booked;
}
int FLIGHT::Cancel(int Psno)
{
  int Cancelled=0;
  cout<<"[---Queen Fisher Airlines ---]"<<endl;
  cout<<"[--- Flight Cancellation  ---]"<<endl;

  DispCh(15,6 ,"Flight No.    :");gotoxy(30,6);cout<<FNO<<endl;
  DispCh(15,7 ,"From          :");gotoxy(30,7);cout<<FROM<<endl;
  DispCh(15,8 ,"To            :");gotoxy(30,8);cout<<TO<<endl;
  DispCh(15,9 ,"Date          :");gotoxy(30,9);cout<<DATE<<endl;
  DispCh(15,10,"Departure Time:");gotoxy(30,10);cout<<DTIME<<endl;
  DispCh(15,11,"Arrival Time  :");gotoxy(30,11);cout<<ATIME<<endl;
  DispCh(15,12,"Fare          :");gotoxy(30,12);cout<<FARE<<endl;
  DispCh(15,13,"Name          :");gotoxy(30,13);cout<<P[Psno-1].Name;
  DispCh(15,14,"Gender [M/F]  :");gotoxy(30,14);cout<<P[Psno-1].Gender;
  DispCh(15,15,"Mobile        :");gotoxy(30,15);cout<<P[Psno-1].Mobile;
  DispCh(15,16,"Email         :");gotoxy(30,16);cout<<P[Psno-1].Email;
  DispCh(15,17,"Seat No       :");gotoxy(30,17);cout<<Psno<<endl;
  char Confirm;
  cout<<"[Do you wish to Cancel this ticket Y/N]";cin>>Confirm;
  Confirm=toupper(Confirm);
  if (Confirm=='Y')
  {
    P[Psno-1].Name[0]='\0';
    P[Psno-1].Gender=' ';
    P[Psno-1].Mobile[0]='\0';
    P[Psno-1].Email[0]='\0';
    DispCh(15,20,"Ticket Cancelled");
    Cancelled++;
  }
  return Cancelled;
}

//Binary file Functions
void FSchedule()
{
  fstream F;
  F.open("FLIGHT.DAT",ios::binary|ios::app);
  FLIGHT CF;
  char CH;
  do
  {
    clrscr();
    cout<<"[---Queen Fisher Airlines ---]"<<endl;
    cout<<"[---   Flight Scheduling   ---]"<<endl;
    CF.Schedule();
    F.write((char*)&CF,sizeof(CF));
    cout<<"More Flights to schedule(Y/N)?";
    cin>>CH;
  }
  while (CH!='N'&&CH!='n');
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();
  F.close();
}
void Mflightview()
{
  fstream F;
  F.open("FLIGHT.DAT", ios::binary|ios::in);
  FLIGHT CF;
  Color(WHITE,BLACK);
  DispCh(2,2,"Flight No.");
  DispCh(14,2,"From");
  DispCh(28,2,"To");
  DispCh(38,2,"Dep Time");
  DispCh(50,2,"Arr Time");
  DispCh(62,2,"Date");
  DispCh(74,2,"Fare");
  Color(WHITE,BLACK);
  int i=4;
  while(F.read((char*)&CF,sizeof(FLIGHT)))
  {
    CF.Display(i);
    i++;
  }
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();

  //F.close();
}
void Mfileedit()
{
  Mflightview();
  fstream F;
  F.open("FLIGHT.DAT",ios::binary|ios::in|ios::out);
  FLIGHT CF;
  int Sfno,C,Found=0;
  char S[80];
  gotoxy(2,15);
  cprintf("Enter Flight No. of record to be edited: ");
  cin>>Sfno;
  while(!Found && F.read((char*)&CF,sizeof(CF)))
  {
    if(CF.Getfno()==Sfno)
    {
      Color(WHITE,BLACK);
      DispCh(2,17,"EDIT--");
      Color(WHITE,BLACK);
      DispCh(8,17,"  :FNO    :FROM    :TO    :DTIME    :ATIME    :FARE ");
      Color(WHITE,BLACK);
      DispCh(9,17,"1");
      DispCh(17,17,"2");
      DispCh(26,17,"3");
      DispCh(33,17,"4");
      DispCh(43,17,"5");
      DispCh(53,17,"6");
      Color(WHITE,BLACK);
      DispCh(62,17,"0:VIEW");
      Color(WHITE,BLACK);
      DispCh(68,17," - ");
      cin>>C;
      switch(C)
      {
	case 1:CF.EditFno();break;
	case 2:CF.EditFrom();break;
	case 3:CF.EditTo();break;
	case 4:CF.EditDtime();break;
	case 5:CF.EditAtime();break;
	case 6:CF.EditFare();break;
      }
      int N= F.tellg()- sizeof(CF);
      F.seekp(N);
      F.write((char*)&CF,sizeof(CF));
      Found++;
    }
  }
  if (Found==0)
  {
    gotoxy(2,17);cprintf("No Record matching.");
  }
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();

  F.close();
}
void fremove()
{
  Mflightview();
  fstream F1,F2;
  FLIGHT M;
  int FnoD;
  char Fname[20]="FLIGHT.DAT";
  char Fname2[20]="FLIGHT1.DAT";
  F1.open(Fname,ios::binary|ios::in);
  F2.open(Fname2,ios::binary|ios::out);
  gotoxy(2,15);
  cprintf("Enter Fno of flight to be deleted: ");
  cin>>FnoD;
  int Del=0;
  while(F1.read((char*)&M,sizeof(M)))
  {
    if(M.Getfno()!=FnoD)
      F2.write((char*)&M,sizeof(M));
    else
      Del++;
  }
  gotoxy(2,18);
  Color(WHITE,BLACK);
  if(Del)
  {
     cprintf("Flight no longer available.");
     remove(Fname);
     rename(Fname2,Fname);
  }
  else
     cprintf("No match found.");
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();

 F1.close();
 F2.close();
}

void sfno()
{
  int Tfno,found=0;
  fstream F;
  FLIGHT M;
  F.open("FLIGHT.DAT",ios::binary|ios::in);
  DispCh(2,8,"Enter Flight No to be searched: ");cin>>Tfno;
  while(F.read((char*)&M,sizeof(FLIGHT)))
  {
    Color(WHITE,BLACK);
    if(M.Getfno()==Tfno)
    { DispCh(2,10,"Flight No.");
      DispCh(16,10,"From");
      DispCh(30,10,"To");
      DispCh(44,10,"Dep Time");
      DispCh(56,10,"Arr Time");
      DispCh(70,10,"Fare");
      Color(WHITE,BLACK);
      M.Display(11);
      found++;
    }
  }
  if(!found)
  DispCh(2,10,"Flight not found.");
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();
  F.close();
}

void soc()
{
  char Toc[20];
  int found=0,i=0;
  fstream F;
  FLIGHT M;
  F.open("FLIGHT.DAT",ios::binary|ios::in);
  DispCh(2,8,"Enter city to be searched: ");cin>>Toc;
  while(F.read((char*)&M,sizeof(FLIGHT)))
  { Color(WHITE,RED);
    if(strcmpi(M.Getoc(),Toc)==0)
    { DispCh(2,10,"Flight No.");
      DispCh(16,10,"From");
      DispCh(30,10,"To");
      DispCh(44,10,"Dep Time");
      DispCh(56,10,"Arr Time");
      DispCh(70,10,"Fare");
      Color(WHITE,BLACK);
      M.Display(11+i);
      i++;
      found++;
    }
  }
  if(!found)
  DispCh(2,10,"Flight not found.");
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();

  F.close();
}
void sfc()
{
  char Tfc[20];
  int found=0,i=0;
  fstream F;
  FLIGHT M;
  F.open("FLIGHT.DAT",ios::binary|ios::in);
  DispCh(2,8,"Enter city to be searched: ");cin>>Tfc;
  while(F.read((char*)&M,sizeof(FLIGHT)))
  { Color(WHITE,BLACK);
    if(strcmpi(M.Getfc(),Tfc)==0)
    { DispCh(2,10,"Flight No.");
      DispCh(16,10,"From");
      DispCh(30,10,"To");
      DispCh(44,10,"Dep Time");
      DispCh(56,10,"Arr Time");
      DispCh(70,10,"Fare");
      Color(WHITE,BLACK);
      M.Display(11+i);
      i++;
      found++;
    }
  }
  if(!found)
  DispCh(2,10,"Flight not found.");
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();
  F.close();
}
void Bookticket()
{
  clrscr();
  Mflightview();

  fstream F;
  F.open("FLIGHT.DAT",ios::binary|ios::in|ios::out);
  FLIGHT M;
  int WFno,Found=0;
  char Wdate[20];
  cout<<"Flight No:";cin>>WFno;
  cout<<"Date     :";gets(Wdate);
  while (!Found && F.read((char*)&M,sizeof(M)))
  {
    if (WFno==M.RFno() && strcmpi(Wdate,M.RDate())==0)
    {
      if (M.Booking()==1)
      {
	int Pos=F.tellg()-sizeof(M);
	F.seekp(Pos);
	F.write((char*)&M,sizeof(M));
      }
      else
	cout<<"Sorry! Seat not available... "<<endl;
      Found++;
    }
  }
  if (!Found)
    cout<<"Try! Some other Date or Flight..."<<endl;
  cout<<endl<<"[Press any Key To Continue...]"<<endl;
  getch();
  F.close();
}
void Cancelticket()
{
  clrscr();
  Mflightview();

  fstream F;
  F.open("FLIGHT.DAT",ios::binary|ios::in|ios::out);
  FLIGHT M;
  int WFno,Found=0;
  char Wdate[20];
  int WSno;
  cout<<"Flight No:";cin>>WFno;
  cout<<"Date     :";gets(Wdate);
  cout<<"Seat No  :";cin>>WSno;
  while (!Found && F.read((char*)&M,sizeof(M)))
  {
    if (WFno==M.RFno() && strcmpi(Wdate,M.RDate())==0)
    {
      if (M.Cancel(WSno)==1)
      {
	int Pos=F.tellg()-sizeof(M);
	F.seekp(Pos);
	F.write((char*)&M,sizeof(M));
      }
      else
	cout<<"Seat not Cancelled... "<<endl;
      Found++;
    }
  }
  if (Found==0)
    cout<<"Invalid Flight and Date ..."<<endl;
  F.close();
}

void welcome()
{
  Color(WHITE,BLACK);
  clrscr();
  window(10,5,75,15);
  Color(WHITE,BLACK);
  clrscr();
  window(1,1,80,25);
  window(8,4,73,14);
  Color(WHITE,BLACK);
  clrscr();
  window(1,1,80,25);
  DispCh(3,6 ,  "  *");
  DispCh(3,7 ,  "  **");
  DispCh(3,8 ,  "  ***");
  DispCh(3,9 ,  "  ****");
  DispCh(3,10,  "  *****");
  DispCh(3,11,  "  ******************************************************************");
  DispCh(3,12,  "  *                                                                 ***");
  DispCh(3,13,  "  *                      QUEENFISHER AIRWAYS                           **");
  DispCh(3,14,  "  *                                                                     *");
  DispCh(3,15,  "  *********************************************************************");
  getch();
  Color(WHITE,BLACK);
  window(1,2,80,25);

  Color(WHITE,BLACK);
  clrscr();
}


void main()
{
  welcome();

  int Quit=0;
  do
  {
    clrscr();
    Color(WHITE,BLACK);
    clrscr();
    //Display Main Menu1
    int N,SN;
    N=HMenu(1,1,Menu,4);
    switch (N)
    {
    case 0:SN=VMenu(1,2,S1Menu,5);
	   clrscr();
	   switch(SN)
	   {
	     case 0:FSchedule();break;
	     case 1:Mflightview();break;
	     case 2:Mfileedit();break;
	     case 3:fremove();break;
	   }
	   break;
    case 1:SN=VMenu(14,2,S2Menu,4);
	   clrscr();
	   switch(SN)
	   {
	     case 0:sfno();break;
	     case 1:soc();break;
	     case 2:sfc();break;
	   }
	   break;

    case 2:SN=VMenu(27,2,S3Menu,4);
	   clrscr();
	   switch(SN)
	   {
	     case 0:Bookticket();break;
	     case 1:Cancelticket();
	     xx: clrscr();
	     break;
	     //case 2:Status();break;
	   }
	   break;

    case 3:Quit=1; break;
    }
  }
  while (!Quit);
  getch();
}
//GENERAL FUNCTIONS
void DispCh(int C,int R,char Ch)
{
  gotoxy(C,R);cprintf("%c",Ch);//C 1-80 R 1-25
}
void DispCh(int C,int R,char Ch[])
{
  gotoxy(C,R);cprintf("%s",Ch);
}

void Color(int TC,int TB)
{
  textcolor(TC);
  textbackground(TB);
}
void Recta(int C1,int R1,int C2,int R2)
{
  DispCh(C1,R1,TL);
  DispCh(C2,R1,TR);
  DispCh(C1,R2,BL);
  DispCh(C2,R2,BR);
  for (int i=C1+1;i<C2;i++)
  {
    DispCh(i,R1,HL);
    DispCh(i,R2,HL);
  }
  for (i=R1+1;i<R2;i++)
  {
    DispCh(C1,i,VL);
    DispCh(C2,i,VL);
  }
}

int VMenu(int C,int R,char Men[][15],int Noo)
{
  Color(WHITE,BLACK);
  Recta(C,R,C+strlen(Men[0])+1,R+Noo+1);//Drawing a rectangle enclosing options
  for (int i=0;i<Noo;i++)
    DispCh(C+1,R+i+1,Men[i]);           //Displaying All options

  int Exit=0,Sel=0;

  do
  {
    int Tsel=Sel;
    Color(BLACK,WHITE);          //Changing color for highlighting
    DispCh(C+1,R+Sel+1,Men[Sel]);//Redisplaying the selected option with changed color
    Color(WHITE,BLACK);          //Changing color to normal
    char Ch=getch();             //Accepting option from user
    switch(Ch)
    {
    case 71:Sel=0;break;        //Home -> Move to first option
    case 79:Sel=Noo-1;break;    //End  -> Move to Last option
    case 72:if (Sel==0)         //Up   -> Checking if already on top
	      Sel=Noo-1;        //        Move to the last option
	    else                //
	      Sel--;            //        Move one option up
	    break;
    case 80:if (Sel==Noo-1)     //Down -> Checking if already at bottom
	      Sel=0;            //        Move to the first option
	    else                //
	      Sel++;            //        Move one step down
	    break;
    case 27:Sel=-1;      //Escape-> Getting out of the Menu without valid selection
    case 13:Exit=1;      //Enter-> Getting out of the Menu with current selection
    }
    DispCh(C+1,R+Tsel+1,Men[Tsel]);//Redisplaying the non-highlighted option
  }
  while (!Exit);
  return Sel;             //Returning the selected value from menu
}
int HMenu(int C,int R,char Men[][15],int Noo)
{
  int Exit=0,Sel=0;
  Color(WHITE,BLACK);
  for (int i=0;i<Noo;i++)
    DispCh(C+13*i+1,R,Men[i]);
  do
  {
    int Tsel=Sel;
    Color(BLACK,WHITE);
    DispCh(C+13*Sel+1,R,Men[Sel]);
    Color(WHITE,BLACK);
    char Ch=getch();
    switch(Ch)
    {
    case 71:Sel=0;break;     //Home
    case 79:Sel=Noo-1;break; //End
    case 75:if (Sel==0)      //Left
	      Sel=Noo-1;
	    else
	      Sel--;
	    break;
    case 77:if (Sel==Noo-1)  //Right
	      Sel=0;
	    else
	      Sel++;
	    break;
    case 27:Sel=-1;    //Escape
    case 13:Exit=1;    //Enter
    }
    DispCh(C+13*Tsel+1,R,Men[Tsel]);
  }
  while (!Exit);
  return Sel;
}