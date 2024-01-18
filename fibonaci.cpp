#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > Matrix_multiplication(vector< vector<int> > &a, vector< vector<int> > &b,long long int m)
{
    int n = a.size();
    vector< vector<int> > ans;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int t = 0;
            for (int k = 0; k < n; k++){
                t+= ( a[i][k]*b[k][j] ) % m;
            }
            t %= m;
            temp.push_back(t);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector< vector<int> > Power(int n, vector< vector<int> >&X,long long int m)
{
    vector< vector<int> >Y = { {1, 0}, {0, 1} };
    while (n)
    {
        if (n&1) Y = Matrix_multiplication(Y, X, m);
        X = Matrix_multiplication(X, X, m);
        n = n/2;
    }
    return Y;
}

int main()
{
    int n;long long int m;
    cin >> n; cin >> m;
    int num; cin >> num;// cout << num;
    // string s; cin >> s;
    // int num = 0;
    // int factor = 1;
    // for (int i = s.size()-1; i >= 0; i--){
    //     num += factor * (s[i] - '0');
    //     factor *= 10;
    //     // cout << num << '-';
    //     // cout << s[i] << ' ';
    // }
    //cout <<endl << num << endl;
    // num = 10;
    vector< vector<int> > A = { {1, 1}, {1, 0}};
    vector< vector<int> >ans = Power(num, A, m);
    cout << ans[1][0];
}