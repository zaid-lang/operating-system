/* 
==================
Experiment 8b: Second Chance (SC) Page Replacement
Simulates the second chance algorithm.
Input: Number of frames and page reference string.
Output: Frame contents after each reference and total page faults.
==================
*/

#include <stdio.h>
#define MAX_REF 100

int main() {
    int frames;
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    int refCount;
    printf("Enter number of page references: ");
    scanf("%d", &refCount);
    
    int refs[MAX_REF];
    printf("Enter the page reference string: ");
    for (int i = 0; i < refCount; i++)
        scanf("%d", &refs[i]);
    
    int frameArr[frames], useBit[frames], fault = 0;
    for (int i = 0; i < frames; i++) {
        frameArr[i] = -1;
        useBit[i] = 0;
    }
    
    int pointer = 0;
    printf("\nSecond Chance Page Replacement:\n");
    for (int i = 0; i < refCount; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == refs[i]) {
                useBit[j] = 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            while (1) {
                if (useBit[pointer] == 0) {
                    frameArr[pointer] = refs[i];
                    useBit[pointer] = 1;
                    pointer = (pointer + 1) % frames;
                    fault++;
                    break;
                } else {
                    useBit[pointer] = 0;
                    pointer = (pointer + 1) % frames;
                }
            }
        }
        
        printf("After accessing %d: ", refs[i]);
        for (int j = 0; j < frames; j++)
            printf("%d ", frameArr[j]);
        printf("\n");
    }
    
    printf("Total Page Faults: %d\n", fault);
    return 0;
}
