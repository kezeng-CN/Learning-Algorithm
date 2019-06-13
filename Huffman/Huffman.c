// HuffmanTree 结构自己定义?
// ComputeFrequency 是统计字符出现次数的?

void ComputeFrequency(char *src, int *freq);
HuffmanTree CreateHuffmanTree(int *freq);
void Compress(char *src, HuffmanTree tree, char *dest);
void DestroyHuffmanTree(HuffmanTree tree);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct huffman_node
{
    int parent;
    int left;
    int right;
    int weight;
} HuffmanTree;

#define HUFFMAN_ERR -1
#define HUFFMAN_OK 0

int huffman_weight_to_node(stHuffManNode **nodeArray, int *weight, int wSize)
{
    int i;

    if (NULL == weight)
        return HUFFMAN_ERR;
    if ((wSize >> 31) > 0)
        return HUFFMAN_ERR;
    *nodeArray = (stHuffManNode *)malloc(sizeof(stHuffManNode) * (2 * wSize));
    if (NULL == *nodeArray)
        return HUFFMAN_ERR;

    for (i = 0; i < 2 * wSize; i++)
    {
        (*nodeArray)[i].parent = -1;
        (*nodeArray)[i].left = -1;
        (*nodeArray)[i].right = -1;
        if (i < wSize)
            (*nodeArray)[i].weight = weight[i];
        else
            (*nodeArray)[i].weight = 0;
    }

    return HUFFMAN_OK;
}

int huffman_find_min(stHuffManNode *nodeArray, int length, int *min1, int *min2)
{
    int minWeight1 = 0x7fffffff;
    int minWeight2 = 0x7fffffff;
    int i;

    *min1 = 0;
    *min2 = 0;

    for (i = 0; i < length; i++)
    {
        if (nodeArray[i].parent == -1 && nodeArray[i].weight < minWeight1)
        {
            *min2 = *min1;
            minWeight2 = minWeight1;
            *min1 = i;
            minWeight1 = nodeArray[i].weight;
        }
        else if (nodeArray[i].parent == -1 && nodeArray[i].weight < minWeight2)
        {
            *min2 = i;
            minWeight2 = nodeArray[i].weight;
        }
    }

    return HUFFMAN_OK;
}

int huffman_tree_create(stHuffManNode *nodeArray, int wSize)
{
    int length = wSize;
    int i;
    int min1, min2;

    for (i = 0; i < length - 1; i++)
    {
        huffman_find_min(nodeArray, length + i, &min1, &min2);
        nodeArray[length + i].left = min1;
        nodeArray[length + i].right = min2;
        nodeArray[length + i].weight = nodeArray[min1].weight + nodeArray[min2].weight;
        nodeArray[min1].parent = length + i;
        nodeArray[min2].parent = length + i;
    }

    return HUFFMAN_OK;
}

int huffman_encode(stHuffManNode *nodeArray, int wSize, char ***huffManCode)
{
    char *code;
    int i, j;

    *huffManCode = (char **)malloc(wSize * sizeof(char *));
    if (NULL == *huffManCode)
        return HUFFMAN_ERR;
    code = (char *)malloc(wSize * sizeof(char));
    if (NULL == code)
        return HUFFMAN_ERR;
    code[wSize - 1] = 0;

    for (i = 0; i < wSize; i++)
    {
        int start = wSize - 1;
        int father = nodeArray[i].parent;
        int current = i;
        while (father != -1)
        {
            if (nodeArray[father].left == current)
            {
                code[start - 1] = '0';
            }
            else
            {
                code[start - 1] = '1';
            }
            start--;
            current = father;
            father = nodeArray[current].parent;
        }
        char *hc = (char *)malloc((wSize - start) * sizeof(char));
        if (NULL == hc)
        {
            printf("malloc error");
            continue;
        }
        memcpy(hc, &code[start], wSize - start);
        (*huffManCode)[i] = hc;
    }

    free(code);
    return HUFFMAN_OK;
}

int huffman_destory(stHuffManNode *nodeArray, char **huffManCode, int wSize)
{
    int i;

    free(nodeArray);
    for (i = 0; i < wSize; i++)
    {
        if (NULL != huffManCode[i])
            free(huffManCode[i]);
    }
    free(huffManCode);

    return HUFFMAN_OK;
}

int main(void)
{
    return 0;
}