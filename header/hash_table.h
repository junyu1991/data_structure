#ifndef HASHTABLEHEADER
#define HASHTABLEHEADER

#include <stdio.h>
#include <stdlib.h>

struct hash_table {
	void *key;
	void *value;
};

int size();
int isEmpty();
int containsValue(void *value);
int containsKey(void *key);
void *get(void *key);
void *getOrDefault(void *key, void *default_value);
void *put(void *key, void *value);
void *remove(void *key);
int replace(void *key, void *old_value, void *new_value);

#endif
