#include <stdio.h>
#include <math.h>

int main() {
    double x;
    int n, m;

    // Ввод значений n, m и x
    printf("Введите значение x: ");
    scanf("%lf", &x);
    printf("Введите значение n (количество итераций для S): ");
    scanf("%d", &n);
    printf("Введите значение m (количество итераций для S1 и S2): ");
    scanf("%d", &m);

    // Вычисление суммы S1
    double S1 = 0.0;
    for (int j = 1; j <= m; j++) {
        S1 += pow((2 * j + 1), 2);
    }

    // Вычисление результата
    double y = 0.0;
    for (int i = 1; i <= n; i++) {
        double S2 = 0.0;
        for (int k = 1; k <= m; k++) {
            S2 += pow((i + 2 * k), 3);
        }
        y += (0.5 * x + S1) / (x + S2);
    }

    printf("Результат: y = %.4f\n", y);
    return 0;
}
