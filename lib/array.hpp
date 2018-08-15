#include <iostream>
#include <cstring>
template <class T>
class array
{
private:
    T* _vals;
    int _n;
public:
    array()
    {
        _n = 0;
    }
    array(int _n_)
    {
        _n = _n_;
        _vals = new T[_n];
    }
    array(int _n_, T val_)
    {
        _n = _n_;
        _vals = new T[_n];
        for (int i = 0; i < _n; i++)
        {
            _vals[i] = val_;
        }
    }
    void clear()
    {
        _n = 0;
        delete [] _vals;
    }
    T& operator [] (int index)
    {
        if (index >= _n)
        {
            cout << "error" << endl;
            return -1;
        }
        return _vals[index];
    }
    void push(T val)
    {
        _n++;
    }
    void erase(int index);
    void subArray(int start, int end);
};