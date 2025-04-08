#include <stdio.h>

int main() {
    int ref[50], frames[20], freq[20] = {0};
    int n, f, faults = 0;

    printf("Enter number of page references: ");
    scanf("%d", &n);
    
    printf("Enter page references: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &ref[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize all frames as empty (-1)
    for(int i=0; i<f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\tFault\n");

    for(int i=0; i<n; i++) {
        int page = ref[i];
        int found = 0;

        // Check if page is already in frames
        for(int j=0; j<f; j++) {
            if(frames[j] == page) {
                found = 1;
                freq[j]++;
                break;
            }
        }

        // If page not found, replace LFU page
        if(!found) {
            // Find least frequently used page
            int lfu = 0;
            for(int j=1; j<f; j++) {
                if(freq[j] < freq[lfu]) {
                    lfu = j;
                }
            }
            
            // Replace
            frames[lfu] = page;
            freq[lfu] = 1;
            faults++;
        }

        // Display current state
        printf("%d\t", page);
        for(int j=0; j<f; j++) {
            if(frames[j] == -1) printf("- ");
            else printf("%d(%d) ", frames[j], freq[j]);
        }
        printf("\t%s\n", found ? "" : "Fault");
    }

    printf("\nTotal page faults: %d\n", faults);
    return 0;
}
