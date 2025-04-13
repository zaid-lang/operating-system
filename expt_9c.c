/* 
==================
Experiment 9c: Disk Scheduling – C-SCAN
Simulates C-SCAN disk scheduling.
Input: Number of disk requests, request sequence, initial head position, and disk size.
Output: Service order and total head movement (approximate).
==================
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
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
    
    qsort(requests, n, sizeof(int), cmp);
    
    int totalMovement = 0;
    printf("\nC-SCAN Disk Scheduling Order:\n");
    
    // Service requests to the right of head.
    int i;
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            printf("%d -> ", requests[i]);
        }
    }
    // Jump to beginning.
    if(n > 0) {
        totalMovement += (diskSize - head);
        totalMovement += diskSize; // jump from end to start
        for (i = 0; i < n; i++) {
            if(requests[i] < head) {
                printf("%d -> ", requests[i]);
            }
        }
    }
    printf("\nTotal head movement (approx.): %d\n", totalMovement);
    return 0;
}
