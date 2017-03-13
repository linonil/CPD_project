#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct item{
	data x;
	item* next;
}
struct data{
	int x;
	int y;
	int z;
}

item* list_init(){
	return NULL;
}

void* list_append(item* root, data x){
	item *new, *aux;

	new = (item*)malloc(sizeof(item));
	if(new == NULL){
		printf("Erro na alocação\n", );
		exit(-1);
	}

	new->x = x;
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

void* list_remove(item* root, data x){
	item *aux, *aux_seg;

	if(root == NULL){
		printf("Already an empty list!\n", );
		return;
	}

	aux = root;
	aux_seg = aux->next;
	if(root->x == x){
		root = root->next;
		free(aux);
	}else{
		while(aux_seg->x != x){
			if(aux_seg->next == NULL){
				printf("No data x found!\n", );
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
