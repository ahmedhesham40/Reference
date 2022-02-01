int gcd(int a, int b) {
    map<int, int>mpA;
    map<int, int>mpB;
    int res = 1, mx = 0;

    for (int i = 2; i <= sqrt(a); ++i)
    {
        while (a % i == 0)
        {
            if (mx < i)
                mx = i;
            mpA[i]++;
            a /= i;
        }
    }
    if (a != 1)
        mpA[a]++;
    if (mx < a)
        mx = a;

    for (int i = 2; i <= sqrt(b); ++i)
    {
        while (b % i == 0)
        {
            if (mx < i)
                mx = i;
            mpB[i]++;
            b /= i;
        }
    }
    if (b != 1)
        mpB[b]++;
    if (mx < b)
        mx = b;

    for (int i = 2; i <= mx; ++i) {
        if (mpA[i] > 0 && mpB[i] > 0) {
            res *= pow(i, min(mpA[i], mpB[i]));
        }

    }
    return res;

}

int gcdEuclidean(int a, int b) {

    while (b != 0) {
        int x = a;
        a = b;
        b = x % b;
    }
    return a;
}
int lcm(int a, int b) {
    return a / gcdEuclidean(a, b) * b;
}
int lcm2(int a, int b) {
    map<int, int>mpA;
    map<int, int>mpB;
    int res = 1, mx = 0;

    for (int i = 2; i <= sqrt(a); ++i)
    {
        while (a % i == 0)
        {
            if (mx < i)
                mx = i;
            mpA[i]++;
            a /= i;
        }
    }
    if (a != 1)
        mpA[a]++;
    if (mx < a)
        mx = a;

    for (int i = 2; i <= sqrt(b); ++i)
    {
        while (b % i == 0)
        {
            if (mx < i)
                mx = i;
            mpB[i]++;
            b /= i;
        }
    }
    if (b != 1)
        mpB[b]++;
    if (mx < b)
        mx = b;

    for (int i = 2; i <= mx; ++i) {
        if (mpA[i] > 0 || mpB[i] > 0) {
            res *= pow(i, max(mpA[i], mpB[i]));
        }

    }
    return res;
}
