#include <stdlib.h>
#include <stdio.h>

#include "protein.h"
#include "neuron.h"
#include "tuple.h"

int main()
{
	int check;
	Protein p1, p2;
	Neuron n1, n2;

	neuron_init(&n1);
	neuron_add_dendrite(&n1, CHEMICAL, 1, 1);
	neuron_add_dendrite(&n1, CHEMICAL, 1, 1);
	neuron_add_axon(&n1, CHEMICAL, 1, 1);

	neuron_init(&n2);
	neuron_add_dendrite(&n2, CHEMICAL, 1, 1);
	neuron_add_dendrite(&n2, CHEMICAL, 1, 1);
	neuron_add_axon(&n2, CHEMICAL, 1, 1);
	
	protein_init(&p1, 4, 0, 1, 2, 3);
	protein_init(&p2, 4, 3, 2, 1, 0);

	while(1);

	return 0;
}