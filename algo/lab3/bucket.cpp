#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void bucketSort(float arr[], int n) {
    const int bucketCount = 10;  

    
    vector<float> buckets[bucketCount];

    
    for (int i = 0; i < n; i++) {
        int bucketIndex = bucketCount * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    
    for (int i = 0; i < bucketCount; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (float value : buckets[i]) {
            arr[index++] = value;
        }
    }
}


void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    float arr[n];
    
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
    
}
