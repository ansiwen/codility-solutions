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
    //cout << "nextDiv: " << x << endl;
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
        //cout << "i: " << i << endl;
        if ( i < N-1 && A[i] > A[i+1] && A[i] > A[i-1]) {
            //cout << "peak: " << i << endl;
            last_peak = i;
            i = endOfBlock(last_peak, div);
        }
        if ((i+1)%div == 0) {
            // cout << "just leaving block" << endl;
            if (i-last_peak >= div && div < N) {
                //cout << "there was no peak in this block, increase div" << endl;
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
