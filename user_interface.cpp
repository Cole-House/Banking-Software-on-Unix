/*********************************************************
//  NAME: Cole House
//
//  HOMEWORK: project 2
//
//  CLASS: ICS 212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE: November 18, 2021
//
//  FILE: user_interface.cpp
//
//  DESCRIPTION: user interface for bank database program.
***********************************************************/
#include <iostream>
#include <iomanip>
#include "record.h"
#include "llist.h"
#include <string.h>
#include <string>

int getAccountNumber();
void getAddress(char *str, int size);

int main (int argc, char * argv[])
{
    char choice[25], junk[25], name[25], address[50];
    char addOpt[4] = "add";
    char printOpt[9] = "printall";
    char findOpt[5] = "find";
    char deleteOpt[7] = "delete";
    char quitOpt[5] = "quit";
    int accNo, i, x=0;
    int choiceLen;
    int valid;
    llist myList;

    std::cout << "Hello this is the user interface for the bank database program!" <<std::endl;
    std::cout << "Here are the menu options:" <<std::endl;
    std::cout << "    add :Add a new record in database" <<std::endl;
    std::cout << "    printall : Print all records in database" <<std::endl;
    std::cout << "    find :Find record with a specified account #" <<std::endl;
    std::cout << "    delete :Delete existing record with a specified account #" <<std::endl;
    std::cout << "    quit : quits program" <<std::endl;

    while (x==0)
    {
        strcpy(choice, " ");
        strcpy(junk, " ");
        std::cout << "Please specify which action you want to perform:";
        std::cin >> choice;
        std::cin.ignore(25, '\n');
        choiceLen = strlen(choice);
        if ( choice[0] == addOpt[0] && choiceLen <= 3)
        {
            valid = 1;
            for(i = 0; i < choiceLen; i++)
            {
                if(choice[i] != addOpt[i])
                {
                    valid = 0;
                    i = choiceLen + 1;
                }
                else
                    valid = 1;
           }
           if (valid == 1)
           {
               std::cout << "[ADD] Now please enter your name:"<<std::endl;
               std::cin.getline(name, 25, '\n');
               accNo = getAccountNumber();
               std::cin.ignore(25, '\n');
               getAddress(address,50);
               myList.addRecord(accNo, name, address);
           }
           else
           {
               std::cout << "Invalid Input!" <<std::endl;
               x = 0;
           }
        }
        else if ( choice[0] == printOpt[0] && choiceLen <= 8 )
        {
            valid = 1;
            for ( i = 0; i < choiceLen; i++ )
            {
                if (choice[i] != printOpt[i] )
                {
                    valid = 0;
                    i = choiceLen + 1;
                }
                else 
                    valid = 1;
            }
            if (valid ==1)
            {
                myList.printAllRecords();
            }
            else
            {
                std::cout << "Invalid Input!" <<std::endl;
                x = 0;
            }
        }
        else if (choice[0] == findOpt[0] && choiceLen <= 4)
        {
            valid = 1;
            for(i = 0; i < choiceLen; i++)
            {
                if(choice[i] != findOpt[i])
                {
                    valid = 0;
                    i = choiceLen + 1;
                }
                else
                    valid = 1;
            }
            if (valid == 1)
            {
                accNo = getAccountNumber();
                myList.findRecord(accNo);
                accNo = 0;
            }
            else
            {
                std::cout << "Invalid Input!" <<std::endl;
                x = 0;
            }
        }
        else if ( choice[0] == deleteOpt[0] && choiceLen <= 6)
        {
            valid = 1;
            for(i = 0; i < choiceLen; i++)
            {
                if(choice[i] != deleteOpt[i])
                {
                    valid = 0;
                    i = choiceLen + 1;
                }
                else
                    valid = 1;
            }
            if (valid == 1)
            {
                accNo = getAccountNumber();
                myList.deleteRecord(accNo);
                accNo = 0;
            }
            else
            {
                std::cout << "Invalid Input!" <<std::endl;
                x = 0;
            }
        }
        else if ( choice[0] == quitOpt[0] && choiceLen <= 4)
        {
            valid = 1;
            for(i = 0; i < choiceLen; i++)
            {
                if(choice[i] != quitOpt[i])
                {
                    valid = 0;
                    i = choiceLen + 1;
                }
                else
                    valid = 1;
            }
            if (valid == 1)
            {
                /*writefile(start, "recordList.txt");
                 cleanup(&start);*/
                x = 1;
            }
            else
            {
                std::cout << "Invalid Input!" <<std::endl;
                x = 0;
            }
        }
        else
            std::cout << "Invalid Input!" <<std::endl;       
    }
    return 0;
}
/******************************************************************
//  Function name : getAccountNumber
//
//  Decscription : function obtains value of account # from user
//
//  Parameters: N/A
//
//  Return Values : usierInput (int): valid account number
******************************************************************/
int getAccountNumber()
{   
    int x = 0;
    int userInput = -100;

    while (x == 0)
    {
        std::cout << "Enter a valid positive account number for the record: ";
        std::cin >> userInput;
        if ( userInput == -100 || userInput < 0 )
            std::cout<< "Invalid Input. Please insert an integer." <<std::endl;
        else
            x = 1;
    }
    return userInput;    
}

/******************************************************************
//  Function name: getAddress
//
//  Description : function obtains the address of the user
//
//  Parameters: str (char []) : array from main function that will take input
//              size (int) : size of char array being passed in
//
//  Return values: void
*******************************************************************/
void getAddress(char str[], int size)
{
    char thisAddress[50];
    std::cout<< "Enter your address (it is OK to use multiple lines) when done enter ';' and press [ENTER] key:"<<std::endl;
    std::cin.getline(thisAddress, 50, ';' );
    std::cin.ignore(25, '\n');
    strcpy(str, thisAddress);
}









