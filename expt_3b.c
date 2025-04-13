/* 
==================
Experiment 3b: Indexed File Allocation
Simulates indexed allocation by allocating an index block and linking to data blocks.
Input: Index block, number of data blocks, and each data block number.
Output: The index block and the list of allocated data blocks.
==================
*/

#include <stdio.h>
#define MAX_BLOCKS 100

int main() {
    int disk[MAX_BLOCKS] = {0};  // 0 = free, 1 = allocated
    int indexBlock, nBlocks, blocks[50];
    
    printf("Indexed File Allocation\n");
    printf("Enter index block: ");
    scanf("%d", &indexBlock);
    
    if(indexBlock < 0 || indexBlock >= MAX_BLOCKS || disk[indexBlock] == 1) {
        printf("Error: Index block is invalid or already allocated.\n");
        return 1;
    }
    
    printf("Enter number of blocks for file: ");
    scanf("%d", &nBlocks);
    
    printf("Enter the data block numbers:\n");
    for (int i = 0; i < nBlocks; i++) {
        scanf("%d", &blocks[i]);
        if(blocks[i] < 0 || blocks[i] >= MAX_BLOCKS || disk[blocks[i]] == 1) {
            printf("Error: Block %d is invalid or already allocated.\n", blocks[i]);
            return 1;
        }
    }
    
    // Allocate the index block and data blocks.
    disk[indexBlock] = 1;
    for (int i = 0; i < nBlocks; i++)
        disk[blocks[i]] = 1;
    
    printf("File allocated using index block %d with data blocks: ", indexBlock);
    for (int i = 0; i < nBlocks; i++)
        printf("%d ", blocks[i]);
    printf("\n");
    
    return 0;
}
