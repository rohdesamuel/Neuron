#include <stdlib.h>
#include "neuron.h"

Neuron * neuron_create()
{
	Neuron * tmp = malloc(sizeof(Neuron));
	neuron_init(tmp);
	return tmp;
}

void neuron_init(Neuron * neuron)
{
	if (neuron != NULL)
		soma_init(&neuron->soma);
}

Dendrite * neuron_add_dendrite(Neuron * neuron, SYNAPSE_TYPE type, int length, int diameter)
{
	Dendrite * new_dendrite = dendrite_create(length, diameter);
	connect(new_dendrite, DENDRITE, &neuron->soma, SOMA, type);
	return new_dendrite;
}

Axon * neuron_add_axon(Neuron * neuron, SYNAPSE_TYPE type, int length, int diameter)
{
	Axon * new_axon = axon_create(length, diameter);
	connect(&neuron->soma, SOMA, new_axon, AXON, type);
	return new_axon;
}