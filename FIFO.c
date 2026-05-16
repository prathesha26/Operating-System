#include <stdio.h>

int main() {
    int pages, frames;

    printf("Enter number of pages in reference string: \n");
    scanf("%d", &pages);

    int ref[pages];

    printf("Enter the reference string: \n");
    for(int i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    printf("Enter number of frames: \n");
    scanf("%d", &frames);

    int frame[frames];

    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    int index = 0;
    int faults = 0, hits = 0;

    for(int i = 0; i < pages; i++) {
        int found = 0;

        for(int j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        if(!found) {
            frame[index] = ref[i];
            index = (index + 1) % frames;
            faults++;
        }
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);

    return 0;
}