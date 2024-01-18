#include<bits/stdc++.h>
using namespace std;

vector< vector<long long int > > Matrix_multiplication(vector< vector<long long int > > &a, vector< vector<long long int> > &b, long long int  m)
{
    long long int n = a.size();
    vector< vector<long long int> >ans;
    for (long long int i = 0; i < n; i++)
    {
        vector<long long int>  temp;
        for (long long int j = 0; j < n; j++)
        {
            long long int t = 0;
            for (long long int k = 0; k < n; k++){
                t+=( a[i][k]*b[k][j] ) % m;
            }
            t %= m;
            temp.push_back(t);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector< vector<long long int >  > Power(vector<long long int >&arr, vector< vector<long long int>  >&X, long long int  m)
{
    vector< vector<long long int>  >Y = { {1, 0}, {0, 1} };
    long long int count = 0;
    for (long long int  it: arr)
    {

        vector< vector<long long int >  > temp = { {1, 0}, {0, 1} };
        for(int i = 0; i < arr[count]; i++) temp = Matrix_multiplication(temp, X, m);
        Y = Matrix_multiplication(Y, temp, m);
        vector< vector<long long int >  > Z;

        Z = Matrix_multiplication(X, X, m); // z = x^2
        X = Matrix_multiplication(Z, Z,m); // x = x^4
        X = Matrix_multiplication(X, X,m); // x = x^8
        X = Matrix_multiplication(X, Z,m); // x = x^10
        count++;
    }
    return Y;
}

int main()
{
    int k;long long int m;
    cin >> k; cin >> m;
    char nums[k]; scanf("%s", nums);
    vector<long long int >numlis;
    for (long long int  i = 0; i < k; i++){
        //cout << nums[i]-'0' << ' ';
        numlis.push_back(nums[k-i -1]-'0');
    }
    vector< vector<long long int>  > A = { {1, 1}, {1, 0}};
    vector< vector<long long int >  >ans = Power(numlis, A,m);
    //for (auto it:ans) for(auto i:it) cout << i << ' ';
    cout << ans[1][0];

}