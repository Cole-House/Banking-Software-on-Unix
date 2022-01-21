/*****************************************************************
//  NAME:        Cole House
  //
  //  HOMEWORK:    3b
  //
  //  CLASS:       ICS 212
  //
  //  INSTRUCTOR:  Ravi Narayan
  //
  //  DATE:        September 25, 2021
  //
  //  FILE:        record.h
  //
  //  DESCRIPTION:
  //   a bank account record of struct data type
****************************************************************/
struct record
{
    int                accountno;
    char               name[25];
    char               address[50];
    struct record*     next;
}
;
