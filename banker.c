#include <stdio.h>

int main() {
    int n, r;
    scanf("%d %d", &n, &r);

    int alloc[n][r], max[n][r], need[n][r], avail[r], finish[n], seq[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    for (int j = 0; j < r; j++) scanf("%d", &avail[j]);

    for (int i = 0; i < n; i++) finish[i] = 0;

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int ok = 1;
                for (int j = 0; j < r; j++)
                    if (need[i][j] > avail[j]) ok = 0;

                if (ok) {
                    for (int j = 0; j < r; j++)
                        avail[j] += alloc[i][j];
                    seq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    if (count == n) {
        printf("Safe\n");
        for (int i = 0; i < n; i++) printf("P%d ", seq[i]);
    } else {
        printf("Not Safe");
    }

    return 0;
}
