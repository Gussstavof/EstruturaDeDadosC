//
// Created by GustavoF on 8/20/2022.
//

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

typedef int TYPEKEY;

typedef struct{
    TYPEKEY key;
}Registry;

typedef struct {
    Registry A[10+1];
    int elementNumber;
}List;

void initList(List* list){
    list->elementNumber = 0;
}

int length(List* list){
    return list->elementNumber;
}

void showList(List* list){
    int i;
    for(i=0; i < list->elementNumber; i++){
        printf("%i ", list->A[i].key);
    }
    printf("\n");
}

int searchElement(List* list, TYPEKEY key){
    int i = 0;
    list->A[list->elementNumber].key = key;
    while (list->A[i].key != key) i++;
    if(i == list->elementNumber){
        return -1;
    }

    return i;
}

bool addElement(List* list, Registry registry){
    if(list->elementNumber >= 10){
        return false;
    }

    int position = list->elementNumber;
    while (position > 0 && list->A[position-1].key > registry.key){
        list->A[position] = list->A[position-1];
        position--;
    }
    list->A[position] = registry;
    list->elementNumber++;
    return true;
}

bool deleteElement(TYPEKEY key, List* list){
    int position, x;
    position = searchElement(list, key);
    if (position == -1){
        return false;
    }
    for (x = position; x < list->elementNumber-1; x++) {
        list->A[x] = list->A[x+1];
    }
    list->elementNumber--;
    return true;
}

void resetList(List* list){
    list->elementNumber = 0;
}

int main(){
    List* list = (List*) malloc(sizeof (List));
    Registry registry1;
    registry1.key = 1;
    initList(list);
    addElement(list, registry1);
    showList(list);
    registry1.key = 5;
    addElement(list, registry1);
    showList(list);
    registry1.key = 7;
    addElement(list, registry1);
    showList(list);
    registry1.key = 6;
    addElement(list, registry1);
    showList(list);
    printf("length: %i \n", length(list));
    deleteElement(5,list);
    showList(list);
    printf("length: %i \n", length(list));
    return 0;
}
