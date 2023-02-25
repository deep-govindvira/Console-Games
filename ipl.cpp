#include <bits/stdc++.h>
using namespace std;
void shuffle(vector<int>& a);
void up_down(int n);
void delay();
class Team {
  private :
    string name;
    int score;
    int growth;
    int prepos;
    int curpos;
    int change;
  public :
    Team() {
        this->name = "";
        this->score = 0;
        this->growth = 0;
        this->prepos = 10;
        this->curpos = 10;
        this->change = 0;
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
    int get_growth() {
        return this->growth;
    }
    int get_prepos() {
        return this->prepos;
    }
    int get_curpos() {
        return this->curpos;
    }
    int get_change() {
        return this->change;
    }
    void set_name(string a) {
        this->name = a;
    }
    void set_score(int a) {
        this->score = a;
    }
    void set_growth(int a) {
        this->growth = a;
    }
    void set_prepos(int a) {
        this->prepos = a;
    }
    void set_curpos(int a) {
        this->curpos = a;
    }
    void set_change(int a) {
        this->change = a;
    }
};
void round(vector<Team>& T, vector<int>& b, int& n);
void firstround(vector<Team>& T, vector<int>& b, int& n);
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
    cout << "\n   Indian Premier League\n\n";
    delay();
    firstround(T, b, n);
    while(n != 1) {
        cout << endl;
        round(T, b, n);
        cout << "   ";
        if(n < 10)
            cout << " ";
        cout << n << "." << T[n - 1].get_name();
        for(int i = 1; i <= 33 - (T[n - 1].get_name()).size(); i++)
            cout << " ";
        cout << "Eliminated." << endl << endl;
        n--;
    }
    getchar();
    return 0;
}
void shuffle(vector<int>& a) {
    for(int times = 1; times <= a.size(); times++) {
        for(int i = 0; i < a.size(); i++) {
            for(int j = i + 1; j < a.size(); j++) {
                if(rand() % 2) {
                    a[i] = a[i] ^ a[j];
                    a[j] = a[i] ^ a[j];
                    a[i] = a[i] ^ a[j];
                }
            }
        }
    }
}
void up_down(int n) {
    if(n > 0) {
        for(int i = 1; i <= n; i++)
            cout << (char)(24) << " ";
    }
    else if(n < 0) {
        n = -n;
        for(int i = 1; i <= n; i++)
            cout << (char)(25) << " ";
    }
    else
        cout << "-";
}
void round(vector<Team>& T, vector<int>& b, int& n) {
    shuffle(b);
    // couting score;
    for(int i = 0; i < n; i++) {
        T[i].set_score(T[i].get_score() + b[i]);
        T[i].set_growth(b[i]);
    }
    // sorting
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(T[j].get_score() > T[i].get_score()) {
                // curpos
                T[i].set_curpos(j + 1);
                T[j].set_curpos(i + 1);
                Team temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
    // change + prepos;
    for(int i = 0; i < n; i++) {
        T[i].set_change(T[i].get_prepos() - T[i].get_curpos());
        T[i].set_prepos(T[i].get_curpos());
    }
    // display
    for(int i = 0; i < n - 1; i++) {
        cout << "   ";
        delay();
        if(i < 9)
            cout << " ";
        cout << i + 1 << ". " << T[i].get_name();
        for(int space = 1; space <= 35 - (T[i].get_name()).size(); space++) {
            cout << " ";
        }
        cout << T[i].get_score();
        if(i != n - 1)
            cout << "(+" << T[i].get_score() - T[n - 2].get_score() << ")";
        else
            cout << "(+0)";
        int space = 5;
        if(T[i].get_score() < 10) {
            space++;
        }
        if(T[i].get_score() - T[n - 1].get_score() < 10)
            space++;
        while(space--)
            cout << " ";
        up_down(T[i].get_change());
        cout << endl << endl;
    }
}
void firstround(vector<Team>& T, vector<int>& b, int& n) {
    shuffle(b);
    // couting score;
    for(int i = 0; i < n; i++) {
        T[i].set_score(T[i].get_score() + b[i]);
        T[i].set_growth(b[i]);
    }
    // sorting
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(T[j].get_score() > T[i].get_score()) {
                // curpos
                T[i].set_curpos(j + 1);
                T[j].set_curpos(i + 1);
                Team temp = T[i];
                T[i] = T[j];
                T[j] = temp;
            }
        }
    }
    // change + prepos;
    for(int i = 0; i < n; i++) {
        T[i].set_change(T[i].get_prepos() - T[i].get_curpos());
        T[i].set_prepos(T[i].get_curpos());
    }
    // display
    for(int i = 0; i < n; i++) {
        cout << "   ";
        delay();
        if(i < 9)
            cout << " ";
        cout << i + 1 << ". " << T[i].get_name();
        for(int space = 1; space <= 35 - (T[i].get_name()).size(); space++) {
            cout << " ";
        }
        cout << T[i].get_score();
        if(i != n - 1)
            cout << "(+" << T[i].get_score() - T[n - 1].get_score() << ")";
        else
            cout << "(+0)";
        cout << endl << endl;
    }
}
void delay() {
    for(int i = 0; i <= INT_MAX / 2; i++);
}
