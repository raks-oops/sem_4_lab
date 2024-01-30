// Rakin Shahriar 210042116
// contest_B.cpp
 
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int s,n;
    bool flag = true;
    cin >> s >> n;
    pair <int, int> a[n];

    for(int i=0; i<n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
 
    sort(a, a+n);

    for(int i=0; i<n; i++)
    {
        if(s > a[i].first)
        {
            s = s + a[i].second;
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}