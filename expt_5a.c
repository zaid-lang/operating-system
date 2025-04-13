/*
Experiment: Worst-Fit Contiguous Memory Allocation
Description:
This program simulates contiguous memory allocation using the worst-fit strategy.
It reads the number of memory holes and their sizes, and the number of processes and
their memory requirements. For each process, the hole with the largest available size
that can accommodate the process is selected, and the process memory is subtracted from it.
Input: Number of holes, size of each hole, number of processes, and process memory requirements
Output: For each process, the allocated hole (or -1 if not allocated)
*/
#include <stdio.h>

int main() {
    int h;
    printf("Enter number of holes (Worst-Fit): ");
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
        int worstIndex = -1;
        for (int j = 0; j < h; j++) {
            if (holes[j] >= process[i]) {
                if (worstIndex == -1 || holes[j] > holes[worstIndex])
                    worstIndex = j;
            }
        }
        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            holes[worstIndex] -= process[i];
        }
    }
    
    printf("\nWorst-Fit Allocation Results:\n");
    for (int i = 0; i < p; i++) {
        if (allocation[i] != -1)
            printf("Process %d allocated in Hole %d.\n", i+1, allocation[i] + 1);
        else
            printf("Process %d could not be allocated.\n", i+1);
    }
    return 0;
}
