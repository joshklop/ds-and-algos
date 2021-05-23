#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

struct List *new_list() {
    struct List *l = malloc(sizeof(struct List));
    if (l == NULL) exit(EXIT_FAILURE);
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

struct Node *search(struct List *l, int k) {
    if (l == NULL) return NULL;
    struct Node *n = l->head;
    while (n != NULL && n->key != k)
        n = n->next;
    return n;
}

struct Node *insert(struct List *l, int k) {
    if (l == NULL) return NULL;
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL) exit(EXIT_FAILURE);
    n->key = k;
    n->next = l->head;
    l->head = n;
    return n;
}

struct Node *delete_list(struct List *l, int k) {
    if (l == NULL || l->head == NULL) return NULL;
    struct Node *n = l->head;
    struct Node *m = NULL;
    while (n != NULL && n->key != k) {
        m = n;
        n = n->next;
    }
    if (n != NULL && n->key == k) {
        if (n == l->head) {
            m = n->next;
            l->head = m;
        } else
            m->next = n->next;
        free(n);
    } else
        m = NULL;
    return m;
}

struct Node *pred(struct List *l, int k) {
    if (l == NULL) return NULL;
    struct Node *n = l->head;
    struct Node *m = l->head;
    while (n != NULL && n->key != k) {
        m = n;
        n = n->next;
    }
    if (n == NULL || n == l->head)
        return NULL;
    else
        return m;
}

struct Node *succ(struct List *l, int k) {
    struct Node *n = search(l, k);
    if (n == NULL || n->next == NULL)
        return NULL;
    else
        return n->next;
}
