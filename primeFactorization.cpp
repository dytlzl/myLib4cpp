#include<bits/stdc++.h>

using namespace std;

map<long long, int> PF;
void primeF(long long n) {
    if (n < 1) return;
    while (n%2 == 0) {
        PF[2]++;
        n /= 2;
    }
    for (int i = 3; (long long)i*i <= n; i += 2) {
        while (n%i == 0) {
            PF[i]++;
            n /= i;
        }
    }
    if (n != 1) PF[n]++;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    primeF(N);
    int size = PF.size(), i = 0;
    printf("%lld = ", N);
    for (const auto &pf : PF) {
        printf("%lld^%d%s", pf.first, pf.second, i == size-1 ? "\n" : " * ");
        ++i;
    }
    return 0;
}
