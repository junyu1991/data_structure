#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "hash.h"

static const uint64_t EXP_BIT_MASK = 9218868437227405312L;
static const uint64_t SIGNIF_BIT_MASK = 4503599627370495L;

static const int FLOAT_EXP_BIT_MASK = 2139095040;
static const int FLOAT_SIGNIF_BIT_MASK = 8388607;

static uint64_t doubleToRawBits(double x) 
{
	uint64_t bits;
	memcpy(&bits, &x, sizeof bits);
	return bits;
}

static long doubleToLongBits(double value) 
{
	long result = (long)doubleToRawBits(value);
	if(((result & EXP_BIT_MASK)==EXP_BIT_MASK) && (result & SIGNIF_BIT_MASK) != 0L)
		result = 0x7ff8000000000000L;
	return result;
}

static int floatToRawIntBits(float value)
{
	union {
		int i;
		float f;
	} u;
	u.f = value;
	return u.i;
}

static int floatToIntBits(float value)
{
	int result = floatToRawIntBits(value);
	if(((result & FLOAT_EXP_BIT_MASK)==FLOAT_EXP_BIT_MASK) && (result & FLOAT_SIGNIF_BIT_MASK) != 0)
		result = 0x7fc00000;
	return result;
}


int string_hash_code(const char *string)
{
	int hash = 0;
	int i = 0;
	int size = strlen(string);
	for(i=0;i<size;i++) {
		hash = 31 * hash + string[i];
	}
	return hash;
}

int int_hash_code(const int value)
{
	return value;
}

int long_hash_code(const long value)
{
	return (int)(value ^ (value >> 32));
}

int double_hash_code(const double value) 
{
	long bits = doubleToLongBits(value);
	return long_hash_code(bits);
}

int float_hash_code(const float value) 
{
	int result = floatToIntBits(value);
	return result;
}
