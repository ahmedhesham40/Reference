vector<int> merge(vector<int>&left, vector<int>&right) {
    vector<int>res;
    int l = 0, r = 0;
    while (l < sz(left) && r < sz(right)) {
        if (left[l] <= right[r]) {
            res.push_back(left[l++]);
        }
        else {
            res.push_back(right[r++]);
        }
    }
    while (l < sz(left)) {
        res.push_back(left[l++]);
    }
    while (r < sz(right)) {
        res.push_back(right[r++]);
    }
    return res;
}
vector<int>mergeSort(int l, int r)
{
    if (l == r)return { arr[l] };
    int mid = (l + r) / 2;
    vector<int>right = mergeSort(mid + 1, r);
    vector<int>left = mergeSort(l, mid);
    return merge(left, right);
}
