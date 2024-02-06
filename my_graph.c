#include <stdio.h>
#include "my_mat.h"

int main() {
    char action;
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {0};
   
    scanf("%c",&action);
    while (action != 'D' || action != EOF) {
        if (action == 'A') {
            getMatrix(matrix);
        }
        else if(action =='B'){
            int i =0,j =0;
            scanf("%d",&i);
            scanf("%d",&j);
            doesPathExist(i,j);
        }
        else if (action == 'C') {
            int i = 0, j = 0;
            scanf("%d",&i);
            scanf("%d",&j);
            shortestPath(i,j);
        }

        scanf("%c",&action);
    }
    return 0;
}
