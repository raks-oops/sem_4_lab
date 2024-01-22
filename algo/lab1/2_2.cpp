#include <bits/stdc++.h>
using namespace std;

int find2DPeak(vector<vector<int> > arr, int rows, int cols){
    bool flag = false;
    int X = 0, Y = 0;

    while (!flag)
    {
        if(X==0 && Y==0){
            if(arr[X][Y] >= arr[X+1][Y] && arr[X][Y] >= arr[X][Y+1]){
                flag = true;
                return arr[X][Y];
            }
            else if(arr[X][Y] < arr[X+1][Y]){
                X++;
            }
            else if(arr[X][Y] < arr[X][Y+1]){
                Y++;
            }
        }

        else if(X==0 && Y==rows-1){
            if(arr[X][Y] >= arr[X+1][Y] && arr[X][Y] >= arr[X][Y-1]){
                flag = true;
                return arr[X][Y];
            }
            else if(arr[X][Y] < arr[X+1][Y]){
                X++;
            }
            else if(arr[X][Y] < arr[X][Y-1]){
                Y--;
            }
        }

        else if(X==cols-1 && Y==0){
            if(arr[X][Y] >= arr[X-1][Y] && arr[X][Y] >= arr[X][Y+1]){
                flag = true;
                return arr[X][Y];
            }
            else if(arr[X][Y] < arr[X-1][Y]){
                X--;
            }
            else if(arr[X][Y] < arr[X][Y+1]){
                Y++;
            }
        }
    }
    
}

int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());

    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int> > arr(rows, vector<int>(cols));

    // Input the 2D matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i+(2*j);
        }
    }

    clock_t start = clock();
    int result = find2DPeak(arr, rows, cols);
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("for loop took %f seconds to execute \n", cpu_time_used);
    cout << "Duration - " << cpu_time_used << endl;
    
    cout << "The 2D peak is: " << result << endl;
    return 0;
}