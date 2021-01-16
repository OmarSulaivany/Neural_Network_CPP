#ifndef NNET_HH
#define NNET_HH
#include "Neuron.h"
#include <vector>
using namespace std;

/* Layer contain a number of Neurons. */
typedef vector<Neuron> Layer;

class Net
{

public:

	/* pass the reference topology vector e.g {3,2,1}. */
	Net(const vector <unsigned> &topology);

	void feedforward(const vector <double> &inputVals);
	void backProb(const vector <double> &targetVals);
	void getResults(vector <double> &resultVals) const {};

private:

	/* m_layers[layerNum][neuronNum], m_layers is a vector of layers and because a layer is a vector of neurons then it means 
	m_layers is a 2d vector that represents [layer_number][neuron_number]. */
	vector <Layer> m_layers;

	// We need this variable to handle the error "the difference between our output values in the last layer and our target value".
    double m_error;

    /* We use this variable in the formula where we can see how well our neural notwork performs by printing out the Error in the
       last couple of iterations. */
    double m_recentAverageError; 

    // Same as above we use this variable in a formula were we can see the results of overall error after some iterations.
	static double m_recentAverageSmoothingFactor;

};

#endif
