#include <iostream>
#include <fstream>
using namespace std;

#include "const_proj3.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "Encryptor.h"


Encryptor::Encryptor()
{
   message = 0;
   mRows = 0;
   mCols = 0;
}


Encryptor::~Encryptor()
{
    for (int r = 0; r < mRows; r++)
    {
        delete [] message[r];
    }
    delete [] message;
    message = 0;
}


void Encryptor::setEven(int &val)
{
   if (val % 2 == 1)
   {
      val -= 1;
   }
}

void Encryptor::setOdd(int &val)
{
   if (val % 2 == 0)
   {
      val += 1;
   }
}

void Encryptor::encodePixel(ColorClass &pixel, int colorValue)
{
   if (colorValue == 0)
   {
      pixel.setTo(setEven(red), setEven(green), setEven(blue));
   }else if(colorValue == 1){
      pixel.setTo(setOdd(red), setEven(green), setEven(blue));
   }else if(colorValue == 2){
      pixel.setTo(setEven(red), setOdd(green), setEven(blue));
   }else if(colorValue == 3){
      pixel.setTo(setEven(red), setEven(green), setOdd(blue));
   }else if(colorValue == 4){
      pixel.setTo(setOdd(red), setOdd(green), setOdd(blue));
   }else if(colorValue == 5){
      pixel.setTo(setOdd(red), setOdd(green), setEven(blue));
   }else if(colorValue == 6){
      pixel.setTo(setOdd(red), setEven(green), setOdd(blue));
   }else if(colorValue == 7){
      pixel.setTo(setEven(red), setOdd(green), setOdd(blue));
   }      
}

void Encryptor::decodePixel(ColorClass &pixel)
{
   if (pixel.getRed() % 2 == 0 && pixel.getGreen() % 2 == 0 && pixel.getBlue() % 2 == 0)
   {
      pixel.setToBlack();
   }else if(pixel.getRed() % 2 == 1 && pixel.getGreen() % 2 == 0 && pixel.getBlue() % 2 == 0)
   {
      pixel.setToRed();
   }else if(pixel.getRed() % 2 == 0 && pixel.getGreen() % 2 == 1 && pixel.getBlue() % 2 == 0)
   {
      pixel.setToGreen();
   }else if(pixel.getRed() % 2 == 0 && pixel.getGreen() % 2 == 0 && pixel.getBlue() % 2 == 1)
   {
      pixel.setToBlue();
   }else if(pixel.getRed() % 2 == 1 && pixel.getGreen() % 2 == 1 && pixel.getBlue() % 2 == 1)
   {
      pixel.setToWhite();
   }else if(pixel.getRed() % 2 == 1 && pixel.getGreen() % 2 == 1 && pixel.getBlue() % 2 == 0)
   {
      pixel.setToYellow();
   }else if(pixel.getRed() % 2 == 1 && pixel.getGreen() % 2 == 0 && pixel.getBlue() % 2 == 1)
   {
      pixel.setToMagenta();
   }else if(pixel.getRed() % 2 == 0 && pixel.getGreen() % 2 == 1 && pixel.getBlue() % 2 == 1)
   {
      pixel.setToCyan();
   }

}



bool Encryptor::readInMessage(string fileName)
{
   int row;
   int column;
   int extraNumber;


   ifstream inFile;
   inFile.open(fileName.c_str());

   if (inFile.fail())
   {
      clearFileInput(inFile);
      cout << "Unable to Open and Load Message File!" << endl;
      return false;
   }

   inFile >> column >> row;
   if (inFile.fail())
   {
      clearFileInput(inFile);
      cout << "Error Found in Image File: " 
      << "The Row and Column should be Integers " << endl;
      return false;
   }
   if (row < 0 || column < 0)
   {
      cout << "Error Found in Image File: " 
      << "The Row and Column should be Nonnegative Integers " << endl;
      return false;
   }

   mCols = column;
   mRows = row;


   message = new int * [mRows];
   for (int rIndex = 0; rIndex < mRows; rIndex++)
   {
      message[rIndex] = new int[mCols];
   }

   for (int rIndex = 0; rIndex < mRows; rIndex++)
   {
      for (int cIndex = 0; cIndex < mCols; cIndex++)
      {
         inFile >> message[rIndex][cIndex];
         if (inFile.fail())
         {
            clearFileInput(inFile);
            cout << "Error Found in Message File: " 
            << "They should be Integers " << endl;
            return false;
         }
         if (message[rIndex][cIndex] < 0 || message[rIndex][cIndex] > 7)
         {
         cout << "Error Found in Image File: " 
         << "They should be in [0,7] " << endl;
         return false;
         }
      }
   }

   inFile >> extraNumber;
   if (inFile.eof())
   {
      cout << "end of read message file!" << endl;
      return true;
   }

   inFile.close();
   cout << "Error Found in Image File : Total Number of "
   << "the Numbers in File is not consistant with Row and Column " << endl;
   return false;   
   
}


bool Encryptor::encodeImage(ColorImageClass &image, int sRow, int sCol)
{
   ColorClass palette;
   RowColumnClass pos; 
   if (sRow > image.getRows() || 
       sCol > image.getCols() ||
       sRow < 0               ||
       sCol < 0)
   {
      cout << "starting position not in range !" << endl;
   }else
   {
      for (int rIndex = 0; rIndex < mRows; ++rIndex)
      {
         for (int cIndex = 0; cIndex < mCols; ++cIndex)
         {
            if (rIndex + sRow <=image.getRows() && cIndex + sCol < = image.getCols())
            encodePixel(palette, message[rIndex][cIndex]);
            pos.setRowCol(rIndex + sRow, cIndex + sCol);
            image.setColorAtLocation(pos, palette);
            //error check
         }
      }
   }
}

bool Encryptor::decodeImage(ColorImageClass &image)
{
   ColorClass palette;
   RowColumnClass pos;
   for (int rIndex = 0; rIndex < mRows; ++rIndex)
   {
      for (int cIndex = 0; cIndex < mCols; ++cIndex)
      {  
         pos.setRowCol(rIndex, cIndex);
         image.getColorAtLocation(pos, palette);
         decodePixel(palette);
         image.setColorAtLocation(pos, palette);
      }
      
   }
   
}


void Encryptor::clearFileInput(ifstream &inFile)
{
   inFile.clear();
   inFile.ignore(200, '\n');
}

void Encryptor::clearUserInput()
{
   cin.clear();
   cin.ignore(DEFAULT_CONSUME, '\n');
}