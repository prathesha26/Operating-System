#include <stdio.h>

int main() {
    int n, ct[20], tat[20], wt[20], at[20], bt[20], done[20] = {0};
    printf("Enter number of processes:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d:\n", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time &&
               (idx == -1 || bt[i] < bt[idx]))
                idx = i;
        }

        if (idx == -1) { time++; continue; }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        done[idx] = 1;
        completed++;
    }

    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    printf("\nAvg TAT = %.2f\nAvg WT = %.2f\n", avg_tat / n, avg_wt / n);
    return 0;
}
