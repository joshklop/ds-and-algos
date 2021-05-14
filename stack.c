#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define GARBAGE 111111

struct Stack {
    int len;
    int *stack;
    int top; /* index of the top element */
};

void push(struct Stack *s, int x);
int pop(struct Stack *s);
int is_empty(struct Stack *s);
int is_full(struct Stack *s);
struct Stack *new(int len);
void free_stack(struct Stack *s);

int main(void) {
    struct Stack *s = new(10);

    /* Test that push works properly in simple case */
    int testval = 11;
    push(s, testval);
    assert(s->stack[0] == testval);
    puts("push was successful: push(s, 11) == 11");

    /* Test for stack underflow */
    puts("Test for stack underflow");
    assert(pop(s) == testval);
    assert(s->top == -1);
    assert(pop(s) == GARBAGE);
    puts("stack underflow detected and mitigated");

    /* Test for stack overflow */
    int i;
    for (i = 0; i < s->len; ++i)
        push(s, i);
    puts("Test for stack overflow: ");
    push(s, i);
    assert(s->top == s->len - 1);
    puts("stack overflow detected and mitigated");

    free_stack(s);
}


struct Stack *new(int length) {
    struct Stack *s = malloc(sizeof(struct Stack));
    s->len = length;
    s->stack = malloc(sizeof(int)*length);
    s->top = -1;
    return s;
}

void free_stack(struct Stack *s) {
    free(s->stack);
    free(s);
}

int is_empty(struct Stack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int is_full(struct Stack *s) {
    if (s->top == s->len - 1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int x) {
    if (is_full(s))
        puts("Stack Overflow!");
    else
        s->stack[++s->top] = x;
}

int pop(struct Stack *s) {
    if (is_empty(s)) {
        puts("Stack Underflow");
        return GARBAGE;
    }
    else
        return s->stack[s->top--];
}
