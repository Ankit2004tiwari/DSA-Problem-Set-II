#include <iostream>
using namespace std;
void Traversal(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}

void Delete(int arr[],int size,int index)
{
    for (int i = index; i < size -1; i++)
    {
        arr[i] = arr[i+1];
    }
}

int main()
{
    int size, arr[100], index;
    cout << "Enter the size of Array : " << endl;
    cin >> size;
    int capacity = 100;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element of the Array " << endl;
        cin >> arr[i];
    }
    cout << "Enter the index value to delete the element : " << endl;
    cin >> index;
    Delete(arr,size,index);
    size-=1;
    Traversal(arr, size);
    return 0;
}