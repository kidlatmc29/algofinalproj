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
    Pre Conditions: None. 
    Post Conditions: None.
*/
void welcomeMsg();

/*
    Pre Conditions: File name was passed in as a console argument. 
    Post Conditions: objWeights is filled with all weights listed in the file. 
                    returns an int array that holds the numOfObjs and binSize
*/
void readData(int &n, int &K, vector<int> objWeights);

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
    int numOfObjs = 0;
    int binSize = 0; 

    welcomeMsg(); 
    
    readData(numOfObjs, binSize, objWeights);

    // cout << "numOfObjs = " << numOfObjs << endl;
    // cout << "binSize = " << binSize << endl; 

    cout << endl << endl; 

    return 0;
}

void welcomeMsg()
{
    cout << endl << endl << "CPSC 4100 - Final Project: Comparing Bin-Packing " << endl;
}

// reading in list of data from input file from cmd line
void readData(int &n, int &K, vector<int> objWeights)
{
    int currentWeight = 0; 

    cin >> n; 
    cin >> K;

    while (cin >> currentWeight)
    {
        objWeights.push_back(currentWeight);
    }
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
Stats findFirstFit(int n, int K, vector<int> objWeights)
{
    Stats currentStats;
    currentStats.elapsedTime = 0.0;
    currentStats.numOfBins = 0; 

    return currentStats; 
}
