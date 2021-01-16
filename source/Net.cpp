#include "Net.h"
#include <iostream>
#include <vector>
using namespace std;


/* pass the reference topology vector e.g {3,2,1}. */
Net::Net( vector<unsigned> &topology)
{
    /* Total number of layers, we need it in order to create layers in the following line codes. */
	unsigned numLayers = topology.size();
 
     /* To create the corresponding layers per topology,/
	    we need this loop that starts from zero to the size of topology. */
	for(unsigned layerNum=0; layerNum<numLayers; ++layerNum)
	{   
	    /* Create a layer and add it to the m_layer 2d vector. */
		m_layers.push_back(Layer());

		/* numOutputs of layer[i] is the numInputs of layer[i+1] numOutputs of last layer is 0/
		numOutputs variable stores number of neurons in the next layer.
		
		This is important when we create neurons we will need to know
		how many output connections the neuron should have.
		this condition specifies the neurons in the last layer "output" layers
		has zero output connections.*/
		unsigned numOutPuts = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
		
		
		
	    
	    /* We have made a new Layer, now fill it ith neurons, and
		add a bias neuron to the layer:
	    To add corresponding neurons per each layer,/
	    we need this loop that starts from zero to the size of layer plus 1 as we need one more neuron for the bias. */

		for(unsigned neuronNum=0 ; neuronNum <=topology[layerNum]; ++neuronNum)
		{

        /* Fill each layer with it's corresponding neurons. */
		m_layers.back().push_back(Neuron(numOutPuts));
		cout<<" A Neuron Made!"<<endl;

		}
	}

}