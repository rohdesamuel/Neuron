#include <stdlib.h>
#include "receiver.h"

/*Receiver * receiver_create( Synapse * synapse )
{
	Receiver * tmp = malloc( sizeof(Receiver) );
	receiver_init(tmp, synapse);
	return tmp;
}

void receiver_init( Receiver * receiver, Synapse * synapse )
{
	if (receiver != NULL)
	{
		receiver->synapse = synapse;
		receiver->action = NULL;
		receiver->receivers = NULL;
		receiver->size = 0;
	}
}

void receiver_add_protein( Receiver * receiver, Protein * protein)
{
	receiver->size ++;
	receiver->receivers = realloc(receiver->receivers, receiver->size * sizeof(Protein));
	receiver->receivers[receiver->size - 1] = *protein;
}

void receiver_set_action( Receiver * receiver, void * (*new_action) ( struct Receiver * receiver ) )
{
	receiver->action = new_action;
}*/