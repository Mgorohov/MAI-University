#include<stdio.h>

int main() {
	int n, p, matrix[100][100] = {0};
	printf("Enter size of matrix: ");
	scanf("%d", &n);
	while (n <= 0) {
		printf("Have entered incorrect size\nEnter size of matrix: ");
		scanf("%d", &n);
	} 
	printf("Enter elements of matrix: ");
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &matrix[i][j]);
	printf("Original matrix:\n");
	for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                        printf("%d ", matrix[i][j]);
		printf("\n");
	}
	p = n/2;
	printf("Receivd sequence:\n");
	for (int i = 1; i <= p; i++) {
		for (int j = i - 1; j < n - i ; j++)
			printf("%d ", matrix[j][i - 1]); // левая
		for (int j = i - 1; j < n - i + 1; j++)
			printf("%d ", matrix[n-i][j]); // нижняя
		for (int j = n - i - 1; j >= i - 1; j--)
			printf("%d ", matrix[j][n - i]); //правая
		for (int j = n - i - 1; j >= i ; --j)
			printf("%d ", matrix[i-1][j]); //верхняя
	}
	if (n % 2 == 1)
		printf("%d", matrix[p][p]);
	printf("\n");
	return 0;
}
