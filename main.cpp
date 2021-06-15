#include <iostream>
#include <vector>

using std::vector;
using namespace std;

void longestAscendingSubsequence(const vector<char> &v) {
    if (v.size() == 0) {
        cout << 0 << endl;
        return;
    }
    int max = 0, current = 1;
    char first = v[0], second;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] > v[i - 1]) {
            current++;
        }
        else if (current > max) {
            max = current;
            second = v[i - current + 1];
            first = i >= current ? v[i - current] : -1;
            current = 1;
        }
        else {
            current = 1;
        }
    }
    cout << max << " " << first;
    if (second > 0) {
        cout << second;
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    char data[] = "cdabcdefbcdeabcdefgh";
    vector<char> v;
    v.insert(v.end(), data, data + sizeof(data) / sizeof(char));
    longestAscendingSubsequence(v);
    return 0;
}