    #include <stdio.h>
    #include <stdlib.h>

    #define MAX 20

    typedef struct adj_list
    {
        int item;
        struct adj_list *next;
    } ADJ_LIST;

    typedef struct graph
    {
        ADJ_LIST *vertices[MAX];
        int visited[MAX];
    } GRAPH;

    typedef struct queue
    {
        int current_size;
        int head;
        int tail;
        int itens[30];
    } QUEUE;

    QUEUE *create_queue()
    {
        QUEUE *new = (QUEUE *)malloc(sizeof(QUEUE));
        new->current_size = 0;
        new->head = 0;
        new->tail = MAX - 1;
        return new;
    }

    GRAPH *create_graph()
    {
        GRAPH *new = (GRAPH *)malloc(sizeof(GRAPH));
        int i;
        for (i = 0; i < MAX; i++)
        {
            new->vertices[i] = NULL;
            new->visited[i] = 0;
        }
        return new;
    }

    ADJ_LIST *create_adj_list(int item)
    {
        ADJ_LIST *new = (ADJ_LIST *)malloc(sizeof(ADJ_LIST));
        new->item = item;
        new->next = NULL;
        return new;
    }

    int is_empty(QUEUE *queue)
    {
        return (queue->itens == 0);
    }

    void add_edge(GRAPH *graph, int v1, int v2)
    {
        ADJ_LIST *vertex = create_adj_list(v2);
        vertex->next = graph->vertices[v1];
        graph->vertices[v1] = vertex;

        //undirected
        vertex = create_adj_list(v1);
        vertex->next = graph->vertices[v2];
        graph->vertices[v2] = vertex;
    }

    void enqueue(QUEUE *queue, int item)
    {
        if (queue->current_size >= MAX)
        {
            printf("Queue Overflow\n");
        }
        else
        {
            queue->tail = (queue->tail + 1) % MAX;
            queue->itens[queue->tail] = item;
            queue->current_size++;
        }
    }

    int dequeue(QUEUE *queue)
    {
        if (queue->head >= MAX)
        {
            printf("Queue Overflow\n");
            return -1;
        }
        else
        {
            int dequeue = queue->itens[queue->head];
            queue->head = (queue->head + 1) % MAX;
            queue->current_size--;
            return dequeue;
        }
    }

    void bfs(GRAPH *graph, int source)
    {
        //printf("oi");
        QUEUE *queue = create_queue();
    
        int dequeued;
        ADJ_LIST *adj_list = graph->vertices[source];
        graph->visited[source] = 1;
        enqueue(queue,source);


        while (!is_empty(queue))
        {
            dequeued = dequeue(queue);
            adj_list = graph->vertices[dequeued];
            while (adj_list != NULL)
            {
                if (!graph->vertices[adj_list->item])
                {
                    printf("%d", adj_list->item);
                    graph->visited[adj_list->item] = 1;
                    enqueue(queue, adj_list->item);
                }
                adj_list = adj_list->next;
            }
        }
    }

    int main()
    {
        GRAPH *graph = create_graph();

        add_edge(graph, 1, 2);
        add_edge(graph, 1, 5);
        add_edge(graph, 2, 5);
        add_edge(graph, 2, 3);
        add_edge(graph, 2, 4);
        add_edge(graph, 3, 4);
        add_edge(graph, 4, 5);

        bfs(graph, 5);
    }