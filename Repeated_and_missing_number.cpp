#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    public:
    vector<int> repeatedNumber(vector<int> &A)
    {

        long long int n = A.size();
        long long int S2n = (long long int)(n * (n + 1) * (2 * n + 1)) / 6;
        long long int Sn = (long long int)(n * (n + 1) / 2);
        long long int Sa = 0;
        long long int S2a = 0;

        for (long long int i = 0; i < n; i++)
        {
            Sa += A[i];
            S2a += (long long int)A[i] * (long long int)A[i];
        }

        long long int val1 = Sn - Sa;   // x - y;
        long long int val2 = S2n - S2a; // x^2 - y^2

        val2 /= val1;

        long long int x = (val1 + val2) / 2;
        long long int y = x - val1;

        return {(int)y, (int)x};
    }
};

int main()
{
    vector<int> a = {1, 2, 2, 3, 5};
    Solution s;
    vector<int> ans = s.repeatedNumber(a);
    cout << ans[0] << " " << ans[1];
    return 0;
}