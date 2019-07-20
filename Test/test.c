#include <CUnit/Basic.h>
#include "../Queue/priority_queue.c"

void teste_node()
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->item = 6;
    new->priority = 2;
    new->next = NULL;

    NODE *test = createNode(6, 2);

    CU_ASSERT(new != NULL);
    CU_ASSERT_EQUAL(new->item, test->item);
    CU_ASSERT_EQUAL(new->priority, test->priority);
    CU_ASSERT_PTR_EQUAL(new->next, test->next);
}

void create_pq_test()
{
    PQ *new = (PQ *)malloc(sizeof(PQ));
    new->head = NULL;

    PQ *teste = createPq();

    CU_ASSERT(new != NULL);
    CU_ASSERT_EQUAL(new->head, teste->head);
}

void is_empty_test()
{
    PQ *new = (PQ *)malloc(sizeof(PQ));
    CU_ASSERT(new != NULL);
}

void enqueue_test()
{
    PQ *pq = (PQ *)malloc(sizeof(PQ));
    int array[3] = {1, 5, 7};

    enqueue(pq, 1, 2);
    enqueue(pq, 5, 5);
    enqueue(pq, 7, 7);

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(pq->head->item, array[2]);
}

void dequeue_test()
{
    PQ *pq = (PQ *)malloc(sizeof(PQ));
    int array[4] = {1, 2, 3, 4};

    enqueue(pq, 'x', 6);
    enqueue(pq, 'y', 3);
    enqueue(pq, 'z', 4);
    dequeue(pq);

    CU_ASSERT(pq != NULL);
    CU_ASSERT_EQUAL(pq->head->priority, array[3]);
}

int main()
{
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }
    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite pSuite = NULL;
    pSuite = CU_add_suite("TEST", 0, 0);

    if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 1", teste_node))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 2", create_pq_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 3", is_empty_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 4", enqueue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == CU_add_test(pSuite, "test - 4", dequeue_test))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests();
    return CU_get_error();
}
