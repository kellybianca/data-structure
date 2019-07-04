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

int push(STACK *stack, int element)
{
  NODE *new = (NODE*) malloc(sizeof(NODE));
  new->element = element;
  new->next = stack->top;
  stack->top = new;
}

int is_empty(STACK *stack)
{
    return (stack->top == NULL);
}

int pop(STACK *stack)
{
  NODE *aux = stack->top;

  if(is_empty(stack))
  {
    printf("Stack underflow\n");
  }
  else{
    printf("Remove %d\n",stack->top->element );
    aux = stack->top;
    stack->top = stack->top->next;
    return (aux->next == NULL);
  }
}

int peek(STACK *stack)
{
  if(is_empty(stack))
  {
    printf("Stack underflow\n");
  }
  else
  {
    printf("%d\n",stack->top->element );
    return (stack->top);
  }
}

void printStack(NODE *node)
{
  if(node != NULL)
  {
    printf("%d ",node->element);
    printStack(node->next);
  }
}

int main()
{
  int n,i,e,rm;
  printf("Insert a number of elements\n");
  scanf("%d",&n);

  STACK *new = createStack();

  for (i = 0; i < n; i++)
  {
    scanf("%d",&e);
    push(new, e);
  }

  printf("Pop: ");
  pop(new);

  printf("\nPeek: ");
  peek(new);

  printf("\nThe stack\n");
  printStack(new->top);

  return 0;
}
