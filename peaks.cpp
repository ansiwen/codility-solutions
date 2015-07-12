//
// Solution for codility test
// https://codility.com/demo/take-sample-test/peaks/
//
// Copyright 2015, Sven Anderson <sven(at)anderson.de>
//

#include <vector>

using namespace std;

inline int nextDiv(int N, int x) {
    while (N%(++x)) {
        if (x > N) {
            return N;
        }
    }
    return x;
}

inline int endOfBlock(int pos, int div) {
    return (pos/div + 1)*div-1;
}

int solution(vector<int> &A) {
    const int N = A.size();
    int last_peak = -1;
    int div = nextDiv(N, 1);
    for (int i = 1; i < N; ++i) {
        if ( i < N-1 && A[i] > A[i+1] && A[i] > A[i-1]) {
            last_peak = i;
            i = endOfBlock(last_peak, div);
        }
        if ((i+1)%div == 0) {
            if (i-last_peak >= div && div < N) {
                div = nextDiv(N, div);
                if (last_peak != -1) {
                    i = endOfBlock(last_peak, div);
                }
            }
        }
    }
    if (last_peak==-1) {
        return 0;
    }
    return N/div;
}
