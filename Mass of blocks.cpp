#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t kol;
    uint64_t density;
    cin>>kol>>density;
    uint64_t sum = 0;
    int a;
    int b;
    int c;
    for(size_t i = 0; i < kol; i ++)
    {

        cin>>a>>b>>c;
        uint64_t V = static_cast<uint64_t >(a)*b*c;
        sum += V;
    }
    cout<<sum*density;
    return 0;
}
