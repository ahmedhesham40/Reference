int fastPower(int base, int power) {
    if (power == 0)return 1;
    int res = fastPower(base, power / 2) % mod;
    res = ((res % mod) * (res % mod)) % mod;
    if (power % 2) {
        return ((res % mod) * (base % mod)) % mod;
    }
    else return res;
}
