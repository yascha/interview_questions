#ifndef ELEM_H
#define ELEM_H

typedef struct Element {
	struct Element *next;
	void *data;
} Element;

#endif //ifndef ELEM_H
