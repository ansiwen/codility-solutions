// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

using namespace std;

//
// despite the task description, this algorithm is not O(N*log(N)) but O(N)
//

int solution(vector<int> &A) {
    const int N = A.size(); // not larger than 100000, so we can cast
    vector<int> acc_right = vector<int>(N, 0);
    vector<int> acc_left = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) {
        if (A[i] < N-1-i) {
            acc_right[i+A[i]] += 1;
        }
        if (A[i] < i) {
            acc_left[i-A[i]] += 1;
        }
    }
    for (int i = 1; i < N; ++i) {
        acc_right[i] += acc_right[i-1];
        acc_left[N-1-i] += acc_left[N-i];
    }
    int result = 0;
    for (int i = 0; i < N; ++i) {
        result += N-1;
        if (A[i] < N-1-i) {
            result -= acc_left[i+A[i]+1];
        }
        if (A[i] < i) {
            result -= acc_right[i-A[i]-1];
        }
        if (result > 20000000) {
            return -1;
        }
    }
    return result/2;
}