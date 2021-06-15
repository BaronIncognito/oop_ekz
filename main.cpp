#include <vector>
#include <iostream>
using std::vector;

void longestAscendingSubsequence(const vector<char> &v) {
    int size = v.size();
    int max = 0, current = 0;
    char second = v[0], first;
    for (int i = 1; i < size; i++) {
        if (v[i] > v[i - 1]) {
            current++;
        }
        else if (current > max) {
            max = current;
            second = v[i - current];
            first = i > current ? v[i - current - 1] : -1;
            current = 1;
        }
    }
    std::cout << max << " " << first;
    if (second >= 0) {
        std::cout << second;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    char data[] = "abcde";
    vector<char> v;
    v.insert(v.end(), data, data + sizeof(data) / sizeof(char));
    longestAscendingSubsequence(v);
    return 0;
}