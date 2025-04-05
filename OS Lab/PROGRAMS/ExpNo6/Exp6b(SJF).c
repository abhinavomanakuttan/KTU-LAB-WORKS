#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int i, j, n, tot_tat = 0, tot_wt = 0;
    int p[30], bt[30], tat[30], wt[30];
    float avg_tat, avg_wt;
    
    // Input number of processes
    printf("Enter the no.of processes: ");
    scanf("%d", &n);
    
    // Input burst times
    printf("Enter burst time for each process:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        p[i] = i; // Process IDs (0 to n-1)
    }
    
    // SJF Sorting - Bubble Sort implementation
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
            }
        }
    }
    
    // Calculate Turnaround Time (TAT)
    for(i = 0; i < n; i++) {
        tat[i] = (i == 0) ? bt[i] : tat[i - 1] + bt[i];
        tot_tat += tat[i];
    }
    
    // Calculate Waiting Time (WT)
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tot_wt += wt[i];
    }
    
    // Output results
    printf("\nPROCESS\tBURST TIME\tTURNAROUND TIME\tWAITING TIME\n");
    for(i = 0; i < n; i++)
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", p[i] + 1, bt[i], tat[i], wt[i]);
    
    // Calculate and display averages
    avg_tat = (float)tot_tat / n;
    avg_wt = (float)tot_wt / n;
    printf("\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
    
    return 0;
}
