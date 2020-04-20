#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int N;
  cin>>N;
  vector <int> number;
  for(int i = N; i > 0; i--)
  {
      number.push_back(i);
  }
    for(int i:number)
    {
        if(i!=number[N-1])
        cout<<i<<" ";
        else cout<<i;
    }
  while(prev_permutation(number.begin(), number.end()))
    {
        cout<< endl;
        for(int i:number)
        {
            if(i!=number[N-1])
                cout<<i<<" ";
            else cout<<i;
        }
    };

  return 0;
}
