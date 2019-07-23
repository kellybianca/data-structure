#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
} NODE;

typedef struct queue
{
    int current_size;
    int head;
    int tail;
    NODE *items;
} QUEUE;

NODE *createNode(int item)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->item = item;
    new->next = NULL;
    return new;
}

QUEUE *createQueue()
{
    QUEUE *new = (QUEUE *)malloc(sizeof(QUEUE));
    new->current_size = 0;
    new->head = 0;
    new->tail = 0;
    new->items = NULL;
    return new;
}

void enqueue(QUEUE *queue, int item)
{
    NODE *aux = createNode(item);

    if (queue->current_size == 0)
    {
        queue->head = item;
        queue->tail = item;
    }

    queue->items = aux;
    queue->tail = item;
    queue->current_size++;
  /*    printf("Head: %d\n", queue->head);
    printf("Tail: %d\n", queue->tail);
    printf("Current size: %d\n", queue->current_size);
    printf("\n");*/
}

void printQueue(QUEUE *queue)
{
    NODE *aux = createNode(queue->items->item);
   
    while (aux != NULL)
    {
        aux->item = queue->head;
        printf("%d\n", aux->item);
        aux = aux->next;
    }
}

int dequeue(QUEUE *queue)
{
    NODE *aux;
    printf("Remove: %d\n", queue->head);

    queue->head = queue->head + 1;
    queue->current_size--;
    return queue->head;
}

int main()
{
    QUEUE *queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    printQueue(queue);
    /*  int k = dequeue(queue);
    printf("\nNew head: %d\n\n", k);
    enqueue(queue, 7);
    enqueue(queue,9);
    k = dequeue(queue);
    printf("\nNew head: %d\n", k);*/
    return 0;
}