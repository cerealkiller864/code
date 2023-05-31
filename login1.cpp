#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;
    unordered_map<string, string> UsernameToPassword;

    for (int i = 0; i < N;i++)
    {
        string username, password;
        cin >> username;
        // cin.ignore(1, '\n');
        // fflush(stdin);
        cin >> password;
        // cin.ignore(1, '\n');
        // fflush(stdin);
        UsernameToPassword[username] = password;
    }

    vector<string> login_inputs(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> login_inputs[i];
    }

    for (int i=0; i < Q; i++)
    {
        if (UsernameToPassword[login_inputs[i]].empty())
            cout << "Chua Dang Ky!" << endl;
        else
            cout << UsernameToPassword[login_inputs[i]] << endl;
    }

    return 0;

}