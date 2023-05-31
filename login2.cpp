#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    unordered_map<string, vector<string>> UsernameToPasswords;

    for (int i = 0; i < N;i++)
    {
        string username, password;
        cin >> username;
        cin >> password;
        UsernameToPasswords[username].push_back(password);
    }

    for (int i=0; i < Q; i++)
    {
        string loginUsername;
        cin >> loginUsername;
        if (UsernameToPasswords[loginUsername].empty())
            cout << "Chua Dang Ky!" << endl;
        else
        {
            for (string s : UsernameToPasswords[loginUsername])
            cout << s << ' ';

        }
        cout << endl;
    }

    return 0;

}