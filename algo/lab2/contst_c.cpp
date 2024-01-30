// Rakin Shahriar 210042116
// contest_C.cpp

#include <bits/stdc++.h>
using namespace std;

long long mrgcnt(string& str, int left, int mid, int right) {
    long long inversions = 0;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<char> leftArr(n1);
    vector<char> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = str[left + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = str[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            str[k++] = leftArr[i++];
        } else {
            str[k++] = rightArr[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1)
        str[k++] = leftArr[i++];

    while (j < n2)
        str[k++] = rightArr[j++];

    return inversions;
}

long long mergeSortAndCount(string& str, int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCount(str, left, mid);
        inversions += mergeSortAndCount(str, mid + 1, right);

        inversions += mrgcnt(str, left, mid, right);
    }

    return inversions;
}

long long countInversions(string& str) {
    return mergeSortAndCount(str, 0, str.size() - 1);
}

bool cmp(pair<int, string> a, pair<int, string> b){
    int x = countInversions(a.second);
    int y = countInversions(b.second);

    if(x != y){
        return x < y;
    }

    return a.first < b.first;
}




int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int t;
    cin >> t;
    for(int j=1; j<=t; j++){
        int n, k;
        vector<pair<int, string> > v(k);
        cin >> n >> k;
        for(int i=0; i<k; i++){
            string s;
            cin >> s;
            v.push_back(make_pair(i, s));
        }

        sort(v.begin(), v.end(), cmp);

        for(int i=0; i<k; i++){
            cout << v[i].second << endl;
        }

        if(j!=t){
            cout << endl;
        }
        
    }


    
    return 0;
}