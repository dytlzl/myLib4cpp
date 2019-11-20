template<typename T>
struct LazySegmentTree {
private:
    int size;
    T initialNode;
    T initialLazy;
    vector<T> node;
    vector<T> lazy;
    function<void(T &, T)> evalFunc;
    function<void(T &, T, T)> parentFunc;
    function<void(T &, T)> propagateFunc;
    function<T(T, T)> getFunc;

public:
    LazySegmentTree(const vector<T> &a, const T _initialNode, const T _initialLazy, const string &method) {
        size = 1;
        initialNode = _initialNode;
        initialLazy = _initialLazy;

        int _size = a.size();
        while (size < _size) size *= 2;

        node.resize(2 * size, initialNode);
        lazy.resize(2 * size, initialLazy);

        if (method == "sum") {
            evalFunc = [](T &_a, const T _b) {
                _a += _b;
            };
            propagateFunc = [](T &_a, const T _b) {
                _a += _b / 2;
            };
            parentFunc = [](T &_a, const T _b, const T _c) {
                _a += _b * _c;
            };
            getFunc = [](const T _a, const T _b) {
                return _a + _b;
            };
        } else if (method == "min") {
            evalFunc = [](T &_a, const T _b) {
                _a = min(_a, _b);
            };
            propagateFunc = evalFunc;
            parentFunc = [](T &_a, const T _b, const T _) {
                _a = min(_a, _b);
            };
            getFunc = [](const T _a, const T _b) {
                return min(_a, _b);
            };
        } else if (method == "starry") {
            evalFunc = [](T &_a, const T _b) {
                _a += _b;
            };
            propagateFunc = [](T &_a, const T _b) {
                _a += _b;
            };
            parentFunc = [](T &_a, const T _b, const T _) {
                _a += _b;
            };
            getFunc = [](const T _a, const T _b) {
                return min(_a, _b);
            };
        }
        for (int i = 0; i < size; i++) node[i + size - 1] = a[i];
        for (int i = size - 2; i >= 0; i--) node[i] = getFunc(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void eval(int k, int l, int r) {
        if (lazy[k] != initialLazy) {
            evalFunc(node[k], lazy[k]);
            if (r - l > 1) {
                propagateFunc(lazy[k * 2 + 1], lazy[k]);
                propagateFunc(lazy[k * 2 + 2], lazy[k]);
            }
            lazy[k] = initialLazy;
        }
    }

    void update(int a, int b, T x, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = size;
        eval(k, l, r);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            parentFunc(lazy[k], x, (r - l));
            eval(k, l, r);
        } else {
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            node[k] = getFunc(node[k * 2 + 1], node[k * 2 + 2]);
        }
    }

    T getRange(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = size;
        eval(k, l, r);
        if (r <= a || b <= l) return initialNode;
        if (a <= l && r <= b) return node[k];
        T lv = getRange(a, b, k * 2 + 1, l, (l + r) / 2);
        T rv = getRange(a, b, k * 2 + 2, (l + r) / 2, r);
        return getFunc(lv, rv);
    }

    T operator[](int _i) {
        return getRange(_i, _i + 1);
    }
};
