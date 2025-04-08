#include <stdio.h>
#define MAX_FRAMES 3
#define MAX_REFERENCES 20

int main() {
    int pages[MAX_REFERENCES], frames[MAX_FRAMES], last_used[MAX_FRAMES] = {0};
    int n, f, faults = 0, time = 1;

    // Get input
    printf("Enter number of page references: ");
    scanf("%d", &n);
    
    printf("Enter page references: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames as empty (-1)
    for(int i=0; i<f; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\tFault\n");

    for(int i=0; i<n; i++) {
        int page = pages[i];
        int found = 0;

        // Check if page is already in frames
        for(int j=0; j<f; j++) {
            if(frames[j] == page) {
                found = 1;
                last_used[j] = time++;
                break;
            }
        }

        // If page not found, replace LRU page
        if(!found) {
            int lru = 0;
            for(int j=1; j<f; j++) {
                if(last_used[j] < last_used[lru]) {
                    lru = j;
                }
            }
            frames[lru] = page;
            last_used[lru] = time++;
            faults++;
        }

        // Display current state
        printf("%d\t", page);
        for(int j=0; j<f; j++) {
            printf("%d ", frames[j]);
        }
        printf("\t%s\n", found ? "" : "Fault");
    }

    printf("\nTotal page faults: %d\n", faults);
    return 0;
}
