// Isabel Ovalles
// CPSC 4100 - Final Project 

// References: 
// https://bastian.rieck.me/blog/posts/2010/bin_packing/
// https://github.com/Pseudomanifold/bin-packing-heuristics

// my-data-set was generating using the perl script in https://github.com/Pseudomanifold/bin-packing-heuristics

#include <iostream> 
#include <iomanip>
#include <fstream>
#include <vector>

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
void readData(int n, int K, vector<int> objWeights);

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
    vector<int> objWeights; 
    int n, K;

    cout << "CPSC 4100 - Final Project: Comparing Bin-Packing " << endl;
    
    readData(n, K, objWeights);

    return 0;
}

// reading in list of data from input file from cmd line
void readData(int n, int K, vector<int> objWeights)
{
    int currentWeight = 0; 
    int sumWeight = 0; 
    cin >> n; 
    cin >> K; 

    while (cin >> currentWeight)
    {
        objWeights.push_back(currentWeight);
        sumWeight += currentWeight; 
    }

    cout << "The sum of the weight for " << n << " objects is " << sumWeight << endl;
}

// 1.) intractable but optimal solution 
Stats findMinNumBins()
{
    Stats currentStats;
    currentStats.elapsedTime = 0.0;
    currentStats.numOfBins = 0; 

    
    return currentStats;
}

// 2.) use heuristic from resourse 
Stats findFirstFit()
{
    Stats currentStats;
    currentStats.elapsedTime = 0.0;
    currentStats.numOfBins = 0; 

    return currentStats; 
}
