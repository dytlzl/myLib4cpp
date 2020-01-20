struct Sieve {
    vector<int> vec;

    explicit Sieve(int n) : vec(n + 1) {
        for (int i = 2; i <= n; ++i) {
            if (vec[i] == 0) {
                vec[i] = i;
                for (long long j = (long long) i * i; j <= n; j += i) {
                    if (vec[j] == 0) vec[j] = i;
                }
            }
        }
    }

    vector<pair<int, int> > factorize(int n) {
        vector<pair<int, int> > res;
        if (vec[n] == 0) return res;
        res.emplace_back(vec[n], 1);
        n /= vec[n];
        while (vec[n] != 0) {
            if (vec[n] == res.back().first) {
                ++res.back().second;
            } else {
                res.emplace_back(vec[n], 1);
            }
            n /= vec[n];
        }
        return res;
    }
};
