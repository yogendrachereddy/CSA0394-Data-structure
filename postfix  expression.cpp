#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

// Stack structure
struct Stack {
    int data[MAX_STACK_SIZE];
    int top;
};

// Initialize stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Push an element onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack->data[++(stack->top)] = value;
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack->data[(stack->top)--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    struct Stack stack;
    initStack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0'); // Convert char to int
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (postfix[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }

    return pop(&stack);
}

int main() {
    char postfixExpression[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("Result: %d\n", result);

    return 0;
}

