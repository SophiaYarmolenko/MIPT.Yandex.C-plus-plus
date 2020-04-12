#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

template <typename First, typename Second>
pair< First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);

template <typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2);

template <typename Key, typename Value>
map <Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2);

/*template <typename Collection>
Collection Sqr(const Collection& c) {
    Collection ss;
    for (const auto& i : c)
    {
        ss << i*i;
    }
    return ss;
}*/

template <typename First, typename Second>
pair< First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2)
{
    First f = p1.first*p2.first;
    Second s = p1.second*p2.second;
    pair<First, Second> result;
    result.first = f;
    result.second = s;
    return result;
}

template <typename T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2)
{
    vector<T> result(v1.size());
    int s = 0;
    for (const auto& i : v1)
    {
        result[s] = i*i;
        s++;
    }
    return result;
}

template <typename Key, typename Value>
map <Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2)
{
    map <Key, Value> result;
    for (const auto& i : m1)
    {
        Key k = i.first;
        Value v = i.second*i.second;
        result.insert(pair<Key, Value>(k, v));
    }
    return result;

}

template <typename T>
T Sqr(T x)
{
    return x * x;
}
/*
int main() {
    // Пример вызова функции
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
            {4, {2, 2}},
            {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }
    return 0;
}*/