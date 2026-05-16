#include <stdio.h>

int main() {
    int n, t = 0, c = 0, idx;
    float tw = 0, tt = 0;

    scanf("%d", &n);
    int at[n], bt[n], pr[n], d[n];

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        d[i] = 0;
    }

    while (c < n) {
        int best = 9999;
        idx = -1;

        for (int i = 0; i < n; i++)
            if (!d[i] && at[i] <= t && pr[i] < best)
                best = pr[i], idx = i;

        if (idx == -1) { t++; continue; }

        tw += t - at[idx];
        t += bt[idx];
        tt += t - at[idx];

        d[idx] = 1;
        c++;
    }

    printf("Avg TAT = %.2f\nAvg WT = %.2f", tt/n, tw/n);
}
