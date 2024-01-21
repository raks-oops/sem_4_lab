//Rakin Shahriar
//IUT, 2024

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "vb" << endl;
    }


    
    return 0;
}