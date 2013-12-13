#ifndef RECEIVER__H
#define RECEIVER__H

#include "neuron.h"

typedef struct Receptor
{
	void * (*action) ( struct Receptor * receptor, int num, ... );
	Synapse * synapse;
	Protein receptor;
	int active;
} Receptor;

typedef struct Receiver 
{
	Receptor * receptors;
	int size;
} Receiver;

Receiver * receiver_create( Synapse * synapse );
void receiver_init( Receiver * receiver, Synapse * synapse );
void receptor_set_action( Receiver * receiver, void * (*new_action) ( struct Receptor * receptor , int num, ...) );

#endif