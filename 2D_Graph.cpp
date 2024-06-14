#include "2D_Graph.h"

void drawAxis(){
    TextColor(BLACK, WHITE);

    char c = 196;
    // DRAW X-AXIS
    gotoxy(0, Y_CENTER);
    cout << "<";
    for (int i = 1; i < X_CENTER; i++){
        gotoxy(i, Y_CENTER);
        cout << c;
    }
    for (int i = X_CENTER + 1; i < CONSOLE_WIDTH; i++){
        gotoxy(i, Y_CENTER);
        cout << c;
    }
    cout << ">";

    c = 197;
    gotoxy(X_CENTER, Y_CENTER);
    cout << c;


    // DRAW Y-AXIS
    c = 179;
    gotoxy(X_CENTER, 0);
    cout << "^";

    for (int i = 1; i < Y_CENTER; i++){
        gotoxy(X_CENTER, i);
        cout << c;
    }
    for (int i = Y_CENTER + 1; i < CONSOLE_HEIGHT; i++){
        gotoxy(X_CENTER, i);
        cout << c;
    }

    gotoxy(X_CENTER, CONSOLE_HEIGHT);
    cout << "v";
}

double calWeight(int y1, int y2){
    double distance = abs(y2 - y1);
    return 1 / getXPowerY(10, distance);
}

void drawGraph(string Function){
    // Calculate for the case x is not in the function

    int x_start = X_CENTER * -1;
    double weight = calWeight(0, calFunction(Function, 1));

    for (double x = x_start; x < X_CENTER; x += weight){
        int y = calFunction(Function, x);
        if (y < Y_CENTER && y > Y_CENTER * -1){
            // Check if Y can fit in the console or not
            
            gotoxy(X_CENTER + x, Y_CENTER - y);
            cout << "*";
        }
    }
}