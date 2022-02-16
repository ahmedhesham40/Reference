const int mod = 1e9 + 7;
// NCR 
ll nCr(ll n, ll r){
	ll ans = 1;
	ll div = 1; // r! 
	for (ll i = r + 1; i <= n; i++){
		ans = ans * i;
		ans /= div;
		div++;
	}
	return ans;
}
// NPR 
ll NpR(ll n, ll r){
	ll ans = 1;
	for (ll i = (n - r) + 1; i <= n; i++){
		ans *= i;
		ans %= mod;
	}
	return ans;
}
