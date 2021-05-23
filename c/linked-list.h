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

struct List *new_list();
void freelist(struct List *l);
void printlist(struct List *l);
struct Node *insert(struct List *l, int k);
struct Node *delete_list(struct List *l, int k);
struct Node *search(struct List *l, int k);
struct Node *pred(struct List *l, int k);
struct Node *succ(struct List *l, int k);
void reverse(struct List *l);
