#include <iostream>
#include <fstream>

using namespace std;

#include "checkValidInput.h"
#include "printMenu.h"
#include "const_proj3.h"

void checkValidInput(int validInputFound, int &choice)
{
   while (!validInputFound)
   {
      printMenu();
      cin >> choice;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(DEFAULT_CONSUME, '\n');
         cout << "Fail state! Please refer to user menu and try again" << endl; 
      }else if (choice < 1 || choice > 4)
      {
         cout << "Invalid choice! Please refer to user menu and try again" << endl; 
      }else{
         validInputFound = true;
      }
   }
}


void checkValidInput(int validInputFound, string &fileName, int &sRow, int &sCol)
{
   while (!validInputFound)
   {
      cout << "Enter name of file containing message: ";
      cin >> fileName;
      cout << "Enter row and column for message placement: ";
      cin >> sRow >> sCol;
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(DEFAULT_CONSUME, '\n');
         cout << "Error: Please enter a string and two integers" << endl; 
      }else{
         validInputFound = true;
      }
   }
}


