//
// Solution for codility test
// https://codility.com/demo/take-sample-test/equi_leader/
//
// Copyright 2015, Sven Anderson <sven(at)anderson.de>
//

#include <vector>

using namespace std;

int solution(vector<int> &A) {
    const int N = A.size();
    int sum = 0;
    int val = 0;
    for (int i = 0; i < N; ++i) {
        if (sum == 0) {
            sum = 1;
            val = A[i];
        } else {
            if (A[i] == val) {
                ++sum;
            } else {
                --sum;
            }
        }
    }
    if (sum == 0) {
        return 0; // there is no leader
    }
    sum = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] == val) {
            ++sum;
        }
        A[i] = sum;
    }
    if (sum <= N/2) {
        return 0; // there is no leader
    }
    int result = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > (i+1)/2 && sum-A[i] > (N-1-i)/2) {
            ++result;
        }
    }
    return result;
}
