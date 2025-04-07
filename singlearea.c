#include <stdio.h>

int main() {
    float S = 0;
    int a, b, h;

    printf("Введите первое основание: ");
    scanf("%d", &a);
    printf("Введите второе основание: ");
    scanf("%d", &b);
    printf("Введите высоту: ");
    scanf("%d", &h);

    S = ((a + b) * h) / 2.0;
    printf("%f\n", S);

    return 0;
}
