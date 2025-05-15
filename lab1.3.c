#include <stdio.h>

int main() {
    int N, M;
     
    printf("morin too: ");
    scanf("%d", &N);
    printf("baganin too: ");
    scanf("%d", &M);

    int table[N][M];  
    int row_s[N];   
    int col_s[M];
    for (int i = 0; i < N; i++) {
        row_s[i] = 0;
    }
    for (int j = 0; j < M; j++) {
        col_s[j] = 0;
    }
    
    printf("elementvvdig oruul:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("table[%d][%d] = ", i, j);
            scanf("%d", &table[i][j]);
            row_s[i] += table[i][j]; 
            col_s[j] += table[i][j]; 
        }
    }
    printf("moruudin niilber:\n");
    for (int i = 0; i < N; i++) {
        printf("mor %d: %d\n", i + 1, row_s[i]);
    }
    
    printf("baganuudin niilber:\n");
    for (int j = 0; j < M; j++) {
        printf("bagana %d: %d\n", j + 1, col_s[j]);
    }
    
    return 0;
}
