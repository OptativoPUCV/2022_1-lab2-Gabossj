#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new -> data = data;
    new -> prev = NULL;
    new -> next = NULL;
    return new;
}

List * createList() {
    List* list= (List*)malloc(sizeof(List));
    assert (list != NULL);

    list -> head = NULL;
    list -> tail = NULL;
    list -> current = NULL; 
    return list;
}

void * firstList(List * list) {
    if (list == NULL || list -> head == NULL)
        return NULL;
    list-> current = list -> head;
    return (list -> head -> data);
}

void * nextList(List * list) {
    if (list -> current && list -> current -> next){
        list -> current = list -> current -> next;
        return (list -> current -> data);}
    return NULL;
}

void * lastList(List * list) {
    if (list == NULL || list -> head == NULL){
        return NULL;}
    list -> current = list -> tail;
    return (list -> tail -> data);
}

void * prevList(List * list) {
    if(list -> current && list -> current->prev){
        list -> current = list -> current->prev;
        return (list -> current -> data);}
    return NULL;
}

void pushFront(List * list, void * data) {
    assert(list != NULL);
    Node* nodo = createNode(data);

    if (list -> head == NULL){
        list -> tail = nodo;}
    else{
        nodo -> next = list -> head;
        list -> head -> prev = nodo;}
    list -> head = nodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    if (list -> current -> next){
        pushFront(list,data);}
    else pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    assert(list != NULL && list -> current != NULL);
    Node * new = createNode(data);

    if(list -> current -> next){
        new -> prev = list -> current;}
    new -> prev = list -> current;

    if(list -> current -> next){
        list -> current -> next -> prev = new;}
    list -> current -> next = new;

    if (list -> current == list -> tail) list -> tail = new;

}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    assert(list != NULL);
    while (list->head != NULL) {
        popFront(list);
    }
}