/* 
==================
Experiment 3c: Linked File Allocation
Simulates linked allocation using a linked list to represent file blocks.
Input: Number of blocks and each block number.
Output: The linked list of blocks allocated.
==================
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 100

typedef struct Node {
    int block;
    struct Node *next;
} Node;

int main() {
    int disk[MAX_BLOCKS] = {0};  // 0 = free, 1 = allocated
    int n, blockNum;
    Node *head = NULL, *tail = NULL;
    
    printf("Linked File Allocation\n");
    printf("Enter number of blocks for the file: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter block number %d: ", i + 1);
        scanf("%d", &blockNum);
        if(blockNum < 0 || blockNum >= MAX_BLOCKS || disk[blockNum] == 1) {
            printf("Error: Block %d is invalid or already allocated.\n", blockNum);
            return 1;
        }
        disk[blockNum] = 1;
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->block = blockNum;
        newNode->next = NULL;
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    printf("File allocated as linked list: ");
    Node *temp = head;
    while(temp) {
        printf("%d -> ", temp->block);
        temp = temp->next;
    }
    printf("NULL\n");
    
    return 0;
}
