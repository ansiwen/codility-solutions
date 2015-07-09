//
// Solution for codility test
// https://codility.com/demo/take-sample-test/genomic_range_query/
//
// Copyright 2015, Sven Anderson <sven(at)anderson.de>
//

#include <vector>
#include <string>

using namespace std;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    vector<int> accA = vector<int>(S.size()+1);
    vector<int> accC = vector<int>(S.size()+1);
    vector<int> accG = vector<int>(S.size()+1);
    vector<int> result = vector<int>(P.size());
    int sumA=0, sumC=0, sumG=0;
    for (size_t i = 0; i < S.size(); ++i) {
        switch (S[i]) {
            case 'A':
                ++sumA;
                break;
            case 'C':
                ++sumC;
                break;
            case 'G':
                ++sumG;
                break;
            default:
                break;
        }
        accA[i+1] = sumA;
        accC[i+1] = sumC;
        accG[i+1] = sumG;
    }
    for (size_t i = 0; i < P.size(); ++i) {
        if (accA[P[i]]!=accA[Q[i]+1]) {
            result[i]=1;
        } else if (accC[P[i]]!=accC[Q[i]+1]) {
            result[i]=2;
        } else if (accG[P[i]]!=accG[Q[i]+1]) {
            result[i]=3;
        } else {
            result[i]=4;
        }
    }
    return result;
}
