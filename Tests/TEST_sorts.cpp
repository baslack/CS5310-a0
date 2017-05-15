/**
 * Benjamin A. Slack
 * CS5310, Summer 1 2017
 * a0, Selection Sort
 * 05.13.17
 * benjamin.slack@wmich.edu
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../sorts.h"

TEST(selection_sort, reverse){
    vector<int> test;
    for (int i = 15; i >= 0; i--){
        test.push_back(i);
    }
    sorts::selectionSort(test);
    for (int i = 0; i < 16; i++){
        ASSERT_EQ(i, test[i]);
    }
}

TEST(selection_sort, empty_list){
    vector<int> test;
    int ret_val = sorts::selectionSort(test);
    ASSERT_EQ(-1, ret_val);
}

int main (int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    exit(0);
}

