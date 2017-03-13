#include "linked_list.h"

struct data{
	int x;
	int y;
	int z;
};

struct item{
	struct data K;
	item* next;
};

item* list_init(){
	return NULL;
}

int equal_data(data K1, data K2){
	if(K1.x == K2.x && K1.y == K2.y && K1.z == K2.z)
		return 1;
	else
		return 0;
}

void* list_append(item* root, data K){
	item *new, *aux;

	new = (item*)malloc(sizeof(item));
	if(new == NULL){
		printf("Erro na alocação\n");
		exit(-1);
	}

	new->K = K;
	new->next = NULL;

	if(root == NULL){
		root = new;
	}else{
		aux = root;
		while(aux->next != NULL)
			aux = aux->next;

		aux->next = new;
	}

	return;
}

void* list_remove(item* root, data K){
	item *aux, *aux_seg;

	if(root == NULL){
		printf("Already an empty list!\n");
		return;
	}

	aux = root;
	aux_seg = aux->next;
	if(equal_data(root->K, K)){
		root = root->next;
		free(aux);
	}else{
		while(equal_data(aux_seg->K, K)){
			if(aux_seg->next == NULL){
				printf("No data K found!\n");
				return;
			}
			aux = aux->next;
			aux_seg = aux_seg->next;
		}
		aux->next = aux_seg->next;
		free(aux_seg);
	}
	return;
}

item* list_search(item* root, data K){
	item *aux;

	if(root == NULL){
		printf("Search cancelled, empty list, returning NULL\n");
		return NULL;
	}

	aux = root;
	while(equal_data(aux->K, K) && aux != NULL)
		aux = aux->next;

	if(aux == NULL){
		printf("Element not found, returning NULL\n");
		return NULL;
	}else{
		return aux;
	}

}

void* list_free(item* root){
	item *aux;

	while(root != NULL){
		aux = root;
		root = root->next;
		free(aux);
	}
	return;
}
