
#include <fstream>
#include <iostream>
#include "clearUserInput.h"
#include "const_proj3.h"
using namespace std;

void clearUserInput()
{
   cin.clear();
   cin.ignore(DEFAULT_CONSUME, '\n');
}