#include <bits/stdc++.h>
using namespace std;
struct detail
{
    string name;
    int age;
    int mark;
};
bool according_to(detail a, detail b)
{
    return a.name < b.name;
}
void data_sort(detail a[], int n){
    sort(a, a+n , according_to); // third argument is called comprator. 
}
int main()
{
    int s;
    cin >> s;
    detail data[s];
    for (int i = 0; i < s; i++)
    {
        cin >> data[i].name;
        cin >> data[i].age;
        cin >> data[i].mark;
    }
    data_sort(data, s);
    for (int i = 0; i < s; i++)
    {
    cout<< data[i].name<< " ";
        cout<<data[i].age<< " ";
    cout<< data[i].mark<<endl;
    }
    return 0;
}