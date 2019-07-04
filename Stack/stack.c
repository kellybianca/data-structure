#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int element;
  struct node *next;
}NODE;

typedef struct stack{
  NODE *top;
}STACK;

STACK *createStack()
{
  STACK *new = (STACK*) malloc(sizeof(STACK));
  new->top = NULL;
  return new;
}

void push(STACK *stack, int element)
{
  NODE *new = (NODE*) malloc(sizeof(NODE));
  new->element = element;
  new->next = stack->top;
  stack->top = new;
}

int is_empty(STACK *stack) {
  if(stack->top == NULL) return 1;
}

int pop(STACK *stack)
{
  if(!is_empty(stack))
  {
    printf("Stack underflow\n");
    return -1;
  }
  else{
    return stack->top--;
  }

}

int main()
{

  return 0;
}
