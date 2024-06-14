#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>

using namespace std;

int calPriorityAddSub(vector <string> convertedFunction, int& curPosition, int x);

int getXPowerY(int x, int y){
    int res = 1;

    if (y == 0) return res;

    for (int i = 0; i < y; i++){
        res *= x;
    }
    
    return res;
}

bool isCharNumber(char c){
    int num = c - '0';
    
    for (int i = 0; i <= 9; i++){
        if (num == i) return true;
    }

    return false;
}

bool isCharOperatorPara(char c){
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')'){
        return true;
    }

    return false; 
}

vector <string> functionConverter(string Function){
    // Still have not calculate the case of many "-" or "+" appear consectively

    int sLen = Function.length();
    string num = "";
    vector <string> Converter;

    for (int i = 0; i < sLen; i++){
        if (Function[i] == 'x' || Function[i] == 'X'){
            Converter.push_back("x");
        }
        if (isCharNumber(Function[i])){
            num += Function[i];
        }
        else{
            if (isCharOperatorPara(Function[i])){
                if (num != ""){
                    Converter.push_back(num);                    
                }
                Converter.push_back(string(1, Function[i]));
                num = "";
            }
        }
    }

    if (num != ""){
        Converter.push_back(num);
    }

    return Converter;
}

int calPriorityPara(vector <string> convertedFunction, int& curPosition, int x){
    int res = 0;

    if (convertedFunction[curPosition] == "("){
        curPosition++;
        res = calPriorityAddSub(convertedFunction, curPosition, x);
        curPosition++;
        return res;
    }
    else{
        if (convertedFunction[curPosition] == "x"){
            res += x;
        }
        else if (convertedFunction[curPosition] != ""){
            res = stoi(convertedFunction[curPosition]);
        }
        curPosition++;
        return res;
    }
}

int calPriorityPower(vector <string> convertedFunction, int& curPosition, int x){
    int res = calPriorityPara(convertedFunction, curPosition, x);

    if (convertedFunction[curPosition] == "^"){
        curPosition++;
        res = getXPowerY(res, calPriorityPower(convertedFunction, curPosition, x));
    }

    return res;
}

int calPriorityMulDiv(vector <string> convertedFunction, int& curPosition, int x){
    int res = calPriorityPower(convertedFunction, curPosition, x);

    if (convertedFunction[curPosition] == "*"){
        curPosition++;
        res *= calPriorityMulDiv(convertedFunction, curPosition, x);
    }
    else if (convertedFunction[curPosition] == "/"){
        curPosition++;
        res /= calPriorityMulDiv(convertedFunction, curPosition, x);
    }

    return res;
}

int calPriorityAddSub(vector <string> convertedFunction, int& curPosition, int x){
    int res = calPriorityMulDiv(convertedFunction, curPosition, x);

    if (convertedFunction[curPosition] == "+"){
        curPosition++;
        res += calPriorityAddSub(convertedFunction, curPosition, x);
    }
    else if (convertedFunction[curPosition] == "-"){
        curPosition++;
        res -= calPriorityAddSub(convertedFunction, curPosition, x);
    }

    return res;
}

int calFunction(string Function, int x){
    vector <string> convertedFunction = functionConverter(Function);
    int curPosition = 0;

    return calPriorityAddSub(convertedFunction, curPosition, x);
}

int main(){
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
    string s;
    getline(cin, s);
    int x = -50;
    cout << calFunction(s, x) << endl;
    return 0;
}