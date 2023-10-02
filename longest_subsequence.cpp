#include <bits/stdc++.h>
using namespace std;
int lcs(int l, int r, string s, string t, vector<vector<int>> &dp)
{
    if (l >= s.size() or r >= t.size())
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    if (s[l] == t[r])
        return dp[l][r] =
                   1 + lcs(l + 1, r + 1, s, t, dp);
    else
        return dp[l][r] = max(
                   lcs(l, r + 1, s, t, dp),
                   lcs(l + 1, r, s, t, dp));
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> dp(s1.size(),vector<int>(s2.size(),-1));
	int len = lcs(0,0,s1,s2,dp);
    cout<<len<<endl;
}