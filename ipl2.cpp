#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
void PrintTeam(string);
void IPL();
void MI();
void GT();
void DC();
void RR();
void CSK();
void SRH();
void LSG();
void RCB();
void KKR();
void KXIP();
void color(string);
int main() {
    srand(time(0));
    vector<string> a = {
        "Chennai Super Kings",
        "Delhi Capitals",
        "Gujarat Titans",
        "Kolkata Knight Riders",
        "Lucknow Super Giants",
        "Mumbai Indians",
        "Punjab Kings",
        "Rajasthan Royals",
        "Royal Challengers Bangalore",
        "Sunrisers Hyderabad"
    };
    int n = a.size();
    int first = 1;
    while(n != 1) {
        system("cls");
        cout << "\n    ";
        IPL();
        cout << "\n\n";
        random_shuffle(a.begin(), a.begin() + n);
        for(int i = 0; i < a.size(); i++) {
            if(i < 9)
                cout << " ";
            cout << "   " << i + 1 << ". ";
            if(i < n-1) {
                // cout << a[i];
                PrintTeam(a[i]);
                if(n == 2) {
                    color("Light Green");
                    for(int space = 1; space <= 35 - a[i].size(); space++) {
                        cout << " ";
                    }
                    cout << "!! Winner !!";
                    color("White");
                }
            }
            else {
                if(!first) {
                    color("Black");
                    cout << a[i];
                    for(int space = 1; space <= 35 - a[i].size(); space++) {
                        cout << " ";
                    }    
                    cout << "Eliminated.";   
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
void CSK() {
    string a = "Chennai Super Kings";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Light Blue");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void MI() {
    string a = "Mumbai Indians";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
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
    color("White");
}
void RR() {
    string a = "Rajasthan Royals";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("Light Blue");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void SRH() {
    string a = "Sunrisers Hyderabad";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Black");
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
void LSG() {
    string a = "Lucknow Super Giants";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Cyan");
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
void GT() {
    string a = "Gujarat Titans";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Cyan");
            b++;
        }
        else if(b == 1) {
            color("Light Blue");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void KXIP() {
    string a = "Punjab Kings";
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
void RCB() {
    string a = "Royal Challengers Bangalore";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Black");
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
void DC() {
    string a = "Delhi Capitals";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Blue");
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
void KKR() {
    string a = "Kolkata Knight Riders";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Purple");
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
void IPL() {
    color("Light Red");
    cout << "Indian ";
    color("White");
    cout << "Pr";
    color("Light Blue");
    cout << "emi";
    color("White");
    cout << "er ";
    color("Green");
    cout << "League ";
    color("Light Red");
    cout << "(";
    color("White");
    cout << "I";
    color("Light Blue");
    cout << "P";
    color("White");
    cout << "L";
    color("Green");
    cout << ")";
    color("White");
}
void PrintTeam(string a) {
    if(a == "Chennai Super Kings")
        CSK();
    if(a == "Mumbai Indians")
        MI();
    if(a == "Rajasthan Royals")
        RR();
    if(a == "Sunrisers Hyderabad")
        SRH();
    if(a == "Lucknow Super Giants")
        LSG();
    if(a == "Gujarat Titans")
        GT();
    if(a == "Punjab Kings")
        KXIP();
    if(a == "Royal Challengers Bangalore")
        RCB();
    if(a == "Delhi Capitals")
        DC();
    if(a == "Kolkata Knight Riders")
        KKR();
}
