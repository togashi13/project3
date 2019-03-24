

#include <fstream>
#include <iostream>
using namespace std;
#include "const_proj3.h"

void clearFileInput(ifstream &inFile)
{
   inFile.clear();
   inFile.ignore(DEFAULT_CONSUME, '\n');
}

