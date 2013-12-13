#ifndef TUPLE__H
#define TUPLE__H

#define tuple(type_1, type_2) TUPLE__(type_1, type_2)
#define TUPLE__(type_1, type_2) struct TUPLE__##type_1##_##type_2 {\
	type_1 first;\
	type_2 second;\
	}

#endif