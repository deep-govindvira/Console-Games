#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
void PrintTeam(string);
void War();
void United_States();
void Russia();
void China();
void India();
void Japan();
void South_Korea();
void France();
void Italy();
void United_Kingdom();
void Turkey();
void color(string);
int main() {
    srand(time(0));
    vector<string> a = {
        "United States",
        "Russia",
        "China",
        "India",
        "Japan",
        "South Korea",
        "France",
        "Italy",
        "United Kingdom",
        "Turkey",
    };
    int n = a.size();
    int first = 1;
    while(n != 1) {
        system("cls");
        cout << "\n    ";
        War();
        cout << "\n\n";
        random_shuffle(a.begin(), a.begin() + n);
        for(int i = 0; i < a.size(); i++) {
            if(i < 9)
                cout << " ";
            if(!first && i == n-1)
                color("Red");
            cout << "   " << i + 1 << ". ";
            if(i < n-1) {
                // cout << a[i];
                PrintTeam(a[i]);
                if(n == 2) {
                    color("Light Green");
                    for(int space = 1; space <= 35 - a[i].size(); space++) {
                        cout << " ";
                    }
                    cout << "!! Survivor !!";
                    color("White");
                }
            }
            else {
                if(!first) {
                    color("Red");
                    cout << a[i];
                    for(int space = 1; space <= 35 - a[i].size(); space++) {
                        cout << " ";
                    }    
                    cout << "XXXXXXXXXXXXX";   
                }
                else {
                    // cout << a[i];
                    PrintTeam(a[i]);
                }  
            }
            cout << "\n\n";
        }
        if(!first)
            n--;
        first = 0;
        getchar();
    }
    return 0;
}
void color(string c) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if(c == "Blue")
        SetConsoleTextAttribute(h, 1);
    else if(c == "Green")
        SetConsoleTextAttribute(h, 2);
    else if(c == "Cyan")
        SetConsoleTextAttribute(h, 3);
    else if(c == "Red")
        SetConsoleTextAttribute(h, 4);
    else if(c == "Purple")
        SetConsoleTextAttribute(h, 5);
    else if(c == "Yellow")
        SetConsoleTextAttribute(h, 6);
    else if(c == "White")
        SetConsoleTextAttribute(h, 7);
    else if(c == "Black")
        SetConsoleTextAttribute(h, 8);
    else if(c == "Light Blue")
        SetConsoleTextAttribute(h, 9);
    else if(c == "Light Green")
        SetConsoleTextAttribute(h, 10);
    else if(c == "Light Cyan")
        SetConsoleTextAttribute(h, 11);
    else if(c == "Light Red")
        SetConsoleTextAttribute(h, 12);
    else if(c == "Light Purple")
        SetConsoleTextAttribute(h, 13);
    else if(c == "Light Yellow")
        SetConsoleTextAttribute(h, 14);
    else if(c == "Light White")
        SetConsoleTextAttribute(h, 15);
}
void Turkey() {
    string a = "Turkey";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("White");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void United_States() {
    string a = "United States";
    int b = 0;
    for(int i = 0; i <= 5; i++) {
        if(b == 0) {
            color("Light Blue");
            b++;
        }
        else if(b == 1) {
            color("White");
            b = 0;
        }
        cout << a[i];
    }
    b = 0;
    for(int i = 6; i <= a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("White");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Japan() {
    string a = "Japan";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("White");
            b++;
        }
        else if(b == 1) {
            color("Light Red");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void India() {
    string a = "India";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("White");
            b++;
        }
        else if(b == 2) {
            color("Light Blue");
            b++;
        }
        else if(b == 3) {
            color("White");
            b++;
        }
        else if(b == 4) {
            color("Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void United_Kingdom() {
    string a = "United Kingdom";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Blue");
            b++;
        }
        else if(b == 1) {
            color("Light Red");
            b++;
        }
        else if(b == 2){
            color("White");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void South_Korea() {
    string a = "South Korea";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Black");
            b++;
        }
        else if(b == 1) {
            color("White");
            b++;
        }
        else if(b == 2) {
            color("Light Red");
            b++;
        }
        else if(b == 3) {
            color("Light Blue");
            b++;
        }
        else if(b == 4) {
            color("White");
            b++;
        }
        else if(b == 5) {
            color("White");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Italy() {
    string a = "Italy";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Green");
            b++;
        }
        else if(b == 1) {
            color("White");
            b++;
        }
        else if(b == 2) {
            color("Light Red");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void France() {
    string a = "France";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Blue");
            b++;
        }
        else if(b == 1) {
            color("White");
            b++;
        }
        else if(b == 2) {
            color("Light Red");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Russia() {
    string a = "Russia";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("White");
            b++;
        }
        else if(b == 1) {
            color("Light Blue");
            b++;
        }
        else if(b == 2) {
            color("Light Red");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void China() {
    string a = "China";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("Yellow");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void War() {
    color("Red");
    cout << "X - X - X - World War - X - X - X";
    color("White");
}
void PrintTeam(string a) {
    if(a == "United States")
        United_States();
    if(a == "United Kingdom")
        United_Kingdom();
    if(a == "China")
        China();
    if(a == "Russia")
        Russia();
    if(a == "India")
        India();
    if(a == "France")
        France();
    if(a == "Japan")
        Japan();
    if(a == "South Korea")
        South_Korea();
    if(a == "Turkey")
        Turkey();
    if(a == "Italy")
        Italy();
}
