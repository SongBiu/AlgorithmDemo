#include <vector>
using namespace std;
#define LEFT(i) 2*i+1
#define RIGHT(i) 2*i+2
template <class T>
class heap
{
private:
    vector<T> vals;
    bool reverse;
public:
    heap(bool reverse_): reverse(reverse_) {};
    void adjust(int i)
    {
        int minIndex = i, minVal = vals[i];
        if (reverse)
        {
            if (LEFT(i) < vals.size() && vals[LEFT(i)] < minVal)
            {
                minIndex = LEFT(i);
                minVal = vals[LEFT(i)];
            }
            if (RIGHT(i) < vals.size() && vals[RIGHT(i)] < minVal)
            {
                minIndex = RIGHT(i);
                minVal = vals[RIGHT(i)];
            }
        }
        else
        {
            if (LEFT(i) < vals.size() && vals[LEFT(i)] > minVal)
            {
                minIndex = LEFT(i);
                minVal = vals[LEFT(i)];
            }
            if (RIGHT(i) < vals.size() && vals[RIGHT(i)] > minVal)
            {
                minIndex = RIGHT(i);
                minVal = vals[RIGHT(i)];
            }
        }
        if (minIndex != i)
        {
            T tmp = vals[i];
            vals[i] = vals[minIndex];
            vals[minIndex] = tmp;
            adjust(minIndex);
        }
    }
    void postDo()
    {
        for (int i = vals.size() / 2 - 1; i >= 0; i--)
        {
            adjust(i);
        }
    }
    void push(T val)
    {
        vals.push_back(val);
        postDo();
    }
    void pop()
    {
        vals[0] = vals[vals.size() - 1];
        vals.pop_back();
        postDo();
    }
    int size()
    {
        return vals.size() - 1;
    }
    void clear()
    {
        vals.clear();
    }
};