#ifndef SOMA__H
#define SOMA__H

#include "synapse.h"

typedef struct Soma {
	Ion_Channel ion_channel;
	CONNECTION(soma, Synapse **, Synapse **) connection;
} Soma;

Soma * soma_create();
void soma_init(Soma * soma);

#endif