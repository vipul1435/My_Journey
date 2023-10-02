// Vipul kumar--Welcome to coding workspace
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            cout << i + 1;
            for (int j = 0; j < (n - 1) * 2 - 1 - i * 2; j++)
                cout << " ";
            if (i + 1 < n)
                cout << i + 1 << endl;
            else
                cout << endl;
        }
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i - 1; j++)
                cout << " ";
            cout << i;
            for (int j = 0; j < 2 * (n)-1 - i * 2; j++)
                cout << " ";
            cout << i << endl;
        }
    return 0;
}