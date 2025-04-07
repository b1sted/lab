#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    double x, y, product_part;

    // Ввод значений n и x от пользователя
    printf("Введите значение n: ");
    scanf("%d", &n);
    printf("Введите значение x: ");
    scanf("%lf", &x);

    // ПЛА: вычисление постоянных значений
    y = 2.4 * sin(x);

    // ЦА: основной цикл для произведения
    product_part = 1.0;  // Начинаем с 1, так как это произведение
    for (i = 6; i <= n; i++) {
        product_part += x + i;
        // product_part *= (x / (double)(x + 1)) + ((i * i) / (double)(1 + i * i));
    }

    // ЗЛА: добавление постоянного значения к результату произведения
    y += product_part;

    // Выводим результат с округлением до двух знаков после запятой
    printf("Результат y = %.2f\n", y);

    return 0;
}
