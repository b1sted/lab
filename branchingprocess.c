#include <stdio.h>
#include <math.h>

int main() {
    double x, y;

    printf("Введите значение x: ");
    scanf("%lf", &x);

    if (x <= 0) {
        y = (log10(fabs(x) / 100 - 0.01) + 2 * x) / (2 * x - 2);
    } 
    
    else {
        y = (log10(fabs(x) / 100 - 0.01) + 2 * x) / (x - 1);
    }

    printf("%lf\n", y);
    return 0;
}

/* gcc -Wall -g -o file -lm = Компиляция через gcc*/
/* 15 точек = -2 + 2/7 до 2*/
