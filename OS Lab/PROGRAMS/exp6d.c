 #include<stdio.h>
int main() {
    int i, limit, total = 0, x, counter = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, burst_time[10], temp[10];
    float average_wait_time, average_turnaround_time;

    // Input total number of processes
    printf("\nEnter Total Number of Processes:\t");
    scanf("%d", &limit);
    x = limit;

    // Input burst times for each process
    for(i = 0; i < limit; i++) {
        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Burst Time:\t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];  // Copy burst time to temp for tracking
    }

    // Input time quantum
    printf("\nEnter Time Quantum:\t");
    scanf("%d", &time_quantum);
    
    // Print header for the process table
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");

    // Round Robin Scheduling loop
    for(total = 0, i = 0; x != 0;) {
        if(temp[i] <= time_quantum && temp[i] > 0) {
            total = total + temp[i]; // Add remaining burst time to total time
            temp[i] = 0; // Process is completed
            counter = 1;
        }
        else if(temp[i] > 0) {
            temp[i] = temp[i] - time_quantum; // Reduce burst time by time quantum
            total = total + time_quantum; // Update total time
        }

        // If process is completed
        if(temp[i] == 0 && counter == 1) {
            x--; // Decrease remaining processes
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total, total - burst_time[i]);
            wait_time = wait_time + total - burst_time[i]; // Add waiting time
            turnaround_time = turnaround_time + total; // Add turnaround time
            counter = 0; // Reset counter
        }

        // Move to the next process in a circular manner
        if(i == limit - 1) {
            i = 0; // Wrap around to the first process
        }
        else {
            i++; // Move to the next process
        }
    }

    // Calculate average waiting time and turnaround time
    average_wait_time = wait_time * 1.0 / limit;
    average_turnaround_time = turnaround_time * 1.0 / limit;

    // Display the results
    printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
    printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
    return 0;
}

