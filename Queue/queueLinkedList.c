#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int item;
    struct node *next;
} NODE;

typedef struct queue
{
    NODE *head;
    NODE *tail;
    int size;
} QUEUE;

NODE *createNode(int item)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->item = item;
    newNode->next = NULL;
    return newNode;
}

void printQueue(QUEUE *queue)
{
    NODE *aux = queue->head;
    while (aux != NULL)
    {
        printf("%d -> ", aux->item);
        aux = aux->next;
    }
}

void enqueue(QUEUE *queue, int item)
{
    NODE *newNode = createNode(item);
    if (queue->size == 0)
    {
        queue->head = newNode;
        queue->tail = newNode;
        queue->size++;
        return;
    }
    queue->tail->next = newNode;
    queue->tail = newNode;
    queue->size++;
    return;
}

int dequeue(QUEUE *queue)
{
    if (!queue->size)
    {
        printf("0 elementos\n");
        return 0;
    }
    if (queue->size == 1)
    {
        queue->size--;
        NODE *a = queue->head;
        queue->head = NULL;
        queue->tail = NULL;
        free(a);
        return 1;
    }
    NODE *aux = queue->head;
    printf("\nRemove head: %d", aux->item);

    queue->head = aux->next;
    queue->size--;
    free(aux);
    return 1;
}

int main()
{
    QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    int i;
    for (i = 0; i < 10; i++)
    {
        enqueue(queue, i);
    }
    printQueue(queue);

    int k = dequeue(queue);
    printf("\nNew head: %d\n", k);
    k = dequeue(queue);
    printf("\nNew head: %d\n", k);
    printQueue(queue);
    return 0;
}