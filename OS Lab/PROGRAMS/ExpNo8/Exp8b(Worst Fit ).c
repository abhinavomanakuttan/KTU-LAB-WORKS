#include <stdio.h>
#define MAX 25

int main() {
    int frag[MAX], b[MAX], f[MAX], i, j, nb, nf, temp, largest;
    static int bf[MAX], ff[MAX];

    printf("\n\tMemory Management Scheme - Worst Fit\n");
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
        largest = -1; // Initialize largest fragment to -1 (no block found)
        ff[i] = 0;    // No block allocated yet
        frag[i] = 0;  // No fragment initially

        for (j = 1; j <= nb; j++) {
            if (bf[j] != 1) { // If block is free
                temp = b[j] - f[i]; // Calculate remaining space

                if (temp >= 0) { // If block can accommodate the file
                    if (largest == -1 || temp > largest) { // Find the largest possible block
                        largest = temp;
                        ff[i] = j;      // Assign block j to file i
                        frag[i] = temp; // Store fragment size
                    }
                }
            }
        }
        if (ff[i] != 0) { // If a block was allocated
            bf[ff[i]] = 1; // Mark the block as allocated
        }
    }

    printf("\nFile Allocation Details:\n");
    printf("File_no\tFile_size\tBlock_no\tBlock_size\tFragment\n");
    for (i = 1; i <= nf; i++) {
        if (ff[i] == 0) {
            printf("%d\t%d\t\tNot Allocated\t-\t\t-\n", i, f[i]);
        } else {
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i, f[i], ff[i], b[ff[i]], frag[i]);
        }
    }

    return 0;
}
