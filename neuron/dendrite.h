#ifndef DENDRITE__H
#define DENDRITE__H

#include "synapse.h"

typedef struct Dendrite {
	Ion_Channel ion_channel;
	CONNECTION(dendrite, Synapse **, Synapse *) connection;
} Dendrite;

Dendrite * dendrite_create(int length, int diameter);
void dendrite_init(Dendrite * dendrite, int length, int diameter);

#endif