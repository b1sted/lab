#include <stdio.h>

int main() {
	int count;

	for (count = 0; count <= 2; count ++) {
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
	}
	return 0;
}
