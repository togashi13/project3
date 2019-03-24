#include <iostream>
using namespace std;

#include "const_proj3.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
#include "clearFileInput.h"







ColorImageClass::ColorImageClass()
{
 


   for (int i = 0; i < IMAGE_ROW; ++i)
   {
      for (int j = 0; j < IMAGE_COL; ++j)
      {
         pixels[i][j].setToBlack();
      }
   }
}

void ColorImageClass::initializeTo(
                      ColorClass &inColor
                      )
{
      for (int i = 0; i < IMAGE_ROW; ++i)
   {
      for (int j = 0; j < IMAGE_COL; ++j)
      {
         pixels[i][j].setTo(inColor);
      }
   }
}

bool ColorImageClass::addImageTo(
                      ColorImageClass &rhsImg
                      )
{
   int numPixClipped = 0;
   for (int i = 0; i < IMAGE_ROW; ++i)
   {
      for (int j = 0; j < IMAGE_COL; ++j)
      {
         if (pixels[i][j].addColor(rhsImg.pixels[i][j]))
         {
            numPixClipped++;
         }
      }
   }  
   return (numPixClipped > 0);
}

bool ColorImageClass::addImages(
                      int numImagesToAdd,
                      ColorImageClass imagesToAdd []
                      )
{
   int numClip = 0;
   for (int i = 0; i < IMAGE_ROW; ++i)
   {
      for (int j = 0; j < IMAGE_COL; ++j)
      {
         pixels[i][j].setToBlack();
      }
   }
   for (int i = 0; i < IMAGE_ROW; ++i)
   {
      for (int j = 0; j < IMAGE_COL; ++j)
      {
         for (int imageIndex = 0; imageIndex < numImagesToAdd; ++imageIndex)
         {
            if (pixels[i][j].addColor(imagesToAdd[imageIndex].pixels[i][j]))
            {
               numClip ++;
            } 
         }
      }
   }
   return (numClip > 0);
}

bool ColorImageClass::setColorAtLocation(
                      RowColumnClass &inRowCol,
                      ColorClass &inColor
                      )
{
   int setRow = inRowCol.getRow();
   int setCol = inRowCol.getCol();
   if ((setRow < IMAGE_ROW) && (setRow >= 0) && 
         (setCol < IMAGE_COL) && (setCol >= 0))
   {
      pixels[setRow][setCol].setTo(inColor);
      return true;
   }else{
      return false;
   }
}
 
bool ColorImageClass::getColorAtLocation(
                      RowColumnClass &inRowCol,
                      ColorClass &outColor
                      )
{
   int setRow = inRowCol.getRow();
   int setCol = inRowCol.getCol();
   if ((setRow < IMAGE_ROW) && (setRow >= 0) && 
         (setCol < IMAGE_COL) && (setCol >= 0))
   {        
      outColor.setTo(pixels[setRow][setCol]);
      return true;
   }else{
      return false;
   }  
}

void ColorImageClass::printImage()
{
   for (int i = 0; i < IMAGE_ROW; ++i)
   {
      for (int j = 0; j < IMAGE_COL; ++j)
      {

         if (j ==  17)
         {
            pixels[i][j].printComponentValues();
            cout << endl;
         }else{
            pixels[i][j].printComponentValues();
            cout << "--";
         }
      }
   }
}

bool ColorImageClass::readInImage(string fileName)
{ 
   string magicNumber;
   int colorValueInFile;
   int row;
   int column;
   int extraNumber;


   ifstream inFile;
   inFile.open(fileName.c_str());

   if (inFile.fail())
   {
      clearFileInput(inFile);
      cout << "Unable to Open and Load File!" << endl;
      return false;
   }

   inFile >> magicNumber;
   if (inFile.fail())
   {
      clearFileInput(inFile);
      cout << "Error Found When loading the Magic Number From File" << endl;
      return false;
   }
   if (magicNumber != MAGIC_NUMBER)
   {
      clearFileInput(inFile);
      cout << "Magic Number in File is not consistant with PPM File" << endl;
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

   numColumns = column;
   numRows = row;

   inFile >> colorValueInFile;
   if (inFile.fail())
   {
      clearFileInput(inFile);
      cout << "Error Found in Image File: " 
      << "The Maximum Value of Color should be Integer " << endl;
      return false;
   }
   if (colorValueInFile != MAX_COLOR_VALUE)
   {
      cout << "Error Found in Image File: The Maximum Value of Color " 
      << "should be: " << MAX_COLOR_VALUE << endl;
      return false;
   }

   pixels = new ColorClass * [numRows];
   for (int rInd = 0; rInd < numRows; rInd++)
   {
      pixels[rInd] = new ColorClass[numColumns];
   }

   for (int rInd = 0; rInd < numRows; rInd++)
   {
      for (int cInd = 0; cInd < numColumns; cInd++)
      {
   

         pixels[rInd][cInd].readInColor(inFile);
      }
   }

   inFile >> extraNumber;
   if (inFile.eof())
   {
      cout << "successful" << endl;
      return true;
   }

   inFile.close();
   cout << "Error Found in Image File : Total Number of "
   << "the Numbers in File is not consistant with Row and Column " << endl;
   return false;   
   
}  

void colorImageClass::clearFileInput(ifstream &inFile)
{
   inFile.clear();
   inFile.ignore(200, '\n');
}