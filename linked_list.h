#include <stdio.h>
#include <stdlib.h>

struct data;
struct item;
typedef struct data data;
typedef struct item item;

item* list_init();

void* list_append(item* root, data K);

void* list_remove(item* root, data K);

item* list_search(item* root, data K);

void* list_free(item* root);
