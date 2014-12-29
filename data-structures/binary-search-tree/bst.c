#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void TreeInit(treeT *treeP)
{
    treeP->root = NULL;
}

void TreeDestroy(treeT *treeP)
{
    treeP->root = NULL;
}

int NodeLookup(treeNodeT *node, treeElementT target)
{
    if (node == NULL) {
        return 0;
    } else {
        if (node->data == target) {
            return 1;
        } else {
            if (target < node->data) {
                return NodeLookup(node->left, target);
            } else {
                return NodeLookup(node->right, target);
            }
        }
    }
}

int TreeLookup(treeT *treeP, treeElementT target)
{
    return NodeLookup(treeP->root, target);
}

treeNodeT* NodeCreate(treeElementT data)
{
    treeNodeT *node = (treeNodeT *) malloc(sizeof(treeNodeT));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

treeNodeT* InsertNode(treeNodeT *node, treeElementT data)
{
    if (node == NULL) {
        return NodeCreate(data);
    } else {
        if (data <= node->data) {
            node->left = InsertNode(node->left, data);
        } else {
            node->right = InsertNode(node->right, data);
        }
    }

    return node;
}

void TreeInsert(treeT *treeP, treeElementT data)
{
    treeNodeT *node = InsertNode(treeP->root, data);

    if (treeP->root == NULL) {
        treeP->root = node;
    }
}

int NodeSize(treeNodeT *node)
{
    if (node == NULL) {
        return 0;
    } else {
        return NodeSize(node->left) + 1 + NodeSize(node->right);
    }
}

int TreeSize(treeT *treeP)
{
    return NodeSize(treeP->root);
}

int NodeMaxDepth(treeNodeT *node)
{
    if (node == NULL) {
        return 0;
    } else {
        int lDepth = NodeMaxDepth(node->left);
        int rDepth = NodeMaxDepth(node->right);

        if (lDepth > rDepth) {
            return lDepth + 1;
        } else {
            return rDepth + 1;
        }
    }
}

int TreeMaxDepth(treeT *treeP)
{
    return NodeMaxDepth(treeP->root);
}

int NodeMinValue(treeNodeT *node)
{
    treeNodeT *current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current->data;
}

int TreeMinValue(treeT *treeP)
{
    return NodeMinValue(treeP->root);
}

void NodePrint(treeNodeT *node)
{
    if (node == NULL) {
        return;
    }

    NodePrint(node->left);
    printf("%d ", node->data);
    NodePrint(node->right);
}

void TreePrint(treeT *treeP)
{
    NodePrint(treeP->root);
}

void NodePrintPostOrder(treeNodeT *node)
{
    if (node == NULL) {
        return;
    }

    NodePrint(node->left);
    NodePrint(node->right);
    printf("%d ", node->data);
}

void TreePrintPostOrder(treeT *treeP)
{
    NodePrintPostOrder(treeP->root);
}

int NodeHasPathSum(treeNodeT *node, treeElementT sum)
{
    if (node == NULL) {
        return sum == 0;
    } else {
        int subSum = sum - node->data;
        return (NodeHasPathSum(node->left, subSum) || NodeHasPathSum(node->right, subSum));
    }
}

int TreeHasPathSum(treeT *treeP, treeElementT sum)
{
    return NodeHasPathSum(treeP->root, sum);
}
