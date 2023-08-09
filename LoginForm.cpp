#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout<<"\n\n\n";
    cout<<"\n\t\t\t _____________________________________________________________________________";
    cout<<"\n\t\t\t|                                  LOGIN FORM                                 |";
    cout<<"\n\t\t\t|--------------------------------------Menu-----------------------------------|";     
    cout<<"\n\t\t\t|_____________________________________________________________________________|";
    cout<<"\n\t\t\t| Press 1 to Login                                                            |";
    cout<<"\n\t\t\t|                                                                             |";
    cout<<"\n\t\t\t| Press 2 to Registration                                                     |";
    cout<<"\n\t\t\t|                                                                             |";
    cout<<"\n\t\t\t| Press 3 to Forgot if you forgot your password                               |";
    cout<<"\n\t\t\t|                                                                             |";
    cout<<"\n\t\t\t| Press 4 Exist                                                               |";
    cout<<"\n\t\t\t|                                                                             |";
    cout<<"\n\t\t\t|_____________________________________________________________________________|";
    cout<<"\n\n\t\t\t Please enter your choice:   ";
    cin>>c;
    cout<<endl;

    switch(c)
    {
    case 1:
         login();
         break;

    case 2:
         registration();
         break;

    case 3:
        forgot();
        break;

    case 4:
        cout<<"\t\t\t\t\t-----------------Thank You!-------------------------";
        break;

    default:    
        system("cls");
        
        cout<<"\n\n\t\t\t     Please select option from given below";
        main();

    }
    
}

void login()
{
    int count=0;
    string userId,password,pass,id;
    system("cls");
    cout<<"\t\t\t Please enter user name and password: "<<endl;
    cout<<"\n\t\t\tUSERNAME:  ";
    cin>>userId;
    cout<<"\n\t\t\tPASSWORD:  ";
    cin>>password;

    ifstream input("record.txt");
    while(input>>id>>pass)
    {
        if(id==userId && pass==password)
        {
            count=1;
            system("cls");
        }
    }
   input.close();

   if(count==1)
   {
    cout<<"\n\n\t\t\t\t\t\t"<<userId<<" your LOGIN is Successfull..\n\n\t\t\t\t\t\t Thank you for logging in ! \n";
   }
   else{
    cout<<"\n\n\t\t\t\t\t\t\t Login Error! \n\n\t\t\t\t\t\tPlease check your username and password...\n";
   }
 
   main();
}

void registration()
{
    string ruserId,rpassword;
    system("cls");
    cout<<"\t\t\t Enter the Username:  ";
    cin>>ruserId;
    cout<<"\t\t\t Enter the Password:  ";
    cin>>rpassword;

    ofstream f1("record.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\n\t\t\t Registration is Successful..";
    main();

}

void forgot()
{
    int choice;
    system("cls");
        cout<<"\n\t\t-------------------------------------------------------";
        cout<<"\n\t\t\tYou forgot the answer? No worry \n";
        cout<<"\n\t\t-------------------------------------------------------";   
        cout<<"\n\n\t\t\tPress 1 to search id by username";
        cout<<"\n\n\t\t\tPress 2 to go back to your main menu";
        cout<<"\n\n\n\t\t\tEnter your choice : ";
      cin>>choice;

    switch (choice)
    {
    case 1:
         {
            int count=0;
           string suserId,sId,spass;
           cout<<"\n\t\t   Enter your username :  ";
           cin>>suserId;
          
           ifstream f2("record.txt");
           while(f2>>sId>>spass)
           {
            if(sId==suserId)
            {
                count=1;
                break;
            }
           }
            f2.close();
             
             if(count==1)
             {  cout<<"\n\t\t\t\t---------------------------------------------";
                cout<<"\n\t\t\t\t\t Your account is found !";
                cout<<"\n\n\t\t\t\t\tYour password is "<<spass;
                cout<<"\n\t\t\t\t---------------------------------------------";
                main();

             }
             else{
                cout<<"\n\t\t\t\t---------------------------------------------";
                cout<<"\n\t\t\t\t   Sorry !  Your account is not found !";
                cout<<"\n\t\t\t\t---------------------------------------------";
                main();

             }
        break;
         }

       case 2:{
            main();
       }
       default:
           cout<<"\n\t\t\t Wrong choice ! Please choose again !";
           forgot();
             
    }

}
