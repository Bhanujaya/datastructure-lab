#include <stdio.h>

typedef struct stack {
    int top;
    int data[1002];

} Stack;



int index_i = 0;
char ans[2004];

void intializeStack(Stack *stack) {
    stack->top = -1;

}

void stackPush(Stack * s , int num ) {
    s->top++; 
    s->data[s->top] = num;
}

void stackPop(Stack * s) {
    if (s->top != -1) {
        s->data[s->top] = 0;
        s->top--;

    }
    

}

void showTop(Stack *s) {
    if (s->top != -1) {
        int num = s->data[s->top];
        ans[index_i] = num;
        index_i++;


    } else if (s->top == -1) {
        ans[index_i] = 'E';
        index_i++;

    }
    
}

void countStack(Stack *s) {
    ans[index_i] = s->top +1;
    index_i++;


}

int main() {
    
    Stack stack;
    int i, num, numAdd, choice;
    intializeStack(&stack);
    scanf("%d " , &num) ;
    for (i = 0 ; i < num ; i++) {
        scanf("%d", &choice) ;
        if (choice == 1) {
            scanf("%d", &numAdd);
            stackPush(&stack , numAdd) ;
          
        } else if (choice == 2 ) {
            stackPop(&stack);
            
            
        } else if (choice ==3) {
            showTop(&stack);
            

        } else if (choice == 4) {
            countStack(&stack);


        }
    }
    

    

    for (i = 0 ; i < index_i  ;i++) {
        if (ans[i] == 'E') {
            printf("EMPTY\n");

        } else {
            printf("%d\n", ans[i]);


        }
    }



}

