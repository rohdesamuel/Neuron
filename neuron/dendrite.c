#include <stdlib.h>
#include "dendrite.h"

Dendrite * dendrite_create(int length, int diameter)
{
	Dendrite * tmp = malloc(sizeof(Dendrite));
	dendrite_init(tmp, length, diameter);
	return tmp;
}

void dendrite_init(Dendrite * dendrite, int length, int diameter)
{
	if (dendrite != NULL)
	{
		dendrite->connection.from = NULL;
		dendrite->connection.to = NULL;
		CONNECTION_INIT(&dendrite->connection);
		ion_channel_init(&dendrite->ion_channel, length, diameter);
	}
}