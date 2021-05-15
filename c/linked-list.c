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
 * reverse
 */

struct List *new();
void printlist(struct List *l);
void insert(struct List *l, int k);
void freelist(struct List *l);
void search(struct List *l, struct Node **n, int k);
void delete(struct List *l, int k);
int *pred(struct List *l, int k);
int *succ(struct List *l, int k);

int main(void) {
    struct List *l = new();
    /* Test insert and search */
    insert(l, 1);
    insert(l, 2);
    struct Node *n = NULL;
    search(l, &n, 1);
    assert(n->key == 1);
    printlist(l);

    /* Test delete */
    puts("delete(l, 1)");
    delete(l, 1);
    printlist(l);

    /* Test pred */
    int *x = pred(l, 2);
    assert(x == NULL);
    insert(l, 1);
    x = pred(l, 2);
    assert(*x == 1);

    /* Test succ */
    x = succ(l, 1);
    assert(*x == 2);
    delete(l, 2);
    x = succ(l, 1);
    assert(x == NULL);

    freelist(l);
}

struct List *new() {
    struct List *l = malloc(sizeof(struct List));
    if (l == NULL) exit(1);
    l->head = NULL;
    return l;
}

void freelist(struct List *l) {
    struct Node *n = l->head;
    struct Node *m = l->head;
    while (n != NULL) {
        m = n;
        n = n->next;
        free(m);
    }
    free(l);
}

void printlist(struct List *l) {
    struct Node *n = l->head;
    while (n != NULL) {
        printf("%d ", n->key);
        n = n->next;
    }
    puts("");
}

void search(struct List *l, struct Node **n, int k) {
    *n = l->head;
    while (*n != NULL && (*n)->key != k)
        *n = (*n)->next;
}

void insert(struct List *l, int k) {
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) exit(1);
    n->key = k;
    n->next = l->head;
    l->head = n;
}

void delete(struct List *l, int k) {
    struct Node *n = l->head;
    struct Node *m = l->head;
    while (n != NULL && n->key != k) {
        m = n;
        n = n->next;
    }
    if (n->key == k) {
        m->next = n->next;
        free(n);
    }
}

int *pred(struct List *l, int k) {
    struct Node *n = l->head;
    struct Node *m = l->head;
    while (n != NULL && n->key != k) {
        m = n;
        n = n->next;
    }
    if (n == NULL || n == l->head)
        return NULL;
    else
        return &m->key;
}

int *succ(struct List *l, int k) {
    struct Node *n;
    search(l, &n, k);
    if (n == NULL || n->next == NULL)
        return NULL;
    else
        return &n->next->key;
}
