#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H


typedef struct Node
{
    int weight;
    unsigned char byte;
    struct Node *left;
    struct Node *right;
} Node, *HuffmanTree;


void ComputeFrequency(char *src, int *freq);

HuffmanTree CreateHuffmanTree(int *freq);

void Compress(char *src, HuffmanTree tree, char *dest);

void DestroyHuffmanTree(HuffmanTree tree);


#endif
