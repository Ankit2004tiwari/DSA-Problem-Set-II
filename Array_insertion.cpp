#include <iostream>
using namespace std;

int insertion_array(int arr[], int, int, int, int);
void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int size, arr[100], index, element;
    int capacity = 100;
    cout << "Enter the size of Array : " << endl;
    cin >> size;
    cout << "Enter the element of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the index value of the array to inserting : " << endl;
    cin >> index;
    cout << "Enter the element of the array" << endl;
    cin >> element;
    insertion_array(arr, size, index, element, capacity);
    size += 1;
    Display(arr, size);
}
int insertion_array(int arr[], int size, int index, int element, int capacity)
{
    for (int i = size + 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}