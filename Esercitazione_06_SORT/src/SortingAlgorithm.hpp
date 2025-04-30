#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

namespace SortLibrary {
    template <typename T>
    concept sortable = requires(T& t) {
        {t < t} -> std::convertible_to<bool>;
    };

    template<sortable T>
    void BubbleSort(vector<T>& v)
    {
        unsigned int n = v.size();
        bool flag = true;
    
        while (flag)
        {
            flag = false;
            for (unsigned int i = 0; i < n - 1; i++)
            {
                if (v[i] > v[i + 1])
                {
                    T tmp = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = tmp;
                    flag = true;
                }
            }
            n = n - 1;
        }
    }
    
    template<sortable T>
    void HeapSort(vector<T>& v)
    {
        make_heap(v.begin(), v.end()); 
        for (auto i = v.end(); i != v.begin(); --i) 
        {
            pop_heap(v.begin(), i);
        }
    }
}


