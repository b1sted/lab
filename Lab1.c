#include <stdio.h>
#include <math.h>

int main() {
    float x, a, b, y, z;

    printf("Введите значение x: ");
    scanf("%f", &x);
    printf("Введите значение a: ");
    scanf("%f", &a);
    printf("Введите значение b: ");
    scanf("%f", &b);

    y = x + 5.3;
    y = (1 + log(y)) / y;
    printf("\n%s %lf\n", "Результат вычисления функции y:", y);

    z = sqrt(y + 15 * sin(a));
    z = z / (z + 2 * b);
    printf("%s %lf\n", "Результат вычисления функции z:", z);

    return 0;
}
