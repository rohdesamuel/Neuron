#include <stdlib.h>
#include "neuron.h"

#define INITIAL_PERM 0.1f
#define INITIAL_THRESH 0.3f
#define INITIAL_RESISTIVITY 1 

Synapse * synapse_create(void * from, CONNECTION_TYPE from_type, void * to, CONNECTION_TYPE to_type, SYNAPSE_TYPE type)
{
	Synapse * new_syn = malloc(sizeof(Synapse));
	if (new_syn != NULL)
	{
		new_syn->from = from;
		new_syn->from_type = from_type;
		new_syn->to = to;
		new_syn->to_type = to_type;
		new_syn->perm = INITIAL_PERM;
		new_syn->type = type;
	}
	return new_syn;
}
void ion_channel_init(Ion_Channel * ion_channel, int length, int diameter)
{
	if (ion_channel != NULL)
	{
		ion_channel->on = 0;
		ion_channel->time = 0;
		ion_channel->voltage = 0;
		ion_channel->length = length;
		ion_channel->area = (float)((diameter / 2) * (diameter / 2)) * 3.141592653f;
		ion_channel->resistivity = INITIAL_RESISTIVITY;
		ion_channel->resistance = (ion_channel->resistivity * ion_channel->length) / (ion_channel->area);
	}
}
void ion_action_init(Ion_Channel * ion_channel, int length, int diameter)
{
	if (ion_channel != NULL)
	{
		ion_channel_init(ion_channel, length, diameter);
		ion_channel->channel_type = ACTION;

		ion_channel->potential.action.threshold = INITIAL_THRESH;
		ion_channel->potential.action.strength = 0;
	}
}

void ion_postsynaptic_init(Ion_Channel * ion_channel, int length, int diameter)
{
	if (ion_channel != NULL)
	{
		ion_channel_init(ion_channel, length, diameter);
		ion_channel->channel_type = POSTSYNAPTIC;

		ion_channel->potential.postsynaptic.decrement_speed = 1;
	}
}

/*
Supports:
	axoaxonic: axon - axon
	axodendritic: axon - dendrite
	axosomatic: axon - soma
	denrodendritic: dendrite - dendrite
*/
void connect(void * from, CONNECTION_TYPE from_type, void * to, CONNECTION_TYPE to_type, SYNAPSE_TYPE type)
{
	Synapse * new_syn = synapse_create(from, from_type, to, to_type, type);
	if (from != NULL && to != NULL)
	{
		switch(from_type)
		{
			case DENDRITE:
				(*(Dendrite*)(from)).connection.to = new_syn;
				break;
			
			case SOMA:
				(*(Soma*)(from)).connection.to_size ++;
				(*(Soma*)(from)).connection.to = realloc((*(Soma*)(from)).connection.to, ((*(Soma*)(from)).connection.to_size + 1) * sizeof(Synapse*));
				(*(Soma*)(from)).connection.to[(*(Soma*)(from)).connection.to_size - 1] = new_syn;
				(*(Soma*)(from)).connection.to[(*(Soma*)(from)).connection.to_size] = NULL;
				break;

			case AXON:
				(*(Axon*)(from)).connection.to_size ++;
				(*(Axon*)(from)).connection.to = realloc((*(Axon*)(from)).connection.to, ((*(Axon*)(from)).connection.to_size + 1) * sizeof(Synapse*));
				(*(Axon*)(from)).connection.to[(*(Axon*)(from)).connection.to_size - 1] = new_syn;
				(*(Axon*)(from)).connection.to[(*(Axon*)(from)).connection.to_size] = NULL;
				break;
		}

		switch(to_type)
		{
			case DENDRITE:
				(*(Dendrite*)(to)).connection.from_size ++;
				(*(Dendrite*)(to)).connection.from = realloc((*(Dendrite*)(to)).connection.from, ((*(Dendrite*)(to)).connection.from_size + 1) * sizeof(Synapse*));
				(*(Dendrite*)(to)).connection.from[(*(Dendrite*)(to)).connection.from_size - 1] = new_syn;
				(*(Dendrite*)(to)).connection.from[(*(Dendrite*)(to)).connection.from_size] = NULL;
				break;
			
			case SOMA:
				(*(Soma*)(to)).connection.from_size ++;
				(*(Soma*)(to)).connection.from = realloc((*(Soma*)(to)).connection.from, ((*(Soma*)(to)).connection.from_size + 1) * sizeof(Synapse*));
				(*(Soma*)(to)).connection.from[(*(Soma*)(to)).connection.from_size - 1] = new_syn;
				(*(Soma*)(to)).connection.from[(*(Soma*)(to)).connection.from_size] = NULL;
				break;

			case AXON:
				(*(Axon*)(to)).connection.from = new_syn;
				break;
		}
	}
}