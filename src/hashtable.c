#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 0.7
#define DEFAULT_SIZE 10

struct Cell {
	int key;
	char *value;
};

struct List {
	int key;
	struct List *next;
};

struct HashTable {
	int size;
	struct List *keys;
	//struct List *values;
	struct Cell *cells;
};

bool containKey(int key, struct List *keys)
{
	struct List *head;
	bool result = false;
	head = keys;
	while(head != NULL){
		if(head->key == key){
			result = true;
			return result;
		}
		heade = head->next;
	}
	return result;
}

int addKey(int key, struct List *keys) {
	struct List *head;
	struct List *pre;
	struct List *newKey;
	head = keys;
	pre = keys;
	while(head != NULL){
		if(head->key == key){
			return 1;
		}
		if(head->next != NULL)
			pre = head;
		head = head->next;
	}
	newKey = malloc(struct List);
	newKey->key = key;
	newKey->next = NULL;
	pre->next = newKey;
	return 1;
}

int InitializeHashTable(int size, struct HashTable *hashtable)
{
	int i;
	//hashtable = malloc(sizeof(struct HashTable));
	if(size < DEFAULT_SIZE)
		size = DEFAULT_SIZE;
	hashtable->size = size;
	printf("InitializeHashTable size with: %d\n", hashtable->size);
	hashtable->cells = malloc(sizeof(struct Cell) * hashtable->size);
	for(i=0; i<hashtable->size; i++){
		hashtable->cells[i].value = NULL;
	}
	hashtable->keys = malloc(sizeof(struct List));
	hashtable->keys->next = NULL;
	hashtable->values = malloc(sizeof(struct List));
	hashtable->keys->next = NULL;
	printf("InitializeHashTable size with: %d\n", hashtable->size);
	return 10;
}

void resizeHashTable(struct HashTable *hashtable)
{
	int size = hashtable->size * 2;
	printf("realloc hashtable size [%d] to [%d]\n", hashtable->size, size);
	hashtable->size = size;
	realloc(hashtable->cells, sizeof(struct Cell) * size);
	printf("realloc hashtable size success\n");
}

int put(int key, char* value, struct HashTable *hashtable)
{
	int current, d;
	d = 0;
	if(!containKey(key, hashtable->keys)) {
		
	}
	current = (key + d) % hashtable->size;
	while(hashtable->cells[current].value != NULL && hashtable->cells[current].key != key) {
		d += 1;
		//printf("%d\n", d);
		current = (key + d) % hashtable->size;
		//printf("%d\n", current);
		if(current > hashtable->size){
			printf("%d\n", current);
			current = 0;
		}
	}
	hashtable->cells[current].key = key;
	hashtable->cells[current].value = value;
	return 0;
}

char * get(int key, struct HashTable *hashtable)
{
	int current, d;
	d = 0;
	current = (key + d) % hashtable->size;
	while(hashtable->cells[current].key != key) {
		d += 1;
		current = (key + d) % hashtable->size;
		if(d >= hashtable->size){
			printf("Hash has no value for key : [%d]", key);
			return NULL;
		}
	}
	return hashtable->cells[current].value;
}

int main(int argc, char *argv)
{
	struct HashTable *hashtable;
	char *value;
	hashtable = malloc(sizeof(struct HashTable));
	InitializeHashTable(DEFAULT_SIZE, hashtable);
	printf("HashTable size is: %d\n", hashtable->size);
	put(1, "Test", hashtable);
	printf("put value success\n");
	value = get(1, hashtable);
	printf("%d : %s\n", 1, value);
	put(1, "Hello", hashtable);
	value = get(3, hashtable);
	printf("%d : %s\n", 1, value);
	free(hashtable->cells);
	free(hashtable->keys);
	free(hashtable);
	return 1;
}
