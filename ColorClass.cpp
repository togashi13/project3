#include <iostream>
using namespace std;

#include "ColorClass.h"
#include "globf_pro2.h"


// int clipInt(
//      int colToClip
//      );

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
   setTo(0, 0, 0);
}

void ColorClass::setToRed()
{
   setTo(1000, 0, 0);
}

void ColorClass::setToGreen()
{
   setTo(0, 1000, 0);
}

void ColorClass::setToBlue()
{
   setTo(0, 0, 1000);
}

void ColorClass::setToWhite()
{
   setTo(1000, 1000, 1000);
}


bool ColorClass::setTo(
                 int inRed,
                 int inGreen,
                 int inBlue
                 )
{

   return clippixels(inRed, inGreen, inBlue);

}

bool ColorClass::setTo(
                 ColorClass &inColor
                 )
{

   return clippixels(inColor.red, inColor.green, inColor.blue);

}

bool ColorClass::addColor(
     ColorClass &rhs) 
{
   return clippixels(red + rhs.red, green + rhs.green, 
      blue + rhs.blue);
}

bool ColorClass::subtractColor(
     ColorClass &rhs
     )
{
   return clippixels(red - rhs.red, green - rhs.green,
    blue - rhs.blue);

}

bool ColorClass::adjustBrightness(
     double adjFactor
     )
{
  return clippixels(int(red * adjFactor), int(green * adjFactor), 
   int(blue * adjFactor));
}

void ColorClass::printComponentValues()
{
   cout << "R: " << red << " G: " << green << " B: " << blue;
}

bool ColorClass::clippixels(
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
