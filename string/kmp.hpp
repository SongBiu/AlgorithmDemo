#include <vector>
#include <string>
using namespace std;
vector<int> findNext(string s)
{
    vector<int> next(s.length() - 1, 0);
    int k = -1;
    next[0] = -1;
    for (int i = 1; i < s.length(); i++)
    {
        while (k >= 0 && s[i - 1] != s[k])
        {
            k = next[k];
        }
        k++;
        if (s[i] == s[k])
        {
            next[i] = next[k];
        }
        else
        {
            next[i] = k;
        }
        
    }
    return next;
}