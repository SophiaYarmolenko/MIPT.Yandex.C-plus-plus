#include <iostream>
#include<vector>
using namespace std;
int main()
{
    size_t N;
    cin>>N;
    if(N >= 1)
    {
    vector <int64_t> temperature(N);
    double avg = 0;
    for(size_t i = 0; i < N; i++)
    {
        cin >> temperature[i];
        avg+=temperature[i]/ static_cast<double> (N);
    }

    size_t N2 = 0;
    vector <int64_t> temperatureAvg;
    for(size_t i = 0; i < N; i++)
    {
        if(temperature[i] > avg)
        {
            N2++;
            temperatureAvg.push_back(i);
        }
    }

    cout << N2 << endl;
    if(N2 >= 1)
    {
        for(size_t i = 0; i < N2-1; i++)
        {
            cout<<temperatureAvg[i]<<" ";
        }
            cout<<temperatureAvg[N2-1];
    }
    }

    return 0;
}
