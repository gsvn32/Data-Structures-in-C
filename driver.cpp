#include "myheaders/stack.h"


int main() {
    Stack s;
    initialize(&s);

    int arr[MAX+1] = {10,20,30,40,50,60};

    for(int i =0;i<MAX+1;i++){
         if(!isFull(&s)){
        push(&s, arr[i]);
         }
         else{
            printf("unable to push %d : %d\n", i, arr[i]);
         }
    }
    
    

    printf("Popped element: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));

    return 0;
}