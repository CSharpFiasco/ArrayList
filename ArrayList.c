#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArrayList ArrayList;

struct ArrayList {
	int size;
	int *data;
};

ArrayList* createArrayList(){
	ArrayList *list = malloc(sizeof *list);
	list->size = 0;
	list->data = malloc(sizeof(int));

	return list;
}

int getArrayListItem(ArrayList* list, int index){
	return list->data[index];
}

void addArrayList(ArrayList* list, int item){
	list->data = realloc(list->data, sizeof(int) * (list->size + 1));
	list->data[list->size] = item;
	list->size++;
}

int getArrayListSize(ArrayList* list){
	return list->size;
}

void main(){
	ArrayList* arr = createArrayList();
	addArrayList(arr, 10);
	addArrayList(arr, 12);
	addArrayList(arr, 45);
	for(int i = 0; i < getArrayListSize(arr); i++){
		printf("%d\n", getArrayListItem(arr, i));
	}
	exit(0);
}