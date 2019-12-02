#include "hash.h"
#include <stdlib.h>
#include <stdio.h>


void test_hash()
{
	int a = 12;
	float b = 23.34;
	double c = 34.678;
	long d = 9223372036854775807;
	long d2 = -9223372036854775808;

	char *string = "hello world";
	char string1[] = "hello world";
	printf("string[%d]\n%d\nfloat[%d]\ndouble[%d]\nlong[%d]\n", string_hash_code(string), string_hash_code(string1), float_hash_code(b), double_hash_code(c), long_hash_code(d));
	printf("%d\t%d\n", long_hash_code(d), long_hash_code(d2));
	printf("%d\n",long_hash_code(1));
}

int main(int argc, char *argv[]) 
{
	test_hash();
}
