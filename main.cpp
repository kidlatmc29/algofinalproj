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
#include <ctime>

using namespace std; 

struct stats
{
    double timeElapsed; 
    int numOfBins; 
};

/*
    Pre Conditions: None. 
    Post Conditions: None.
*/
void welcomeMsg();

/*
    Reading in list of data from input file from cmd line.
    Pre Conditions: File name was passed in as a console argument. 
    Post Conditions: objWeights is filled with all weights listed in the file. 
                    returns an int array that holds the numOfObjs and binSize
*/
void readData(vector<int> &objWeights);

/*
    Intractable but optimal solution.
    Pre Conditions: objWeights is initalized. n and K are positive numbers. 
    Post Conditions: returns a stat struct that contains time elapsed and num of bins.
*/
stats findMinNumBins(int n, int K, vector<int> &objWeights);

/*
    Greedy heuristics for approximation. 
    Pre Conditions: objWeights is initalized. n and K are positive numbers. 
    Post Conditions: returns a stat struct that contains time elapsed and num of bins.
*/
stats findNextFit(int n, int k, vector<int> &objWeights);

/*
    Pre Conditions: m is initalized properly. 
    Post Conditions: None.
*/
void printStats(stats m);

int main()
{  
    vector<int> objWeights; 
    int numOfObjs = 0;
    int binSize = 0; 

    welcomeMsg(); 

    cin >> numOfObjs; 
    cin >> binSize;
    readData(objWeights);

    cout << "Using a data set with " << numOfObjs << " objects with a bin size of " 
         << binSize << "." << endl << endl;

    cout << "====== Find Minimum Number of Bins ======= " << endl;
    cout << "=== (Intractable but Optimal Solution) === " << endl;
    printStats(findMinNumBins(numOfObjs, binSize, objWeights));
    cout << "==========================================" <<  endl << endl;

    cout << "=== Next Fit Stats === " << endl;
    printStats(findNextFit(numOfObjs, binSize, objWeights));
    cout << "========================" <<  endl;

    cout << endl << endl; 
    return 0;
}

void welcomeMsg()
{
    cout << endl << endl << "CPSC 4100 - Final Project: Comparing Bin-Packing " << endl << endl;
}

void readData(vector<int> &objWeights)
{
    int currentWeight = 0; 

    while (cin >> currentWeight)
    {
        objWeights.push_back(currentWeight);
    }
}

stats findMinNumBins(int n, int K, vector<int> &objWeights)
{
    stats minBinStats; 
    int numOfBins = 0; 
    vector<bool> isObjsProcessed; 
    int numObjsProcessed = 0; 
    int currentWeight = 0; 

    clock_t start = clock();

    for(int i = 0; i < n; i++)
    {
        isObjsProcessed.push_back(false);
    }

    while(numObjsProcessed < n)
    {
        currentWeight = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            if(!isObjsProcessed[i] && currentWeight < K)
            {
                currentWeight += objWeights[i];
                isObjsProcessed[i] = true;
                numObjsProcessed++;
                if (currentWeight > K)
                {
                    isObjsProcessed[i] = false;
                    numObjsProcessed--;
                    currentWeight -= objWeights[i];
                    break;
                }
            } 
        }

        for(int j = 0; j < objWeights.size(); j++)
        {
            if(!isObjsProcessed[j] && currentWeight < K)
            {
                currentWeight += objWeights[j];
                isObjsProcessed[j] = true;
                numObjsProcessed++;
                if (currentWeight > K)
                {
                    isObjsProcessed[j] = false;
                    numObjsProcessed--;
                    currentWeight -= objWeights[j];
                    break;
                }
            } 
        }
        numOfBins++;
    }

    clock_t end = clock();

    minBinStats.timeElapsed = (end-start)/static_cast<double>(CLOCKS_PER_SEC);
    minBinStats.numOfBins = numOfBins;
    return minBinStats;
}

stats findNextFit(int n, int K, vector<int> &objWeights)
{
    int numOfBins = 1; 
    int currentBinWeight = K; 
    stats nextFitStats; 

    clock_t start = clock();
    for(int i = 0; i < n; i++)
    {
        if(objWeights[i] > currentBinWeight)
        {
            numOfBins++;
            currentBinWeight = K - objWeights[i];
        } else {
            currentBinWeight -= objWeights[i];
        }
    }
    clock_t end = clock(); 

    nextFitStats.timeElapsed = (end-start)/static_cast<double>(CLOCKS_PER_SEC);
    nextFitStats.numOfBins = numOfBins;
    
    return nextFitStats; 
}

void printStats(stats m)
{
    cout << "Time Elapsed: " << fixed << setprecision(8) << m.timeElapsed << " miliseconds" << endl;
    cout << "Number of Bins: " << m.numOfBins << endl;
}