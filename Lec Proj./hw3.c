
#include <stdio.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct stack {
    char item[MAX_STACK_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

void stackPush(Stack *s, char input) {
    s->top++;
    s->item[s->top] = input;
}

char stackPop(Stack *s) {
    char r = s->item[s->top];
    s->top--;
    return r;
}

int checkStack(Stack *s) {
    return s->top;
}

int getPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

int main() {
    Stack stack;
    initializeStack(&stack);
    char input_list[MAX_STACK_SIZE];
    int i = 0;

    scanf("%s", input_list);

    while (input_list[i] != '\0') {
        char input = input_list[i];
        if (isalpha(input)) {
            printf("%c", input);
        } else if (input == '(') {
            stackPush(&stack, input);
        } else if (input == ')') {
            while (checkStack(&stack) != -1 && stack.item[stack.top] != '(') {
                printf("%c", stackPop(&stack));
            }
            if (checkStack(&stack) != -1 && stack.item[stack.top] == '(') {
                stackPop(&stack);
            }
        } else {
            while (checkStack(&stack) != -1 && getPrecedence(input) <= getPrecedence(stack.item[stack.top])) {
                printf("%c", stackPop(&stack));
            }
            stackPush(&stack, input);
        }
        i++;
    }

    while (checkStack(&stack) != -1) {
        printf("%c", stackPop(&stack));
    }

}


//input : A+B*C
//output : ABC*+

//input : (A+B)*C
//output : AB+C*

//input : (A+B)*(C-D)
//output : AB+CD-*

//input : A*(B+C/D)-E
//output : ABCD/+*E-