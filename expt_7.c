/* 
==================
Experiment 7: Banker's Algorithm
Simulates Banker's algorithm.
Input: Number of processes and resource types, allocation and maximum matrices, and available resources.
Output: Safe sequence if system is safe; otherwise, indicates unsafe state.
==================
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    
    int alloc[n][m], max[n][m], avail[m], need[n][m];
    
    printf("\nEnter allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("\nEnter maximum resource matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("\nEnter available resources: ");
    for (int j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }
    
    // Calculate need matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    
    bool finish[n];
    for (int i = 0; i < n; i++)
        finish[i] = false;
    
    int safeSeq[n], count = 0;
    
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }
                if (j == m) { // Process i can be allocated all resources
                    for (int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state.\n");
            return 0;
        }
    }
    
    printf("Safe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
    
    return 0;
}
