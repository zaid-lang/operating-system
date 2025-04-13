/*
Experiment: MVT Memory Management Simulation
Description:
This program simulates memory allocation for processes under MVT.
It reads the total memory size and then the memory required for each process.
For each process, if enough free memory exists, the process is allocated, and the
free memory is reduced accordingly.
Input: Total memory size, number of processes, memory required for each process
Output: Allocation result for each process and remaining memory
*/
#include <stdio.h>

int main() {
    int totalMemory;
    printf("Enter total memory size (MVT): ");
    scanf("%d", &totalMemory);

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int process[n];

    // Read memory required for each process.
    for (int i = 0; i < n; i++) {
        printf("Enter memory required for Process %d: ", i+1);
        scanf("%d", &process[i]);
    }

    printf("\nMVT Allocation Results:\n");
    for (int i = 0; i < n; i++) {
        if (process[i] <= totalMemory) {
            printf("Process %d allocated %d memory.\n", i+1, process[i]);
            totalMemory -= process[i];
        } else {
            printf("Process %d cannot be allocated: Not enough memory.\n", i+1);
        }
    }
    printf("Remaining memory: %d\n", totalMemory);
    return 0;
}
