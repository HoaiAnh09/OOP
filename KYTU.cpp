#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_CHAR = 300;

class CharacterCounter {
private:
    char s[100010];
    int n, res, total, cmax;
    int C[MAX_CHAR], a[MAX_CHAR][MAX_CHAR], vs[MAX_CHAR];

    void dfs(int i) {
        vs[i] = true;
        total += C[i];
        cmax = max(cmax, C[i]);
        for (int j = 0; j < MAX_CHAR; ++j)
            if (!vs[j] && a[i][j]) dfs(j);
    }

public:
    CharacterCounter() : n(0), res(0), total(0), cmax(0) {
        memset(s, 0, sizeof(s));
        memset(C, 0, sizeof(C));
        memset(a, 0, sizeof(a));
        memset(vs, 0, sizeof(vs));
    }

    void setInputString() {
        cin.getline(s, sizeof(s));
        n = strlen(s);
    }

    void countOccurrences() {
        for (int i = 0; i < n; ++i) C[s[i]]++;

        for (int i = 0, j = n - 1; i < j; ++i, --j)
            a[s[i]][s[j]] = a[s[j]][s[i]] = 1;

        for (int i = 0; i < MAX_CHAR; ++i)
            if (!vs[i]) {
                total = cmax = 0;
                dfs(i);
                res += total - cmax;
            }
    }
    void printResult() {
        cout << res << endl;
    }
    friend ostream& operator<<(ostream& os, const CharacterCounter& counter) {
        os << counter.res << endl;
        return os;
    }
};

int main() {
    CharacterCounter counter;
    counter.setInputString();
    counter.countOccurrences();
    cout << counter;

    return 0;
}