#include <stdio.h>

int main() {
    int n = 5;

    int pid[] = {0, 1, 2, 3, 4};
    int at[]  = {0, 1, 2, 3, 4};
    int bt[]  = {5, 7, 6, 2, 4};

    int ct[5], tat[5], wt[5];

    // whwn the first process arrives, it starts executing immediately, so its CT is simply AT + BT
    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i - 1] + bt[i];
    }

    // we know that TAT = CT - AT and WT = TAT - BT
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }
    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]); 
    }
    // for average TAT and WT we divide the total TAT and WT by the number of processes
    printf("\nAverage TAT = %.2f", total_tat / n);
    printf("\nAverage WT  = %.2f\n", total_wt / n);
    return 0;
}
