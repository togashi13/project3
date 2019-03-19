#ifndef _COLORIMAGECLASS_H_
#define _COLORIAMGECLASS_H_

#include "const_pro2.h"
#include "ColorClass.h"
#include "RowColumnClass.h"


class ColorImageClass
{
private:

   ColorClass pixels [IMAGE_ROW][IMAGE_COL];
   
   //10 rows x 18 cols, but the size of the 
   //image can be changed easily.
public:
   ColorImageClass();
   // default ctor set to full black

   void initializeTo(
        ColorClass &inColor
        );
   //initialize all image pixels to the color 
   //provided.

   bool addImageTo(
        ColorImageClass &rhsImg
        );
   //{}pixels-wise addition, right hand side 
   //  input image added to it.
   //  clipping -- true.

   bool addImages(
        int numImagesToAdd,
        ColorImageClass imagesToAdd []
        );
   //{}sum each image in the imagesToAdd input
   //  parameter and assign to current image.
   //  clipping -- true

   bool setColorAtLocation(
        RowColumnClass &inRowCol,
        ColorClass &inColor
        );
   //{}if the specified location is valid, the
   //  the value is changed to inColor parameter,
   //  and returns true. Otherwise nothing is 
   //  modified and returns false.

   bool getColorAtLocation(
        RowColumnClass &inRowCol,
        ColorClass &outColor
        );
   //{}if row/col provided is valid, returns
   //  true and outColor = color at the loaction
   //  otherwise -- false, outColor is not modified.

   void printImage();
   //{}each pixels is printed using ColorClass format.
   //  newl after the last pixels of each row.
   //  -- between each pixels.


};

#endif