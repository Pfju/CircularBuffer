#include "CircularBuffer.h"

static RingBuffer_t *g_buffer;

void RingBuffer_init(RingBuffer_t *p){
	g_buffer = p;
	g_buffer->head = 0;
	g_buffer->tail = 0;
	g_buffer->length = 0;
} /* end RingBuffer_init */

void RingBuffer_push(int value){
	g_buffer->buffer[g_buffer->tail] = value;
	g_buffer->tail = (g_buffer->tail + 1) % BUFFER_SIZE;
	if (g_buffer->length < BUFFER_SIZE){
		g_buffer->length += 1;
	} /* end if */
	else{
		g_buffer->head += 1;
	} /* end else */
} /* end RingBuffer_push */

int RingBuffer_pop(int *pValue){
	/* return error if buffer is empty */
	if (0 == g_buffer->length)	return -1;

	*pValue = g_buffer->buffer[g_buffer->head];
	g_buffer->head = (g_buffer->head +1) % BUFFER_SIZE;
	g_buffer->length -= 1;
	return 0;
} /* end RingBuffer_pop */
