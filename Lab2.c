#include <stdio.h>
#include <math.h>

int main() {
    float x, y;

    printf("Введите значение x: ");
    scanf("%f", &x);

    if (x <= 4)
        y = (cos(x) + 14) / (sin(x) + 15);
    else if (x < 12 && x > 4)
        y = pow(x + log(fabs(x - 8)), 1.0/3.0);
    else if (x < 38 && x >= 12)
        y = sqrt(x - 13);
    else if (x >= 38)
        y = 5 * x;
    
    printf("\n%s %lf\n", "Результат вычисления функции y:", y);
    return 0;
}
