#include "Neuron.h"
#include "Connection.h"
#include <vector>
#include <cmath>
//Added plus

Neuron::Neuron(unsigned numOutPuts, unsigned myIndex)
{

/* Loop through number of outputs, the next code will create connections based on the number of outputs, after that feed each weight
 with random number. */
 for (unsigned c = 0; c < numOutPuts; ++c)
 {
 	/* Create output connections in the neuron. */
 	m_outputWeights.push_back(Connection());

 	/* Set a random number to the Weight variable in the created connection. */
    m_outputWeights.back().weight = randomWeight();
 }

/* Handle the index of the neuron locally. */
m_myIndex = myIndex;

}

double Neuron::Activation(double x)
{
    /* We will use Hyperbolic tangent function to transform our output value into a range between (-1,1). */
	return tanh(x);
}


double Neuron::Activation_prime(double x)
{
    /* The derivative of Tanh(x). */
	return 1- x * x;
}


void Neuron::feedforward(const layer &preLayer)
{
    // variable sum, to sum the output of each neuron of the previous layer including the bias neuron. (which are our inputs).
	double sum = 0.0;

    /* loop through each neuron in the previous layer. */
	for(unsigned n = 0 ; n<preLayer; ++n)
	{

		/* Sum all ( neurons * weights in the previous layer), and since our weight vector has it's own index we will pass m_myindex 
		wich is the neuron index. */
		sum+= preLayer[n].getOutputVals() * preLayer[n].m_outputWeights[m_myIndex].weight;
	}

    /* Apply an activation function to the output to make it between a specific range, in our case -1,1. */
	m_outputVal = Neuron::Activation(sum);
}

void Neuron::calcOutputGradients(double targetVals)
{	
	/* Calculate the difference between the target and output value of the neuron. */
	double delta = targetVals - m_outputVal;

	/* To get the gradient we multiply the derivative of the activation function with our delta change. */
	m_gradient = delta * Neuron::Activation_prime(m_outputVal);
}

void Neuron::calcHiddenGradients(const Layer& nextLayer)
{
	/* Because the hidden layer doesn't have the Target value,and to calculate the error rate we will take the sum of the
	   derivative of weight of the next layer. */
	double dow = sumDOW(nextLayer);

	/* To get the gradient we multiply the derivative of the activation function with our delata change. */
	m_gradient = dow * Neuron::activationDerivative(m_outputVal);
}