#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Binary_Tree
{
private:
    struct TreeNode *tree_root;
    void tree_create(int arr[], int flag[], int len)
    {
        tree_root = new struct TreeNode[len]();
        for (size_t i = 0; i < len; i++)
        {
            tree_root[i].val = arr[i];
        }
        for (size_t i = 0; i < len / 2; i++)
        {
            if (i * 2 + 1 < len)
            {
                tree_root[i].left = flag == NULL || flag[i * 2 + 1] > 0 ? &tree_root[i * 2 + 1] : NULL;
            }
            if (i * 2 + 2 < len)
            {
                tree_root[i].right = flag == NULL || flag[i * 2 + 2] > 0 ? &tree_root[i * 2 + 2] : NULL;
            }
        }
    }

public:
    Binary_Tree(int arr[], int len)
    {
        tree_create(arr, NULL, len);
    }
    Binary_Tree(int arr[], int flag[], int len)
    {
        tree_create(arr, flag, len);
    }
    ~Binary_Tree()
    {
        free(tree_root);
    }
    TreeNode *get_root()
    {
        return tree_root;
    }
};

#endif