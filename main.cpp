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
void readData(vector<int> &objWeights);

/*
    Pre Conditions: 
    Post Conditions: 
*/
void findMinNumBins();

/*
    Pre Conditions: 
    Post Conditions: 
*/
void findNextFit(int n, int k, vector<int> &objWeights);

int main()
{  
    vector<int> objWeights; 
    int numOfObjs = 0;
    int binSize = 0; 

    welcomeMsg(); 

    cin >> numOfObjs; 
    cin >> binSize;
    readData(objWeights);

    cout << "=== Next Fit Stats === " << endl;
    findNextFit(numOfObjs, binSize, objWeights);
    cout << "========================" <<  endl;

    cout << endl << endl; 
    return 0;
}

void welcomeMsg()
{
    cout << endl << endl << "CPSC 4100 - Final Project: Comparing Bin-Packing " << endl << endl;
}

// reading in list of data from input file from cmd line
void readData(vector<int> &objWeights)
{
    int currentWeight = 0; 

    while (cin >> currentWeight)
    {
        objWeights.push_back(currentWeight);
    }
}

// 1.) intractable but optimal solution 
void findMinNumBins()
{

}

// 2.) use heuristic from resourse 
void findNextFit(int n, int K, vector<int> &objWeights)
{
    int numOfBins = 0; 
    int binCap = K; 

    clock_t start = clock();
    for(int i = 0; i < n; i++)
    {
        if(objWeights[i] > binCap)
        {
            numOfBins++;
            binCap = K - objWeights[i];
        } else {
            binCap -= objWeights[i];
        }
    }

    clock_t end = clock(); 

    cout << "Time Elapsed: " << fixed  << setprecision(10) << (end-start)/static_cast<double>(CLOCKS_PER_SEC) <<  " miliseconds" << endl;
    cout << "Num of Bins " << numOfBins << endl;
}