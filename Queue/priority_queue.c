#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int item;
  int priority;
  struct node *next;
}NODE;

typedef struct pq{
  NODE *head;
}PQ;

NODE *createNode(int item, int p)
{
  NODE *new = (NODE*) malloc(sizeof(NODE));
  new->item = item;
  new->priority = p;
  new->next = NULL;
  return new;
}

PQ *createPq()
{
  PQ *new = (PQ*) malloc(sizeof(PQ));
  new->head = NULL;
  return new;
}

int is_empty(PQ *pq)
{
  return (pq->head == NULL);
}

void enqueue(PQ *pq, int i, int p)
{
 NODE *new = createNode(i,p);
  // NODE *new = (NODE*) malloc(sizeof(NODE));
  // new->item = i;
  // new->priority = p;
  if((is_empty(pq)) || (p > pq->head->priority))
  {
    new->next = pq->head;
    pq->head = new;
  }
  else
  {
    NODE *current = pq->head;
    while ((current->next != NULL) && (current->next->priority > p))
    {
      current = current->next;
    }
    new->next = current->next;
    current->next = new;
  }
}

NODE *dequeue(PQ *pq)
{
  if(is_empty(pq))
  {
    printf("Priority queue underflow\n");
    return NULL;
  }
  else
  {
    NODE *new = pq->head;
    pq->head = pq->head->next;
    new->next = NULL;
    return new;
  }
}

int maximum(PQ *pq)
{
  if(is_empty(pq))
  {
    printf("Priority queue underflow\n");
    return -1;
  }
  else
  {
    pq->head->item;
  }
}

void printQueue(PQ *q)
{
  // int i;
  if(!is_empty(q))
  {
    printf("%d ",q->head->item);

  }

}

int main()
{
  PQ *newPq = createPq();
  int n,e;

  printf("Elements of the queue\n");
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&e);
    enqueue(newPq, e, 1);
  }
  printf("Queue: \n");
  // printQueue(newPq);

  printf("\nRemove: \n");
  dequeue(newPq);
  printQueue(newPq);
  return 0;
}
