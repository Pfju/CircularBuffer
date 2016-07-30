#include "unity.h"
#include "CircularBuffer.h"

static RingBuffer_t g_testBuffer;

void setUp(void)
{
	RingBuffer_init(&g_testBuffer);
} /* end setUp */

void tearDown(void)
{
} /* end tearDown */

static void flushBuffer(int value)
{
	int i = 0;
	while(i < BUFFER_SIZE) {
		RingBuffer_push(value);
		i++;
	} /* end while */
} /* end flushBuffer */

void test_init_AllAttributesAreZero(void)
{
	TEST_ASSERT_EQUAL_INT(0, g_testBuffer.head);
	TEST_ASSERT_EQUAL_INT(0, g_testBuffer.tail);
	TEST_ASSERT_EQUAL_INT(0, g_testBuffer.length);
} /* end test_init */

void test_push_AddFirstElement(void)
{
	RingBuffer_push(10);
	TEST_ASSERT_EQUAL_INT(10, g_testBuffer.buffer[0]);
}

void test_push_AddTwoElementsToFullBuffer(void)
{
	flushBuffer(10);
	RingBuffer_push(20);
	RingBuffer_push(30);
	TEST_ASSERT_EQUAL_INT(20, g_testBuffer.buffer[0]);
	TEST_ASSERT_EQUAL_INT(30, g_testBuffer.buffer[1]);
} /* end test_push_AddTwoElementsToFullBuffer */

void test_pop_ReturnErrorForEmptyList(void)
{
	int status;
	int value;
	status = RingBuffer_pop(&value);
	TEST_ASSERT_EQUAL_INT(-1, status);
} /* end test_pop_ReturnErrorForEmptyList */

void test_GetOldestValue(void)
{
	int value;
	int status;
	RingBuffer_push(20);
	status = RingBuffer_pop(&value);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_INT(20, value);
} /* end test_GetOldestValue */

void test_GetOldestValueInFullBuffer(void)
{
	int value;
	int status;
	int i;
	for(i = 0; i <= 6; i++){
		RingBuffer_push(i);
	} /* end for loop */
	status = RingBuffer_pop(&value);
	TEST_ASSERT_EQUAL_INT(0, status);
	TEST_ASSERT_EQUAL_INT(2, value);
} /* end test_GetOldestValueInFullBuffer */
