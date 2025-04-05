#include<stdio.h>

void main() 
{
    // Declare variables
    int p[30], bt[30], tat[30], wt[30], n;
    int tot_tat = 0, tot_wt = 0;
    float avg_tat, avg_wt;

    // Input number of processes
    printf("\nEnter the Number of Processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    printf("Enter Burst Time for Each Process:\n");
    for(int i = 0; i < n; i++) 
    {
        printf("Process[%d]: ", i);
        scanf("%d", &bt[i]);
        p[i] = i; // Process IDs (0, 1, 2,..., n-1)
    }

    printf("\nFCFS Scheduling Algorithm\n");

    // Calculate Turnaround Time and Waiting Time
    wt[0] = 0; // First process has 0 waiting time
    
    for(int i = 0; i < n; i++) 
    {
        if(i > 0) 
        {
            wt[i] = wt[i-1] + bt[i-1];
        }
        tat[i] = wt[i] + bt[i];
        
        // Sum totals for averages
        tot_wt += wt[i];
        tot_tat += tat[i];
    }

    // Calculate averages (using float for precision)
    avg_wt = (float)tot_wt / n;
    avg_tat = (float)tot_tat / n;

    // Display results
    printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++) 
    {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", p[i], bt[i], tat[i], wt[i]);
    }

    // Print summary
    printf("\nTotal Turnaround Time: %d", tot_tat);
    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nTotal Waiting Time: %d", tot_wt);
    printf("\nAverage Waiting Time: %.2f\n", avg_wt);
}



