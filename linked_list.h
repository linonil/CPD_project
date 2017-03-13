#include <stdio.h>
#include <stdlib.h>

item* list_init();

item* list_append(item* root, data x);

item* list_remove(item* root, data x);

item* list_search(item* root, data x);

item* list_free(item* root);


