#include <stdlib.h>
#include "axon.h"

Axon * axon_create(int length, int diameter)
{
	Axon * tmp = malloc(sizeof(Axon));
	axon_init(tmp, length, diameter);
	return tmp;
}

void axon_init(Axon * axon, int length, int diameter)
{
	if (axon != NULL)
	{
		axon->connection.from = NULL;
		axon->connection.to = NULL;
		CONNECTION_INIT(&axon->connection);
		ion_channel_init(&axon->ion_channel, length, diameter);
	}
}