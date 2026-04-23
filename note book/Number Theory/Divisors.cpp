long long divi(long long n) { // complexity: O(sqrt(n))
    long long res = 1;
    for (long long i = 2; i * i <= n; i++) {
        long long cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        res *= (cnt + 1);
    }
    if (n > 1) res *= 2; // n is a prime factor
    return res;
}