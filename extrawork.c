#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double x, y = 0.0, sum_part = 0.0, product_part = 1.0;

    // Ввод значений n и x от пользователя
    printf("Введите значение n: ");
    scanf("%d", &n);
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // Цикл для суммы
    for (i = 1; i <= n; i++) {
        sum_part += (i * i + 2);
    }

    // Цикл для произведения
    for (i = 1; i <= n; i++) {
        product_part *= (2 * i + 2);
    }

    // Вычисление окончательного значения y
    y = sum_part + product_part * 3;

    // Выводим результат
    printf("Результат y = %.2f\n", y);

    return 0;
}
