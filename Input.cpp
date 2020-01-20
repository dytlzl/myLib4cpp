struct Input {
    vector<vector<string> > buf;

    Input() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
    }

    void readLines() {
        string s;
        while (getline(cin, s)) {
            buf.emplace_back(split(s, ' '));
        }
    }

    static vector<string> split(string &s, char delimiter) {
        vector<string> v;
        string tmp;
        for (const auto c : s) {
            if (c == delimiter) {
                v.push_back(tmp);
                tmp.clear();
            } else {
                tmp += c;
            }
        }
        if (!tmp.empty()) v.push_back(tmp);
        return v;
    }

};
