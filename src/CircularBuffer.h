#ifndef CircularBuffer_H
#define CircularBuffer_H

#define BUFFER_SIZE 5

typedef struct {
	int buffer[BUFFER_SIZE];
	int head;
	int tail;
	int length;
}RingBuffer_t; /* end struct RingBuffer_t */

void RingBuffer_init(RingBuffer_t *p);

void RingBuffer_push(int value);

int RingBuffer_pop(int *pValue);

#endif // CircularBuffer_H
