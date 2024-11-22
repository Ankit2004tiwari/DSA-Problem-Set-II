#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> ThreeSum (int arr[], int n)
{
    set<vector<int>> st;
    for(int i = 0; i < n; i++)
    {
        set<int> hashSet;
        for(int j = i+1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            if(hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}
int main()
{
    int n, k = 0;
    cout<<"Enter the Size of the Array : ";
    cin>>n;
    int *arr = (int *) malloc (n * sizeof(int));
    cout<<"Enter Array : "<<endl;

    for(int i = 0; i < n ; i++)
    {
        cout<<"A["<<i<<"] : ";
        cin>>arr[i];
    }

    vector<vector<int>> temp = ThreeSum(arr, n);
    cout << "Triplets adding up to " << k << " are:" << endl;
    for (const auto &triplet : temp)
    {
        cout<<"{";
        for (const auto &num : triplet)
        {
            cout << num << " ";
        } 
        cout <<"}"<<endl;
    }
    free(arr);
    return 0;
}

// -1,0,1,2,-1,-4



// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;

// vector<vector<int>> ThreeSum(int arr[], int n, int k)
// {
//     set<vector<int>> st;

//     for (int i = 0; i < n; i++)
//     {
//         set<int> hashSet;
//         for (int j = i + 1; j < n; j++)
//         {
//             int third = k - (arr[i] + arr[j]); 
//             if (hashSet.find(third) != hashSet.end())
//             {
//                 vector<int> temp = {arr[i], arr[j], third};
//                 sort(temp.begin(), temp.end()); 
//                 st.insert(temp);
//             }
//             hashSet.insert(arr[j]);
//         }
//     }

//     vector<vector<int>> result(st.begin(), st.end()); 
//     return result;
// }

// int main()
// {
//     int n, k;
//     cout << "Enter the Size of the Array: ";
//     cin >> n;
//     int *arr = (int *)malloc(n * sizeof(int)); 
//     cout << "Enter k (the target sum): ";
//     cin >> k;
//     cout << "Enter Array: " << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cout << "A[" << i << "]: ";
//         cin >> arr[i];
//     }

//     vector<vector<int>> temp = ThreeSum(arr, n, k);

//     cout << "Triplets adding up to " << k << " are:" << endl;
//     for (const auto &triplet : temp)
//     {
//         for (const auto &num : triplet)
//         {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     free(arr);
//     return 0;
// }