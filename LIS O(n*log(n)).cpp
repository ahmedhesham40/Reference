#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define sz(s) (int)(s.size())
#define all(v) v.begin(),v.end()
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;

using namespace std;


void file() {
#ifndef ONLINE_JUDGE
    freopen("TextFile3.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
}
template<class val>
istream& operator>>(istream& is, vector<val>& vec) {
    for (int i = 0; i < vec.size(); i++)
        is >> vec[i];
    return is;
}
template<class val>
ostream& operator<<(ostream& os, vector<val>& vec) {
    for (int i = 0; i < sz(vec); i++) {
        os << vec[i];
        if (i + 1 < sz(vec))
            os << ' ';
    }
    return os;
}
template<class f, class s>
istream& operator>>(istream& is, pair<f, s>& p) {
    is >> p.first >> p.second;
    return is;
}
template<class f, class s>
ostream& operator<<(ostream& os, pair<f, s>& p) {
    os << p.first << ' ' << p.second;
    return os;
}
int n;
vector<int>arr;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    file();
    cin >> n; 
    arr = vector<int>(n); cin >> arr;
    vector<int>lis(n + 1, INT_MAX);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(all(lis), arr[i]) - lis.begin();
        if (lis[idx] == INT_MAX)cnt++;
        lis[idx] = arr[i];
    }
    cout << cnt;
   
    return 0;
}
