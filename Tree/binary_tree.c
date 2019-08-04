#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int item;
    struct tree *left;
    struct tree *right;
} TREE;

TREE *create_empty_TREE()
{
    TREE *new = (TREE *) malloc(sizeof(TREE));
    new->item = 0;
    new->left = NULL;
    new->right = NULL;
    return new;
}

TREE *createBinaryTree(TREE *left, TREE *right, int item)
{
    TREE *new = (TREE *)malloc(sizeof(TREE));
    new->left = NULL;
    new->right = NULL;
    new->item = item;
    return new;
}

int is_empty(TREE *bt)
{
    return (bt->left == NULL && bt->right == NULL);
}

TREE *search(TREE *bt, int item)
{   
    if(bt == NULL || bt->item == item)
    {
        return bt;
    }
    else if(bt->item > item)
    {
       return search(bt->left, item);    
    }
    else
    {
       return search(bt->right, item);
    }
    
}   

void print_in_order(TREE *bt)
{
    if (bt != NULL)
    {
        print_in_order(bt->left);
        printf("%d", bt->item);
        print_in_order(bt->right);
    }
}
void print_pre_order(TREE *bt)
{
    if (bt != NULL)
    {
        printf("%d", bt->item);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
    }
}
void print_post_order(TREE *bt)
{
    if (bt != NULL)
    {

        print_post_order(bt->left);
        print_post_order(bt->right);
        printf("%d", bt->item);
    }
}

TREE *add(TREE *bt, int item)
{
    if(bt == NULL)
    {
        bt = createBinaryTree(NULL,NULL,item);
    }
    else if(bt->item > item)
    {   
        bt->left = add(bt->left, item);
    }
    else
    {
        bt->right = add(bt->right, item);
    }
    return bt;
}
int main()
{
    TREE *bt = create_empty_TREE();
    
    return 0;
}