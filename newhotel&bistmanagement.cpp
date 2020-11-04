#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
#include<ctime>
#include<dos.h>
#include<iomanip>
#include<string>

using namespace std;
int tothotppl;

class hotel
{

int room_no;
char name[30];
char address[50];
char phone[10];
int ppl=0;
char aadharnumber[50];

public:

void main_menu(); //to dispay the main menu
void add(); //to book a room
void display(); //to display the customer record
void rooms(); //to display alloted rooms
void edit(); //to edit the customer record
int check(int); //to check room status
void modify(int); //to modify the record
void delete_rec(int); //to delete the record
void bill(int);
void checkout(int);                 //for the bill of a record
     };
    //END OF CLASS



//FOR DISPLAYING MAIN MENU



void hotel::main_menu()
{

int choice;
while(choice!=5)
{

  tothotppl=0;
  system("cls");
cout<<"\n\t\t\t\t*************************";
cout<<"\n\t\t\t\t SIMPLE HOTEL MANAGEMENT ";
cout<<"\n\t\t\t\t      * MAIN MENU *";
cout<<"\n\t\t\t\t*************************";
cout<<"\n\n\n\t\t\tPeople currently staying at the hotel: ";
ifstream fin("Record.dat",ios::in);
 while((fin.read((char*)this,sizeof(hotel))) != NULL)
{tothotppl= tothotppl+ ppl;}
cout<<tothotppl;
fin.close();
cout<<"\n\n\n\t\t\t1.Book A Room";
cout<<"\n\t\t\t2.Customer Records";
cout<<"\n\t\t\t3.Rooms Allotted";
cout<<"\n\t\t\t4.Edit Record";
cout<<"\n\t\t\t5.Checkout";
cout<<"\n\t\t\t6.Exit";
cout<<"\n\n\t\t\tEnter Your Choice: ";
cin>>choice;

switch(choice)
{

case 1: add();
break;

case 2: display();
break;

case 3: rooms();
break;

case 4:
    edit();
break;

case 5:

    system("cls");
    int a;
    cout<<"\n Enter room no: " ;
cin>>a;
   checkout(a);
case 6:
    break;

default:
{

cout<<"\n\n\t\t\tWrong choice.....!!!";
cout<<"\n\t\t\tPress any key to   continue....!!";
getch();

}

}

}

}


//END OF MENU FUNCTION


//FUNCTION FOR BOOKING OF ROOM


void hotel::add()
{

  system("cls");
int r,flag;
ofstream fout("Record.dat",ios::app);

cout<<"\n Enter Customer Details";
cout<<"\n ----------------------";
cout<<"\n\n Room no: ";
cout<<"\n Total no. of Rooms -50";
cout<<"\n Ordinary Rooms from 1 - 30";
cout<<"\n Elegant Rooms from 31 - 45";
cout<<"\n Royal Rooms from 46 - 50";
cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
cin>>r;

flag=check(r);

if(flag)
cout<<"\n Sorry..!!!Room is already booked";

else
{

room_no=r;
cout<<" Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone No: ";
cin>>phone;
cout<<" Aadhar No: ";
cin>>aadharnumber;
cout<<"People staying in the room: ";
cin>>ppl;
fout.write((char*)this,sizeof(hotel));
cout<<"\n Room is booked...!!!";

}

cout<<"\n Press any key to continue.....!!";

getch();
fout.close();

}


//END OF BOOKING FUNCTION


//FUNCTION FOR DISPLAYING A PURTICULAR CUSTOMER`S RECORD





void hotel::display()
{

  system("cls");

ifstream fin("Record.dat",ios::in);
int r,flag;

cout<<"\n Enter room no. for a particular customer`s details :- "<<endl;
cin>>r;

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

  system("cls");
cout<<"\n Customer Details";
cout<<"\n ----------------";
cout<<"\n\n Room no: "<<room_no;
cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Phone no: "<<phone;
cout<<"\n Aadhar No.: "<<aadharnumber;
cout<<"\n People in room: "<<ppl;
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant....!!";
cout<<"\n\n Press any key to continue....!!";

getch();
fin.close();
}


//END OF DISPLAY FUNCTION

//FUNCTION TO DISPLAY ALL ROOMS OCCUPIED


void hotel::rooms()
{

  system("cls");
//ifstream fin("Record.dat",ios::in); while((fin.read((char*)this,sizeof(hotel))) != NULL) fin.close();
ifstream fin("Record.dat",ios::in);
cout<<"\n\t\t\t    List Of Rooms Allotted";
cout<<"\n\t\t\t    ----------------------";
cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\t\tAadhar Number\tPeople In Room\n";

/*while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t\t\t"<<phone;
cout<<"\t\t\t"<<aadharnumber;

}*/
while((fin.read((char*)this,sizeof(hotel))) != NULL)
{
    cout<<"\n\n "<<room_no<<"\t\t"<<name;
cout<<"\t\t"<<address<<"\t\t\t\t"<<phone;
cout<<"\t\t\t"<<aadharnumber<<"\t\t\t"<<ppl;
}
cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
getch();
fin.close();

}


//FUNCTION FOR EDITING RECORDS AND FOR BILL


void hotel::edit()
{
system("cls");
int choice,r;
cout<<"\n EDIT MENU";
cout<<"\n ---------";
cout<<"\n\n 1.Modify Customer Record";
cout<<"\n 2.Delete Customer Record";
cout<<"\n 3. Bill Of Customer";
cout<<"\n Enter your choice: ";

cin>>choice;
  system("cls");

cout<<"\n Enter room no: " ;
cin>>r;

switch(choice)
{

case 1: modify(r);
break;

case 2: delete_rec(r);
break;

case 3: bill(r);
break;

default: cout<<"\n Wrong Choice.....!!";

}
cout<<"\n Press any key to continue....!!!";

getch();
}


int hotel::check(int r)
{

int flag=0;

ifstream fin("Record.dat",ios::in);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)
{

flag=1;
break;

}

}

fin.close();
return(flag);

}


//FUNCTION TO MODIFY CUSTOMERS RECORD


void hotel::modify(int r)
{

long pos,flag=0;

fstream file("Record.dat",ios::in|ios::out|ios::binary);

while(!file.eof())
{

pos=file.tellg();
file.read((char*)this,sizeof(hotel));

if(room_no==r)
{

cout<<"\n Enter New Details";
cout<<"\n -----------------";
cout<<"\n Name: ";
cin>>name;
cout<<" Address: ";
cin>>address;
cout<<" Phone no: ";
cin>>phone;
cout<<" Aadhar Number: ";
cin>>aadharnumber;
cout<<"People staying room: ";
cin>>ppl;
file.seekg(pos);
file.write((char*)this,sizeof(hotel));
cout<<"\n Record is modified....!!";
flag=1;
break;

}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}


//END OF MODIFY FUNCTION


//FUNCTION FOR DELETING RECORD


void hotel::delete_rec(int r)
{
int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(room_no==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<address;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}

}


//END OF DELETE FUNCTION


//FUNCTION FOR CUSTOMER`S BILL

void hotel::bill(int r)
{

hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.room_no == r)
  {

  if(h1.room_no>=1&&h1.room_no<=30)
  cout<<"your bill = 5000";

  else if (h1.room_no>=35&&h1.room_no<=45)
  cout<<"your bill = 8500" ;

  else
  cout<<"your bill = 12000";

  }

  else
  { cout<<"room no. not found";}

  }

  f1.close();
  getch();

}

void hotel::checkout(int r)
{


hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {



  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.room_no == r)
  {
    ofstream mifile ("feedback.txt");
    string b;
    system("cls");
    cout<<"Enter Your feedback: ";
    cin>>b;
    mifile<<b<<endl;
    mifile.close();

  if(h1.room_no>=1&&h1.room_no<=30)
  cout<<"your bill = 5000";

  else if (h1.room_no>=35&&h1.room_no<=45)
  cout<<"your bill = 8500" ;

  else
  cout<<"your bill = 12000";

  }

  else
  { cout<<"room no. not found";}

  }

  f1.close();
  getch();

}


class restro {
                public:
                int foodmanager();
             };
int restro::foodmanager()
    {
        string menu[500]={"Continental/ Fast Food","Gujarati","South Indian","Chinese","Punjabi","Deserts","Soup","Beverages","Appetizers","Diet Options","Classic cheese Pizza","Marghertia","7 Spice Pizza","Custom Pizza","Spicy Pasta","Cheese Pasta","Custom Pasta","Grilled Sandwich","Cheese Sandwich","Vegetable Sandwich","Paav Bhaji","Cheese Macroni","Regular Macroni","Custom Macroni","Classic Thali","Dhoklas","Methi Theplas","Daal Dhokli","Kadhi","Khandvi","Shaak Bhaaji","Daabeli","Simple Dosa","Cheese Dosa","Custom Dosa","Meduvadaa","Cheese Meguvadaa","Custom Meduvadaa","Idli","Utappam","Vadaa Sambhar","Sambhar","Fried Rice","Manchurian","Simple Noodles","hakka Noodles","Schezwan Noodles","ChauMin","Tofu","Spring roll","Sarso Ka saag","Makke Di Roti","Chole Bhature","Chanaa Masaala","Dhaba daal","Daal Makhni","Amristsari Kulcha","Kulcha","Paneer Tikka","Choco lava cake","Rasgulla","Gulab Jamoon","Custard","Kheer","Shri Khand","Mancahu soup","Tomato soup","Minestrone Soup","Noodle Soup","French Onion Soup","Creame Soup","Totellini Soup","Bread Soup","Sweet Corn Plain Soup","Manchurian Soup","Sweet Corn Soup","Simple Tea","Elachi Tea","Masala Tea","Cold Drink","Cappuccino","Mocha","Mocha","Black Coffee","Espresso","French fries","French fries with gravy","Sweet Potato","Onion Rings","Pub Chips","Garlic Bread","Fruit","Whole Grains","Nuts","Apple Cider Vinegar","Avocados","Cottage Cheese","Beans and Legumes","Tuna","Boiled Potatoes","Lean Beef and Chicken","Cruciferous Vegetables","Salmon","Leafy Greens","Whole Eggs"};
        int signalchoice[500]; //This variable will store what was ordered
        int counter;
        int dine=0;
        string billstring,line,mailid;
        for(counter=0;counter<500;counter++)
        {
            signalchoice[counter]=0;
        }
        counter=0;
        int calories[500]={0,0,0,0,0,0,0,0,0,0,(272*8),(250*8),830,2000,200,190,250,661,497,150,400,310,300,400,(141+97+76+84+447+84+68+115+197+231+135),190,155,120,100,250,134,185,100,200,150,200,270,290,79,110,145,90,(110*2),(270*2),211,(100+20+75),375,300,290,410,200,75,310,175,150,300,205,110,195,225,300,350,250,355,220,120,110,100,105,110,110,115,100,105,120,125,120,125,130,200,300,310,220,250,305,200,210,300,220,225,335,100,90,65,22,160,98,105,95,110,80,75,105,94,165};
       /* for(counter=0;counter<500;counter++)
        {
            calories[counter]=1000;
        }*/
        int mrp[500]={0,0,0,0,0,0,0,0,0,0,250,220,300,210,250,225,230,180,220,190,175,180,190,200,180,140,100,110,90,135,115,75,70,100,105,90,110,120,80,125,130,50,155,200,210,220,185,190,170,180,150,90,150,120,95,110,90,80,155,190,175,180,100,120,120,90,95,90,100,90,90,80,95,95,100,95,50,65,70,100,150,180,175,155,200,130,150,125,120,110,130,80,60,120,90,80,125,135,150,140,180,100,90,175,190};

        counter=0;
        int mailchoice=0,av,impinput,listing,pplcounter;
        int a,b,i=0,foodbill=0,totcalories=0;
        srand(time(NULL));
        pplcounter = 20+(rand()%21);

            while(i!=3)
            {
                //switch()
                theinitialmenu:
                system("cls");
                cout<<"\n\t\t\t\t\t*************************************";
                cout<<"\n\t\t\t\t\t        - Restaurant MANAGEMENT -";
                cout<<"\n\t\t\t\t\t*************************************";
                cout<<"\n\n\n\t\t\t\t\tNumber of people currently at restaurant: "<<pplcounter;
                cout<<"\n\n\n\n\t\t\t\t\t1. Order \n\t\t\t\t\t2.Print Bill\n\t\t\t\t\t3.Go Back"<<endl;
                cout<<"\t\t\t\t\tTotal Bill: ";
                cout<<"    "<<foodbill<<" Rs";
                cout<<"\n\t\t\t\t\tTotal Calories: "<<totcalories<<" cal";
                cout<<"\n\n\t\t\t\t\tEnter Choice: ";
                cin>>i;
                if(i==1)
                {
                    system("cls");
                    //roti is 5 and shabgi is 10
                    cout<<"\n\n\n\t\t\t\t\t Select you preferred place: \n\n\n\n\n\n\t\t\t\t\t1. Dine at restro\n\t\t\t\t\t2. Takeaway\n\t\t\t\t\t3. Home delivery (+100 Rs.)\n\t\t\t\t\tYour Selection : ";
                    cin>>dine;
                    system("cls");
                    label:
                        cout<<"\n\n\n\n\n\n\n\n\n\n";
                    for(counter=0;counter<10;counter++)
                    {
                        cout<<"\t\t\t\t\t";
                        cout<<(counter+1);
                        cout<<". ";
                        cout<<menu[counter];
                        cout<<"\n";
                    }
                    cout<<"\t\t\t\t\t11. Go Back";
                    cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                    cin>>a;
                    switch(a){
                    case 1 :
                            somelabel1:
                                system("cls");
                             cout<<"\n\n\n\n\t\t\t\t\t Continental/ Fast Food";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=10;counter<24;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                            if(impinput<1 || impinput>15)
                            {
                                goto somelabel1;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+9]++;
                            foodbill=foodbill+mrp[impinput+9];
                            totcalories=totcalories+calories[impinput+9];
                            goto somelabel1;
                            break;
                    case 2 :


                            somelabel2:
                                system("cls");
                             cout<<"\n\n\n\n\t\t\t\t\t Gujarati";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=24;counter<32;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                            if(impinput<1 || impinput>9)
                            {
                                goto somelabel2;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+23]++;
                            foodbill=foodbill+mrp[impinput+23];
                            totcalories=totcalories+calories[impinput+23];
                            goto somelabel2;
                            break;
                    case 3 :
                                somelabel3:
                                system("cls");
                             cout<<"\n\n\n\n\t\t\t\t\t South Indian";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=32;counter<42;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                            if(impinput<1 || impinput>11)
                            {
                                goto somelabel3;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+31]++;
                            foodbill=foodbill+mrp[impinput+31];
                            totcalories=totcalories+calories[impinput+31];
                            goto somelabel3;
                            break;
                    case 4 :
                                                        somelabel4:
                                system("cls");
                             cout<<"\n\n\n\n\t\t\t\t\t Chinese";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=42;counter<50;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                            if(impinput<1 || impinput>9)
                            {
                                goto somelabel4;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+41]++;
                            foodbill=foodbill+mrp[impinput+41];
                            totcalories=totcalories+calories[impinput+41];
                            goto somelabel4;
                            break;
                    case 5 :
                                                     somelabel5:
                                system("cls");
                             cout<<"\n\n\n\n\t\t\t\t\t Punjabi";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=50;counter<59;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                                                        if(impinput<1 || impinput>10)
                            {
                                goto somelabel5;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+49]++;
                            foodbill=foodbill+mrp[impinput+49];
                            totcalories=totcalories+calories[impinput+49];
                            goto somelabel5;
                            break;
                    case 6 :
                                                 somelabel6:
                                system("cls");
                                 cout<<"\n\n\n\n\t\t\t\t\t Deserts";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=59;counter<65;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                            if(impinput<1 || impinput>7)
                            {
                                goto somelabel6;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+58]++;
                            foodbill=foodbill+mrp[impinput+58];
                            totcalories=totcalories+calories[impinput+58];
                            goto somelabel6;
                            break;
                    case 7 :
                                           somelabel7:
                                system("cls");
                             cout<<"\n\n\n\n\t\t\t\t\t Soup";
                            cout<<"\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=65;counter<76;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                                                        if(impinput<1 || impinput>12)
                            {
                                goto somelabel7;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+64]++;
                            foodbill=foodbill+mrp[impinput+64];
                            totcalories=totcalories+calories[impinput+64];
                            goto somelabel7;
                            break;
                    case 8 :
                                     somelabel8:
                                system("cls");
                                 cout<<"\n\n\n\n\t\t\t\t\t Beverages";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=76;counter<85;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                                                        if(impinput<1 || impinput>10)
                            {
                                goto somelabel8;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+75]++;
                            foodbill=foodbill+mrp[impinput+75];
                            totcalories=totcalories+calories[impinput+75];
                            goto somelabel8;
                            break;
                    case 9 :
                                 somelabel9:
                                system("cls");
                             cout<<"\n\n\n\n\t\t\t\t\t Appetizers";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=85;counter<91;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                                                        if(impinput<1 || impinput>7)
                            {
                                goto somelabel9;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+84]++;
                            foodbill=foodbill+mrp[impinput+84];
                            totcalories=totcalories+calories[impinput+84];
                            goto somelabel9;
                            break;
                    case 10:
                            somelabel10:
                                system("cls");
                            cout<<"\n\n\n\n\t\t\t\t\t Diet Options";
                            cout<<"\n\n\n\n\n\n";
                            av=1;
                            cout<<"\t\t\t\t\t  ";
                            cout<<"           Item name";
                            cout<<"                MRP       Calories";
                            cout<<"\n\t\t\t\t\t********************************************************";
                            cout<<"\n";
                            for(counter=91;counter<105;counter++)
                            {
                                cout<<"\t\t\t\t\t";
                                cout<<setw(3)<<left<<(av);
                                cout<<". ";
                                cout<<setw(30)<<left<<menu[counter];
                                cout<<"-  ";
                                cout<<setw(13)<<mrp[counter];
                                cout<<calories[counter];
                                cout<<"\n";
                                av++;
                            }
                            cout<<"\t\t\t\t\t";
                            cout<<setw(3)<<left<<av;
                            cout<<". Go back\n\t\t\t\t\t";
                            cout<<"\n\t\t\t\t\tTotal Bill yet:"<<foodbill<<endl;
                            cout<<"\n\t\t\t\t\tTotal Calories yet:"<<totcalories<<endl;
                            cin>>impinput;
                                                        if(impinput<1 || impinput>15)
                            {
                                goto somelabel10;
                            }
                            if(impinput==av)
                            {
                                system("cls");
                                goto label;
                            }
                            signalchoice[impinput+90]++;
                            foodbill=foodbill+mrp[impinput+90];
                            totcalories=totcalories+calories[impinput+90];
                            goto somelabel10;
                            break;

                    case 11:
                        goto theinitialmenu;
                    }
                }

                if(i==2)
                {
                    system("cls");
                    ofstream myfile ("bill.txt");
                    listing=0;
                    myfile<<"\n\t\t\t\t\t*************************************";cout<<"\n\t\t\t\t\t*************************************";
                    myfile<<"\n\t\t\t\t\t-         Printed Bill               -";cout<<"\n\t\t\t\t\t-         Printed Bill               -";
                    myfile<<"\n\t\t\t\t\t*************************************\n\n\n";cout<<"\n\t\t\t\t\t*************************************\n\n\n";
                    myfile<<"\t\t\t\t\t           Item name";cout<<"\t\t\t\t\t           Item name";
                          myfile<<"                MRP         Calories";cout<<"                MRP         Calories";
                            myfile<<"\n\t\t\t\t\t********************************************************";cout<<"\n\t\t\t\t\t********************************************************";
                            myfile<<"\n";cout<<"\n";
                    for(counter=0;counter<500;counter++)
                    {

                        for(av=0;av<signalchoice[counter];av++)
                        {
                            listing++;
                            myfile<<"\n\t\t\t\t\t";cout<<"\n\t\t\t\t\t";
                            myfile<<setw(3)<<left<<listing;cout<<setw(3)<<left<<listing;
                            myfile<<". ";cout<<". ";
                            myfile<<setw(30)<< left<< menu[counter];cout<<setw(30)<< left<< menu[counter];
                            myfile<<" ";cout<<" ";
                            myfile<<setw(14)<<left<<mrp[counter];cout<<setw(14)<<left<<mrp[counter];
                            myfile<<calories[counter];cout<<calories[counter];
                        }
                    }
                    if(dine==3)
                        {
                          myfile<<"\n\t\t\t\t\t"<<(listing+1)<<" . "<<"Home Delivery Charge           100";cout<<"\n\t\t\t\t\t"<<(listing+1)<<" . "<<"Home Delivery Charge           100";
                          foodbill= foodbill+100;
                        }
                     myfile<<"\n\t\t\t\t\t********************************************************\n\t\t\t\t\t";cout<<"\n\t\t\t\t\t********************************************************\n\t\t\t\t\t";
                     myfile<<setw(33)<<left<<"Total Price:";cout<<setw(33)<<left<<"Total Price:";
                     myfile<<"   "<<foodbill;cout<<"   "<<foodbill;
                     myfile<<"+18%GST= "<<((1.18*foodbill)- 18)<<" Rs";cout<<"+18%GST= "<<((1.18*foodbill)- 18)<<" Rs";
                     myfile<<"\n\n\t\t\t\t\t"; cout<<"\n\n\t\t\t\t\t";
                     myfile<<setw(33)<<left<<"Total Calories:";cout<<setw(33)<<left<<"Total Calories:";
                     myfile<<"                 "<<totcalories<<" cal";cout<<"                 "<<totcalories<<" cal";
                     cout<<"\n\n\n\t\t\t\t\tPRESS 1. TO GET THE BILL IN MAIL FORMAT OR ANY OTHER KEY TO SKIP...";
                     myfile.close();
                     cin>>mailchoice;
                     ifstream myfilye ("bill.txt");
                     while ( getline (myfilye,line) )
                        {
                          billstring+= line;
                          billstring+= "\n";
                        }
                        myfilye.close();
                     if(mailchoice==1)
                     {


                        cout<<"\n\t\t\t\t\tEnter your email id: ";
                        cin>>mailid;
                        cout<<"\n\t\t\t\t\tSending...";
                        ofstream file;
                        file.open("test.ps1");
                        string powershell;
                        powershell = "$EmailFrom = \"19it055@charusat.edu.in\"\n";
                        powershell += "$EmailTo = \"";
                        powershell += mailid;
                        powershell += "\"\n";
                        powershell += "$Subject = \"Alpine Resort FoodBill\"\n";
                        powershell += "$Body = \"";
                        powershell += billstring ;
                        powershell +="\"\n";
                        powershell += "$SMTPServer = \"smtp.gmail.com\"\n";
                        powershell += "$SMTPClient = New-Object Net.Mail.SmtpClient($SmtpServer, 587)\n";
                        powershell += "$SMTPClient.EnableSsl = $true\n";
                        powershell += "$SMTPClient.Credentials = New-Object System.Net.NetworkCredential(\"19it055@charusat.edu.in\", \"iamfarhankhatri\");\n";
                        powershell += "$SMTPClient.Send($EmailFrom, $EmailTo, $Subject, $Body)\n";
                        file << powershell << endl;
                        file.close();

                        system("powershell -ExecutionPolicy Bypass -F test.ps1");

                       remove("test.ps1");
                       cout<<"\n\t\t\t\t\tDone..";
                        cout<<"\n\t\t\t\t\t press any key to continue";                    }
                    getch();
                }
            }
            return 0;
    }

int main()
    {
    startagain:
    int alpha;
        system("cls");
        cout<<"\n\t\t\t\t\t*************************************";
        cout<<"\n\t\t\t\t\t        - HOTEL MANAGEMENT -";
        cout<<"\n\t\t\t\t\t*************************************";
        cout<<"\n\n\n\n\t\tDEVELOPED BY:";
        cout<<"\n\n\n\t\t\t\t\tDrashti Jhaveri and Farhan Khatri ";
        cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
        getch();
        system("cls");
        cout<<"\n\t\t\t\t\t**************************************";
        cout<<"\n\t\t\t\t\t     - ALPINE RESORT MANAGEMENT -";
        cout<<"\n\t\t\t\t\t**************************************";
        cout<<"\n\n\n\t\t\t\t\t1. Hotel Management\n\t\t\t\t\t2. Restaurant Management\n\t\t\t\t\tYour Selection: ";
        cin>>alpha;
    if(alpha==1)
    {   //HOTEL MANAGEMENT STARTS FROM HERE
        system("cls");
        hotel h;
        h.main_menu();
        return 0;
    //HOTEL MANAGEMENT ENDS HERE
    }
    else

        {   if(alpha==2)
        {
                //FOOD MANAGEMENT STARTS FROM HERE
                restro f;
                f.foodmanager();
                system("cls");
                goto startagain;
                //FOOD MANAGEMENT ENDS HERE
                }
        else{cout<<"\n\n\n\t\t\t\t\tInvalid Input\n\t\t\t\t\tPress any key to restart.....";
            getch();
        system("cls");
        goto startagain;}
        }
    }

//END OF MAIN PROGRAM

