#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
void PrintTeam(string);
class Team {
  private :
    string name;
    int score;
  public :
    Team() {
        this->name = "";
        this->score = 0;
    }
    Team(string a) {
        this->name = a;
    }
    string get_name() {
        return this->name;
    }
    int get_score() {
        return this->score;
    }
    void set_name(string a) {
        this->name = a;
    }
    void set_score(int a) {
        this->score = a;
    }
    void show_name() {
        PrintTeam(this->name);
    }
};
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
void shuffle(vector<int>& a);
void round(vector<Team>& T, vector<int>& b, int& n, int& firstround);
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
    vector<int> b(n);
    for(int i = 0; i < n; i++)
        b[i] = i + 1;
    vector<Team> T(n);
    for(int i = 0; i < n; i++)
        T[i].set_name(a[i]);
    int firstround = 1;
    cout << "\n    ";
    IPL();
    getchar();
    cout << "\n\n";
    while(n) {
        system("cls");
        cout << "\n    ";
        IPL();
        cout << "\n\n\n";
        if(n != 1) {
            if(n > 5) {
                color("Green");
            }
            else if(n > 2){
                color("Yellow");
            }
            else {
                color("Light Red");
            }
            cout << "    Round - " << n << " : \n\n";
            color("White");
        }
        else {
            color("Red");
            cout << "    Last Round : " << "\n\n";
            color("White");
        }
        shuffle(b);
        // couting score;
        for(int i = 0; i < T.size(); i++) {
            T[i].set_score(T[i].get_score() + b[i]);
        }
        // sorting
        for(int i = 0; i < T.size(); i++) {
            for(int j = i + 1; j < T.size(); j++) {
                if(T[j].get_score() > T[i].get_score()) {
                    // curpos
                    Team temp = T[i];
                    T[i] = T[j];
                    T[j] = temp;
                }
            }
        }

        for(int i = 0; i < T.size(); i++) {
            if(i == 4) {
                if(n != 1)
                    cout << "    ----------------------------------------\n\n";
                else
                    cout << "    --------------------------------------------------------\n\n";
            }
            cout << "   ";
            if(i < T.size() - 1)
                cout << " ";
            cout << i + 1 << ". ";
            T[i].show_name();
            for(int space = 1; space <= 35 - (T[i].get_name()).size(); space++) {
                cout << " ";
            }
            if(n != 1)
                cout << T[i].get_score() - T[3].get_score();
            else {
                if(i < 4) {
                    color("Light Green");
                    cout << "!! Qualified !!";
                    color("White");
                }
                else {
                    color("Black");
                    cout << "?? Disqualified ??";
                    color("White");
                }
            }
            if(firstround) {
                cout << "\n\n";
            }
            else {
                if(i != T.size() - 1)
                    cout << "\n\n";
            }
        }
        n--;
        getchar();
        cout << "\n";
    }
    getchar();

    color("Green");
    cout << "    Qualifier - 1 :    ";
    color("White");
    PrintTeam(T[0].get_name());
    cout << "  v/s  ";
    PrintTeam(T[1].get_name());
    getchar();
    string finalteam1, finalteam2, semifinalteam1,semifinalteam2;
    if(rand()%2) {
        finalteam1 = T[0].get_name();
        semifinalteam1 = T[1].get_name();
    }
    else {
        finalteam1 = T[1].get_name();
        semifinalteam1 = T[0].get_name();
    }
    cout << "\n           Winner :    ";
    PrintTeam(finalteam1);
    cout << "\n";
    getchar();

    color("Light Red");
    cout << "\n       Eliminator :    ";
    color("White");
    PrintTeam(T[2].get_name());
    cout << "  v/s  ";
    PrintTeam(T[3].get_name());
    getchar();
    if(rand()%2) {
        semifinalteam2 = T[2].get_name();
    }
    else {
        semifinalteam2 = T[3].get_name();
    }
    cout << "\n           Winner :    ";
    PrintTeam(semifinalteam2);
    cout << "\n";
    getchar();

    color("Light Red");
    cout << "\n    Qualifier - 2 :    ";
    color("White");
    PrintTeam(semifinalteam1);
    cout << "  v/s  ";
    PrintTeam(semifinalteam2);
    getchar();
    if(rand()%2) {
        finalteam2 = semifinalteam1;
    }
    else {
        finalteam2 = semifinalteam2;
    }
    cout << "\n           Winner :    ";
    PrintTeam(finalteam2);
    cout << "\n";
    getchar();

    string winner;

    color("Red");
    cout << "\n            Final :    ";
    color("White");
    PrintTeam(finalteam1);
    cout << "  v/s  ";
    PrintTeam(finalteam2);
    getchar();
    if(rand()%2) {
        winner = finalteam1;
    }
    else {
        winner = finalteam2;
    }
    cout << "\n           Winner :    ";
    PrintTeam(winner);
    getchar();

    return 0;
}
void shuffle(vector<int>& a) {
    random_shuffle(a.begin(), a.end());
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
