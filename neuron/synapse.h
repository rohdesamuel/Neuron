#ifndef SYNAPSE__H
#define SYNAPSE__H

#include "protein.h"
typedef enum CONNECTION_TYPE {DENDRITE, SOMA, AXON} CONNECTION_TYPE;
typedef enum SYNAPSE_TYPE {CHEMICAL, ELECTRICAL} SYNAPSE_TYPE;
typedef enum CHANNEL_TYPE {ACTION, POSTSYNAPTIC} CHANNEL_TYPE;

typedef struct Synapse {
	void * from;
	void * to;
	CONNECTION_TYPE from_type;
	CONNECTION_TYPE to_type;
	SYNAPSE_TYPE type;
	union  {
		struct Electrical_Synapse {
			int delete_me;
		} electrical;

		struct Chemical_Synapse {
			Protein * transmitter;
			Protein * receptor;
		} chemical;
	}synapse;

	float perm;
} Synapse;

typedef struct Ion_Channel{
	int time, on;
	int length, diameter, velocity;
	float voltage, area, resistivity, resistance;

	CHANNEL_TYPE channel_type;
	union {
		struct action_potential{
			float threshold;
			int strength;
		} action;

		struct postsynaptic_potential{
			int decrement_speed;
		} postsynaptic;

	} potential;
}Ion_Channel;

#define CONNECTION(name, from, to) CONNECTION_(name, from, to)
#define CONNECTION_(name_, from_, to_) struct connection_##name_{\
from_ from;\
to_ to;\
int from_size;\
int to_size;\
}

#define CONNECTION_INIT(connection) (connection)->from_size = 0;\
(connection)->to_size = 0;

Synapse * synapse_create(void * from, CONNECTION_TYPE from_type, void * to, CONNECTION_TYPE to_type, SYNAPSE_TYPE type);
void connect(void * from, CONNECTION_TYPE from_type, void * to, CONNECTION_TYPE to_type, SYNAPSE_TYPE type);
void ion_channel_init(Ion_Channel * ion_channel, int length, int diameter);

#endif