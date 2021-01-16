#include "../headers/Neuron.h"
#include "../headers/Connection.h"
#include <vector>
Neuron::Neuron(unsigned numOutPuts)
{

/* Loop through number of outputs, the next code will create connections based on the number of outputs, after that feed each weight with/
random number. */
 for (unsigned c = 0; c < numOutPuts; ++c)
 {
 	/* Create output connections in the neuron. */
 	m_outputWeights.push_back(Connection());

 	/* Set a random number to the Weight variable in the created connection. */
    m_outputWeights.back().weight = randomWeight();
 }

}
