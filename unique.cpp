#include <bits/stdc++.h>
using namespace std;
int main()
{
    // uniqe functionis used to remove continiuos repetatin of elements;
    // example;
    // arrr[]= { 1,2,5,5,2,2,1,1,3,3,5,5};
    // unique function return
    // arrr = {1,2,5,2,1,3,5}
    // syntex
    vector<int> v = {1, 1, 1, 3, 5, 5, 1, 1};
    vector<int>::iterator it;
    it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));
    for (auto p : v)
        cout << p << " ";
    cout << endl;
}