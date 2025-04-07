#include <stdio.h>
#include <math.h>

#define START -2.0
#define FINISH 2
#define TCOUNT 15

int main() {
    double x = -2, y, truestep;
    int step = 0;

    truestep = ((FINISH - START) / (TCOUNT - 1));

    for (x = -2.0; x <= 2.0; x = x + truestep) {
        step ++;

        if (x <= 0) {
            y = (log10(fabs(x) / 100 - 0.01) + 2 * x) / (2 * x - 2); /* график существует до (-∞; -1] */
        } 
    
        else {
            y = (log10(fabs(x) / 100 - 0.01) + 2 * x) / (x - 1); /* график существует с (1; +∞) */
        }

        printf("%d %lf %lf\n", step, x, y);
    }
    return 0;
}

/* gcc -Wall -g -o file -lm = Компиляция через gcc*/
/* 15 точек = -2 + 2/7 до 2*/
