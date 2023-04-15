int mod = 998244353;
ll inv(int i) {
    return i <= 1 ? i : mod - (ll)(mod / i) * inv(mod % i) % mod;
}
