#ifndef PROTEIN__H
#define PROTEIN__H

#define PROTEIN_SIZE 5

typedef struct Protein
{
	int size,
	    checksum,
	    key;
} Protein;

Protein * protein_create(int size, ...);
Protein * protein_create_array(int size, int chain []);

void protein_init(Protein * protein, int size, ...);
void protein_init_array(Protein * protein, int size, int chain []);

int protein_check(Protein * protein1, Protein * protein2);

#endif