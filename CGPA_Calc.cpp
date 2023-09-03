#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stack>
#include <stdio.h>
#include <complex>
#include <list>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define repn(i, b) for (int i = 0; i < b; i++)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = b; i >= a; i--)
#define ff first
#define ss second
#define int long long
#define ln "\n"
#define mii map<int, int>
const int N = 1e5 + 2, MOD = 1e9 + 7;

double CGPA_Calc(vector<double> marks, int n);

signed main()
{
    int n;
    cin >> n;
    vector<double> marks(n);

    repn(i, n)
            cin >>
        marks[i];

    double ans;
    ans = CGPA_Calc(marks, n);

    cout << ans;
    return 0;
}

double CGPA_Calc(vector<double> marks, int n)
{
    vector<double> GPA(n);
    repn(i, n)
    {
        GPA[i] = marks[i] / 10;
    }
    double sum = 0;
    repn(i, n)
    {
        sum += GPA[i];
    }

    double CGPA = sum / n;
    return CGPA;
}