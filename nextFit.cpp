#include <iostream>
#include <iomanip>
#include <vector> 

using namespace std;


void nextFit(int n, int K, vector<int> weights);

int main()
{
    vector<int> myWeights; 
    int n = 10; 
    int K = 100; 

    myWeights.push_back(10);
    myWeights.push_back(47);
    myWeights.push_back(67);
    myWeights.push_back(29);
    myWeights.push_back(82);
    myWeights.push_back(45);
    myWeights.push_back(12);
    myWeights.push_back(54);
    myWeights.push_back(71);
    myWeights.push_back(39); 

    nextFit(n, K, myWeights);

    return 0; 
}

void nextFit(int n, int K, vector<int> weights)
{
    int numOfBins = 0;
    int binCap = K; 
    
    clock_t start = clock();
    for(int i = 0; i < n; i++)
    {
        if(weights[i] > binCap)
        {
            numOfBins++;
            binCap = K - weights[i];
        } else {
            binCap -= weights[i];
        }
    }

    clock_t end = clock(); 

    cout << "Time Elapsed: " << fixed  << setprecision(10) << (end-start)/static_cast<double>(CLOCKS_PER_SEC) <<  " miliseconds" << endl;
    cout << "num of bins " << numOfBins << endl;

}