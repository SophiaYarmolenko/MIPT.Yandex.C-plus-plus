#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename RandomIt>
void MergeSort1(RandomIt range_begin, RandomIt range_end)
{
    if(range_end - range_begin >= 2)
    {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        auto middle = elements.begin() + (range_end - range_begin)/2;

       MergeSort1(elements.begin(), middle);

       MergeSort1(middle, elements.end());

        merge(elements.begin(), middle, middle, elements.end(), range_begin);
    }
    return;
}

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if(range_end - range_begin >= 2)
    {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        auto OneThird = elements.begin() + (range_end - range_begin)/3;
        auto TwoThird = elements.begin() + (range_end - range_begin)*2/3;

        MergeSort(elements.begin(), OneThird);
        MergeSort(OneThird, TwoThird);
        MergeSort(TwoThird, elements.end());

        vector<typename RandomIt::value_type> elements1;
        merge(elements.begin(), OneThird, OneThird, TwoThird,  back_inserter(elements1));
        merge(elements1.begin(), elements1.end(), TwoThird, elements.end(), range_begin);
    }
    return;
}

int main()
{
    vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
