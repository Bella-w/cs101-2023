#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char buffer[80];

void hanoi(FILE* fp, int n, char A, char B, char C) {
    static int step = 1;
    if (n == 1) {
        time_t rawtime;
        struct tm* timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "(%Y %m%d %H:%M:%S)", timeinfo);
        char sheet_name[3];
        sprintf(sheet_name, "%dP", n);
        fprintf(fp, "%d %s: %s from %c to %c\n",step, buffer, sheet_name, A, C);
        step++;
    }else{
        hanoi(fp, n - 1, A, C, B);
        char sheet_name[3];
        sprintf(sheet_name, "%dP", n);
        fprintf(fp, "%d %s: %s from %c to %c\n", step, buffer,sheet_name, A, B);
        step++;
        hanoi(fp, n - 1, B, A, C);
    }
}

int main() {
    FILE* fp = fopen("Hanoi.txt", "w");
    hanoi(fp, 20, 'A', 'B', 'C');
    fclose(fp);
    return 0;
}
