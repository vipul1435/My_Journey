#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string temp = "@";
        for (int i = 0; i < s.size(); i++)
        {
            temp += '#';
            temp += s[i];
        }
        temp += '#';
        temp += '&';
        int r = 0;
        int c = 0;
        vector<int> lps(temp.size(), 0);
        for (int i = 1; i < temp.size() - 1; i++)
        {
            int mirr = c - (i - c);
            if (c < r)
            {
                lps[i] = min(lps[mirr], r - i);
            }
            while (temp[i + lps[i] + 1] == temp[i - lps[i] - 1])
            {
                lps[i]++;
            }
            if (i + lps[i] > r)
            {
                c = i;
                r = i + lps[i];
            }
        }
        int ind = 0, maxi = 0;
        for (int i = 1; i < temp.size() - 1; i++)
        {
            if (lps[i] > maxi)
            {
                maxi = lps[i];
                ind = i;
            }
        }
        int dd = ind - maxi + 1;
        dd = (dd - 2) / 2;
        return s.substr(dd, maxi);
    }
};
int main()
{
    string str;
    cin>>str;
    Solution obj;
    string longest_palindrome = obj.longestPalindrome(str);
    cout<<longest_palindrome<<endl;
}