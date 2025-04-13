/* 
==================
Experiment 1a: FCFS CPU Scheduling (Non-preemptive)
Simulates FCFS scheduling by reading process arrival and burst times,
sorting processes by arrival time, and computing each process’s completion,
turnaround, and waiting times.
==================
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
} Process;

// Compare based on arrival time
int compareArrival(const void *a, const void *b) {
    Process *p1 = (Process*)a;
    Process *p2 = (Process*)b;
    return p1->arrival - p2->arrival;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("\nProcess P%d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst);
    }
    
    // Sort based on arrival time.
    qsort(proc, n, sizeof(Process), compareArrival);
    
    int time = 0;
    for (int i = 0; i < n; i++) {
        if(time < proc[i].arrival)
            time = proc[i].arrival;  // CPU idle until process arrives
        proc[i].completion = time + proc[i].burst;
        proc[i].turnaround = proc[i].completion - proc[i].arrival;
        proc[i].waiting = proc[i].turnaround - proc[i].burst;
        time = proc[i].completion;
    }
    
    printf("\nFCFS Scheduling:\n");
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", 
            proc[i].id, proc[i].arrival, proc[i].burst,
            proc[i].completion, proc[i].turnaround, proc[i].waiting);
    }
    
    printf("\nExecution Order (sorted by arrival time): ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", proc[i].id);
    }
    printf("\n");
    
    return 0;
}
