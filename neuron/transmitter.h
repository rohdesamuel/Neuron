#ifndef TRANSMITTER__H
#define TRANSMITTER__H

#include "neuron.h"

typedef struct Vesicle
{
	Protein * protein;
	struct Receptor * receptor;
	int released;
} Vesicle;

typedef struct Transmitter 
{
	Vesicle * vesicles;
	int size;
} Transmitter;


#endif