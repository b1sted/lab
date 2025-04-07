#include <stdio.h>
#include <math.h>

double sum_of_series(int start, int end, int a, int b) {
    double sum = 0;

    for (int k = start; k <= end; k++) {
        sum += pow(a * k + b, 2);
    }

    return sum;
}

int main() {
    int a, b, start, end;
    double S[3], y;

    for (int i = 0; i < 3; i++) {
        printf("Введите данные для набора %d: \n", i + 1);
        printf("a: ");
        scanf("%d", &a);
        printf("b: ");
        scanf("%d", &b);
        printf("start: ");
        scanf("%d", &start);
        printf("stop: ");
        scanf("%d", &end);

        S[i] = sum_of_series(start, end, a, b);
    }

    y = (a * S[0]) / (1 + 2 * S[1] + 3 * S[2]);

    printf("Значение y: %.3f\n", y);
    
    return 0;
}