#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
map<string, int> value = {
    {"Qatar",29},
    {"Ecuador",24},
    {"Senegal",16},
    {"Netherlands",7},
    {"England",4},
    {"Iran",19},
    {"United States",10},
    {"Wales",31},
    {"Argentina",1},
    {"Saudi Arabia",28},
    {"Mexico",11},
    {"Poland",21},
    {"France",2},
    {"Australia",22},
    {"Denmark",17},
    {"India",31},
    {"Spain",9},
    {"Costa Rica",27},
    {"Germany",14},
    {"Japan",18},
    {"Belgium",5},
    {"Canada",26},
    {"Morocco",13},
    {"Croatia",6},
    {"Brazil",3},
    {"Serbia",20},
    {"Switzerland",12},
    {"Cameroon",25},
    {"Portugal",8},
    {"Ghana",30},
    {"Uruguay",15},
    {"South Korea", 23}
};

bool win(int n) {
    if(n > 0)   return rand()%n == 0;
    if(n == 0)  return rand()%2;
    if(n < 0)   return rand()%(-n) != 0;
    return 1;
}

bool findin(string s, vector<string> v) {
    for(int i = 0; i < v.size(); i++) {
        if(s == v[i])   return 1;
    }
    return 0;
}

void s(int n) {
    for(int i = 1; i <= 15 - n; i++) {
        cout << " ";
    }
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

vector<string> teams = {
    "Qatar",
    "Ecuador",
    "Senegal",
    "Netherlands",
    "England",
    "Iran",
    "United States",
    "Wales",
    "Argentina",
    "Saudi Arabia",
    "Mexico",
    "Poland",
    "France",
    "Australia",
    "Denmark",
    "India",
    "Spain",
    "Costa Rica",
    "Germany",
    "Japan",
    "Belgium",
    "Canada",
    "Morocco",
    "Croatia",
    "Brazil",
    "Serbia",
    "Switzerland",
    "Cameroon",
    "Portugal",
    "Ghana",
    "Uruguay",
    "South Korea"
};

void Qatar() {
    string a = "Qatar";
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
void Ecuador() {
    string a = "Ecuador";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
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
void Senegal() {
    string a = "Senegal";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Green");
            b++;
        }
        else if(b == 1) {
            color("Yellow");
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
void Netherlands() {
    string a = "Netherlands";
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
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void England() {
    string a = "England";
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
void Iran() {
    string a = "Iran";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Green");
            b++;
        }
        else if(b == 1) {
            color("White");
            b++;
        }
        else if(b == 2) {
            color("White");
            b++;
        }
        else if(b == 3) {
            color("Light Red");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void United_States() {
    string a = "United States";
    int b = 0;
    for(int i = 0; i < 6; i++) {
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
    for(int i = 6; i < a.size(); i++) {
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
void Wales() {
    string a = "Wales";
    color("White");
    cout << a[0] << a[1];
    color("Light Red");
    cout << a[2];
    color("Green");
    cout << a[3] << a[4];
    color("White");
}
void Argentina() {
    string a = "Argentina";
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
void Saudi_Arabia() {
    string a = "Saudi Arabia";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Green");
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
void Mexico() {
    string a = "Mexico";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Green");
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
void Poland() {
    string a = "Poland";
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
void Australia() {
    string a = "Australia";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Denmark() {
    string a = "Denmark";
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
void Tunisia() {
    string a = "Tunisia";
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
void Spain() {
    string a = "Spain";
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
void Costa_Rica() {
    string a = "Costa Rica";
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
            b++;
        }
        else if(b == 3) {
            color("White");
            b++;
        }
        else if(b == 4) {
            color("Light Blue");
            b = 1;
        }
        cout << a[i];
    }
    color("White");
}
void Germany() {
    string a = "Germany";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Black");
            b++;
        }
        else if(b == 1) {
            color("Light Red");
            b++;
        }
        else if(b == 2) {
            color("Yellow");
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
void Belgium() {
    string a = "Belgium";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Black");
            b++;
        }
        else if(b == 1) {
            color("Yellow");
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
void Canada() {
    string a = "Canada";
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
void Morocco() {
    string a = "Morocco";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Croatia() {
    string a = "Croatia";
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
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Brazil() {
    string a = "Brazil";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Yellow");
            b++;
        }
        else if(b == 1) {
            color("Light Blue");
            b++;
        }
        else if(b == 2) {
            color("Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Serbia() {
    string a = "Serbia";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("Light Blue");
            b++;
        }
        else if(b == 2) {
            color("White");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Switzerland() {
    string a = "Switzerland";
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
void Cameroon() {
    string a = "Cameroon";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Green");
            b++;
        }
        else if(b == 1) {
            color("Light Red");
            b++;
        }
        else if(b == 2) {
            color("Yellow");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Portugal() {
    string a = "Portugal";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Green");
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
void Ghana() {
    string a = "Ghana";
    int b = 0;
    for(int i = 0; i < a.size(); i++) {
        if(b == 0) {
            color("Light Red");
            b++;
        }
        else if(b == 1) {
            color("Yellow");
            b++;
        }
        else if(b == 2) {
            color("Green");
            b = 0;
        }
        cout << a[i];
    }
    color("White");
}
void Uruguay() {
    string a = "Uruguay";
    int b = 0;
    color("Yellow");
    cout << a[0];
    for(int i = 1; i < a.size(); i++) {
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

void Team(string a) {
    if(a == "Qatar")
        Qatar();
    if(a == "Ecuador")
        Ecuador();
    if(a == "Senegal")
        Senegal();
    if(a == "Netherlands")
        Netherlands();
    if(a == "England")
        England();
    if(a == "Iran")
        Iran();
    if(a == "United States")
        United_States();
    if(a == "Wales")
        Wales();
    if(a == "Argentina")
        Argentina();
    if(a == "Saudi Arabia")
        Saudi_Arabia();
    if(a == "Mexico")
        Mexico();
    if(a == "Poland")
        Poland();
    if(a == "France")
        France();
    if(a == "Australia")
        Australia();
    if(a == "Denmark")
        Denmark();
    if(a == "Tunisia")
        Tunisia();
    if(a == "Spain")
        Spain();
    if(a == "Costa Rica")
        Costa_Rica();
    if(a == "Germany")
        Germany();
    if(a == "Japan")
        Japan();
    if(a == "Belgium")
        Belgium();
    if(a == "Canada")
        Canada();
    if(a == "Morocco")
        Morocco();
    if(a == "Croatia")
        Croatia();
    if(a == "Brazil")
        Brazil();
    if(a == "Serbia")
        Serbia();
    if(a == "Switzerland")
        Switzerland();
    if(a == "Cameroon")
        Cameroon();
    if(a == "Portugal")
        Portugal();
    if(a == "Ghana")
        Ghana();
    if(a == "Uruguay")
        Uruguay();
    if(a == "South Korea")
        South_Korea();
    if(a == "India")
        India();
}


void play() {
    system("cls");
    vector<int> point(32, 0);
    random_shuffle(teams.begin(), teams.end());
    vector<string> a;
    for(int i = 0; i < 32; i++) {
        a.push_back(teams[i]);
    }
    for(int i = 0; i < a.size();) {
        cout << a[i]; i++;
        if(i%2 == 0)    cout << endl;
        cout << endl;
    }
    getchar();
    system("cls");
    for(int i = 0; i < 32; i++) point[i] = i + 1;
    random_shuffle(point.begin(), point.end());
    vector<string> b;
    for(int i = 0; i < a.size(); i += 2) {
        if(point[value[a[i]]] + value[a[i + 1]] - value[a[i]] > point[value[a[i + 1]]])   b.push_back(a[i]);
        else              b.push_back(a[i + 1]);
    }
    for(int i = 0, j = 0; i < a.size();) {
        if(findin(a[i], b)) {
            Team(a[i]);
        }
        else {
            cout << a[i];
        }
        s(a[i].size());i++;
        if(9 <= i and i < 25) {
            cout << " " << b[j]; j++;
        }
        if(i%2 == 0)    cout << endl;
        cout << endl;
    }
    getchar();
    system("cls");
    random_shuffle(point.begin(), point.end());
    vector<string> c;
    for(int i = 0; i < b.size(); i += 2) {
        if(point[value[b[i]]] + value[b[i + 1]] - value[b[i]] > point[value[b[i + 1]]])   c.push_back(b[i]);
        // if(value[b[i]] < value[b[i + 1]])         c.push_back(b[i]);
        else            c.push_back(b[i + 1]);
    }
    for(int i = 0, j = 0, k = 0; i < a.size();) {
        if(findin(a[i], b)) {
            Team(a[i]);
        }
        else {
            cout << a[i];
        }
        s(a[i].size());i++;
        if(9 <= i and i < 25) {
            cout << " "; 
            if(findin(b[j], c))    Team(b[j]);
            else cout << b[j];
            s(b[j].size()); j++;
        }
        if(13 <= i and i < 21) {
            cout << " " << c[k]; k++;
        }
        if(i%2 == 0)    cout << endl;
        cout << endl;
    }
    getchar();
    system("cls");
    random_shuffle(point.begin(), point.end());
    vector<string> d;
    for(int i = 0; i < c.size(); i += 2) {
        if(point[value[c[i]]] + value[c[i + 1]] - value[c[i]] > point[value[c[i + 1]]])   d.push_back(c[i]);
        // if(value[c[i]] < value[c[i + 1]])    d.push_back(c[i]);
        else            d.push_back(c[i + 1]);
    }
    for(int i = 0, j = 0, k = 0, l = 0; i < a.size();) {
        if(findin(a[i], b)) {
            Team(a[i]);
        }
        else {
            cout << a[i];
        }
        s(a[i].size());i++;
        if(9 <= i and i < 25) {
            cout << " ";
            if(findin(b[j], c))    Team(b[j]);
            else cout << b[j];
            s(b[j].size()); j++;
        }
        if(13 <= i and i < 21) {
            cout << " ";
            if(findin(c[k], d)) Team(c[k]);
            else cout << c[k];
            s(c[k].size()); k++;
        }
        if(15 <= i and i < 19) {
            cout << " " << d[l]; l++;
        }
        if(i%2 == 0)    cout << endl;
        cout << endl;
    }
    getchar();
    system("cls");
    random_shuffle(point.begin(), point.end());
    vector<string> e;
    for(int i = 0; i < d.size(); i += 2) {
        if(point[value[d[i]]] + value[d[i + 1]] - value[d[i]] > point[value[d[i + 1]]])   e.push_back(d[i]);
        // if(value[d[i]] < value[d[i + 1]])         e.push_back(d[i]);
        else            e.push_back(d[i + 1]);
    }
    for(int i = 0, j = 0, k = 0, l = 0, m = 0; i < a.size();) {
        if(findin(a[i], b)) {
            Team(a[i]);
        }
        else {
            cout << a[i];
        }
        s(a[i].size());i++;
        if(9 <= i and i < 25) {
            cout << " ";
            if(findin(b[j], c))    Team(b[j]);
            else cout << b[j];
            s(b[j].size()); j++;
        }
        if(13 <= i and i < 21) {
            cout << " ";
            if(findin(c[k], d)) Team(c[k]);
            else cout << c[k];
            s(c[k].size()); k++;
        }
        if(15 <= i and i < 19) {
            cout << " ";
            if(findin(d[l], e)) Team(d[l]);
            else cout << d[l];
            s(d[l].size()); l++;
        }
        if(16 <= i and i < 18) {
            cout << " " << e[m]; m++;
        }
        if(i%2 == 0)    cout << endl;
        cout << endl;
    }
    getchar();
    system("cls");
    random_shuffle(point.begin(), point.end());
    vector<string> f;
    for(int i = 0; i < e.size(); i += 2) {
        if(point[value[e[i]]] + value[e[i + 1]] - value[e[i]] > point[value[e[i + 1]]])   f.push_back(e[i]);
        // if(value[e[i]] < value[e[i + 1]])    f.push_back(e[i]);
        else            f.push_back(e[i + 1]);
    }
    for(int i = 0, j = 0, k = 0, l = 0, m = 0, n = 0; i < a.size();) {
        if(findin(a[i], b)) {
            Team(a[i]);
        }
        else {
            cout << a[i];
        }
        s(a[i].size());i++;
        if(9 <= i and i < 25) {
            cout << " ";
            if(findin(b[j], c))    Team(b[j]);
            else cout << b[j];
            s(b[j].size()); j++;
        }
        if(13 <= i and i < 21) {
            cout << " ";
            if(findin(c[k], d)) Team(c[k]);
            else cout << c[k];
            s(c[k].size()); k++;
        }
        if(15 <= i and i < 19) {
            cout << " ";
            if(findin(d[l], e)) Team(d[l]);
            else cout << d[l];
            s(d[l].size()); l++;
        }
        if(16 <= i and i < 18) {
            cout << " ";
            if(findin(e[m], f)) Team(e[m]);
            else cout << e[m];
            s(e[m].size()); m++;
        }
        if(i == 16) {
            cout << endl;
            for(int sp = 1; sp <= 16*5; sp++) {
                cout << " ";
            }
            Team(f[n]); n++;
        }
        if(i%2 == 0 and i != 16)    cout << endl;
        cout << endl;
    }
    getchar();
    system("cls");
}

int main() {
    srand(time(0));
    getchar();
    while(1)    play();
    return 0;
}