#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

class ColorClass
{
   private:
      int red;//amount of each color
      int green;
      int blue;
      //additional member functions must be private
      //{}default ctor set to full white.
      bool clippixels(     
           int colorR,
           int colorG,
           int colorB
           );

   public:
      ColorClass();

      ColorClass(
           int inRed,
           int inGreen,
           int inBlue
           );
      //{}value ctor clipping: set to max and min 
      //  when out of range [0,1000].
      void setToBlack();//set to full colors.
      void setToRed();
      void setToGreen();
      void setToBlue();
      void setToWhite();

      bool setTo(
           int inRed,
           int inGreen,
           int inBlue
           );
      //{}clipping needed, return true if clipping 
      //  is necessary.

      bool setTo(
           ColorClass &inColor
           );
      //{}sets the color's component color values to 
      //  the same as those in the "inColor" input.

      bool addColor(
           ColorClass &rhs
           );
      //{}add RGB in rhs to this object, return if 
      //  clipping is necessary.


      bool subtractColor(
           ColorClass &rhs
           );
      //{}similar to addColor 


      bool adjustBrightness(
           double adjFactor
           );
      //{}brighter if adjFactor > 1, clipping --
      //  true. 
      //  Type cast the color values to int.

      void printComponentValues();
      //{}"R: <red> G: <green> B: <blue>", no newl.
};

#endif