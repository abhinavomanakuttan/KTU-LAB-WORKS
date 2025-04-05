#include <stdio.h>

// Swap function for sorting
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    // Variable declarations
    int i, j, n;
    int p[30], bt[30], pr[30], tat[30], wt[30];
    int tot_tat = 0, tot_wt = 0;
    float avg_tat, avg_wt;
    
    // Input number of processes
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    
    // Input burst time and priority for each process
    for (i = 0; i < n; i++) {
        printf("Enter burst time and priority of process[%d]: ", i + 1);
        scanf("%d%d", &bt[i], &pr[i]);
        p[i] = i + 1; // Process numbering starts at 1
    }
    
    // Priority-based sorting (bubble sort)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (pr[i] > pr[j]) { // Lower number = higher priority
                swap(&pr[i], &pr[j]);
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
            }
        }
    }
    
    // Calculate waiting and turnaround times
    wt[0] = 0;               // First process has no wait
    tat[0] = bt[0];          // First process TAT = its burst time
    tot_tat = tat[0];
    
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  // Cumulative waiting time
        tat[i] = wt[i] + bt[i];         // TAT = WT + BT
        tot_wt += wt[i];
        tot_tat += tat[i];
    }
    
    // Calculate averages
    avg_wt = (float)tot_wt / n;
    avg_tat = (float)tot_tat / n;
    
    // Display results
    printf("\nPROCESS\t\tBURST TIME\tPRIORITY\tWAITING TIME\tTURNAROUND TIME");
    for (i = 0; i < n; i++) {
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], pr[i], wt[i], tat[i]);
    }
    
    // Display summary statistics
    printf("\n\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    
    return 0;
}
