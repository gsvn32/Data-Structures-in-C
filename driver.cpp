#include "myheaders/stack.h"


int main() {
    Stack s;
    initialize(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Popped element: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));

    return 0;
}