/*
Experiment: MFT Memory Management Simulation
Description:
This program simulates fixed-partition (MFT) memory allocation.
It reads the number of partitions and the size for each partition, then the number of processes
and the memory requirement for each process. Each partition can hold one process if the process
memory requirement does not exceed the partition size.
Input: Number of partitions, partition sizes, number of processes, process memory requirements
Output: Allocation results (which partition gets which process)
*/
#include <stdio.h>

int main() {
    int partitions;
    printf("Enter number of fixed partitions: ");
    scanf("%d", &partitions);
    
    int size[partitions];
    int allocated[partitions];
    for (int i = 0; i < partitions; i++) {
        printf("Enter size for Partition %d: ", i+1);
        scanf("%d", &size[i]);
        allocated[i] = 0;  // not allocated initially
    }
    
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int process[n];
    for (int i = 0; i < n; i++) {
        printf("Enter memory required for Process %d: ", i+1);
        scanf("%d", &process[i]);
    }
    
    printf("\nMFT Allocation Results:\n");
    for (int i = 0; i < n; i++) {
        int allocatedFlag = 0;
        for (int j = 0; j < partitions; j++) {
            if (!allocated[j] && process[i] <= size[j]) {
                allocated[j] = 1;
                printf("Process %d allocated in Partition %d (size %d).\n", i+1, j+1, size[j]);
                allocatedFlag = 1;
                break;
            }
        }
        if (!allocatedFlag)
            printf("Process %d cannot be allocated in any partition.\n", i+1);
    }
    return 0;
}
