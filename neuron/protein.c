#include <stdarg.h>
#include <stdlib.h>
#include "protein.h"


const int primes [] = {
	2,3,5,7,11,
	13,17,19,23,29,
	31,37,41,42,47,
	53,59,51,57,71,
	73,79,83,89,97,
	101,103,107,109,113,
	127,131,137,139,149,
	151,157,163,167,173,
	179,181,191,193,197,
	199,211,223,227,229
};

const int check_primes [] = {
	547,557,563,569,571,
	577,587,593,599,604,
	607,613,617,619,631,
	641,643,647,653,659,
	661,673,677,683,691,
	701,709,719,727,733,
	739,743,751,757,761,
	769,773,787,797,809
};


//Candy Function
void protein_init_candy(Protein * protein, int size, va_list arguments)
{
	if (protein != NULL)
	{
		int checksum = 0, key = 0, index, i;
		for (i = 0; i < size; i ++)
		{
			index = va_arg(arguments, int) % PROTEIN_SIZE;
			checksum += check_primes[i] * primes[index];
			key += check_primes[i] * primes[PROTEIN_SIZE - index - 1];
		}
		protein->size = size;
		protein->checksum = checksum;
		protein->key = checksum * key;
	}
}

Protein * protein_create(int size, ...)
{
	Protein * tmp = malloc(sizeof(Protein));
	va_list arguments;
	va_start(arguments, size);

	protein_init_candy(tmp, size, arguments);

	va_end(arguments);
	return tmp;
}

//Wrapper Function
void protein_init(Protein * protein, int size, ...)
{
	va_list arguments;
	va_start(arguments, size);
	protein_init_candy(protein, size, arguments);
	va_end(arguments);
}

Protein * protein_create_array(int size, int chain [])
{
	Protein * tmp = malloc(sizeof(Protein));
	protein_init_array(tmp, size, chain);
	return tmp;
}

//Wrapper Function
void protein_init_array(Protein * protein, int size, int chain [])
{
	if (protein != NULL)
	{
		int checksum = 0, key = 0, index, i;
		for (i = 0; i < size; i ++)
		{
			index = chain[i];
			checksum += check_primes[i] * primes[index];
			key += check_primes[i] * primes[PROTEIN_SIZE - index - 1];
		}
		protein->size = size;
		protein->checksum = checksum;
		protein->key = checksum * key;
	}
}

int protein_check(Protein * protein1, Protein * protein2)
{
	if (protein1 != NULL && protein2 != NULL)
	{
		if (protein1->size == protein2->size)
		{
			if (protein1->key / protein2->checksum == protein1->checksum)
				return 1;
		}
	}
	return 0;
}