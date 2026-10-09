long long fastPow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {          // 如果 b 的当前二进制位是 1
            res = (res * a) % mod;
        }
        a = (a * a) % mod;    // 底数平方
        b >>= 1;              // 右移一位
    }
    return res;
}