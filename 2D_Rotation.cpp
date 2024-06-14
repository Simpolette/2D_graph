#include <iostream>
#include "Drawing.h"
#include "2D_Function.h"
#include "2D_Graph.h"

using namespace std;

int main(){
    string Function;
    cout << "Please enter your function: f(x) = ";
    getline(cin, Function);
    system("cls");
    while(1){
            drawAxis();
        drawGraph(Function);
    }
    return 0;
}