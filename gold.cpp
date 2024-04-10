#include <bits/stdc++.h>
using namespace std;

int select(int nn) {
    return rand() % nn;
}

int n = 10, mi = -1, mj = -1, gi = -1, gj = -1, cnt = 0;
bool magic = 1, hint = 1;
vector<vector<int>> secure;
vector<vector<int>> vis;

bool me(int i, int j) {
    return i == mi and j == mj;
}

bool safe(int i, int j) {
    for(int k = 0; k < secure.size(); k++) {
        if(secure[k][0] == i and secure[k][1] == j) {
            return 1;
        }
    }
    return 0;
}

bool gold(int i, int j) {
    return i == gi and j == gj;
}

void row(int i) {
    cout << '|';
    for(int j = 0; j < n; j++) {
        if(safe(i, j)) {
            if(me(i, j)) {
                if(gold(i, j)) {
                    cout << '@';
                }
                else {
                    cout << 'o';
                }
            }
            else {
                if(gold(i, j)) {
                    cout << ' ';
                    // cout << '$';
                }
                else if(vis[i][j]) {
                    cout << '.';
                }
                else {
                    cout << ' ';
                }
            }
        }
        else {
            if(gold(i, j)) {
                cout << '!';
            }
            else if(me(i, j)) {
                cout << 'x';
            }
            else {
                cout << '#';
            }
        }
        cout << ' ';
    }
    cout << "|";
}

void board() {
    cout << " ";
    for(int i = 0; i < 2 * n; i++) {
        cout << "_";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        row(i);
        cout << endl;
    }
    cout << " ";
    for(int i = 0; i < 2 * n; i++) {
        cout << "-";
    }
}

void Lost() {
    system("cls");
    board();
    cout << endl << endl << "     You Lost. ";
    getchar();
    getchar();
    exit(0);
}

void Won() {
    system("cls");
    board();
    cout << endl << endl << "      You Won. ";
    getchar();
    getchar();
    exit(0);
}

void move() {
    char c;
    if(mi == -1 or mj == -1) {
        mi = select(n);
        mj = select(n);
    }
    else {
        cout << endl << endl << "          ";
        cin >> c;
        if(c == 'a')    mj = (mj - 1 + n) % n;
        if(c == 'w')    mi = (mi - 1 + n) % n;
        if(c == 'd')    mj = (mj + 1) % n;
        if(c == 's')    mi = (mi + 1) % n;
        if(c == 'q')    {mj = (mj - 1 + n) % n; mi = (mi - 1 + n) % n;}
        if(c == 'e')    {mj = (mj + 1) % n; mi = (mi - 1 + n) % n;}
        if(c == 'z')    {mj = (mj - 1 + n) % n; mi = (mi + 1) % n;}
        if(c == 'x')    {mj = (mj + 1) % n; mi = (mi + 1) % n;}
        if(c == 't' and magic)    {   cin >> mi;  cin >> mj;  magic = 0;}
        if(c == 'h' and hint and cnt > 32) {
            hint = 0;
            cout << endl << " ";
            if(mi == gi or mj == gj or abs(gi - mi) == abs(gj - mj)) {
                cout << "Cross";
            }
            else {
                if(gi < mi and gj < mj) {
                    cout << "Left Up";
                }
                else if(gi > mi and gj < mj) {
                    cout << "Left Down";
                }
                else if(gi > mi and gj > mj) {
                    cout << "Right Down";
                }
                else {
                    cout << "Right Up";
                }
            }
            getchar();
            getchar();
        }
        mi = mi % n;
        mj = mj % n;
    }
    if(!safe(mi, mj))   Lost();
    if(gold(mi, mj))    Won();
    vis[mi][mj]++;
}

void kill(int idx) {
    if(secure.size() == 0) Lost();
    int i = secure[idx][0];
    int j = secure[idx][1];
    // while(gold(i, j)) {
    //     idx = select((int)secure.size());
    //     i = secure[idx][0];
    //     j = secure[idx][1];
    // }
    secure.erase(secure.begin() + idx);
    if(me(i, j) or gold(i, j))  Lost();
}

void ini() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            secure.push_back({i, j});
        }
    }
    gi = select(n);
    gj = select(n);
    vis = vector<vector<int>> (n, vector<int> (n, 0));
}

int main() {
    srand(time(0));
    ini();
    while(1) {
        random_shuffle(secure.begin(), secure.end());
        board();
        int next = select((int)secure.size());
        int i = secure[next][0];
        int j = secure[next][1];
        if(abs(i - mi) + abs(j - mj) <= 3 and abs(gi - i) + abs(gj - j) <= 3) {
            cout << endl <<  " You and Gold are in Danger." << endl;
        }
        else if(abs(i - mi) + abs(j - mj) <= 3) {
            cout << endl << " You are in Danger." << endl;
        }
        else if(abs(gi - i) + abs(gj - j) <= 3) {
            cout << endl << " Gold is in Danger." << endl;
        }
        move();
        kill(next);
        kill(next);
        cnt++;
        system("cls");
    }
    return 0;
}

