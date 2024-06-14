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

double getXPowerY(double x, int y);
bool isCharNumber(char c);
bool isCharOperatorPara(char c);

vector <string> functionConverter(string Function);
double calPriorityPara(vector <string> convertedFunction, int& curPosition, double x);
double calPriorityPower(vector <string> convertedFunction, int& curPosition, double x);
double calPriorityMulDiv(vector <string> convertedFunction, int& curPosition, double x);
double calPriorityAddSub(vector <string> convertedFunction, int& curPosition, double x);

int calFunction(string Function, double x);                    // Returning the value of current Y coord when enter X in the function
