#ifndef _BST_H
#define _BST_H

typedef int treeElementT;

typedef struct treeTag {
    treeElementT data;
    struct treeTag *left;
    struct treeTag *right;
} treeNodeT;

typedef struct {
    treeNodeT *root;
} treeT;

void TreeInit(treeT *treeP);

void TreeDestroy(treeT *treeP);

int NodeLookup(treeNodeT *node, treeElementT target);
int TreeLookup(treeT *treeP, treeElementT target);

treeNodeT* NodeCreate(treeElementT data);
treeNodeT* InsertNode(treeNodeT *node, treeElementT element);
void TreeInsert(treeT *treeP, treeElementT element);

int NodeSize(treeNodeT *node);
int TreeSize(treeT *treeP);

int NodeMaxDepth(treeNodeT *node);
int TreeMaxDepth(treeT *treeP);

int NodeMinValue(treeNodeT *node);
int TreeMinValue(treeT *treeP);

void NodePrint(treeNodeT *node);
void TreePrint(treeT *treeP);

void NodePrintPostOrder(treeNodeT *node);
void TreePrintPostOrder(treeT *treeP);

int NodeHasPathSum(treeNodeT *node, treeElementT sum);
int TreeHasPathSum(treeT *treeP, treeElementT sum);

#endif
