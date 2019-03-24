
#include <fstream>
#include <iostream>
#include "clipInt.h"
#include "const_proj3.h"

int clipInt(int colToClip)
{
   if (colToClip < COLOR_MIN)
   {
      return COLOR_MIN;
   }else if (colToClip > COLOR_MAX){
      return COLOR_MAX;
   }else{
      return colToClip;
   }
   
}
