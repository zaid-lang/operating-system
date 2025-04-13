/*
Experiment: First-Fit Contiguous Memory Allocation
Description:
This program simulates contiguous allocation using the first-fit strategy.
It reads the number of holes and their sizes, along with the number of processes and
their memory requirements. For each process, it scans the holes from the beginning
and allocates the first hole that is large enough. The hole size is then reduced accordingly.
Input: Number of holes, hole sizes, number of processes, process memory requirements
Output: Allocation result for each process
*/
#include <stdio.h>

int main() {
    int h;
    printf("Enter number of holes (First-Fit): ");
    scanf("%d", &h);
    int holes[h];
    for (int i = 0; i < h; i++) {
        printf("Enter size of hole %d: ", i+1);
        scanf("%d", &holes[i]);
    }
    
    int p;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    int process[p];
    for (int i = 0; i < p; i++) {
        printf("Enter memory required for Process %d: ", i+1);
        scanf("%d", &process[i]);
    }
    
    int allocation[p];
    for (int i = 0; i < p; i++)
        allocation[i] = -1;
    
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < h; j++) {
            if (holes[j] >= process[i]) {
                allocation[i] = j;
                holes[j] -= process[i];
                break;
            }
        }
    }
    
    printf("\nFirst-Fit Allocation Results:\n");
    for (int i = 0; i < p; i++) {
        if (allocation[i] != -1)
            printf("Process %d allocated in Hole %d.\n", i+1, allocation[i] + 1);
        else
            printf("Process %d could not be allocated.\n", i+1);
    }
    return 0;
}
