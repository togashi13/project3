#ifndef _ENCRYPTOR_H_
#define _ENCRYPTOR_H_

#include "const_proj3.h"
#include "ColorClass.h"
// #include "ColorImageClass.h"
#include "RowColumnClass.h"
#include <iostream>

using namespace std;

class Encryptor 
{
private:
   int ** message;
   int mRows;
   int mCols;

   int setEven(int val);
   int setOdd(int val);

   void encodePixel(ColorClass &pixel, int colorValue);

   void decodePixel(ColorClass &pixel);



public:
   Encryptor();

   ~Encryptor();

   bool readInMessage(string fileName);


   bool encodeImage(ColorImageClass &image, int sRow, int sCol);

   void decodeImage(ColorImageClass &image);

   void clearFileInput(ifstream &inFile);

    // This function aims to clear all the input in buffer
   void clearUserInput();

};




#endif