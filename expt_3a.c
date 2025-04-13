/* 
==================
Experiment 3a: Sequential File Allocation
Simulates sequential allocation by marking consecutive blocks as allocated.
Input: Starting block and length of the file.
Output: The range of blocks allocated.
==================
*/

#include <stdio.h>
#define MAX_BLOCKS 100

int main() {
    int disk[MAX_BLOCKS] = {0};  // 0 = free, 1 = allocated
    int start, length;
    
    printf("Sequential File Allocation\n");
    printf("Enter starting block and length of file: ");
    scanf("%d %d", &start, &length);
    
    if (start < 0 || start + length > MAX_BLOCKS) {
        printf("Error: Out of disk bounds.\n");
        return 1;
    }
    
    for (int i = start; i < start + length; i++) {
        if (disk[i] == 1) {
            printf("Error: Block %d already allocated.\n", i);
            return 1;
        }
    }
    
    for (int i = start; i < start + length; i++) {
        disk[i] = 1;
    }
    
    printf("File allocated from block %d to %d.\n", start, start + length - 1);
    return 0;
}
