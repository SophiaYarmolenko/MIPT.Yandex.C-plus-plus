#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

template <typename Key, typename Value>
Value& GetRefStrict( map <Key, Value> &m1, Key k)
{
    if (m1.count(k) == 0) {
        throw runtime_error("no such key in dictionary");
    }
    return m1[k];
}
/*
int main()
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}*/