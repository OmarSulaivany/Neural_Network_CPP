#include "Neuron.h"
#include "Connection.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib> // For srand() and rand()

// Overall net learning rate, we might need to tune this number to make our network perform better and faster.
double Neuron::learning_rate = 0.01;

// Momentum, multiplier of last deltaWeight, we might need to change this number to make our network perform better and faster.
double Neuron::momentum = 0.05;

Neuron::Neuron(unsigned numOutputs, unsigned myIndex)
{
    // Seed the random number generator (only once for reproducibility)
    static bool seeded = false;
    if (!seeded) {
        srand(42); // Fixed seed for reproducibility
        seeded = true;
    }

    /* Loop through the number of outputs. The next code will create connections based on the number of outputs,
       after that feed each weight with a random number using Xavier Initialization. */
    for (unsigned c = 0; c < numOutputs; ++c)
    {
        /* Create output connections in the neuron. */
        m_outputWeights.push_back(Connection());

        /* Set a random number to the Weight variable in the created connection using Xavier Initialization. */
        m_outputWeights.back().weight = randomWeight(numOutputs);
    }

    /* Handle the index of the neuron locally. */
    m_myIndex = myIndex;
}

/* Tanh activation function: Transforms the output value into a range between -1 and 1. */
double Neuron::Activation(double x) {
    return tanh(x);
}

/* Derivative of the tanh function: tanh'(x) = 1 - tanh(x)^2. */
double Neuron::Activation_prime(double x) {
    double tanh_x = tanh(x);
    return 1.0 - tanh_x * tanh_x;
}

void Neuron::feedforward(const Layer &preLayer)
{
    // Variable sum, to sum the output of each neuron of the previous layer including the bias neuron (which are our inputs).
    double sum = 0.0;

    /* Loop through each neuron in the previous layer including bias. */
    for (unsigned n = 0; n < preLayer.size(); ++n)
    {
        /* Sum all (neurons * weights in the previous layer), and since our weight vector has its own index, 
           we will pass m_myIndex, which is the current neuron index. */
        sum += preLayer[n].getOutputVal() * preLayer[n].m_outputWeights[m_myIndex].weight;
    }

    /* Apply the tanh activation function to the output. */
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
	m_gradient = dow * Neuron::Activation_prime(m_outputVal);
}

double Neuron::sumDOW(const Layer& nextLayer) const
{
	// We will need this variable to store the summation of the derivative of weights of each neuron in the next layer.
	double sum = 0.0;

	/* loop through each neuron in the next layer except the bias neuron. */
	for (unsigned n = 0; n < nextLayer.size() - 1; ++n)
	{
		/* The weights in the current neuron * the gradient decent of the neuron in the next layer. */
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}

void Neuron::updateInputWeights(Layer& prevLayer)
{
	/* Note: The weights to be updated are in a container of connections in the neurons of the previous layer. */

	/* loop through each neuron in the previous layer including bias. */
	for (unsigned n = 0; n < prevLayer.size(); ++n)
	{
		/* Create a neuron to be same as the neuron in the previous layer. */
		Neuron& neuron = prevLayer[n];

		// Save all "current" weights of neuron of the previous layer.
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		 /* Factors that effects the updating of weights of each neuron are ("learning rate, gradient decent of the neuron and
		    the output value of the previous neuron.

		    learning rate * output of the previous neuron * gradient decent of the current neuron.
		    Plus momentum = a fraction of the previous delta weight * "Old Weights".

		    momentum helps to extend the movement in the same direction, when the oldweights are almost the same as the
		    current weights.*/
		double newDeltaWeight =

			/* Individual input, magnified by the gradient and train rate. */
			learning_rate

			/* Output value of the previous neuron. */
			* neuron.getOutputVal()

			// Gradient decent of the neuron
			* m_gradient

			/* momentum = a fraction of the previous delta weight. */
			+ momentum

			/* Old changing weight. */
			* oldDeltaWeight;

		/* Update the delta weights to store the current new weight. in the previous layer neurons. */
		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;

		/* Update the current weights in each neuron of the previous layer, W_new=W_old + NewDeltaWeights. */
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;
	}
}
