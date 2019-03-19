#include <iostream>
using namespace std;
// #include "globf_pro2.h"

int clipInt(int colToClip)
{
   if (colToClip < 0)
   {
      return 0;
   }else if (colToClip > 1000){
      return 1000;
   }else{
      return colToClip;
   }
   
}
