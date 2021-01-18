// Neural Network Implementation in C++. Gitkraken man i have added you.
#include <vector>
#include "../headers/Net.h"
#include <iostream>
using namespace std;


int main()

{
    /* Create a vector of topology, which specifies number of layers and neurons in the Neural network. */
	 vector <unsigned> topology;

	/* Input layer e.g topology.push_back(3) has 3 neurons */
	topology.push_back(2);

	/* Hidden layer, e.g topology.push_back(2) has 2 neurons */
	topology.push_back(2);

	/* Output layer, e.g topology.push_back(1) has one neuron*/
	topology.push_back(1);


   	Net myNet(topology);

    
  /*  vector <double> inputVals;
    inputVals.push_back(3);
    inputVals.push_back(4);
    inputVals.push_back(2);

	myNet.feedForward(inputVals);


	vector <double> targetVals;

	targetVals.push_back(2);
	myNet.backProbagation(targetVals);

	vector <double> resultVals;
	myNet.getResults(resultVals);

	for(unsigned i=0;i<resultVals.size();++i)
		{cout<<"Prediction = "<<resultVals[i]<<endl;}*/

   	

    return 0;
}
