#include <stdio.h>

void calculateWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; 
    
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void calculateTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;
    
    calculateWaitingTime(processes, n, bt, wt);
    calculateTurnaroundTime(processes, n, bt, wt, tat);
    
    printf("Process \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d \t\t %d \t\t %d \t\t %d\n", processes[i], bt[i], wt[i], tat[i]);
    }
    
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int processes[n], burst_time[n];
    
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    
    findAverageTime(processes, n, burst_time);
    
    return 0;
}

