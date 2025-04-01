
#include <stdio.h>

int main() {
    // Declare variables
    int p[30], bt[30], tat[30], wt[30], n, tot_tat = 0, tot_wt = 0;
    float avg_tat, avg_wt;

    // Prompt the user to enter the number of processes
    printf("\nEnter the Number of Processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process[%d]: ", i);
        scanf("%d", &bt[i]);
        p[i] = i;  // Assign process ID
    }

    // FCFS Algorithm
    printf("\nFCFS Scheduling Algorithm\n");

    // Calculate Turnaround Time (TAT)
    for (int i = 0; i < n; i++) {
        if (i == 0)
            tat[i] = bt[i];  // First process TAT = BT
        else
            tat[i] = tat[i - 1] + bt[i];  // TAT = Previous TAT + Current BT

        tot_tat += tat[i];  // Sum up Turnaround Time
    }

    // Calculate Waiting Time (WT)
    wt[0] = 0;  // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // WT = Previous WT + Previous BT
        tot_wt += wt[i];  // Sum up Waiting Time
    }

    // Calculate averages
    avg_tat = (float) tot_tat / n;
    avg_wt = (float) tot_wt / n;

    // Display results
    printf("\nPROCESS\t\tBURST TIME\tTURNAROUND TIME\tWAITING TIME");
    for (int i = 0; i < n; i++)
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], tat[i], wt[i]);

    // Print totals and averages
    printf("\n\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);

    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);

    return 0;  // Indicate successful execution
}
