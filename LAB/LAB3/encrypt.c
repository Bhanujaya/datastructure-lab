#include <stdio.h>

int main() {
    int col, row, i , j, new_num;
    scanf("%d %d", &row, &col);
    int array[row][col];
    int check[col];

    for (i = 0 ; i < row ; i++ ) {
        for (j = 0 ; j < col; j++ ) {
            scanf("%d", &(array[i][j]));

        }
    }

    for (i = 0 ; i < row-1 ; i++ ) {
        for (j = 0 ; j < col; j++ ) {
            if (i ==0 ) {
                new_num = array[i][j];
                check[j] = array[i+1][new_num-1];
        
            } else {
                new_num = check[j];
                check[j] = array[i+1][new_num-1];

            }

        }
    }

    for (j = 0; j < col ; j++) {
        printf("%d ",check[j]);
    }



}