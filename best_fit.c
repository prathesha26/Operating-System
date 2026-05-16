#include <stdio.h>

int main() {
    int m;
    printf("Enter number of memory blocks:\n");
    scanf("%d", &m);

    int block[m], remaining[m];

    printf("Enter size of each block:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &block[i]);
        remaining[i] = block[i];
    }

    int n;
    printf("Enter number of processes:\n");
    scanf("%d", &n);

    int process[n];

    printf("Enter size of each process:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &process[i]);
    }

    for(int i = 0; i < n; i++) {
        int best = -1;

        for(int j = 0; j < m; j++) {
            if(remaining[j] >= process[i]) {
                if(best == -1 || remaining[j] < remaining[best]) {
                    best = j;
                }
            }
        }

        if(best != -1) {
            printf("Process %d of size %d is allocated to Block %d of size %d with Fragment %d\n",
                   i+1, process[i], best+1, block[best], remaining[best] - process[i]);

            remaining[best] -= process[i];
        } else {
            printf("Process %d of size %d is not allocated\n", i+1, process[i]);
        }
    }

    return 0;
}