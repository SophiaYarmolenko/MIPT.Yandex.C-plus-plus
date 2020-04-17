#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<string> result;
    auto it = begin(s);
    string word = "";

    while ( it != end(s))
    {
        if (*it != ' ')
        {
            word += *it;
            ++it;
        }
        else
        {
        result.push_back(word);
        word = "";
        ++it;
        }
    }
    result.push_back(word);
    return result;
}
/*
int main()
{

  string s = "C Cpp Java Python";
   vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  return 0;
}
*/
