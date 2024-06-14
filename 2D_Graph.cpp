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

void drawGraph(string Function){
    int x = X_CENTER * -1;

    for (int i = x; i < X_CENTER; i++){
        int y = calFunction(Function, i);
        if (y < Y_CENTER && y > Y_CENTER * -1){
            // Check if Y can fit in the console or not
            
            gotoxy(X_CENTER + i, Y_CENTER - y);
            cout << "*";
        }
    }
}