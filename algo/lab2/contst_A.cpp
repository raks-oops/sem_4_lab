// Rakin Shahriar 210042116
// contest_A.cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    

    vector<pair<int, int> > v;

    long long t;
    cin >> t;
    while(t--){
        long long price, quality;
        cin >> price >> quality;
        v.push_back(make_pair(price, quality));
    }

    sort(v.begin(), v.end());

    bool flag = false;

    for(long long i=0; i<v.size()-1; i++){
        if(v[i].second > v[i+1].second){
            flag = true;
            break;
        }
    }

    if(flag){
        cout << "Happy Alex";
    }
    else{
        cout << "Poor Alex";
    }



    
    return 0;
}