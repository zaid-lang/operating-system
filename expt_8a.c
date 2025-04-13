/* 
==================
Experiment 8a: FIFO Page Replacement
Simulates FIFO page replacement.
Input: Number of frames, length of page reference string, and the reference string.
Output: Frame contents after each access and total page faults.
==================
*/

#include <stdio.h>
#include <stdlib.h>
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
    for (int i = 0; i < refCount; i++) {
        scanf("%d", &refs[i]);
    }
    
    int frameArr[frames], fault = 0, front = 0;
    for (int i = 0; i < frames; i++)
        frameArr[i] = -1;
    
    printf("\nFIFO Page Replacement:\n");
    for (int i = 0; i < refCount; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frameArr[j] == refs[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frameArr[front] = refs[i];
            front = (front + 1) % frames;
            fault++;
        }
        printf("After accessing %d: ", refs[i]);
        for (int j = 0; j < frames; j++) {
            printf("%d ", frameArr[j]);
        }
        printf("\n");
    }
    
    printf("Total Page Faults: %d\n", fault);
    return 0;
}
