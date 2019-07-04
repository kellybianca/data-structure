#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int element;
  struct node *next;
}NODE;

NODE *createList(int element)
{
  NODE *newNode = (NODE*) malloc(sizeof(NODE));
  newNode->element = element;
  newNode->next = NULL;
  return newNode;
}

NODE *addListTail(NODE *node, int elements)
{
  NODE *aux = node;
  if(aux == NULL)
  {
    return createList(elements);
  }
  aux->next = addListTail(aux->next, elements);
  return aux;
}

NODE *addListHead(NODE *node, int element)
{
  NODE *aux = createList(element);
  aux->next = node;
  return aux;
}

void printListRecursive(NODE *node)
{
  NODE *aux = node;
  if(aux != NULL)
  {
    printf("%d ",aux->element);
    printListRecursive(aux->next);
  }
}

void printList(NODE *node)
{
  NODE *aux = node;
  while (aux->next != NULL)
  {
    printf("%d ",aux->element);
    aux = aux->next;
  }
  printf("%d\n",aux->element);
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
      return searchRecursive(aux->next, element);
    }
  }
  return 0;
}

NODE *search(NODE *node, int element)
{
  NODE *aux = node;
  while (aux != NULL)
  {
    if(aux->element == element)
    {
      return node;
    }
    aux = aux->next;
  }
  return 0;
}

NODE *removeList(NODE *node, int element)
{
  NODE *previous = NULL;
  NODE *current = node;

  while (current != NULL && !(current->element == element))
  {
    previous = current;
    printList(node);
    current = current->next;
  }
  if(current == NULL)
  {
    printList(node);
    return node;
  }
  if(previous == NULL)
  {
    printList(node);
    node = current->next;
  }
  else
  {
    printList(node);
    previous->next = current->next;
  }
  printList(node);
  free(current);

  return node;
}

int main()
{
  NODE *newNode = NULL;

  int n, i, elements,s,r,rm;
  printf("Enter a quantity of elements in the list:\n");
  scanf("%d",&n);
  for (i = 0; i < n; i++)
  {
    scanf("%d",&elements);
    //adds elements at the top of the list
    newNode = addListHead(newNode, elements);
    //adds elements to the tail of the list
    // newNode = addListTail(newNode, elements);
  }
  // printListRecursive(newNode);
  printf("\n");

  // printf("Enter a number for the search\n");
  // scanf("%d",&s );

  // if(searchRecursive(newNode, s))
  // {
  //   printf("The element was found in the list\n");
  // }
  // else
  // {
  //   printf("The element is not in the list\n");
  // }

  printf("Enter a number for the remove\n");
  scanf("%d",&rm);
  newNode = removeList(newNode, rm);


  printf("The elements of the list: \n");
  printList(newNode);
  return 0;
}
