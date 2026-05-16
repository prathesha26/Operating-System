#include <stdio.h>
int main() {
    int n, ct = 0;
    float tat = 0, wt = 0;
    printf("Enter number of processes:\n");
    scanf("%d", &n);

    for (int i = 0, at, bt; i < n; i++) {
        printf("Enter AT and BT for P%d:\n", i + 1);
        scanf("%d %d", &at, &bt);

        if (ct < at) ct = at;
        ct += bt;

        tat += (ct - at);
        wt += (ct - at - bt);
    }

    printf("\nAvg TAT = %.2f\nAvg WT = %.2f\n", tat/n, wt/n);
    return 0;
}
