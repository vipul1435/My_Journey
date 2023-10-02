// this is manacher alogith to find the logenst palindrome substring in the o(N)
// this is best alogrith to find the longest palindrome while in dp it gives O(N)sqaure;

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //here we create a string by replcaing # in scpaces
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
        // here create a lps vector and initialize with 0
        vector<int> lps(temp.size(), 0);
        for (int i = 1; i < temp.size() - 1; i++)
        {
            // this is manacher algorith formula
            int mirr = c - (i - c);
            if (c < r)
            {
                lps[i] = min(lps[mirr], r - i);
            }
            // this is brute force
            while (temp[i + lps[i] + 1] == temp[i - lps[i] - 1])
            {
                lps[i]++;
            }
            //updating the condition of 
            if (i + lps[i] > r)
            {
                c = i;
                r = i + lps[i];
            }
        }

        // choosing the greatest integer
        int ind = 0, maxi = 0;
        for (int i = 1; i < temp.size() - 1; i++)
        {
            if (lps[i] > maxi)
            {
                maxi = lps[i];
                ind = i;
            }
        }
        // finding the actual statring index in the main string
        int dd = ind - maxi + 1;
        dd = (dd - 2) / 2;

        // taink the substring
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