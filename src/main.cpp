// Neural Network.
#include <vector>
#include "../headers/Net.h"
#include <iostream>
using namespace std;


int main()

{
    /* Create a vector of topology, which specifies number of layers and neurons in the Neural network. */
	 vector <unsigned> topology;

	/* Input layer e.g topology.push_back(3) has 3 neurons */
	topology.push_back(3);

	/* Hidden layer, e.g topology.push_back(2) has 2 neurons */
	topology.push_back(2);

	/* Output layer, e.g topology.push_back(1) has one neuron*/
	topology.push_back(1);


   	Net myNet(topology);


    vector <double> inputVals;
	myNet.feedforward(inputVals);

	vector <double> targetVals;
	myNet.backProb(targetVals);

	vector <double> resultVals;
	myNet.getResults(resultVals);

    return 0;
}
