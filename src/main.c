#include <stdio.h>
#include <stdint.h>
#include "CircularBuffer.h"

int main(){

	tCircularBuffer stTestBuffer;
	CircularBuffer_voInit(&stTestBuffer);

	printf("Index start: %d\n", stTestBuffer.ssStart);
	printf("Index end: %d\n", stTestBuffer.ssEnd);

} /* end main */
