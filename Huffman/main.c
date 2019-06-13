#include <stdio.h>
#include <stdlib.h>
#include "HuffmanCode.h"


int main(int argc, char *argv[])
{
    int freq[256];
    HuffmanTree tree;

    // Count the frequency of each character
    ComputeFrequency("Jane+Eyre.txt", freq);
    // Create a huffman tree based on the frequency of each character
    tree = CreateHuffmanTree(freq);
    // Compress the file
    Compress("Jane+Eyre.txt", tree, "Compressed_Jane+Eyre");
    // Destroy the tree
    DestroyHuffmanTree(tree);

    return 0;
}
