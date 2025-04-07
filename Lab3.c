#include <stdio.h>
#include <math.h>

int main() {
    int N, a, step = 0;
    float start_x, end_x, step_x, x, y;

    printf("Введите количество расчетных точек: ");
    scanf("%d", &N);
    printf("Введите значение параметра функции: ");
    scanf("%d", &a);
    printf("Введите начальное значение аргумента: ");
    scanf("%f", &start_x);
    printf("Введите конечное значение аргумента: ");
    scanf("%f", &end_x);

    x = start_x;
    step_x = (end_x - start_x) / (N - 1);

    printf("\n%4s\t %10s %10s\n", "Номер", "Аргумент", " Функция");

    for (step = 1; step <= N; step++) {
        y = (sin(a * x) + pow(sin(a), 2)) / (4 + pow(sin(x), 2));

        printf("%4d %10.3f %10.3f\n", step, x, y);

        x += step_x;
    }
    return 0;
}
