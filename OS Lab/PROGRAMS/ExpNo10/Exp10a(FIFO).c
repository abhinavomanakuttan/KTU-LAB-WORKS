#include <stdio.h> 
 
int main() { 
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n; 
 
    printf("\n Enter the number of page references : "); 
    scanf("%d", &n); 
    printf("\n Enter the page references : "); 
    for (i = 0; i < n; i++) 
       scanf("%d", &rs[i]); 
 
 
    printf("\n Enter number of frames : "); 
    scanf("%d", &f); 
 
    for (i = 0; i < f; i++) 
        m[i] = -1;      // Initialize all frames as empty (-1) 
 
    printf("\n FIFO Page Replacement \n"); 
     
    for (i = 0; i < n; i++) { 
              // Check if page is already in memory 
        for (k = 0; k < f; k++) { 
            if (m[k] == rs[i]) 
                break; 
        } 
 
              // If page not found, replace using FIFO 
        if (k == f) { 
            m[count] = rs[i];     // Replace at the FIFO position 
            pf++;       // Increment page fault count 
            count = (count + 1) % f;    // Move FIFO pointer circularly 
        } 
 
              // Print the current frame status 
        for (j = 0; j < f; j++) 
            printf("\t%d", m[j]); 
 
        if (k == f) 
            printf("\tPF No. %d", pf); 
        printf("\n"); 
    } 
 
    printf("\nTotal number of page faults using FIFO is %d \n", pf); 
    return 0; 
} 
