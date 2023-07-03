#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define col 4
#define row pow(2,col) 

void print_table(int **gray_table){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d",gray_table[i][j]);
        }
        printf("\n");
    }
}

void decimal_to_binary(int num, int **gray_table, int pos) {
    int j = 0;
    for (int i = col - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        gray_table[pos][j++]=bit;
    }
}

void generate_gray(int **gray_table){
    for (int i = 0; i < row; i++){
        int N = i;
        int N_2 = N << 1;
        int gray = (N ^ N_2) >> 1;
        decimal_to_binary(gray,gray_table,i);
    }
}

int * get_row(int **gray_table, int id){
    return gray_table[id];
}

int main() {
    int** gray_table = malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        gray_table[i] = malloc(sizeof(int) * col);
    }

    generate_gray(gray_table);
    print_table(gray_table);

    for (int i = 0; i < row; i++) {
        free(gray_table[i]);
    }
    free(gray_table);
    
    return 0;
}