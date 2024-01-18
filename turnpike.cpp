#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myfunc(vector<int>&ans, vector<int>dis, int depth, int n);

int main()
{
    int n;
    cin >> n;
    int m = n * (n-1)/2;
    if (n==0) 
    {
        cout << -1;
        return 0;
    }

    vector<int> distances(m);
    for (int i = 0; i<m; i++) cin >> distances[i];
    sort(distances.begin(), distances.end());

    vector<int>ans;
    ans.push_back(0);
    ans.push_back(distances.back());
    bool b = myfunc(ans, distances, 2, n);
    if (!b)
    {
        for (int i = 0; i < n; i++)
            cout << -1 << " ";
        return 0;
    }
    sort(ans.begin(), ans.end());
    //cout << "here is the ans" << endl;
    for (int it:ans) cout << it << " ";
}


// whether new array is correct or not
bool check(vector<int>&ans, vector<int>dis)
{
    int len = ans.size();
    vector<int>dup(dis);

    for(int i = 0; i<len-1; i++)
    {
        for (int j = i+1; j<len; j++)
        {
            int temp = abs(ans[j]-ans[i]);
            auto t = find(dup.begin(), dup.end(), temp);
            if (t == dup.end())
                return false;
            dup.erase(t);
        }
    }
    return true;
}

//generate and check right array
bool right(vector<int>&ans, vector<int>dis, int n)
{

    int s = ans.size();
    vector<int>dup(dis);
    for (int i = 0; i < s-1; i++)
    {
        for (int j = i+1; j < s; j++)
        {
            int t = abs(ans[j] - ans[i]);
            auto it = find (dup.begin(), dup.end(), t);
            dup.erase(it);
        }
    }
    int t = dup.back();
    //int t = *(dis.end()-ans.size());
    if (find(ans.begin(), ans.end(), t) != ans.end())
        return false;

    ans.push_back(t);// cout << ans.back() << "-r "; for (int it:ans) cout << it<<','; cout << endl;
    bool flag = check(ans, dis);
    if (flag) {
        bool temp = myfunc(ans, dis, ans.size(), n);
        if (temp) return temp;
        //now we get to pop back in case of backtracing
        ans.pop_back();
        return temp;
    }
    else{
        ans.pop_back();
        return false;
    }
}

//generate and check left array
bool left(vector<int>&ans, vector<int>dis, int n)
{

    int s = ans.size();
    vector<int>dup(dis);
    for (int i = 0; i < s-1; i++)
    {
        for (int j = i+1; j < s; j++)
        {
            int ti = abs(ans[j] - ans[i]);
            auto it = find (dup.begin(), dup.end(), ti);
            dup.erase(it);
        }
    }
    int t = ans[1] - dup.back();

    //now check after putting in left integer
    //int t = ans[1] - *(dis.end()-ans.size());
    if (find(ans.begin(), ans.end(), t) != ans.end())
        return false;
    ans.push_back(t);// cout << ans.back() << "-l "; for (int it:ans) cout << it<< ','; cout << endl;
    bool flag = check(ans, dis);
    if (!flag){
        ans.pop_back();
        return false;
    }
    bool temp = myfunc(ans, dis, ans.size(), n);
    if (temp) return true;
    //now if we get false and have to backtrace
    ans.pop_back();
    return false;
}

bool myfunc(vector<int>&ans, vector<int>dis, int depth, int n)
{
    //check right side
    if (ans.size() == n) return true;
    bool temp = right(ans, dis, n);
    if (!temp){
        return left(ans, dis, n);//check left
    }
    return temp;
}