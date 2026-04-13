#include <stdio.h>

int main() {
    int n = 5;
    int pid[] = {0, 1, 2, 3, 4};
    int at[]  = {0, 0, 0, 0, 0};
    int bt1[] = {5, 7, 6, 8, 5};
    int io[]  = {2, 2, 3, 1, 2};
    int bt2[] = {3, 2, 4, 2, 5};

    int ct[5], tat[5], wt[5];
    int time = 0;
    // when forst process arrives,
    for (int i = 0; i < n; i++) {
        time += bt1[i];
    }

    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        // first CPU + I/O + second CPU
        ct[i] = time + io[i] + bt2[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - (bt1[i] + bt2[i]);

        total_tat += tat[i];
        total_wt += wt[i];
    }
    printf("\nPID\tBT1\tIO\tBT2\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], bt1[i], io[i], bt2[i],
               ct[i], tat[i], wt[i]);
    }
     // we calculate average TAT and WT by dividing the total TAT and WT by the number of processes
    printf("\nAverage TAT = %.2f", total_tat / n);
    printf("\nAverage WT  = %.2f\n", total_wt / n);

    return 0;
}
