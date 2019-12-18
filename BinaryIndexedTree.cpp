/*
 * 0-indexed BIT
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BinaryIndexedTree {
    vector<T> payload;
    BinaryIndexedTree(T n) {
        payload.resize(n, 0);
    }
    T _sum(T i) {
        if (!i) return 0;
        return payload[i-1] + _sum(i-(i&-i));
    }
    T sum(T i) {
        return _sum(i+1);
    }
    void _add(T i, T x) {
        if (i > payload.size()) return;
        payload[i-1] += x;
        _add(i+(i&-i), x);
    }
    void add(T i, T x) {
        _add(i+1, x);
    }
};

int main(){
    int N;
    cin >> N;
    BinaryIndexedTree<int> B(N);
    for (int i = 0; i < N; ++i) {
        B.add(i, i+1);
    }
    for (int i = 0; i < N; ++i) {
        printf("%d, %d, %d\n", B.payload[i], B.sum(i), B.sum(i)-B.sum(i-1));
    }
    return 0;
}
