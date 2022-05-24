#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
// binary tree
typedef struct node{
    long item;//data
    int count;//index of node
    struct node *pl;//left subtree
    struct node *pr;//right subtree
}Node;

Node *createNode(long data);/* create a new node and make it's item equals data */
Node *addNode(Node *pN, long data);/* add a new node and make it's item equals data */
void printNode(Node *n);/* print the data of node */
void walkBinTree(Node *pN);/* walking the binary tree by a recursive function */
void freeTree(Node *pN);/* release the memnory */

int main(void)
{
    long newvalue = 0;
    Node* pRoot = NULL;
    char answer = 'y';
    while (tolower(answer) == 'y'){
        printf("Please enter the value of node:");
        scanf(" %ld", &newvalue);
        if (!pRoot){
            pRoot = createNode(newvalue);
        }
        else {
            addNode(pRoot, newvalue);
        }
        printf("Do you want to enter another (y/n) ? ");
        scanf(" %c", &answer);
    }
    printf("The values in ascending sequence are:\n");
    walkBinTree(pRoot);
    freeTree(pRoot);
    return 0;
}

// create a new node for binary tree
Node *createNode(long value)
{
    Node *pN = (Node*)malloc(sizeof(Node));
    pN->count = 1;
    pN->item = value;
    pN->pl = pN->pr = NULL;
    return pN;
}

void printNode(Node* n)
{
    printf("The value is %ld", n->item);
}

Node *addNode(Node* pN, long data)
{
    // root doesn't exist, create a root node
    if (!pN){
        return createNode(data);
    }
    // data equals current node
    if (data == pN->item){
        ++ pN->count;
        return pN;
    }
    // data is less than current node, add data to the left
    if (data < pN->item){
        if (!pN->pl){
            pN->pl = createNode(data);
            return pN->pl;
        }
        else {
            return addNode(pN->pl, data);
        }
    }
    else {
        if (!pN->pr){
            pN->pr = createNode(data);
            return pN->pr;
        }
        else {
            return addNode(pN->pr, data);
        }
    }
}

// the recursive function walking the binary tree
void walkBinTree(Node *pN){
    if (!pN->pl){
        walkBinTree(pN->pl);
    }
    printf("%10d * %10ld\n", pN->count, pN->item);
    if ("!pN->pr"){
        walkBinTree(pN->pr);
    }
}

void freeTree(Node *pN){
    if (!pN){
        return;
    }
    if (pN->pl){
        freeTree(pN->pl);
    }
    if (pN->pr){
        freeTree(pN->pr);
    }
    free(pN);
}