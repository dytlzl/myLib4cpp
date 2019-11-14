/*
 * return minimum x which func(x) returns false
 * 
 * 
 * bool func(long long x) { // upper bound
 *     return x <= k; // or !(x > k)
 * }
 * bool func(long long x) { // lower bound
 *     return x < k;
 * }
 */
long long binSearch(long long first, long long last, bool func(long long)) {
    long long len = last-first;
    while (len != 0) {
        long long half = len / 2;
        long long mid = first+half;
        if (func(mid)) {
            len -= half + 1;
            first = ++mid;
        } else {
            len = half;
        }
    }
    return first;
}
