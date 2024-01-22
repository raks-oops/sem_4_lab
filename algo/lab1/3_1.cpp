#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int* arr, int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(int* arr, int len){
    for(int i = 1; i < len; i++){
        int j = i - 1;
        int temp = arr[i];
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergeSort(int* arr, int left, int right){
    if(left >= right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i = left; i <= right; i++){
        arr[i] = temp[i - left];
    }
}


int main() {
    // Redirect input from input.txt
    ifstream in("../input.txt");
    cin.rdbuf(in.rdbuf());

    // Redirect output to output.txt
    ofstream out("../output.txt");
    cout.rdbuf(out.rdbuf());


    int n;
    cin >> n;

    int arr[n];

    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }

    clock_t start_B = clock();
    bubbleSort(arr, n);
    clock_t end_B = clock();

    double cpu_time_used_B = ((double) (end_B - start_B)) / CLOCKS_PER_SEC;
    cout << "Bubble Sort Duration - " << cpu_time_used_B << endl;

    
    
    return 0;
}