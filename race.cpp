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
void Race();
void Usain_Bolt();
void Yohan_Blake();
void Tyson_Gay();
void Asafa_Powell();
void Justin_Gatlin();
void Christian_Coleman();
void Nesta_Carter();
void Maurice_Greene();
void Steve_Mullings();
void Richard_Thompson();
void color(string);
int main() {
    srand(time(0));
    vector<string> a = {
        "Usain Bolt",
        "Yohan Blake",
        "Tyson Gay",
        "Asafa Powell",
        "Justin Gatlin",
        "Christian Coleman",
        "Nesta Carter",
        "Maurice Greene",
        "Steve Mullings",
        "Richard Thompson"
    };
    int n = a.size();
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        b[i] = i + 1;
    }
    vector<Team> T(n);
    for(int i = 0; i < n; i++) {
        T[i].set_name(a[i]);
    }
    int rounds = a.size()+1;
    int first = 1;
    while(rounds) {
        system("cls");
        cout << "\n    ";
        Race();
        if(first) {
            getchar();
        }
        if(!first) {
            cout << "\n";
        }
        if(rounds > 5) {
            color("Green");
        }
        else if(rounds > 2) {
            color("Yellow");
        }
        else {
            color("Red");
        }
        cout << "\n\n" << "    " << rounds-1 << " Sec ... " << "\n\n";
        color("White");
        // shuffle
        random_shuffle(b.begin(), b.end());
        // count score
        for(int i = 0; i < T.size(); i++) {
            T[i].set_score(T[i].get_score() + b[i]);
        }
        // sort
        for(int i = 0; i < T.size(); i++) {
            for(int j = i + 1; j < T.size(); j++) {
                if(T[j].get_score() > T[i].get_score()) {
                    Team temp = T[i];
                    T[i] = T[j];
                    T[j] = temp;
                }
            }
        }
        // display
        for(int i = 0; i < T.size(); i++) {
            if(i != 9)
                cout << " ";
            cout << "   ";
            cout << i + 1 << ". ";
            PrintTeam(T[i].get_name());
            for(int space = 1; space < 35 - (T[i].get_name()).size(); space++) {
                cout << " ";
            }
            if(rounds == 1) {
                if(i == 0) {
                    color("Yellow");
                    cout << "!! Gold !!";
                    color("White");
                }
                if(i == 1) {
                    color("White");
                    cout << "!! Silver !!";
                    color("White");
                }
                if(i == 2) {
                    color("Black");
                    cout << "!! Bronze !!";
                    color("White");
                }
            }
            // cout << T[i].get_score() << "\n\n";
            cout << "\n\n";
        }
        cout << "    ";
        getchar();
        first = 0;
        rounds--;
    }
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
void Usain_Bolt() {
    string a = "Usain Bolt";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Black");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Yohan_Blake() {
    string a = "Yohan Blake";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Light Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Tyson_Gay() {
    string a = "Tyson Gay";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Red");
            b++;
        }
        else if(b == 1) {
            color("Blue");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Asafa_Powell() {
    string a = "Asafa Powell";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Light Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Justin_Gatlin() {
    string a = "Justin Gatlin";
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
void Richard_Thompson() {
    string a = "Richard Thompson";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Red");
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
void Steve_Mullings() {
    string a = "Steve Mullings";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Light Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Christian_Coleman() {
    string a = "Christian Coleman";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Black");
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
void Nesta_Carter() {
    string a = "Nesta Carter";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Light Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Maurice_Greene() {
    string a = "Maurice Greene";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("White");
            b++;
        }
        else if(b == 1) {
            color("Black");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Race() {
    color("Red");
    cout << "Race :";
    color("White");
}
void PrintTeam(string a) {
    if(a == "Usain Bolt")
        Usain_Bolt();
    if(a == "Yohan Blake")
        Yohan_Blake();
    if(a == "Tyson Gay")
        Tyson_Gay();
    if(a == "Asafa Powell")
        Asafa_Powell();
    if(a == "Justin Gatlin")
        Justin_Gatlin();
    if(a == "Christian Coleman")
        Christian_Coleman();
    if(a == "Nesta Carter")
        Nesta_Carter();
    if(a == "Maurice Greene")
        Maurice_Greene();
    if(a == "Steve Mullings")
        Steve_Mullings();
    if(a == "Richard Thompson")
        Richard_Thompson();
}
