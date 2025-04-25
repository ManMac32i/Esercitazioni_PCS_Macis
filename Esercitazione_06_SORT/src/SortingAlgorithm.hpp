#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace SortLibrary {
    template <typename T>
    concept sortable = requires(T& t) {
        {t < t} -> std::convertible_to<bool>;
    };

    template<sortable T>
    void SelectionSort(vector<T> & v)
    {
        const unsigned int n = v.size();
        for (int i = 0, i < n - 1, i++)
        {
            unsigned int min_index = i;
            for (int j = i + 1, i < n, j++)
            {
                if (v[j] < v[min_index])
                {
                    min_index = j;
                }

            }
            T swap = v[i];
            v[i] = v[min_index];
            v[min_index] = swap;
        }
    }


}


