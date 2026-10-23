#include <iostream>
#include <vector>
using namespace std;

// 原地划分：以 arr[l] 作为枢轴
static int partitionQS(vector<int>& arr, int l, int r) {
    int pivot = arr[l];
    while (l < r) {
        while (l < r && arr[r] >= pivot) r--;
        arr[l] = arr[r];
        while (l < r && arr[l] <= pivot) l++;
        arr[r] = arr[l];
    }
    arr[l] = pivot;
    return l;
}

static void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int p = partitionQS(arr, l, r);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, r);
}

// 使用示例（可删）
int main() {
    vector<int> a{5, 2, 9, 1, 5, 6};
    quickSort(a, 0, (int)a.size() - 1);
    for (int x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}
