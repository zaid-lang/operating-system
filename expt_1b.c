/* 
==================
Experiment 1b: SJF CPU Scheduling (Non-preemptive)
Assumes all processes arrive at time 0. Inputs burst times,
sorts processes by burst time (preserving original IDs),
and computes waiting and turnaround times.
==================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burst;
    int waiting;
    int turnaround;
} Process;

int compareBurst(const void *a, const void *b) {
    Process *p1 = (Process*)a;
    Process *p2 = (Process*)b;
    return p1->burst - p2->burst;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process proc[n];
    
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &proc[i].burst);
    }
    
    // Sort processes by burst time for SJF scheduling
    qsort(proc, n, sizeof(Process), compareBurst);
    
    proc[0].waiting = 0;
    proc[0].turnaround = proc[0].burst;
    
    for (int i = 1; i < n; i++) {
        proc[i].waiting = proc[i-1].waiting + proc[i-1].burst;
        proc[i].turnaround = proc[i].waiting + proc[i].burst;
    }
    
    printf("\nSJF Scheduling (Non-preemptive):\n");
    printf("Execution Order: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", proc[i].id);
    }
    printf("\n\nProcess\tBurst\tWaiting\tTurnaround\n");
    
    int totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", proc[i].id, proc[i].burst, proc[i].waiting, proc[i].turnaround);
        totalWaiting += proc[i].waiting;
        totalTurnaround += proc[i].turnaround;
    }
    
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaiting/n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaround/n);
    
    return 0;
}
