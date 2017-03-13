#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

item* list_init();

void* list_append(item* root, data x);

void* list_remove(item* root, data x);

void* list_search(item* root, data x);

void* list_free(item* root);
