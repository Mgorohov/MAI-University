#include<stdio.h>

int main() {
	int k = -1, str = 0, stb = 0, n, max = 0, matrix[100][100] = {0};
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
	max = matrix[0][0];
	for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                        if (matrix[i][j] > max) {
				max = matrix[i][j];
				str = i;
				stb = j;
			}
	}
	for (int i = str + 1; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                        if (matrix[i][j] == max && k != i) {
                                for(int k = 0; k < n; k++) {
					matrix[str][k] += matrix[i][k];
				}
				k = i;
			}
        }
	printf("Received matrix:\n");
//	printf("Строка: %d, столбец :%d\n", str + 1, stb + 1);
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j)
                        printf("%d ", matrix[i][j]);
                printf("\n");
        }
	return 0;
}
