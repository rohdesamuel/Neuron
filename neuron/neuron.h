#ifndef NEURON__H
#define NEURON__H

#include "soma.h"
#include "axon.h"
#include "dendrite.h"

typedef struct Neuron {
	Soma soma;
} Neuron;

Neuron * neuron_create();
void neuron_init(Neuron * neuron);

Dendrite * neuron_add_dendrite(Neuron * neuron, SYNAPSE_TYPE type, int length, int diameter);
Axon * neuron_add_axon(Neuron * neuron, SYNAPSE_TYPE type, int length, int diameter);

#endif