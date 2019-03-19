#ifndef GLOBF_PRO2
#define GLOBF_PRO2

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

#endif

