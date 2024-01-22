#include<bits/stdc++.h>
using namespace std;

vector<int> randomGen(int len){
    vector<int> r;
    for(int i=0; i<len; i++){
        r.push_back(i);
    }
    return r;
}
int findPeak(vector<int> arr){
    int len = arr.size();
    for(int i=0; i<len; i++){
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1]){
            return arr[i];
        }
    }
    return -1;
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
    while(t--){
        int n;
        cin >> n;
        vector<int> arr = randomGen(n);
        
        clock_t start = clock();
        int x = findPeak(arr);
        clock_t end = clock();

        double cpu_time_used = ((double) (end - start));
        cout << "Duration - " << cpu_time_used << endl;
        arr.clear();
    }

    return 0;
}