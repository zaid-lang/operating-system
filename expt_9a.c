/* 
==================
Experiment 9a: Disk Scheduling – FCFS
Simulates FCFS disk scheduling.
Input: Number of disk requests, request sequence, and initial head position.
Output: Service order and total head movement.
==================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    
    int requests[n];
    printf("Enter the disk request sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    
    printf("Enter initial head position: ");
    scanf("%d", &head);
    
    int totalMovement = 0;
    printf("\nFCFS Disk Scheduling Order:\n");
    printf("%d -> ", head);
    for (int i = 0; i < n; i++) {
        totalMovement += abs(head - requests[i]);
        head = requests[i];
        printf("%d -> ", head);
    }
    printf("\nTotal head movement = %d\n", totalMovement);
    return 0;
}
