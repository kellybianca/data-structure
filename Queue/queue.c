#include <stdio.h>
#include <stdlib.h>
#define MAX 30


typedef struct queue{
  int current_size;
  int head;
  int tail;
  int itens[30];
}QUEUE;

QUEUE *create()
{
  QUEUE *new = (QUEUE*) malloc(sizeof(QUEUE));
  new->current_size = 0;
  new->head = 0;
  new->tail = MAX-1;
  return new;
}

void enqueue(QUEUE *queue, int item)
{
  if(queue->current_size >= MAX)
  {
    printf("Queue Overflow\n");
  }
  else
  {
    queue->tail = (queue->tail+1) % MAX;
    queue->itens[queue->tail] = item;
    queue->current_size++;
  }
}

int is_empty(QUEUE *queue)
{
  return (queue->itens == 0);
}

int dequeue(QUEUE *queue)
{
  if(queue->head >= MAX)
  {
    printf("Queue Overflow\n");
    return -1;
  }
  else
  {
    int dequeue = queue->itens[queue->head];
    queue->head = (queue->head+1)%MAX;
    queue->current_size--;
    return dequeue;
  }
}

void printQueue(QUEUE *q)
{
  int i;
  for (i = 0; i < q->current_size; i++)
  {
    printf("%d ",q->itens[i]);
  }
}

int main()
{
  QUEUE *new = create();
  int n,e;
  printf("Elements of the queue\n");
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&e);
    enqueue(new, e);
  }
  printf("Queue: \n");
  printQueue(new);

  printf("\nRemove: \n");
  dequeue(new);
  printQueue(new);
  printf("\n");
  return 0;
}
