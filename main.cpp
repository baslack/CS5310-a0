#include <iostream>
#include <chrono>
#include <cmath>
#include "sorts.h"
#define ITERATIONS 5000
#define SEED 2891569

using namespace std;

//generates a list of length n
int generateTest(vector<int> &test, int n);

int main(int argc, char **argv) {
    bool bDebug = true;

    // set the various n's we're going to sort
    vector<int> n = {10, 20, 40, 80, 160, 320, 640, 1280};
    vector<int>::iterator n_iter = n.begin();

    //declare a general test var
    vector<int> test;

    //declare our timer variables

    using namespace std::chrono;

    high_resolution_clock::time_point start_time;
    high_resolution_clock::time_point end_time;
    duration<double> delta;

    using namespace std;

    double running_total;
    double average;

    //iterate over the various values of n
    while(n_iter != n.end()){
        running_total = 0.0;
        average = 0.0;
        //iterate the following
        for (int i = 0; i < ITERATIONS; i++){
            //generate a random list
            if (generateTest(test, *n_iter) < 0){
                cerr << "Something has gone horribly wrong!\n";
                exit(-1);
            }
            //start the timer
            start_time = std::chrono::high_resolution_clock::now();
            //sort the list
            sorts::selectionSort(test);
            //stop the timer
            end_time = std::chrono::high_resolution_clock::now();
            //calculate the net
            delta = std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time);
            //add the net to the running total
            running_total += delta.count();
        }

        //when done iterating
        //divide the net by the iter count
        average = running_total / ITERATIONS;
        //write out the average and the n value
        cout << "For n: " << *n_iter << ", average sort time is " << average << " seconds.\n";
        //advance to the next n
        n_iter++;
    }
    exit(0);
}

int generateTest(vector<int> &test, int n){
    srand(SEED);
    try{
        test.clear();
        for (int i = 0; i < n; i++){
            test.push_back(rand() % 100);
        }
        return 0;
    }
    catch (...) {
        return -1;
    }
}