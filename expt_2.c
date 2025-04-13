/* 
==================
Experiment 2: Multi-level Queue Scheduling
Divides processes into two queues:
 - System processes (priority 0)
 - User processes (priority 1)
Each queue is scheduled using FCFS.
Input: Process type and burst time.
Output: Execution order along with start and finish times.
==================
*/

#include <stdio.h>

typedef struct {
    int id;
    int type;   // 0 = system, 1 = user
    int burst;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process proc[n];
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("\nProcess P%d:\n", i + 1);
        printf("Type (0 for system, 1 for user): ");
        scanf("%d", &proc[i].type);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst);
    }
    
    int time = 0;
    printf("\nMulti-level Queue Scheduling Execution Order:\n");
    // Process system (priority 0) first
    for (int priority = 0; priority <= 1; priority++) {
        for (int i = 0; i < n; i++) {
            if (proc[i].type == priority) {
                printf("P%d executed from time %d to %d\n", proc[i].id, time, time + proc[i].burst);
                time += proc[i].burst;
            }
        }
    }
    
    return 0;
}
