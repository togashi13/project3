#ifndef GLOBF_PRO2
#define GLOBF_PRO2

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

#endif

