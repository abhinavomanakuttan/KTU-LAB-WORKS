#include <stdio.h>
#define MAX_PROC 10
#define MAX_RES 10

int main() {
    int finish[MAX_PROC] = {0}, safeseq[MAX_PROC];
    int alloc[MAX_PROC][MAX_RES], max[MAX_PROC][MAX_RES], need[MAX_PROC][MAX_RES];
    int avail[MAX_RES], maxres[MAX_RES];
    int m, n, i, j, executed_processes = 0;

    // Input: Number of processes and resources
    printf("\nEnter the number of processes and the number of resources: ");
    scanf("%d%d", &n, &m);

    // Input: Maximum instances of each resource
    printf("\nEnter maximum instances of resources:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &maxres[j]);
        avail[j] = maxres[j]; // Initially available = max resources
    }

    // Input: Allocation Matrix
    printf("\nEnter the Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input: Max Matrix and calculate Need Matrix
    printf("\nEnter the Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j]; // Need = Max - Allocation
        }
    }

    // Display Need Matrix
    printf("\nThe Need Matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Calculate Available Resources after Allocation
    for (j = 0; j < m; j++) {
        int sum = 0;
        for (i = 0; i < n; i++) {
            sum += alloc[i][j];
        }
        avail[j] -= sum;
    }

    // Banker's Algorithm: Find Safe Sequence
    int ind = 0;
    while (executed_processes < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int canExecute = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canExecute = 0;
                        break;
                    }
                }
                if (canExecute) {
                    safeseq[ind++] = i;
                    for (j = 0; j < m; j++) {
                        avail[j] += alloc[i][j]; // Release resources
                    }
                    finish[i] = 1;
                    executed_processes++;
                    found = 1;
                }
            }
        }
        if (!found) break; // No process found in this iteration
    }

    // Check for Safe State
    if (executed_processes < n) {
        printf("\nSystem is in an unsafe state. Deadlock may occur.\n");
    } else {
        printf("\nSafe Sequence:\n");
        for (i = 0; i < n; i++) {
            printf("P%d", safeseq[i]);
            if (i != n - 1) printf(" -> ");
        }
        printf("\n");
    }

    return 0;
}
