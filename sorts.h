//
// Created by iam on 5/10/2017.
//

#ifndef A0_SORTS_H
#define A0_SORTS_H

#include <iostream>
#include <c++/4.8.3/vector>

using namespace std;

namespace sorts{
    //this had to be defined inline because of the
    //use of vector. Looking into ways to keep it
    //as a separate file.
    inline int selectionSort(vector<int> &v){
        //if the vector has less than
        //two, we've nothing to do
        if (v.size() < 2){
            return 0;
        }
        //start with an unsorted list
        int sorted_index = 0;
        int smallest_index = sorted_index;
        //start with comparing to the second element
        int index = 1;
        //while the vector isn't sorted
        while(sorted_index < v.size()){
            //compare to each element in the list
            while(index < v.size()){
                //if the current is smaller that smallest
                //node that and change smallest
                if (v[smallest_index] > v[index]){
                    smallest_index = index;
                }
                //next element
                index++;
            }
            //swap
            int temp;
            temp = v[sorted_index];
            v[sorted_index] = v[smallest_index];
            v[smallest_index] = temp;
            //increment the sorted
            sorted_index++;
            index = sorted_index + 1;
        }
        return 0;
    }
}

#endif //A0_SORTS_H
