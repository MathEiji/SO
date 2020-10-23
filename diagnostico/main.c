#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

typedef struct p { 
    int top; 
    unsigned capacity; 
    char **str; 
} Stack; 

void iniciarStack(unsigned capacity, Stack *stack) {
    stack->capacity = capacity; 
    stack->top = -1;
    char lista[capacity][50];
    stack->str = lista;
}

void push(Stack *stack, char *item) {
    stack->str[++stack->top] = item; 
    printf("%s inserido na pilha\n", item);
} 

char* pop(Stack *stack) {
    return stack->str[stack->top--]; 
} 

int main(void) {
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  iniciarStack(100, stack);

  printf("Nomes:\n");

  while(1) {
    char *input = malloc(50*sizeof(char));
    scanf("%s", input);

    if(strcmp(input, "fim") == 0) {
      break;
    } else {
      push(stack, input);
    }
  }

  printf("\n\nNome(s) inputados(s):\n"); 
  while(stack->top >= 0) {
    printf("%s\n", pop(stack)); 
  }

  return 0;
}
