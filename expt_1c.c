/* 
==================
Experiment 1c: Round Robin CPU Scheduling (Non-preemptive)
Reads the number of processes, burst time for each, and a time quantum.
Simulates scheduling in round robin order, computing waiting and turnaround times.
==================
*/

#include <stdio.h>

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int burst[n], remaining[n], waiting[n], turnaround[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        waiting[i] = 0;
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    int time = 0;
    int done;
    // Continue until all processes are done.
    while (1) {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    waiting[i] = time - burst[i];  // waiting = finish time - burst time
                    remaining[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
    
    for (int i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
    }
    
    printf("\nRound Robin Scheduling:\n");
    printf("Process\tBurst\tWaiting\tTurnaround\n");
    int totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
        totalWaiting += waiting[i];
        totalTurnaround += turnaround[i];
    }
    
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaiting/n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaround/n);
    
    return 0;
}
