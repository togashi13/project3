#ifndef GLOBF_PROJ3
#define GLOBF_PROJ3

#include<fstream>

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

void clearFileInput(ifstream &inFile)
{
    inFile.clear();
    inFile.ignore(DEFAULT_CONSUME, '\n');
}

// This function aims to clear all the input in buffer
void clearUserInput()
{
    cin.clear();
    cin.ignore(DEFAULT_CONSUME, '\n');
}
#endif

