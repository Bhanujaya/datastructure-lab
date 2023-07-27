#define MAX_STACK_SIZE 100
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


typedef struct stack {
    char item[MAX_STACK_SIZE];
    int top;


} Stack ;

void intializeStack(Stack *stack) {
    stack->top = -1;

}

void stackPush(Stack *s, char input) {
    s->top++;
    s->item[s->top] = input;


}

char stackPop(Stack *s) {
    char r = s->item[s->top];
    s->item[s->top] = 0;
    s->top -=1;
    return r;
}

int checkStack(Stack *s) {
    return s->top;

}
bool hasHigherPrecedence(Stack *s, char op1) {
    char op2 = s->item[s->top];
    // Define the precedence levels based on C operator precedence rules
    // You can modify this based on the C standard rules for precedence
    int precedence[] = {0, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    // Get the precedence level for op1 and op2
    int precedenceOp1 = precedence[op1 - '('];
    int precedenceOp2 = precedence[op2 - '('];

    // Compare the precedence and return the result
    return precedenceOp1 = precedenceOp2;
}

int main() {
    Stack stack;
    int check = 1;
    char input_list[MAX_STACK_SIZE] , j; 
    int i = 0;

    intializeStack(&stack);
    scanf("%s", input_list);
    
    while (check == 1) 
    {
        // scanf("%c" , &input);
        char input = input_list[i];
        if (isalpha((int)input)) {
            // printf("hi %c\n", input);
            printf("%c", input);



        } else if (input_list[i] == '\0') {
                // printf("hey");
                while (checkStack(&stack) != -1) {
                    // printf("ayo %c", stackPop(&stack));
                    printf("%c", stackPop(&stack));

                    
                }
                check = 0;

        } else  {
            if (checkStack(&stack) == -1) {
                // printf("hello");
                stackPush(&stack , input);
 
            } else if (input == '(') {
                stackPush(&stack , input);

            } else if (input == ')') {
                while (j != '(') {
                    j = stackPop(&stack);
                    if (j!= '(') {
                        printf("%c" , j);
                    }
                }

            } else if (hasHigherPrecedence(&stack, input)) {
                stackPush(&stack, input);
            } else if (!hasHigherPrecedence(&stack, input)) {
                // printf("lala %c", stackPop(&stack));
                printf("%c", stackPop(&stack));

                while (!hasHigherPrecedence(&stack, input)) {
                    printf("%c", stackPop(&stack));


                } 
                stackPush(&stack, input);
            } 
        }
        i+=1;

    
            
        }
}  