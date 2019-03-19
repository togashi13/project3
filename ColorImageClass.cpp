#include <iostream>
using namespace std;

#include "const_pro2.h"
#include "ColorClass.h"
#include "RowColumnClass.h"
#include "ColorImageClass.h"








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