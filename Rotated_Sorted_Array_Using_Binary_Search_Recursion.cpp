#include <iostream>
#include <vector>
using namespace std;
int ans = -1;
void binary_search(int arr[], int low, int high, int target)
{

    if (low > high)
        return;

    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
        ans = mid;
        return;
    }

    if (arr[low] <= arr[mid])
    {
        if (target >= arr[low] && target <= arr[mid])
            binary_search(arr, low, mid - 1, target);
        else
            binary_search(arr, mid + 1, high, target);
    }
    else
    {
        if (arr[low] <= target && target >= arr[mid])
            binary_search(arr, low, mid - 1, target);
        else
            binary_search(arr, mid + 1, high, target);
    }
}

int main()
{
    int arr[] = {5, 6, 7, 8, 1, 2, 3, 4};
    int search = 4;
    int n = 8;
    binary_search(arr, 0, n - 1, search);
    cout << ans;
    return 0;
}