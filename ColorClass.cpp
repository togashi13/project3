#include <iostream>
#include <fstream>
using namespace std;

#include "ColorClass.h"
#include "clipInt.h"
// #include "clearFileInput.h"
#include "const_proj3.h"




ColorClass::ColorClass()
{
   setToWhite();
}

ColorClass::ColorClass(
                 int inRed,
                 int inGreen,
                 int inBlue
                 )
{
   setTo(inRed, inGreen, inBlue);
}

void ColorClass::setToBlack()
{
   setTo(COLOR_MIN, COLOR_MIN, COLOR_MIN);
}

void ColorClass::setToRed()
{
   setTo(COLOR_MAX, COLOR_MIN, COLOR_MIN);
}

void ColorClass::setToGreen()
{
   setTo(COLOR_MIN, COLOR_MAX, COLOR_MIN);
}

void ColorClass::setToBlue()
{
   setTo(COLOR_MIN, COLOR_MIN, COLOR_MAX);
}

void ColorClass::setToWhite()
{
   setTo(COLOR_MAX, COLOR_MAX, COLOR_MAX);
}

void ColorClass::setToYellow()
{
   setTo(COLOR_MAX, COLOR_MAX, COLOR_MIN);
}

void ColorClass::setToMagenta()
{
   setTo(COLOR_MAX, COLOR_MIN, COLOR_MAX);
}

void ColorClass::setToCyan()
{
   setTo(COLOR_MIN, COLOR_MAX, COLOR_MAX);
}

int ColorClass::getRed()
{
   return red;
}

int ColorClass::getGreen()
{
   return green;
}

int ColorClass::getBlue()
{
   return blue;
}



bool ColorClass::setTo(
                 int inRed,
                 int inGreen,
                 int inBlue
                 )
{

   return clipPixels(inRed, inGreen, inBlue);

}

bool ColorClass::setTo(
                 ColorClass &inColor
                 )
{

   return clipPixels(inColor.red, inColor.green, inColor.blue);

}

bool ColorClass::addColor(
     ColorClass &rhs) 
{
   return clipPixels(red + rhs.red, green + rhs.green, 
      blue + rhs.blue);
}

bool ColorClass::subtractColor(
     ColorClass &rhs
     )
{
   return clipPixels(red - rhs.red, green - rhs.green,
      blue - rhs.blue);

}

bool ColorClass::adjustBrightness(
     double adjFactor
     )
{
  return clipPixels(int(red * adjFactor), int(green * adjFactor), 
   int(blue * adjFactor));
}

void ColorClass::printComponentValues()
{
   cout << "R: " << red << " G: " << green << " B: " << blue;
}

bool ColorClass::clipPixels(
     int inRed,
     int inGreen,
     int inBlue
     )
{
   red = clipInt(inRed);
   green = clipInt(inGreen);
   blue = clipInt(inBlue);

   if ((red == inRed) && (green == inGreen) && (blue == inBlue))
   {
      return false;
   }else{
      return true;
   }
}

// int clipInt(int colToClip)
// {
//    if (colToClip < 0)
//    {
//       return 0;
//    }else if (colToClip > 1000){
//       return 1000;
//    }else{
//       return colToClip;
//    }
   
// }

bool ColorClass::readInColor(ifstream &colorFile)
{        
   int redVal;
   int greenVal;
   int blueVal;

   colorFile >> redVal >> greenVal >> blueVal;
   if (colorFile.fail()) 
   {
      clearFileInput(colorFile);
      cout << "Error Found in Image File: " 
      << "The Color Value should be Integer " 
      << "not Space or other types " << endl;
      exit(1);
   }

   if (setTo(redVal, greenVal, blueVal))
   {
      cout << "Error Found in Image File: The Color Value of Color " 
      << "should be [ " << MIN_COLOR_VALUE << "  " 
      << MAX_COLOR_VALUE << " ]" << endl;
      return false;
   }else{
      return true;
   }
}

void ColorClass::clearFileInput(ifstream &inFile)
{
   inFile.clear();
   inFile.ignore(DEFAULT_CONSUME, '\n');
}

void ColorClass::clearUserInput()
{
   cin.clear();
   cin.ignore(DEFAULT_CONSUME, '\n');
}

void ColorClass::outputColor(ofstream &outFile)
{
    outFile << red << "  " << green << "  " << blue << "  ";
}