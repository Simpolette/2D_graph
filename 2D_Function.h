#pragma once

#include "Drawing.h"
#include <string>
#include <math.h>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

const float PI = 3.141592653589793238462643383279502884197;

int calXcoord(int x, int y, float theta);                   // Calculate new X coord
int calYcoord(int x, int y, float theta);                   // Calculate new Y coord

int getXPowerY(int x, int y);
bool isCharNumber(char c);
bool isCharOperatorPara(char c);

vector <string> functionConverter(string Function);
int calPriorityPara(vector <string> convertedFunction, int& curPosition, int x);
int calPriorityPower(vector <string> convertedFunction, int& curPosition, int x);
int calPriorityMulDiv(vector <string> convertedFunction, int& curPosition, int x);
int calPriorityAddSub(vector <string> convertedFunction, int& curPosition, int x);

int calFunction(string Function, int x);                    // Returning the value of current Y coord when enter X in the function
