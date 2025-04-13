/* 
==================
Experiment 8d: LRU Page Replacement
Simulates LRU replacement using a counter to track recency.
Input: Number of frames and the page reference string.
Output: Frame contents after each reference and total page faults.
==================
*/

#include <stdio.h>
#include <limits.h>

int main() {
    int frames;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    int refCount;
    printf("Enter number of page references: ");
    scanf("%d", &refCount);
    
    int refs[100];
    printf("Enter the page reference string: ");
    for (int i = 0; i < refCount; i++)
        scanf("%d", &refs[i]);
    
    int frameArr[frames], counter[frames], fault = 0, time = 0;
    for (int i = 0; i < frames; i++) {
        frameArr[i] = -1;
        counter[i] = 0;
    }
    
    printf("\nLRU Page Replacement:\n");
    for (int i = 0; i < refCount; i++) {
        int found = 0, pos = 0;
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == refs[i]) {
                found = 1;
                counter[j] = ++time;
                break;
            }
        }
        if (!found) {
            int min = INT_MAX;
            for (int j = 0; j < frames; j++) {
                if (counter[j] < min) {
                    min = counter[j];
                    pos = j;
                }
            }
            frameArr[pos] = refs[i];
            counter[pos] = ++time;
            fault++;
        }
        
        printf("After accessing %d: ", refs[i]);
        for (int j = 0; j < frames; j++)
            printf("%d ", frameArr[j]);
        printf("\n");
    }
    
    printf("Total Page Faults: %d\n", fault);
    return 0;
}
