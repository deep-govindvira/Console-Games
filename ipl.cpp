#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

#define N 10

int Run();

int sp = 6;
vector<string> fav;


struct Team;
struct Match;
struct IPL;

void s(int n);
void PrintTeam(string);
void I_P_L();
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
void six();
void four();
void zero();
void Print_run(int);
void color(string);
void set_fav();

int mx_six = 0;
int mx_four = 0;
int mx_run = 0;
double mx_sr = 0;
double mx_nrr = 0;
int mx_ball = 0;
int mx_out = 0;
int mx_hr = 0;
int mx_lr = 0;

int mn_six = 0;
int mn_four = 0;
int mn_run = 0;
double mn_sr = 0;
double mn_nrr = 0;
int mn_ball = 0;
int mn_out = 0;
int mn_hr = 0;
int mn_lr = 0;

struct Team {
    string name = "";
    int id = 0;
    int m = 0;
    int w = 0;
    int l = 0;
    int nr = 0;
    double nrr = 0;
    double sr = 0;
    int pts = 0;
    int r = 0;
    int hr = 0;
    int lr = INT_MAX;
    int b = 0;
    int o = 0;
    int run = 0;
    int ball = 0;
    int s = 0;
    int f = 0;
    string status = "-";

    void show() {
        ::s(3);
        bool favourite = 0;
        for(int i = 0; i < fav.size(); i++) {
            if(name == fav[i]) {
                favourite = 1;
                ::s(27 - name.size());
                PrintTeam(name);
                break;
            }
        }
        if(!favourite)  cout << setw(27) << name;
        cout << setw(sp) << pts;
        if(nrr == mn_nrr)    color("Red");
        if(nrr == mx_nrr)   color("Light Green");
        cout << setw(sp) << nrr;
        color("White");
        if(sr == mn_sr) color("Red");
        if(sr == mx_sr) color("Light Green");
        cout << setw(sp) << setprecision(2) << (sr * 6.0);
        color("White");
        cout << setw(sp) << m;
        cout << setw(sp) << w;
        cout << setw(sp) << l;
        cout << setw(sp) << nr;
        if(r == mn_run) color("Red");
        if(r == mx_run) color("Light Green");
        cout << setw(sp) << r;
        color("White");
        if(b == mx_ball) color("Red");
        if(b == mn_ball) color("Light Green");
        cout << setw(sp) << b;
        color("White");
        if(s == mn_six) color("Red");
        if(s == mx_six) color("Light Green");
        cout << setw(sp) << s;
        color("White");
        if(f == mn_four) color("Red");
        if(f == mx_four) color("Light Green");
        cout << setw(sp) << f;
        color("White");
        if(o == mx_out) color("Red");
        if(o == mn_out) color("Light Green");
        cout << setw(sp) << o;
        color("White");
        if(hr == mn_hr) color("Red");
        if(hr == mx_hr) color("Light Green");
        cout << setw(sp) << hr;
        color("White");
        if(lr == mn_lr) color("Red");
        if(lr == mx_lr) color("Light Green");
        if(lr == INT_MAX)
            cout << setw(sp) << "0";
        else
            cout << setw(sp) << lr;
        color("White");
        if(status == "DSQ") color("Red");
        if(status == "GOOD") color("Light Green");
        if(status == "BAD") color("Yellow");
        if(status == "Q")   color("Green");
        cout << setw(sp) << status << endl;
        color("White");
    }
};

struct Match {
    Team a;
    Team b;
    Team winner;
    Team losser;

    Match(string _a_name = "", string _b_name = "") {
        srand(time(0));
        if(rand() % 2) {
            a.name = _b_name;
            b.name = _a_name;
        }
        a.name = _a_name;
        b.name = _b_name;
    }

    int six(Team c) {
        if(c.name == a.name)    return a.s;
        return b.s;
    }

    int four(Team c) {
        if(c.name == a.name)    return a.f;
        return b.f;
    }

    double NRR(Team c) {
        if(c.name == a.name)    return (((double)(a.run*b.ball)) - ((double)(a.ball*b.run))) / ((double)(a.ball*b.ball));
        else                     return (((double)(b.run*a.ball)) - ((double)(b.ball*a.run))) / ((double)(a.ball*b.ball));
    }

    int run(Team c) {
        if(c.name == a.name)    return a.run;
        return b.run;
    }

    int ball(Team c) {
        if(c.name == a.name)    return a.ball;
        return b.ball;
    }

    int out(Team c) {
        if(c.name == a.name)    return a.o;
        return b.o;
    }

    int LR(Team c) {
        if(c.name == a.name)    return a.lr;
        return b.lr;
    }

    int HR(Team c) {
        if(c.name == a.name)    return a.hr;
        return b.hr;
    }

    void Play() {
        a.m++;
        b.m++;
        if(rand() % 2) {
            Team temp = b;
            b = a;
            a = temp;
        }
        s(3);
        PrintTeam(a.name);
        cout << endl;
        // cout << a.name << endl;
        a.run = 0;
        a.ball = 1;
        for(; a.ball <= 6; a.ball++) {
            bool f = 0;
            for(int i = 0; i < fav.size(); i++) {
                if(fav[i] == a.name || fav[i] == b.name) {
                    f = 1;
                    getchar();
                    break;
                }
            }
            if(!f) cout << endl;
            int cur = Run();
            if(cur == 0)    a.o++;
            if(cur == 4)    a.f++;
            if(cur == 6)    a.s++;
            a.run += cur;
            a.r += a.run;
            a.b += a.ball;
            s(3);
            cout << "Ball - " << a.ball << " : " << a.run << "(";
            Print_run(cur);
            cout << ")     S.R. = " << a.run * 1.0 / a.ball;
        }
        if(a.ball == 7)  a.ball--;
        cout << endl << endl;
        s(3);
        PrintTeam(b.name);
        cout << endl;
        // cout << b.name << endl;
        b.run = 0;
        b.ball = 1;
        for(; b.ball <= 6; b.ball++) {
            if(b.run > a.run) {
                b.ball--;
                break;
            }
            bool f = 0;
            for(int i = 0; i < fav.size(); i++) {
                if(fav[i] == a.name || fav[i] == b.name) {
                    f = 1;
                    getchar();
                    break;
                }
            }
            if(!f) cout << endl;
            int cur = Run();
            if(cur == 0)    b.o++;
            if(cur == 4)    b.f++;
            if(cur == 6)    b.s++;
            b.run += cur;
            b.r += b.run;
            b.b += b.ball;
            s(3);
            cout << "Ball - " << b.ball << " : " << b.run << "(";
            Print_run(cur);
            cout << ")     " << a.run + 1 - b.run << " in " << 6 - b.ball;
            b.nrr = b.r * 1.0 / b.b;
        }
        if(b.ball == 7)  b.ball--;
        cout << endl << endl;
        if(a.run > b.run) {
            a.pts += 2;
            a.nrr += a.run - b.run;
            a.w++;
            b.l++;
            winner = a;
            losser = b;
            s(3);
            PrintTeam(a.name);
            cout << " won by " << a.run - b.run << " runs." << endl;
        }
        else if(a.run < b.run) {
            b.pts += 2;
            b.nrr += b.run - a.run + (7 - b.ball) * 3.0;
            b.w++;
            a.l++;
            winner = b;
            losser = a;
            s(3);
            PrintTeam(b.name);
            cout << " won by " << 6 - b.ball << " balls." << endl;
        }
        else {
            a.pts++;
            b.pts++;
            a.nr++;
            b.nr++;
            s(3);
            cout << "Match Tied." << endl;
        }
        bool f = 0;
        for(int i = 0; i < fav.size(); i++) {
            if(fav[i] == a.name || fav[i] == b.name) {
                f = 1;
                getchar();
                break;
            }
        }
        a.hr = max(a.hr, a.run);
        a.lr = min(a.lr, a.run);
        b.hr = max(b.hr, b.run);
        b.lr = min(b.lr, b.run);
        if(!f) cout << endl;
    }
};
struct IPL {
    vector<Team> g;
    vector<Match> m;
    vector<vector<pair<int, int>>> match = {
        {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}},
        {{1, 3}, {2, 4}, {5, 7}, {6, 9}, {8, 10}},
        {{1, 4}, {2, 3}, {5, 8}, {6, 10}, {7, 9}},
        {{1, 5}, {2, 6}, {3, 7}, {4, 10}, {8, 9}},
        {{1, 6}, {2, 5}, {3, 8}, {4, 9}, {7, 10}},
        {{1, 7}, {2, 8}, {3, 9}, {4, 6}, {5, 10}},
        {{1, 8}, {2, 9}, {3, 10}, {4, 5}, {6, 7}},
        {{1, 9}, {2, 10}, {3, 5}, {4, 7}, {6, 8}},
        {{1, 10}, {2, 7}, {3, 6}, {4, 8}, {5, 9}}
    };
    IPL() {
        g.resize(N);
        g[0].name = "Chennai Super Kings";
        g[0].id = 0;
        g[1].name = "Delhi Capitals";
        g[1].id = 1;
        g[2].name = "Gujarat Titans";
        g[2].id = 2;
        g[3].name = "Kolkata Knight Riders";
        g[3].id = 3;
        g[4].name = "Lucknow Super Giants";
        g[4].id = 4;
        g[5].name = "Mumbai Indians";
        g[5].id = 5;
        g[6].name = "Punjab Kings";
        g[6].id = 6;
        g[7].name = "Rajasthan Royals";
        g[7].id = 7;
        g[8].name = "Royal Challengers Bangalore";
        g[8].id = 8;
        g[9].name = "Sunrisers Hyderabad";
        g[9].id = 9;
        m.resize(45);
        int mi = 0;
        shuffle();
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 5; j++) {
                Match cur(g[match[i][j].first - 1].name, g[match[i][j].second - 1].name);
                m[mi] = cur;
                mi++;
            }
        }
    }

    void shuffle() {
        srand(time(0));
        random_shuffle(match.begin(), match.end());
        for(vector<pair<int, int>>& v : match) {
            random_shuffle(v.begin(), v.end());
            for(auto [i, j] : v) {
                if(rand() % 2) swap(i, j);
            }
        }
    }

    double SR(string name_) {
        for(int i = 0; i < N; i++) {
            if(g[i].name == name_)  return g[i].sr;
        }
        return 0;
    }

    void Schedule() {
        s(3);
        cout <<  "Schedule ..." << endl << endl;
        for(int i = 0; i < m.size(); i++) {
            s(3);
            bool f = 0;
            for(int j = 0; j < fav.size(); j++) {
                if(m[i].a.name == fav[j] || m[i].b.name == fav[j]) {
                    f = 1;
                    cout << "Match - " << i + 1 << " : ";
                    PrintTeam(m[i].a.name);
                    cout << " - ";
                    PrintTeam(m[i].b.name);
                    break;
                }
            }
            if(!f)  cout << "Match - " << i + 1 << " : " << m[i].a.name << " - " << m[i].b.name;
            if(i != m.size() - 1) {
                cout << endl;
            }
            if((i + 1) % 5 == 0) {
                cout << endl;
            }
        }
        for(int i = 0; i < 45; i += 5) {
            int j = rand() % 5;
            int k = rand() % 5;
            if(rand() % 2) {}
        }
        getchar();
    }

    void Point_Table(string q) {
        cout << endl;
        s(3);
        cout << setw(27) << "Team";
        cout << setw(sp) << "Pts";
        cout << setw(sp) << "NRR";
        cout << setw(sp) << "AVG";
        cout << setw(sp) << "M";
        cout << setw(sp) << "W";
        cout << setw(sp) << "L";
        cout << setw(sp) << "NR";
        // cout << setw(5) << "Pts" << endl << endl;
        cout << setw(sp) << "R";
        cout << setw(sp) << "B";
        cout << setw(sp) << "S";
        cout << setw(sp) << "F";
        cout << setw(sp) << "O";
        cout << setw(sp) << "HR";
        cout << setw(sp) << "LR";
        cout << setw(sp + 1) << "OA " << endl << endl;
        mn_six = g[0].s;
        mn_four = g[0].f;
        mn_run = g[0].r;
        mn_sr = g[0].sr;
        mn_nrr = g[0].nrr;
        mn_ball = g[0].b;
        mn_out = g[0].o;
        mn_lr = g[0].lr;
        mn_hr = g[0].hr;
        mx_six = g[0].s;
        mx_four = g[0].f;
        mx_run = g[0].r;
        mx_sr = g[0].sr;
        mx_nrr = g[0].nrr;
        mx_ball = g[0].b;
        mx_out = g[0].o;
        mx_lr = g[0].lr;
        mx_hr = g[0].hr;
        for(int i = 0; i < N; i++) {
            mn_six = min(mn_six, g[i].s);
            mn_four = min(mn_four, g[i].f);
            mn_run = min(mn_run, g[i].r);
            mn_sr = min(mn_sr, g[i].sr);
            mn_nrr = min(mn_nrr, g[i].nrr);
            mn_ball = min(mn_ball, g[i].b);
            mn_out = min(mn_out, g[i].o);
            mn_lr = min(mn_lr, g[i].lr);
            mn_hr = min(mn_hr, g[i].hr);
            mx_six = max(mx_six, g[i].s);
            mx_four = max(mx_four, g[i].f);
            mx_run = max(mx_run, g[i].r);
            mx_sr = max(mx_sr, g[i].sr);
            mx_nrr = max(mx_nrr, g[i].nrr);
            mx_ball = max(mx_ball, g[i].b);
            mx_out = max(mx_out, g[i].o);
            mx_lr = max(mx_lr, g[i].lr);
            mx_hr = max(mx_hr, g[i].hr);
            if(i < 4) {
                if(g[i].status != "DSQ") {
                    g[i].status = "GOOD";
                }
            }
            else {
                if(g[i].status != "DSQ") {
                    g[i].status = "BAD";
                }
            }
        }
        if(q != "Q") {
            for(int i = 0; i < N; i++) {
                if(g[i].pts + 2 * (N - 1 - g[i].m) < g[3].pts) {
                    g[i].status = "DSQ";
                }
                if(i == 4) {
                    s(5);
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                }
                g[i].show();
            }
        }
        else if(q == "Q") {
            for(int i = 0; i < N; i++) {
                if(i == 4) {
                    s(5);
                    cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
                }
                g[i].show();
            }
        }
    }

    void update(string q, Match& m) {
        for(int i = 0; i < N; i++) {
            if(g[i].name == m.a.name || g[i].name == m.b.name) {
                g[i].w += m.winner.name == g[i].name ? 1 : 0;
                g[i].l += m.losser.name == g[i].name ? 1 : 0;
                g[i].r += m.run(g[i]);
                g[i].b += m.ball(g[i]);
                g[i].o += m.out(g[i]);
                g[i].sr = g[i].r * 1.0 / g[i].b;
                g[i].nrr = (m.NRR(g[i]) + g[i].nrr*g[i].m)/(g[i].m + 1);
                g[i].pts += m.winner.name == g[i].name ? 2 : m.winner.name == "" ? 1 : 0;
                g[i].nr += m.winner.name == "" ? 1 : 0;
                g[i].s += m.six(g[i]);
                g[i].f += m.four(g[i]);
                g[i].lr = min(g[i].lr, m.LR(g[i]));
                g[i].hr = max(g[i].hr, m.HR(g[i]));
                g[i].m++;
            }
        }
        if(q == "Q")    return;
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(g[j].pts > g[i].pts) {
                    swap(g[i], g[j]);
                }
                else if(g[j].pts == g[i].pts) {
                    if(g[j].nrr > g[i].nrr) {
                        swap(g[i], g[j]);
                    }
                    else if(g[j].nrr == g[i].nrr) {
                        if(g[j].sr > g[i].sr) {
                            swap(g[i], g[j]);
                        }
                    }
                }
            }
        }
    }

    void ipl() {
        srand(time(0));
        cout << endl; s(3);
        I_P_L();
        cout << endl;
        getchar();
        Schedule();
        for(int i = 0; i < m.size(); i++) {
            system("cls");
            cout << endl;
            s(3);
            I_P_L();
            cout << endl;
            Point_Table(" ");
            bool f = 0;
            for(int j = 0; j < fav.size(); j++) {
                if(fav[j] == m[i].a.name || fav[j] == m[i].b.name) {
                    f = 1;
                    getchar();
                    break;
                }
            }
            if(!f) cout << endl;
            cout << endl;
            s(3);
            cout << "Match - " << i + 1 << " : " << m[i].a.name << " (" << ((SR(m[i].a.name) * 100.0) / (SR(m[i].a.name) + SR(m[i].b.name))) << "%)" << " v/s " << m[i].b.name << " (" << ((SR(m[i].b.name) * 100.0) / (SR(m[i].a.name) + SR(m[i].b.name))) << "%)"  << endl << endl;
            m[i].Play();
            update(" ", m[i]);
        }
        system("cls");
        for(int i = 0; i < N; i++) {
            if(i < 4) {
                g[i].status = "Q";
            }
            else {
                g[i].status = "DSQ";
            }
        }
        cout << endl;
        s(3);
        I_P_L();
        cout << endl;
        Point_Table("Q");
        Play_Off();
    }
    void Play_Off() {
        cout << endl;
        s(3);
        cout << "Qualifier - 1 : " << g[0].name << " (" << ((SR(g[0].name) * 100.0) / (SR(g[0].name) + SR(g[1].name))) << "%)" << " v/s " << g[1].name << " (" << ((SR(g[1].name) * 100.0) / (SR(g[0].name) + SR(g[1].name))) << "%)" << endl << endl;
        Match q1(g[0].name, g[1].name);
        while(q1.winner.name == "") q1.Play();
        string q1w = q1.winner.name;
        string q1l = q1.losser.name;
        update("Q", q1);
        s(3);
        cout << "Eliminator : " << g[2].name << " (" << ((SR(g[2].name) * 100.0) / (SR(g[2].name) + SR(g[3].name))) << "%)" << " v/s " << g[3].name << " (" << ((SR(g[3].name) * 100.0) / (SR(g[2].name) + SR(g[3].name))) << "%)" << endl << endl;
        Match e(g[2].name, g[3].name);
        while(e.winner.name == "")  e.Play();
        string ew = e.winner.name;
        update("Q", e);
        s(3);
        cout << "Qualifier - 2 : " << q1l << " (" << ((SR(q1l) * 100.0) / (SR(q1l) + SR(ew))) << "%)" << " v/s " << ew  << " (" << ((SR(ew) * 100.0) / (SR(q1l) + SR(ew))) << "%)" << endl << endl;
        Match q2(q1l, ew);
        while(q2.winner.name == "") q2.Play();
        string q2w = q2.winner.name;
        update("Q", q2);
        s(3);
        cout << "Final : " << q1w << " (" << ((SR(q1w) * 100.0) / (SR(q1w) + SR(q2w))) << "%)" << " v/s " << q2w << " (" << ((SR(q2w) * 100.0) / (SR(q1w) + SR(q2w))) << "%)" << endl << endl;
        Match f(q1w, q2w);
        while(f.winner.name == "") f.Play();
        update("Q", f);
        string winner = f.winner.name;
        string losser = f.losser.name;
        system("cls");
        cout << endl;
        s(3);
        I_P_L();
        cout << endl << endl;
        s(3);
        cout << "Winner    : ";
        PrintTeam(f.winner.name);
        cout << endl << endl;
        s(3);
        cout << "Runner Up : ";
        PrintTeam(f.losser.name);
        cout << endl << endl;
        Point_Table("Q");
        getchar();
    }
};

int main() {
    srand(time(0));
    IPL Season_2023;
    set_fav();
    Season_2023.ipl();
    // Match a("Chennai Super Kings", "Kolkata Knight Riders");
    // cout << endl;
    // a.Play();
    return 0;
}

int Run() {
    int r = rand() % 7;
    if(r == 3) {
        return 4;
    }
    if(r == 5) {
        return 6;
    }
    return r;
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
void I_P_L() {
    color("Light Red");
    cout << "Indian ";
    color("White");
    cout << "Pr" << "";
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

void s(int n) {
    for(int i = 1; i <= n; i++) {
        cout << " ";
    }
}
void Print_run(int n) {
    if(n != 4 && n != 6 && n != 0) {
        cout << n;
        return;
    }
    if(n == 0) {
        zero();
        return;
    }
    if(n == 4) {
        four();
        return;
    }
    if(n == 6) {
        six();
        return;
    }
}

void zero() {
    color("Red");
    cout << "0";
    color("White");
}
void six() {
    color("Light Green");
    cout << "6";
    color("White");
}
void four() {
    color("Yellow");
    cout << "4";
    color("White");
}

void set_fav() {
    fav.push_back("Chennai Super Kings");
    fav.push_back("Gujarat Titans");
    fav.push_back("Royal Challengers Bangalore");
    fav.push_back("Sunrisers Hyderabad");
    fav.push_back("Kolkata Knight Riders");
    fav.push_back("Lucknow Super Giants");
    fav.push_back("Punjab Kings");
    fav.push_back("Rajasthan Royals");
    fav.push_back("Delhi Capitals");
    fav.push_back("Mumbai Indians");
}
