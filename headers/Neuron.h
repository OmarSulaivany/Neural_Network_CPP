#ifndef NNEURON_HH
#define NNEURON_HH
#include "Connection.h"
#include <cstdlib>
#include<vector>
using namespace std;

/*The Neuron has the following:
1- output value.
2- output weights in a vector
And it needs to know the number of Neurons in the next layer in order to create output connections.  */

class Neuron
 {


public:
    
  /* To construct a neuron it need to know the number of neurons in the next layer,/
     and the index number for indexing the weight vector while doing the feedforward. */
	Neuron(unsigned numOutputs, unsigned myIndex);

  /* This function assigns output values to the neurons that comes from Feedforward function in th Net class. */
  void setOutputVal(double val) { m_outputVal = val;}

  /* Get output values of neuron for visualizing "printing". */
  double getOutputVal(void) const {return m_outputVal;}

  /* This function apply math part inside the neuron output = sum(Inputi * Weighti). */
  void feedforward(const layer &preLayer);

  /* This function calculates the gradient of each neuron in the output layer. */
  void calcOutputGradients(double targetVals); 

  /* This function calculates the gradient of each neuron in the hidden layers. */
  void calcHiddenGradients(const Layer& nextLayer);

  /* This function updates the weights of each neurons. it needs to know the previous layer parameter. */
  void updateInputWeights(Layer& prevLayer);

private:

  /* We need an activation function to normalize "squeeze" our output value of neuron between either 0,1 or -1,1 .. */
  static double Activation(double x);

  /* We need this function when we do the backpropagation to update our weights. */
  static double Activation_prime(double x);


  /* This function will return a random decimal number between 0,1. We need this function because when we first construct a neuron
   we need to assign to it random weight values. */
	static double randomWeight(void) { return rand() / double(RAND_MAX);}

   // The output value of the neuron.
   double m_outputVal;

   // the vector of Output weights and deltaweights. 
   vector <Connection> m_outputWeights;

   // indexing each neuron, this important when we sum up outputvals * weights , we need the neuron index to know what weights
   // to multiply with what outputvals.
   unsigned m_myIndex;

   // We need this variable to handle the error "the difference between our output values in the last layer and our target value".
   double m_error;

};


#endif

