#include <stdio.h>
#include <stdlib.h>

#define MAX 11

typedef struct element
{
    int key;
    int value;
} ELEMENT;

typedef struct hash
{
    ELEMENT *table[MAX];
} HASH;

HASH *createHash()
{
    HASH *new = (HASH *)malloc(sizeof(HASH));
    int i;
    for (i = 0; i < MAX; i++)
    {
        new->table[i] = NULL;
    }
    return new;
}

ELEMENT *createElement(int key, int value)
{
    ELEMENT *new = (ELEMENT *)malloc(sizeof(ELEMENT));
    new->key = key;
    new->value = value;
    return new;
}

void put(HASH *hash, int key, int value)
{
    int h = key % MAX;
    while (hash->table[h] != NULL)
    {
        if (hash->table[h]->key == key)
        {
            hash->table[h]->value = value;
            break;
        }
        h = (h + 1) % MAX;
    }

    if (hash->table[h] == NULL)
    {
        ELEMENT *new = createElement(key, value);
        hash->table[h] = new;
    }
}

int get(HASH *hash, int key)
{
    int h = key % MAX;

    while (hash->table[h] != NULL)
    {
        if (hash->table[h]->key == key)
        {
            return hash->table[h]->value;
        }
        h = (h + 1) % MAX;
    }
    return -100;
}

void remove_Hash(HASH *hash, int key)
{
    int h = key % MAX;
    while (hash->table[h] != NULL)
    {
        if (hash->table[h]->key == key)
        {
            hash->table[h]->key = -1;
        }
        h = (h + 1) % MAX;
    }
}

void print_HASH(HASH *hash)
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (hash->table[i] != NULL)
        {
            printf("key: %d value :%d\n", hash->table[i]->key, hash->table[i]->value);
        }
    }
}

int main()
{
    HASH *hash = createHash();

    put(hash, 3, 1000);
    put(hash, 14, 2000);
    put(hash, 15, 3000);
    put(hash, 92, 4000);

    print_HASH(hash);

    int n = get(hash, 92);
    printf("Get: %d\n", n);
    n = get(hash, 16);
    printf("Get: %d\n", n);

    remove_Hash(hash, 15);

    print_HASH(hash);
    return 0;
}