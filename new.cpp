#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[300005];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 2; i < n; i++)
        {
            if (a[i - 1] == a[i])
            {
                printf("NO\n");
                goto end;
            }
            if (a[i] < a[i - 1])
            {
                printf("YES\n");
                for (int j = 1; j <= i; j++)
                    cout << j << ' ';
                for (int j = i + 2; j <= n; j++)
                    cout << j << ' ';
                cout << i + 1 << endl;
                goto end;
            }
        }
        if (a[n - 1] < a[n])
        {
            printf("YES\n");
            for (int i = 1; i <= n; i++)
                cout << i << ' ';
            cout << endl;
        }
        else
            printf("NO\n");
    end:;
    }
}
