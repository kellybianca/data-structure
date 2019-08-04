#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

typedef struct heap
{
    int size;
    int data[MAX];
} HEAP;

HEAP *create_heap()
{
    int i;
    HEAP *new = (HEAP *)malloc(sizeof(HEAP));
    new->size = 0;
    for (i = 1; i <= MAX; i++)
    {
        new->data[i] = 0;
    }
    return new;
}
int get_parent_index(HEAP *heap, int i)
{
    return i / 2;
}
int get_left_index(HEAP *heap, int i)
{
    return 2 * i;
}
int get_right_index(HEAP *heap, int i)
{
    return 2 * i + 1;
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int is_empty(HEAP *heap)
{
    return (heap->size == 0);
}

void enqueue(HEAP *heap, int item)
{
    if (heap->size >= MAX)
    {
        printf("Heap underflow");
    }
    else
    {
        heap->data[++heap->size] = item;
        int key_index = heap->size;
        int parent_index = get_parent_index(heap, heap->size);

        while (parent_index >= 1 && heap->data[key_index] > heap->data[parent_index])
        {
            swap(&heap->data[key_index], &heap->data[parent_index]);
            key_index = parent_index;
            parent_index = get_parent_index(heap, key_index);
        }
    }
}

void max_heapify(HEAP *heap, int i)
{
    int largest;
    int left_index = get_left_index(heap, i);
    int right_index = get_right_index(heap, i);

    if (left_index <= heap->size && heap->data[left_index] > heap->data[i])
    {
        largest = left_index;
    }
    else
    {
        largest = i;
    }

    if (right_index <= heap->size && heap->data[right_index] > heap->data[largest])
    {
        largest = right_index;
    }

    if (heap->data[i] != heap->data[largest])
    {
        swap(&heap->data[i], &heap->data[largest]);
        max_heapify(heap, largest);
    }
}

void dequeue(HEAP *heap)
{
    if (!is_empty(heap))
    {
        int las = heap->data[heap->size];
        heap->data[heap->size] = heap->data[1];
        heap->data[1] = las;
        heap->size--;
        max_heapify(heap, las);
    }
}

int item_of(HEAP *heap, int i);

void heapsort(HEAP *heap)
{
    int i;
    for (i = heap->size; i >= 2; i--)
    {
        if (heap->size <= 0)
        {
            continue;
        }
        swap(&heap->data[1], &heap->data[i]);
        heap->size--;
        max_heapify(heap, 1);
    }
}

void printHeap(HEAP *heap)
{
    int i;
    for (i = 1; i <= heap->size; i++)
    {
        if (!heap->data[i])
        {
            continue;
        }
        printf("heap %d ==> %d\n", i, heap->data[i]);
    }
}

int main()
{
    HEAP *new = create_heap();

    int i, n, k;
/*    
    scanf("%d", &k);

    for (i = 1; i <= k; i++)
    {
        scanf("%d", &n);
        enqueue(new, n);
    }
*/
    while (scanf("%d", &n) != EOF)
    {
        enqueue(new, n);
    }
    printHeap(new);

/*
    printf("Remove: \n");
    dequeue(new);
    printHeap(new);
*/
    printf("Heapsort: \n");
    heapsort(new);

    new->size = MAX;

    printHeap(new);

    return 0;
}