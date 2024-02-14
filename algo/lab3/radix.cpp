#include <iostream>

using namespace std;


int getMax(int arr[], int n) {
    int maxNum = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxNum)
            maxNum = arr[i];
    }
    return maxNum;
}


void countingSort(int arr[], int n, int exp) {
    const int base = 10;
    int output[n];
    int count[base] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % base]++;

    for (int i = 1; i < base; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[--count[(arr[i] / exp) % base]] = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}


void radixSort(int arr[], int n) {
    int maxNum = getMax(arr, n);

    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}


int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    radixSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "";
    
    return 0;

}
