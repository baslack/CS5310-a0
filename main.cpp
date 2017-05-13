/**
 * Benjamin A. Slack
 * CS5310, Summer 1 2017
 * a0, Selection Sort
 * 05.13.17
 * benjamin.slack@wmich.edu
 */

#include <iostream>
#include <fstream>
#include <chrono>
#include <cmath>
#include "sorts.h"
#define ITERATIONS 10000
#define SEED 2891569
#define N_OF_INTEREST 10

using namespace std;

//generates a list of length n
int generateTest(vector<int> &test, int n);
//dumps the contents of the list two std::out
void dumpTest(vector<int> &test);

int main(int argc, char **argv) {
    //allow for a change of seed
    int in_seed;
    if (argc > 1){
        in_seed = atoi(argv[1]);
    }else{
        in_seed = SEED;
    }
    srand(in_seed);

    //setup dump file
    ofstream outfile;
    outfile.open("a0.csv", ios::trunc);
    if (!(outfile.is_open())){
        cerr << "Unable to open file for writing.\n";
        exit(-1);
    }

    // set the various n's we're going to sort
    vector<int> n = {2, 4, 8, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int>::iterator n_iter = n.begin();

    //declare a general test var
    vector<int> test;
    vector<int> clone;

    //declare our timer variables
    using namespace std::chrono;

    //create a short hand for chrono objects
    typedef high_resolution_clock clock;
    typedef nanoseconds ns;
    typedef milliseconds ms;
    //setup vars to capture trial durations
    clock::time_point start_time;
    clock::time_point end_time;
    ns delta;
    ns running_total;
    ns average;

    using namespace std;

    //output the header for the csv
    outfile << "n, nanoseconds\n";

    //iterate over the various values of n
    while(n_iter != n.end()){
        //output the current "n"
        outfile << *n_iter << ", ";
        //zero out the totals and averages from the last pass
        running_total = running_total.zero();
        average = average.zero();
        //generate a random list
        if (generateTest(test, *n_iter) < 0){
            cerr << "Something has gone horribly wrong!\n";
            exit(-1);
        }
        //iterate the following
        for (int i = 0; i < ITERATIONS; i++){
            //need to work on a copy so...
            clone.clear();
            for (int i = 0; i < test.size(); i++){
                clone.push_back(test[i]);
            }
            //for the lower n's output the pre and post lists
            //for confirmation that sort's doing what we want
            if ((*n_iter == N_OF_INTEREST) && (i == 0)){
                dumpTest(clone);
            }
            //start the timer
            start_time = clock::now();
            //sort the list
            sorts::selectionSort(clone);
            //stop the timer
            end_time = clock::now();
            //dump the sorted list if needed
            if ((*n_iter == N_OF_INTEREST) && (i == 0)){
                dumpTest(clone);
            }
            //calculate the delta T
            delta = duration_cast<ns>(end_time - start_time);
            //add the net to the running total
            running_total += delta;
        }

        //when done iterating
        //divide the net by the iter count
        average = running_total / ITERATIONS;
        //output the average to file
        outfile << average.count() << "\n";
        //write out the average and the n value
        cout << "For n: "
             << *n_iter
             << ", average sort time is "
             << average.count()
             << " nanoseconds.\n";

        //advance to the next n
        n_iter++;
    }
    outfile.close();
    exit(0);
}

/**
 * clears and updates the vector referenced
 * by test to include n integers in a range
 * of 1 to 100.
 * @param test vector to update
 * @param n number of ints
 * @return 0 on success, -1 on failure
 */
int generateTest(vector<int> &test, int n){
    try{
        test.clear();
        for (int i = 0; i < n; i++){
            test.push_back(rand() % 100 + 1);
        }
        return 0;
    }
    catch (...) {
        return -1;
    }
}

/**
 * Dumps the contents of a give vector to
 * std::out
 * @param test vector to be dumped
 */
void dumpTest(vector<int> &test){
    cout << "Start List:\n";
    for (int i = 0; i < (test.size() - 1); i++){
        cout << test[i] << ", ";
        if ((i+1) % 20 == 0){
            cout << endl;
        }
    }
    cout << test[test.size()-1] << "\n";
    cout << "End List\n";
}