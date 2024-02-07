//
// Created by adipe on 04/02/2024.
//

#include "my_mat.h"

int distancesMatrix[MATRIX_SIZE][MATRIX_SIZE] = {0};
// int paths[MATRIX_SIZE][MATRIX_SIZE] = {0}; only if actual path is needed
void floydWarshall(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


void getMatrix(int mat[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    floydWarshall(mat);
    
    
    
}

void doesPathExist(int i, int j) {
    if (distancesMatrix[i][j] != 0&&distancesMatrix[i][j]!=INF) printf("True\n");
    else printf("False\n");
}

void shortestPath(int i, int j) {
    if (distancesMatrix[i][j] != 0&&distancesMatrix[i][j]!=INF) {
        printf("%d\n", distancesMatrix[i][j]);
//        while (i != j) {     only if actual path is needed
//            printf("%d --> ", i);
//            i = paths[i][j];
//        }
//        printf("%d\n", j);
    } else
        printf("-1\n");


}


void floydWarshall(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    // Initialize the distance matrix

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j]==0&&i!=j)
            {
               /* code */
               distancesMatrix[i][j] = INF; /* code */
            }
            

            else {
                distancesMatrix[i][j] = matrix[i][j];
            }
            // if (matrix[i][j] != 0 && i != j) only if actual path is needed
            //     paths[i][j] = j;
            // else
            //     paths[i][j] = -1; only if actual path is needed
        }
    }

    // Compute shortest paths using flloyd warshall algorithm
    for (int k = 0; k < MATRIX_SIZE; k++) { 
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                  if (distancesMatrix[i][k]!=INF&&distancesMatrix[k][j]!=INF&& distancesMatrix[i][k]+distancesMatrix[k][j] <distancesMatrix[i][j]) {
                    distancesMatrix[i][j] = distancesMatrix[i][k] + distancesMatrix[k][j];
                    // paths[i][j] = paths[i][k]; if actual path is needed
                }
            }
        }
    }
}
