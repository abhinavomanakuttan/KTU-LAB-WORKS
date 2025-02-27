#include<stdio.h>
void main() // Main function
{
// Declare variables
int p[30], bt[30], tot_tat = 0, wt[30], n, tot_wt = 0, tat[30];
float awt, avg_tat, avg_wt; // Variables for average calculations

int i;
// Prompt the user to enter the number of processes
printf("\nEnter the No. of Processes: \n");
scanf("%d", &n); // Read the number of processes from the user
// Prompt the user to enter burst times for each process
printf("Enter Burst time for each process:\n");
for(i = 0; i < n; i++) // Loop through each process
{
scanf("%d", &bt[i]); // Read burst time
p[i] = i; // Assign process ID (0, 1, 2,..., n-1)
}
// Display that the FCFS algorithm is being used
printf("\n FCFS Algorithm \n");
// Calculate Turnaround Time (TAT)
for(i = 0; i < n; i++)
{
if(i == 0)
tat[i] = bt[i]; // First process TAT is equal to its Burst Time
else
tat[i] = tat[i - 1] + bt[i]; // Next process TAT = Previous TAT + Current BT
tot_tat = tot_tat + tat[i]; // Sum up Turnaround Time
}
// Calculate Waiting Time (WT)
wt[0] = 0; // First process has no waiting time
for(i = 1; i < n; i++) // Loop from the second process
{
wt[i] = wt[i - 1] + bt[i - 1]; // WT = Previous WT + Previous BT
tot_wt = tot_wt + wt[i]; // Sum up Waiting Time
}
// Display results
printf("\nPROCESS\t\tBURST TIME\tTURN AROUND TIME\tWAITING TIME");
for(i = 0; i < n; i++)
printf("\nprocess[%d]\t\t%d\t\t%d\t\t%d", p[i], bt[i], tat[i], wt[i]);
// Print total turnaround time and average turnaround time
printf("\n\nTotal Turnaround Time: %d", tot_tat);
printf("\nAverage Turnaround Time: %d", tot_tat / n);

// Print total waiting time and average waiting time
printf("\nTotal Waiting Time: %d", tot_wt);
printf("\nAverage Waiting Time: %d\n", tot_wt / n);
}
