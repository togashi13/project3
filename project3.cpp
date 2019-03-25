#include <iostream>
#include <cstdlib>
using namespace std;
#include "const_proj3.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "Encryptor.h"
#include "printMenu.h"
#include "checkValidInput.h"
//{}header

//Do we need to consider it being other type: setRow, setCol.

//I guess from the name of the function and variable, it should be 
//that we store the RGB value of the given location in outColor, 
//but in p2specs it says: "the output parameter "outColor" is assigned
//to the color of the image pixel at that location." 
//I'm not sure about the "be assigned to" phrase.






int main(int argc, char const *argv[])
{  
   if (argc != 2)
   {
      cout << "Usage: ./project3.exe <startPPM.ppm>" << endl;
      exit (2);
   }
   string fileName;
   int sRow;
   int sCol;
   int choice;
   bool validInputFound = false;
   cout << "Reading initial image from: " << argv[1] << endl;
   ColorImageClass testImage;
   Encryptor testEnc;
   if (testImage.readInImage(argv[1]))
   {
      cout <<  "Image read successful: Yes" << endl;
   }else
   {
      cout << "Image read successful: No" << endl;
      cout << "Error: While reading the image, an error was encountered." <<
       " Exiting the program!" << endl;
      exit(3);
   }


   checkValidInput(validInputFound, choice);

   while (choice != 4)
   {
      if (choice == 1)
      {  
         checkValidInput(validInputFound, fileName, sRow, sCol);

         if (testEnc.readInMessage(fileName))
         {

            if (testEnc.encodeImage(testImage, sRow, sCol))
            {
               cout << "Message encode successful: Yes" << endl;
            }else {
               cout << "Message encode successful: No" << endl;
            }

         }else{
            cout << "Message encode successful: No" << endl;
         }

         

      }

      else if (choice == 2)
      {
         testEnc.decodeImage(testImage);
         cout << "Image modified to decoded image contents" << endl;

      }

      else if (choice == 3)
      
      {
         if (testImage.outputFile())
         {  
            cout << "Image write successful: Yes" << endl;
         } 
         else
         {
            cout << "Image write successful: No" << endl;
         }
      }
      checkValidInput(validInputFound, choice);
   }
   cout << "Thanks for using this program!" << endl;
   return 0;
}






