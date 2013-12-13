#ifndef AXON__H
#define AXON__H

#include "synapse.h"

typedef struct Axon {
	Ion_Channel ion_channel;
	CONNECTION(axon, Synapse *, Synapse **) connection;
} Axon;

Axon * axon_create(int length, int diameter);
void axon_init(Axon * axon, int length, int diameter);

#endif