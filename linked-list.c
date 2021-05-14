#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node *next;
    int key;
};

struct List {
    struct Node *head;
};

/*
 * insert
 * delete
 * search
 * pred
 * succ
 * reverse
 */

struct List *new();
void printlist(struct List *l);
void insert(struct List *l, struct Node *n);

int main(void) {
    struct List *l = new();
    printlist(l);
    struct Node n1 = {NULL, 3};
    insert(l, &n1);
    struct Node n2 = {NULL, 4};
    insert(l, &n2);
    printlist(l);
    free(l);
}

struct List *new() {
    struct List *l = malloc(sizeof(struct List));
    l->head = NULL;
    return l;
}

void printlist(struct List *l) {
    struct Node *n = l->head;
    while (n != NULL) {
        printf("%d ", n->key);
        n = n->next;
    }
    puts("");
}

void insert(struct List *l, struct Node *n) {
    n->next = l->head;
    l->head = n;
}
