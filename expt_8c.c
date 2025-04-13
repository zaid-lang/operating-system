/* 
==================
Experiment 8c: NRU (Not Recently Used) Page Replacement
Simulates NRU replacement by randomly selecting from pages with useBit == 0.
Input: Number of frames and page reference string.
Output: Frame contents and total page faults.
==================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    
    int frameArr[frames], useBit[frames], fault = 0;
    for (int i = 0; i < frames; i++) {
        frameArr[i] = -1;
        useBit[i] = 0;
    }
    
    srand(time(NULL));
    printf("\nNRU Page Replacement:\n");
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
            int candidates[frames], count = 0;
            for (int j = 0; j < frames; j++) {
                if (frameArr[j] == -1 || useBit[j] == 0)
                    candidates[count++] = j;
            }
            int replaceIndex = (count > 0) ? candidates[rand() % count] : 0;
            frameArr[replaceIndex] = refs[i];
            useBit[replaceIndex] = 1;
            fault++;
        }
        // Reset use bits periodically every 5 references
        if ((i+1) % 5 == 0)
            for (int j = 0; j < frames; j++)
                useBit[j] = 0;
        
        printf("After accessing %d: ", refs[i]);
        for (int j = 0; j < frames; j++)
            printf("%d ", frameArr[j]);
        printf("\n");
    }
    
    printf("Total Page Faults: %d\n", fault);
    return 0;
}
