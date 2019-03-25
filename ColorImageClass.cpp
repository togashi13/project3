#include <iostream>
#include <fstream>
using namespace std;

#include "const_proj3.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"
// #include "clearFileInput.h"







ColorImageClass::ColorImageClass()
{
    numRows = 0;
    numColumns = 0;
    pixels = 0;
}

void ColorImageClass::initializeTo(
                      ColorClass &inColor
                      )
{
   for (int i = 0; i < numRows; ++i)
   {
      for (int j = 0; j < numColumns; ++j)
      {
         pixels[i][j].setTo(inColor);
      }
   }
}

// bool ColorImageClass::addImageTo(
//                       ColorImageClass &rhsImg
//                       )
// {
//    int numPixClipped = 0;
//    for (int i = 0; i < numRows; ++i)
//    {
//       for (int j = 0; j < numColumns; ++j)
//       {
//          if (pixels[i][j].addColor(rhsImg.pixels[i][j]))
//          {
//             numPixClipped++;
//          }
//       }
//    }  
//    return (numPixClipped > 0);
// }

// bool ColorImageClass::addImages(
//                       int numImagesToAdd,
//                       ColorImageClass imagesToAdd []
//                       )
// {
//    int numClip = 0;
//    for (int i = 0; i < numRows; ++i)
//    {
//       for (int j = 0; j < numColumns; ++j)
//       {
//          pixels[i][j].setToBlack();
//       }
//    }
//    for (int i = 0; i < numRows; ++i)
//    {
//       for (int j = 0; j < numColumns; ++j)
//       {
//          for (int imageIndex = 0; imageIndex < numImagesToAdd; ++imageIndex)
//          {
//             if (pixels[i][j].addColor(imagesToAdd[imageIndex].pixels[i][j]))
//             {
//                numClip ++;
//             } 
//          }
//       }
//    }
//    return (numClip > 0);
// }

bool ColorImageClass::setColorAtLocation(
                      RowColumnClass &inRowCol,
                      ColorClass &inColor
                      )
{
   int setRow = inRowCol.getRow();
   int setCol = inRowCol.getCol();
   if ((setRow < numRows) && (setRow >= 0) && 
         (setCol < numColumns) && (setCol >= 0))
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
   if ((setRow < numRows) && (setRow >= 0) && 
         (setCol < numColumns) && (setCol >= 0))
   {        
      outColor.setTo(pixels[setRow][setCol]);
      return true;
   }else{
      return false;
   }  
}

void ColorImageClass::printImage()
{
   for (int i = 0; i < numRows; ++i)
   {
      for (int j = 0; j < numColumns; ++j)
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
         if (!pixels[rInd][cInd].readInColor(inFile))
         {
            cout << "Error: Reading image pixel at row: " << rInd << " "
            << "col: " << cInd << endl;
            return false;
         }
      }
   }

   inFile >> extraNumber;
   if (inFile.eof())
   {
      return true;
   }

   inFile.close();
   cout << "Error: Total Number of "
   << "the Numbers in File is not consistant with Row and Column " << endl;
   return false;   
   
}  

void ColorImageClass::clearFileInput(ifstream &inFile)
{
   inFile.clear();
   inFile.ignore(200, '\n');
}

void ColorImageClass::clearUserInput()
{
   cin.clear();
   cin.ignore(DEFAULT_CONSUME, '\n');
}


bool ColorImageClass::outputFile()
{
    clearUserInput();
    string fileName;
    cout << "Enter name of file name to write image to: ";
    cin >> fileName;
    ofstream outFile;
    outFile.open(fileName.c_str());
    if (outFile.fail())
    {

      cout << "Unable to open output file" << endl;
      return false;
    }
    outFile << MAGIC_NUMBER << '\n';
    outFile << numColumns << " " << numRows << " " << '\n';
    outFile << MAX_COLOR_VALUE << '\n';
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            pixels[i][j].outputColor(outFile);
        }
        outFile << '\n' ;
    }
    
    outFile.close();
    return true;
}


ColorImageClass::~ColorImageClass()
{
    for (int r = 0; r < numRows; r++)
    {
        delete [] pixels[r];
    }
    delete [] pixels;
    pixels = 0;
}


int ColorImageClass::getRows()
{
   return numRows;
}

int ColorImageClass::getCols()
{
   return numColumns;
}