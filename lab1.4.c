#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
int main() {
    int N, M;
    printf("Мөрийн тоо (N): ");
    scanf("%d", &N);
    printf("Баганын тоо (M): ");
    scanf("%d", &M);


    int** table = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        table[i] = (int*)malloc(M * sizeof(int));
    }


    int max_even = INT_MIN; 
    int max_odd = INT_MIN; 


    printf("Элементүүдийг оруулна уу:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("table[%d][%d] = ", i, j);
            scanf("%d", &table[i][j]);

 
            if (table[i][j] % 2 == 0) {
                if (table[i][j] > max_even) {
                    max_even = table[i][j];
                }
            } else { 
                if (table[i][j] > max_odd) {
                    max_odd = table[i][j];
                }
            }
        }
    }

    printf("Хамгийн их тэгш тоо: ");
    if (max_even == INT_MIN) {
        printf("Тэгш тоо олдсонгүй.\n");
    } else {
        printf("%d\n", max_even);
    }

    printf("Хамгийн их сондгой тоо: ");
    if (max_odd == INT_MIN) {
        printf("Сондгой тоо олдсонгүй.\n");
    } else {
        printf("%d\n", max_odd);
    }

 
    for (int i = 0; i < N; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}
