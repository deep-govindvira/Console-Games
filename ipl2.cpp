#include "windows.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> score(10, 0);
vector<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> pos(10, 10);
vector<int> pre(10, 10);
vector<int> growth(10, 0);
vector<string>  team = {
    "Gujarat Titans",
    "Mumbai Indians",
    "Punjab Kings",
    "Delhi Capitals",
    "Rajasthan Royals",
    "Royal Challengers Bangalore",
    "Sunrisers Hyderabad",
    "Chennai Super Kings",
    "Lucknow Super Giants",
    "Kolkata Knight Riders"
};
void delay();
void short_delay();
void color(string color);
void P(string s);
void s(int n);
void Shuffle(int n);
void Shuffle_d(int n);
void sorting(int n);
void cal_score(int n);
void print_teams(int n);
void CSK();
void MI();
void SRH();
void LSG();
void GT();
void KXIP();
void RCB();
void DC();
void KKR();
void Team(string a);
void ALL_TEAMS();
void GROWTH(int n) {
    for(int i = 0; i < n; i++) {
        growth[i] = pos[i] - pre[i];
        pre[i] = pos[i];
    }
}
int main() {
    srand(time(0));
    Shuffle(10);
    int n = 10;
    P("\n   Indian Premier League (IPL)");
    Shuffle_d(10);
    cal_score(n);
    sorting(n);
    P("\n\n   Free Round : \n");
    for(int i = 0; i < n; i++) {
        P("\n   ");
        short_delay();
        Team(team[i]);
        s(35 - team[i].size());
        cout << score[i];
    }
    for(int i = 1; i <= 9; i++) {
        P("\n\n   Elimination Round - ");
        cout << i << " : \n";
        Shuffle_d(10);
        cal_score(n);
        sorting(n);
        print_teams(n);
        n--;
    }
    P("\n\n");
    getchar();
}
void s(int n) {
    for(int i = 1; i <= n; i++)
        cout << " ";
}
void P(string s) {
    cout << s;
}
void Shuffle_d(int n) {
    for(int times = 1; times <= 100; times++) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(rand() % 2) {
                    int a = d[i];
                    d[i] = d[j];
                    d[j] = a;
                }
            }
        }
    }
}
void Shuffle(int n) {
    for(int times = 1; times <= 100; times++) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(rand() % 2) {
                    string a = team[i];
                    team[i] = team[j];
                    team[j] = a;
                    int b = score[i];
                    score[i] = score[j];
                    score[j] = b;
                }
            }
        }
    }
}
void sorting(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(score[i] < score[j]) {
                int a = d[i];
                d[i] = d[j];
                d[j] = a;
                string c = team[i];
                team[i] = team[j];
                team[j] = c;
                int b = score[i];
                score[i] = score[j];
                score[j] = b;
                int asd = pos[i];
                pos[i] = pos[j];
                pos[j] = asd;
                int cxvb = growth[i];
                growth[i] = growth[j];
                growth[j] = cxvb;
            }
        }
    }
}
void cal_score(int n) {
    for(int i = 0; i < n; i++) {
        score[i] += d[i];
    }
}
void print_teams(int n) {
    for(int i = 0; i < n - 1; i++) {
        P("\n   ");
        delay();
        Team(team[i]);
        s(35 - team[i].size());
        cout << score[i] << "   ";
        // cout << score[i] << "   " << "(+" << d[i] << ")";
    }
    P("\n   ");
    color("Black");
    P(team[n - 1]);
    s(34 - team[n - 1].size());
    P(" Eliminated");
    color("White");
}
void color(string color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if(color == "Blue")
        SetConsoleTextAttribute(h, 1);
    else if(color == "Green")
        SetConsoleTextAttribute(h, 2);
    else if(color == "Cyan")
        SetConsoleTextAttribute(h, 3);
    else if(color == "Red")
        SetConsoleTextAttribute(h, 4);
    else if(color == "Purple")
        SetConsoleTextAttribute(h, 5);
    else if(color == "Yellow")
        SetConsoleTextAttribute(h, 6);
    else if(color == "White")
        SetConsoleTextAttribute(h, 7);
    else if(color == "Black")
        SetConsoleTextAttribute(h, 8);
    else if(color == "Light Blue")
        SetConsoleTextAttribute(h, 9);
    else if(color == "Light Green")
        SetConsoleTextAttribute(h, 10);
    else if(color == "Light Cyan")
        SetConsoleTextAttribute(h, 11);
    else if(color == "Light Red")
        SetConsoleTextAttribute(h, 12);
    else if(color == "Light Purple")
        SetConsoleTextAttribute(h, 13);
    else if(color == "Light Yellow")
        SetConsoleTextAttribute(h, 14);
    else if(color == "Light White")
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
void ALL_TEAMS() {
    CSK();
    P("\n");
    MI();
    P("\n");
    RR();
    P("\n");
    SRH();
    P("\n");
    LSG();
    P("\n");
    GT();
    P("\n");
    KXIP();
    P("\n");
    RCB();
    P("\n");
    DC();
    P("\n");
    KKR();
}
void Team(string a) {
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
void delay() {
    for(long long int i = -999999999; i <= 999999999; i++);
}
void short_delay() {
    for(long long int i = -99999999; i <= 99999999; i++);
}
