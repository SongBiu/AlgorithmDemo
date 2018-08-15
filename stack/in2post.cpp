#include <stack>
#include <string>
using namespace std;
string in2post(string in)
{
    string res = "";
    stack<char> ops;
    for (auto s: in)
    {
        if (s == '(')
        {
            ops.push(s);
        }
        else if (s == '+' || s == '-')
        {
            while (!ops.empty() && ops.top() != '(' && (ops.top() == '*' || ops.top() == '/'))
            {
                res.push_back(ops.top())
                ops.pop();
            }
            ops.push(s);
        }
        else if (s == '*' || s == '/')
        {
            ops.push(s);
        }
        else if (s == ')')
        {
            while (!ops.empty() && ops.top() != '(')
            {
                res.push_back(ops.top())
                ops.pop();
            }
            ops.pop();
        }
        else
        {
            res.push_back(s);
        }
    }
    while (!ops.empty())
    {
        res.push_back(ops.top());
        ops.pop();
    }
    return res;
}