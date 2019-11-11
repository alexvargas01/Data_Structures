#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n, phone;
    string comd, name;
    map<int, string> data;

    map<int, string>::iterator itr;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> comd;
        if (comd == "add")
        {
            cin >> phone >> name;
            itr = data.find(phone);
            if (itr == data.end())
            {
                data.insert(pair<int, string>(phone, name));
            }
            else
            {
                data.erase(itr);
                data.insert(pair<int, string>(phone, name));
            }
        }
        else if (comd == "find")
        {
            cin >> phone;
            itr = data.find(phone);
            if (itr == data.end())
            {
                cout << "not found" << endl;
            }
            else
            {
                cout << itr->second << endl;
            }
        }
        else if (comd == "del")
        {
            cin >> phone;
            itr = data.find(phone);
            if (itr != data.end())
            {
                data.erase(itr);
            }
        }
    }
    return 0;
}