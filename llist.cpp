/*****************************************************************
//  NAME:        Cole House
//
//  HOMEWORK:    Project 2 
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 24, 2021
//
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   This file contains the conctructor and destrucotrs for the llist class.
//   Along with the database function definitions.
****************************************************************/
#include "record.h"
#include "llist.h"
#include <iostream>
#include <assert.h>
#include <string.h>
#include <fstream>
/*****************************************************************
//  Function name: llist()
//  //
//  //  DESCRIPTION:   Constructor for llist class that takes no paramaters.
//  //                 Sets up initial variables of class and calls readfile
****************************************************************/
llist::llist()
{
    #ifdef DEBUG
    std::cout << "*DEBUG* llist constructor called." <<std::endl;
    #endif
    start = NULL;
    char const thisName[16] = "recordFile.txt";
    assert(strlen(thisName) < sizeof(filename));
    strcpy(filename, thisName);
    readfile();
}
/*****************************************************************
//  Function name: llist (char [])
//
//  DESCRIPTION:   Constructor for the linked list that takes in char [] for filename
//
//  Parameters:    fname (char []) : initial file name given
****************************************************************/
llist::llist(char fname[])
{
    #ifdef DEBUG
    std::cout << "*DEBUG* llist() constructor called with paramaters: "<< fname <<std::endl;
    #endif
    start = NULL;
    assert(strlen(fname) < sizeof(filename));
    strcpy(filename, fname);
    readfile();
}
/*****************************************************************
//  Function name: ~llist()
//
//  DESCRIPTION:   A deconstructor for the linked list of records
//                 calls the writefile and clenup functions.
****************************************************************/
llist::~llist()
{
    #ifdef DEBUG
    std::cout << "*DEBUG* llist deconstructor called." <<std::endl;
    #endif
    writefile();
    cleanup();
}

/*****************************************************************
//  Function name: addRecord
//
//  DESCRIPTION:   A bank database function
//                 Adds a record to database with appropriate parameters.
//    
//  PARAMETERS :   acc (int) : account Number to be added to the record.
//                 name (char []) : name for record.
//                 address (char []) : address for record
//
//  Return values:  0 : successfully added record.
//                  -1 : failed to add record.
//                 
****************************************************************/
int llist::addRecord(int accNo, char name[], char address[])
{
    int cont = 0;
    int result = 0;
    struct record * temp = this->start;
    struct record * newRecord;
    #ifdef DEBUG
    std::cout << " *DEBUG* addRecord() called with parameter:" << accNo << ", "<< name << ", " << address<<std::endl;
    #endif
    while (cont == 0)
    {
        if ( temp == NULL )
        {
            newRecord = new struct record;
            newRecord->accountno = accNo;
            strcpy(newRecord->name, name);
            strcpy(newRecord->address, address);
            newRecord->next = temp;
            this->start = newRecord;
            std::cout << "Record added." <<std::endl;
            cont = 1;
        }
        else if (temp != NULL && accNo == temp->accountno)
        {
            result = -1;
            std::cout << "Record not added because of duplicate account #" <<std::endl;
            cont = 1;
        }
        else if (temp != NULL && accNo > temp->accountno)
        {
            newRecord = new struct record;
            newRecord->accountno = accNo;
            strcpy(newRecord->name, name);
            strcpy(newRecord->address, address);
            newRecord->next = temp;
            this->start = newRecord;
            std::cout << "Record added." <<std::endl;
            cont = 1;
        }
        else
        {
            while (temp->next != NULL && temp->next->accountno >= accNo)
            {
                if (accNo == temp->next->accountno)
                {
                    result = -1;
                    std::cout << "Record not added because of duplicate account #" <<std::endl;
                    cont = 1;
                }
                temp = temp->next;
            }
            newRecord = new struct record;
            newRecord->accountno = accNo;
            strcpy(newRecord->name, name);
            strcpy(newRecord->address, address);
            newRecord->next = temp->next;
            temp->next = newRecord;
            std::cout << "Record added." <<std::endl;
            cont = 1;           
        }
    }
    temp = NULL;
    newRecord = NULL;
    return result;   
}
/*****************************************************************
//  Function name: printAllRecords
//
//  DESCRIPTION:   A bank database function
//                 This function prints all the records in the databse
//
//  Parameters:    N/A                    
//
//   Return values:  void
//            
****************************************************************/
void llist::printAllRecords()
{
    int thisAccNo;
    char thisName[25];
    char thisAddress[50];
    struct record *temp = this->start;
    #ifdef DEBUG
    std::cout << "*DEBUG* printAllRecords() called." <<std::endl;
    #endif
    if (this->start == NULL)
    {
        std::cout << "Empty List." <<std::endl;
    }   
    else
    {
         while (temp != NULL)
         {
             if (temp->next == NULL)
             {
                 thisAccNo = temp->accountno;
                 strcpy(thisName, temp->name);
                 strcpy(thisAddress, temp->address);
                 std::cout << "Record:" <<std::endl;
                 std::cout << "accountno: "<< thisAccNo <<std::endl;
                 std::cout << "name: "<< thisName <<std::endl;
                 std::cout << "address:" <<std::endl;
                 std::cout << thisAddress <<std::endl;
             }
             else
             {
                 thisAccNo = temp->accountno;
                 strcpy(thisName, temp->name);
                 strcpy(thisAddress, temp->address);
                 std::cout << "Record:" <<std::endl;
                 std::cout << "accountno: "<< thisAccNo <<std::endl;
                 std::cout << "name: "<< thisName <<std::endl;
                 std::cout << "address:" <<std::endl;
                 std::cout << thisAddress <<std::endl;
             }
             temp = temp->next;
         }
    }
}
/*****************************************************************
//  Function name: findRecord
//
//  DESCRIPTION:   A bank database function
//                 finds a record from database with appropriate parameters.
//
//  Parameters:    acc (int) : account number to be found.
//
//  Return values:  0 : successfully found.
//                  -1 : failed to find.
//                 
****************************************************************/
int llist::findRecord(int accNo)
{
    int result , cont;
    struct record * temp;
    struct record * printThis;
    result = 0;
    cont = 0;
    temp = this-> start;
    #ifdef DEBUG
    std::cout << "*DEBUG* findRecord() called with parameter: "<< accNo <<std::endl;
    #endif
    while (cont == 0)
    {
         if (temp == NULL)
         {
             result = -1;
             std::cout << "List is empty" <<std::endl;
             cont = 1;
         }
         else if (temp->accountno == accNo)
         {
             printThis = temp->next;
             std::cout << "Record:" <<std::endl;
             std::cout << "accountno: "<< printThis->accountno <<std::endl;
             std::cout << "name: "<< printThis->name <<std::endl;
             std::cout << "address:" <<std::endl;
             std::cout << printThis->address <<std::endl;
             cont = 1;
         }
         else
         {
              while (temp->next != NULL && temp->next->accountno != accNo)
              {
                  temp = temp->next;
              }
              if (temp->next == NULL)
              {
                  result = -1;
                  std::cout << "List does not contain record with indicated account #" <<std::endl;
                  cont = 1;
              }
              else if (temp->next->accountno == accNo)
              {
                  std::cout << "Record:" <<std::endl;
                  std::cout << "accountno: "<< printThis->accountno <<std::endl;
                  std::cout << "name: "<< printThis->name <<std::endl;
                  std::cout << "address:" <<std::endl;
                  std::cout << printThis->address <<std::endl;
                  cont = 1;
              }
         }
    }
    temp = NULL;
    printThis = NULL;
    return result;   
}
/*****************************************************************
//  Function name: deleteRecord
//
//  DESCRIPTION:   A bank database function
//                 deletes a record from database with appropriate parameters.
//
//  Parameters:    acc (int) : account number.
//
//  Return values:  0 : successfully deleted.
//                  -1: failed to delete.                 
****************************************************************/
int llist::deleteRecord(int accNo)
{
    int result = 0;
    int cont = 0;
    struct record * temp;
    struct record * deleteThis;
    temp = this->start;
    #ifdef DEBUG
    std::cout << "*DEBUG* deleteRecord() called with parameter: "<< accNo <<std::endl;
    #endif
    while (cont == 0)
    {
        if (temp == NULL)
        {
            result = -1;
            std::cout << "List is empty" <<std::endl;
            cont = 1;
        }
        else if (temp->accountno == accNo)
        {
            this->start = temp->next;
            delete temp;
            std::cout << "Record was deleted" <<std::endl;
            cont = 1;
        }
        else
        {
            while (temp->next != NULL && temp->next->accountno != accNo)
            {
                temp = temp->next;           
            }
            if (temp->next == NULL)
            {
                result = -1;
                std::cout << "List does not contain record with indicated account #" <<std::endl;
                cont = 1;
            }
            else if (temp->next->accountno == accNo)
            {
                deleteThis = temp->next;
                temp->next = deleteThis->next;
                delete deleteThis;
                std::cout << "Record was deleted" <<std::endl;
                cont = 1;   
            }
        }
    }
    temp = NULL;
    deleteThis = NULL;
    return result;
}
/*****************************************************************
//  Function name: writefile
/
//  DESCRIPTION:   A bank database function
//                 writes records from linked list to specified text file.
//
//  Return values:  0 : success.
//                  -1 : failure to write.
// 
****************************************************************/
int llist::writefile()
{
    int thisAccNo, result, cont;
    char thisName[25];
    char thisAddress[50];
    struct record* temp = this->start;
    result = 0;
    cont = 0;
    std::ofstream myFile;
    myFile.open(this->filename);
    #ifdef DEBUG
    std::cout << "*DEBUG* writefile() called" <<std::endl;
    #endif
    while (cont == 0)
    {
        if (myFile.is_open())
        {
            if (start == NULL)
            {
                result = -1;
                cont = 1;
            }  
            else
            {
                while (temp != NULL)
                {
                    if (temp->next == NULL)
                    {
                        thisAccNo = temp->accountno;
                        strcpy(thisName, temp->name);
                        strcpy(thisAddress, temp->address);
                        myFile << thisAccNo << std::endl;
                        myFile << thisName << std::endl;
                        myFile << thisAddress;
                        myFile << ";" << std::endl;
                    }
                    else 
                    {
                        thisAccNo = temp->accountno;
                        strcpy(thisName, temp->name);
                        strcpy(thisAddress, temp->address);
                        myFile << thisAccNo << std::endl;
                        myFile << thisName << std::endl;
                        myFile << thisAddress;
                        myFile << ";" << std::endl;
                    }
                    temp = temp->next;
                }
            }
            myFile.close();
            cont = 1;           
        }
        else
        {
            result = -1;
            cont = 1;
        } 
    }
    return result;
}
/*****************************************************************
//   Function name: readfile
// 
//   DESCRIPTION:   A bank database function
//                 reads from textfile and adds records to linked list.
//
//   Return values:  0 : success.
//                   -1 : failure to read.
//  
****************************************************************/
int llist::readfile()
{
    int thisAccNo, result, cont;
    char thisName[25];
    char thisAddress[50];
    result = 0;
    cont = 0;
    std::ifstream myFile;
    myFile.open(this->filename);
    #ifdef DEBUG
    std::cout << "*DEBUG* readfile() called" <<std::endl;
    #endif
    while (cont == 0)
    {
        if (myFile.is_open())
        {
            while ( myFile >> thisAccNo )
            {
                myFile.ignore(25, '\n');
                myFile.getline(thisName, 25, '\n');
                myFile.getline(thisAddress, 50, ';');
                myFile.ignore(25,'\n');
                addRecord(thisAccNo, thisName, thisAddress);
            }
            myFile.close();
            cont = 1;       
        }
        else
        {
            result = -1;
            cont = 1;
        }
    }
    return result;
}
/*****************************************************************
//   Function name: cleanup
// 
//   DESCRIPTION:   A bank database function
//                  releases all allocated spaces on heap and assigns NULL to start.
//
//   Return values:  void.
//                     
****************************************************************/
void llist::cleanup()
{
    struct record * temp;
    struct record * deleteThis;
    temp = this->start;
    #ifdef DEBUG
    std::cout << "*DEBUG* cleanup() called" <<std::endl;
    #endif
    while (temp != NULL)
    {
        deleteThis = temp;
        temp = temp->next;
        delete deleteThis;
    }
    this->start = NULL;
}



