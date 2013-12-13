#include <stdlib.h>
#include "soma.h"

Soma * soma_create()
{
	Soma * tmp = malloc(sizeof(Soma));
	soma_init(tmp);
	return tmp;
}

void soma_init(Soma * soma)
{
	if (soma != NULL)
	{
		soma->connection.from = NULL;
		soma->connection.to = NULL;
		CONNECTION_INIT(&soma->connection);
		ion_channel_init(&soma->ion_channel, 0, 1);
	}
}