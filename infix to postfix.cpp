#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the stack structure
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

// Get the top element of the stack
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Get the precedence of an operator
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char* infix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, j = 0;

    for (i = 0; infix[i]; ++i) {
        char c = infix[i];

        if (isalnum(c))
            printf("%c", c);
        else if (c == '(')
            push(stack, c);
        else if (c == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                printf("%c", pop(stack));
            pop(stack); // Remove '(' from stack
        } else if (isOperator(c)) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(c))
                printf("%c", pop(stack));
            push(stack, c);
        }
    }

    while (!isEmpty(stack))
        printf("%c", pop(stack));
}

int main() {
    char infix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");
    infixToPostfix(infix);

    return 0;
}

