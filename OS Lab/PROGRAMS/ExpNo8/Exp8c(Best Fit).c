#include <stdio.h> 
#define MAX 25 

int main() { 
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, best_fit; 
    int bf[MAX] = {0}, ff[MAX] = {0}; // Initialize all to 0

    printf("\n\tMemory Management Scheme - Best Fit\n");
    printf("---------------------------------------------\n");
    printf("Enter the number of blocks: "); 
    scanf("%d", &nb); 
    printf("Enter the number of files: "); 
    scanf("%d", &nf); 
    printf("\nEnter the size of the blocks:\n"); 

    for (i = 1; i <= nb; i++) { 
        printf("Block %d: ", i); 
        scanf("%d", &b[i]); 
    } 

    printf("\nEnter the size of the files:\n"); 
    for (i = 1; i <= nf; i++) { 
        printf("File %d: ", i); 
        scanf("%d", &f[i]); 
    } 

    for (i = 1; i <= nf; i++) { 
        best_fit = -1; // Initialize to -1 (no block found yet)
        ff[i] = 0;     // No block allocated yet
        frag[i] = 0;   // No fragment initially

        for (j = 1; j <= nb; j++) { 
            if (bf[j] != 1) { // If block is free
                temp = b[j] - f[i]; // Calculate remaining space

                if (temp >= 0) { // If block can accommodate the file
                    // Find the smallest possible block that fits
                    if (best_fit == -1 || temp < frag[best_fit]) {
                        best_fit = j;
                        ff[i] = j;      // Assign block j to file i
                        frag[i] = temp;  // Store fragment size
                    }
                } 
            } 
        } 
        if (ff[i] != 0) { // If a block was allocated
            bf[ff[i]] = 1; // Mark the block as allocated
        } 
    } 

    printf("\nFile Allocation Details:\n");
    printf("File No\tFile Size\tBlock No\tBlock Size\tFragment\n"); 
    for (i = 1; i <= nf; i++) { 
        if (ff[i] == 0) {
            printf("%d\t%d\t\tNot Allocated\t-\t\t-\n", i, f[i]);
        } else {
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]); 
        }
    } 

    return 0; 
}
