// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    const size_t N = A.size();
    vector<int> stack;
    int bodycount = 0;
    for (size_t i = 0; i < N; ++i) {
        if (B[i]) {
            stack.push_back(A[i]);
        } else {
            while (stack.size() && stack.back() < A[i]) {
                stack.pop_back();
                ++bodycount;
            }
            if (stack.size()) {
                ++bodycount;
            }
        }
    }
    return N-bodycount;
}
