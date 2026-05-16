#include <stdio.h>
int main() {
    int n, tq, time = 0, done = 0;
    scanf("%d %d", &n, &tq);

    int at[n], bt[n], rem[n], ct[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }

    while (done < n) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (rem[i] > 0 && at[i] <= time) {
                flag = 1;
                if (rem[i] <= tq) {
                    time += rem[i];
                    ct[i] = time;
                    rem[i] = 0;
                    done++;
                } else {
                    time += tq;
                    rem[i] -= tq;
                }
            }
        }
        if (!flag) time++;
    }

    float tat = 0, wt = 0;
    for (int i = 0; i < n; i++) {
        tat += ct[i] - at[i];
        wt += ct[i] - at[i] - bt[i];
    }

    printf("Avg TAT=%.2f\nAvg WT=%.2f", tat/n, wt/n);
}
