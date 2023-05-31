
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;

vector<int> get_ans(const vector<int> &A, int K)
{
    map<int, int> Hash;
    int N = A.size();
    vector<int> ans;
    vector<const int*> save_color;
    for (int i = 0; i < N; i++)
    {
        Hash[A[i]]++;
        if (Hash[A[i]] > 1)
            save_color.push_back(&A[i]);
    }

    for (auto x = Hash.begin(); x != Hash.end() && K > 0; x++)
    {
        ans.push_back(x->first);
        x->second--;
        K--;
    }

    for (int i = 0; i < save_color.size() && K > 0; i++)
    {
        while (Hash[*save_color[i]] > 0 && K > 0)
        {
            ans.push_back(*save_color[i]);
            Hash[*save_color[i]]--;
            K--;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> ans = get_ans(a, k);

    for (const int &x : ans)
        cout << x << ' ';
    return 0;
}
