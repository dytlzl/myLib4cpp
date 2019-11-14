#include<bits/stdc++.h>
using namespace std;
struct itorrent {
    template <typename _T> inline const itorrent& operator>>(_T &_a) const {
        _T f = 1;
        _a = 0;
        char c = getchar();
        while (c < '0' || c > '9' ) {
            if (c == '-') f = -1;
            c = getchar();
        }
        while (c >= '0' && c <= '9') {
            _a = _a*10+c-'0';
            c = getchar();
        }
        _a *= f;
        return *this;
    }
    inline const itorrent& operator>>(string &_a) const {
        char c = getchar();
        while (c < '!' || c > '~') {
            c = getchar();
        }
        while ( c >= '!' && c <= '~') {
            _a += c;
            c = getchar();
        }
        return *this;
    }
    template <typename _T> inline const itorrent& operator>>(vector<_T> &_a) const {
        for (auto &__a : _a) {
            *this >> __a;
        }
        return *this;
    }
    template <typename _T1, typename _T2> inline const itorrent& operator>>(pair<_T1, _T2> &_a) const {
        *this >> _a.first >> _a.second;
        return *this;
    }
};
struct otorrent {
    const otorrent& operator<<(const int _a) const {
        printf("%d", _a);
        return *this;
    }
    const otorrent& operator<<(const long long _a) const {
        printf("%lld", _a);
        return *this;
    }
    const otorrent& operator<<(const float _a) const {
        printf("%f", _a);
        return *this;
    }
    const otorrent& operator<<(const double _a) const {
        printf("%lf", _a);
        return *this;
    }
    const otorrent& operator<<(const string _a) const {
        int _asize = _a.size();
        for (int i = 0; i < _asize; i++) {
            putchar(_a[i]);
        }
        return *this;
    }
    const otorrent& operator<<(const char _a) const {
        putchar(_a);
        return *this;
    }
    template <typename _T> const otorrent& operator<(_T _a) const {
        *this << _a;
        putchar(' ');
        return *this;
    }
    template <typename _T> const otorrent& operator<=(_T _a) const {
        *this << _a;
        putchar('\n');
        return *this;
    }
    template <typename _T> const otorrent& operator<(vector<_T> _a) const {
        int _asize = _a.size();
        for (int i = 0; i < _asize; i++) {
            *this << _a[i];
            putchar(i == _asize-1 ? '\n' : ' ');
        }
        return *this;
    }
    template <typename _T> const otorrent& operator<=(vector<_T> _a) const {
        int _asize = _a.size();
        for (int i = 0; i < _asize; i++) {
            *this < _a[i];
            putchar('\n');
        }
        return *this;
    }
    template <typename _T1, typename _T2> const otorrent& operator<<(pair<_T1, _T2> _a) const {
        return *this << _a.first << ' ' <<_a.second;
    }
    void operator++(int) const {
        putchar('\n');
    }
};
int main() {
    itorrent cin;
    otorrent cout;
    int N, K;
    cin >> N >> K;
    vector<pair<int, pair<int, int> > > V(N);
    cin >> V;
    cout < N <= K;
    cout << N;
    cout <= K;
    cout++;
    cout < V;
    cout++;
    cout <= V;
    cout++;
    cout < N <= K;
    return 0;
}
