#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int element;
  struct node *current;
  struct node *previous;
}NODE;

NODE *create(int element)
{
  NODE *newNode = (NODE*) malloc(sizeof(NODE));
  newNode->element = element;
  newNode->current = NULL;
  newNode->previous = NULL;
  return newNode;
}

NODE *add(NODE *node, int element)
{
  NODE *newNode = create(element);
  if(node != NULL)
  {
    node->previous = newNode;
    newNode->current = node;
  }
  return newNode;
}


NODE *search(NODE *node, int element)
{
  NODE *aux = node;
  while(aux != NULL)
  {
    if(aux->element == element)
    {
      return aux;
    }
    aux = aux->current;
  }
  return 0;
}

NODE *searchRecursive(NODE *node, int element)
{
  NODE *aux = node;
  if(aux != NULL)
  {
    if(aux->element == element)
    {
      return node;
    }
    else
    {
      searchRecursive(aux->current, element);
    }
  }
  else
  {
    return 0;
  }
}

NODE *removeList(NODE *node, int element)
{
  NODE *aux = node;
  while (aux != NULL && !(aux->element == element))
  {
    aux = aux->current;
  }
  if(aux == NULL)
  {
    return node;
  }
  if(aux == node)
  {
    node = aux->current;
  }
  else
  {
    aux->previous->current = aux->current;
  }
  if(aux->current != NULL)
  {
    aux->current->previous = aux->previous;
  }
  free(aux);
  return node;
}

void printList(NODE *node)
{
  if(node != NULL)
  {
    printf("%d ",node->element);
    printList(node->current);
  }
  // printf("%d\n",node->element);
}

int main()
{
  int n,i,elements,s, rm ;
  NODE *new = NULL;
  printf("Enter a quantity of numbers\n");
  scanf("%d",&n);
  for (i = 0; i < n; i++)
  {
    scanf("%d",&elements);
    new = add(new, elements);
  }
  printList(new);
  printf("\n");
  // printf("Enter a number for the search\n");
  // scanf("%d",&s );
  // if(searchRecursive(new, s))
  // {
  //   printf("Number found\n");
  // }
  // else
  // {
  //   printf("Number not found\n");
  // }

  printf("Enter a number for the remove\n");
  scanf("%d",&rm);
  new = removeList(new, rm);

  printf("The elements of the list: \n");
  printList(new);
  printf("\n");
  return 0;
}
