#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define GARBAGE 1111111

struct Queue {
    int head; /* Index of next item to be dequeued */
    int tail; /* Index+1 of the most recently enqueued item */
    int is_full;
    int len;
    int *queue;
};

struct Queue *new(int n);
void enqueue(struct Queue *q, int x);
int dequeue(struct Queue *q);
void free_queue(struct Queue *q);
int is_empty(struct Queue *q);

int main(void) {
    int n = 10;
    struct Queue *q = new(n);

    /* Basic enqueue case */
    enqueue(q, n);
    assert(q->tail == 1);
    assert(q->queue[0] == n);
    puts("enqueue works properly in basic case");

    /* Underflow */
    assert(dequeue(q) == n);
    assert(dequeue(q) == GARBAGE);
    assert(q->tail == q->head);
    puts("underflow test passed successfully");

    /* Overflow */
    int i;
    for (i = 0; i < n; ++i)
        enqueue(q, i);
    assert(q->is_full == 1);
    dequeue(q);
    assert(q->is_full == 0);
    puts("dequeue when full works properly");
    enqueue(q, i);
    assert(q->is_full == 1);
    enqueue(q, ++i);
    puts("If you see \"Queue overflow!\" above, then the overflow test succeeeded");

    free_queue(q);
}

struct Queue *new(int n) {
    if (n <= 0) {
        puts("Invalid queue length");
        exit(1);
    }
    struct Queue *q = malloc(sizeof(struct Queue));
    q->head = 0;
    q->tail = 0;    
    q->is_full = 0;
    q->len = n;
    q->queue = malloc(sizeof(int)*n);
    return q;
}

void free_queue(struct Queue *q) {
    free(q->queue);
    free(q);
}

int is_empty(struct Queue *q) {
    if (q->head == q->tail && q->is_full == 0)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q, int x) {
    if ((q->tail == q->head || (q->tail == q->len-1 && q->head == 0)) && q->is_full == 1)
        puts("Queue overflow!");
    q->queue[q->tail] = x;
    if (q->tail == q->len-1)
        q->tail = 0;
    else
        ++q->tail;
    if (q->tail == q->head || (q->tail == q->len-1 && q->head == 0))
        q->is_full = 1;
}

int dequeue(struct Queue *q) {
    if (q->head == q->tail && q->is_full == 0) {
        puts("Queue underflow!");
        return GARBAGE;
    }
    int x = q->queue[q->head];
    q->is_full = 0;
    if (q->head == q->len-1)
        q->head = 0;
    else
        ++q->head;
    return x;
}
