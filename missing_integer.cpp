// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

using namespace std;

int solution(vector<int> &A) {
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i] == 0) {
            A[i] = -1;
        }
    }
    for (size_t i = 0; i < A.size(); ++i) {
        int x = A[i];
        while (x > 0 && (unsigned int)(x) < A.size()+1) {
            int y = A[x-1];
            A[x-1] = 0;
            x = y;
        }
    }
    for (size_t i = 0; i < A.size(); ++i) {
        if (A[i]) {
            return i+1;
        }
    }
    return A.size()+1;
}
