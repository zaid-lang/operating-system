/* 
==================
Experiment 9b: Disk Scheduling – SCAN
Simulates SCAN disk scheduling.
Input: Number of disk requests, request sequence, initial head position, and disk size.
Output: Service order and total head movement (approximate).
==================
*/

#include <stdio.h>
#include <stdlib.h>

// Helper function for qsort.
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, head, diskSize;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    
    int requests[n];
    printf("Enter the disk request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &requests[i]);
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size (max cylinder): ");
    scanf("%d", &diskSize);
    
    qsort(requests, n, sizeof(int), compare);
    
    int totalMovement = 0;
    printf("\nSCAN Disk Scheduling Order:\n");
    
    // Find index where requests[i] >= head
    int split;
    for (split = 0; split < n; split++) {
        if (requests[split] >= head)
            break;
    }
    
    // Move upward
    for (int i = split; i < n; i++) {
        printf("%d -> ", requests[i]);
    }
    // Then reverse for lower requests, adding movements.
    if (n > 0) {
        totalMovement += abs(head - requests[split]);
        totalMovement += abs(requests[n-1] - 0);
    }
    for (int i = split - 1; i >= 0; i--) {
        printf("%d -> ", requests[i]);
    }
    printf("\nTotal head movement (approx.): %d\n", totalMovement);
    return 0;
}
