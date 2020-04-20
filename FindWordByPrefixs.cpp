#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith1(RandomIt range_begin, RandomIt range_end, char prefix)
{
    auto left = lower_bound(range_begin, range_end, string(1, prefix));
    char next_prefix = static_cast<char>(prefix + 1);
    auto right = lower_bound(range_begin, range_end, string(1, next_prefix));
    return {left, right};
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix)
{
    auto left = lower_bound(range_begin, range_end, prefix);
    string upper_bound = prefix;
    ++upper_bound[upper_bound.size() - 1];

    auto right = lower_bound(range_begin, range_end, upper_bound);
    return {left, right};
}

/*int main()
{
    const vector<string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "m");
    for (auto it = m_result.first; it != m_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto p_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "m");
    cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

    const auto z_result =
            FindStartsWith(begin(sorted_strings), end(sorted_strings), "m");
    cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;

    return 0;
}*/