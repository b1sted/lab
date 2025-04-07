#include <stdio.h>
#include <math.h>

// Описания функций
void InputMatrix(double[][10]);
void CalcDeviations(double[][10]);
void Output(double[][10]);

int n, m;

int main() {
    double a[10][10] = {{0.0}}; // Инициализация массива с ограничениями N <= 10, M <= 10

    // Ввод исходных данных
    printf("Введите размеры массива N и M (не более 10 и 10): ");
    scanf("%d %d", &n, &m);

    // Проверка на ограничение n <= 10
    if (n > 10 || n <= 0) {
        printf("Неверное значение n. Допустимый диапазон: 1 <= n <= 10.\n");
        return 1;
    }

    // Проверка на ограничение n <= 10
    if (m > 10 || m <= 0) {
        printf("Неверное значение m. Допустимый диапазон: 1 <= n <= 10.\n");
        return 1;
    }

    InputMatrix(a);
    CalcDeviations(a);
    Output(a);

    return 0;
}

void InputMatrix(double a[][10]) {
    printf("Введите элементы массива (%d чисел в строке): \n", m);

    for (int i = 0; i < n; i++) {
        printf("Строка %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }    
    }
}

void CalcDeviations(double a[][10]) {
    double row_avg;

    for (int i = 0; i < n; i++) {
        row_avg = 0.0;

        for (int j = 0; j < m; j++) {
            row_avg += a[i][j];
        }

        row_avg /= m;

        for (int j = 0; j < m; j++) {
            a[i][j] = fabs(a[i][j] - row_avg);
        }
    }
}

void Output(double a[][10]) {
    printf("Результат вычислений (отклонения элементов от среднего значения строки):\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.3lf ", a[i][j]);
        }
        printf("\n");
    }
}
