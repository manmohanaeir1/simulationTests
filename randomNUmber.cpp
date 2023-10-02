// to generate random numbers by using linera congential method and chi-square test and test the uniformaty of generated numbers 





#include <bits/stdc++.h>
using namespace std;

// Function to generate random numbers
void linearCongruentialMethod(
	int Xo, int m, int a, int c,
	vector<int>& randomNums,
	int noOfRandomNums)
{

	// Initialize the seed state
	randomNums[0] = Xo;

	// Traverse to generate required
	// numbers of random numbers
	for (int i = 1; i < noOfRandomNums; i++) {
		// Follow the linear congruential method
		randomNums[i]
			= ((randomNums[i - 1] * a) + c) % m;
	}
}

// to test the uniformaty of generated numbers
void chiSquareTest(vector<int>& randomNums, int noOfRandomNums)
{
    int k = 10;
    int n = noOfRandomNums;
    int f[k];
    for(int i=0;i<k;i++)
    {
        f[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        f[randomNums[i]]++;
    }
    float chiSquare = 0;
    for(int i=0;i<k;i++)
    {
        chiSquare += pow(f[i],2);
    }
    chiSquare = (chiSquare*n)/k;
    cout<<"Chi-Square value is "<<chiSquare<<endl;
    if(chiSquare<16.9)
    {
        cout<<"Uniformity is satisfied"<<endl;
    }
    else
    {
        cout<<"Uniformity is not satisfied"<<endl;
    }
}


// Driver Code
    int main()
   {
	int Xo = 5; // Seed value
	int m = 7; // Modulus parameter
	int a = 3; // Multiplier term
	int c = 3; // Increment term

	// Number of Random numbers
	// to be generated
	int noOfRandomNums = 100;

	// To store random numbers
	vector<int> randomNums(
		noOfRandomNums);

	// Function Call
	linearCongruentialMethod(
		Xo, m, a, c,
		randomNums, noOfRandomNums);

	// Print the generated random numbers
	for (int i = 0; i < noOfRandomNums; i++) {
		cout << randomNums[i] << " ";
	}
    cout<<endl;
    chiSquareTest(randomNums,noOfRandomNums);
    return 0;
}
