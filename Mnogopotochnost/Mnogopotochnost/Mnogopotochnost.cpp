#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class QuickSorter {
public:
    void ExecuteSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int pivotIndex = Partition(arr, left, right);
            ExecuteSort(arr, left, pivotIndex - 1);
            ExecuteSort(arr, pivotIndex + 1, right);
        }
    }

private:
    int Partition(vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left - 1;

        for (int j = left; j < right; ++j) {
            if (arr[j] <= pivot) {
                ++i;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[right]);
        return i + 1;
    }
};

int main() {
    vector<int> numbers(10);
    cout << "Enter 10 numbers: ";
    for (int& num : numbers) {
        cin >> num;
    }

    QuickSorter sorter;
    thread sortThread([&sorter, &numbers] { sorter.ExecuteSort(numbers, 0, numbers.size() - 1); });
    sortThread.join();

    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}