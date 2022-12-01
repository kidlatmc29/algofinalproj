// Isabel Ovalles
// CPSC 4100 - Final Project 

// References: 
// https://bastian.rieck.me/blog/posts/2010/bin_packing/
// https://github.com/Pseudomanifold/bin-packing-heuristics

// my-data-set was generating using the perl script in https://github.com/Pseudomanifold/bin-packing-heuristics

#include <iostream> 
#include <iomanip>
#include <fstream>

using namespace std; 

struct Stats
{
    int numOfBins; 
    double elapsedTime; 
};

/*
    Pre Conditions: 
    Post Conditions: 
*/
void readData();

/*
    Pre Conditions: 
    Post Conditions: 
*/
Stats findMinNumBins();

/*
    Pre Conditions: 
    Post Conditions: 
*/
Stats findFirstFit();

int main()
{
    cout << "CPSC 4100 - Final Project: Comparing Bin-Packing " << endl;

    return 0;
}

// reading in list of data
void readData()
{

}

// 1.) intractable but optimal solution 
Stats findMinNumBins()
{

}

// 2.) use heuristic from resourse 
Stats findFirstFit()
{

}