#ifndef NNEURON_HH
#define NNEURON_HH
#include "Connection.h"
#include <cstdlib>
#include <cmath> // For sqrt
#include <vector>
using namespace std;

/* The Neuron has the following:
1- output value.
2- output weights in a vector.
And it needs to know the number of Neurons in the next layer in order to create output weight connections. */

class Neuron;

/* Layer contains a number of Neurons. */
typedef vector<Neuron> Layer;

class Neuron
{
public:
    /* To construct a neuron, it needs to know the number of neurons in the next layer
       and the index number for indexing the weight vector while doing the feedforward. */
    Neuron(unsigned numOutputs, unsigned myIndex);

    /* This function assigns output values to the neurons that come from the Feedforward function in the Net class. */
    void setOutputVal(double val) { m_outputVal = val; }

    /* Get output values of neuron for visualizing "printing". */
    double getOutputVal(void) const { return m_outputVal; }

    /* This function applies the math part inside the neuron: output = sum(Inputi * Weighti). */
    void feedforward(const Layer &preLayer);

    /* This function calculates the gradient of each neuron in the output layer. */
    void calcOutputGradients(double targetVals);

    /* This function calculates the gradient of each neuron in the hidden layers. */
    void calcHiddenGradients(const Layer &nextLayer);

    /* This function updates the weights of each neuron. It needs to know the previous layer parameter. */
    void updateInputWeights(Layer &prevLayer);

private:
    /* We need an activation function to normalize "squeeze" our output value of the neuron between either 0,1 or -1,1. */
    static double Activation(double x);

    /* We need this function when we do the backpropagation to update our weights. */
    static double Activation_prime(double x);

    /* To calculate the error rate in the hidden layers per each neuron, we will take the sum of the derivative of weights of
       the next layer. */
    double sumDOW(const Layer &nextLayer) const;

    /* This function will return a random weight using Xavier Initialization. */
    static double randomWeight(unsigned numOutputs)
    {
        // Xavier Initialization: Random weight scaled by sqrt(1 / number of outputs).
        return rand() / double(RAND_MAX) * sqrt(1.0 / numOutputs);
    }

    // Is the learning rate of the overall Network.
    static double learning_rate;

    // Multiplier of last weight change [momentum].
    static double momentum;

    // The output value of the neuron.
    double m_outputVal;

    // The vector of output weights and delta weights.
    vector<Connection> m_outputWeights;

    /* Indexing each neuron. This is important when we sum up outputVals * weights.
       We need the neuron index to know what weights to multiply with what outputVals. */
    unsigned m_myIndex;

    // This member handles the gradient descent of the neuron.
    double m_gradient;
};

#endif
