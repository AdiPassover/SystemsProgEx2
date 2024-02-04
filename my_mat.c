//
// Created by adipe on 04/02/2024.
//

#include "my_mat.h"

int distancesMatrix[MATRIX_SIZE][MATRIX_SIZE] = {0};
int paths[MATRIX_SIZE][MATRIX_SIZE] = {0}; //to check if we need to print the path or only the cost
void floydWarshall(int matrix[MATRIX_SIZE][MATRIX_SIZE]);


void getMatrix(int mat[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            scanf("%d",&mat[i][j]);
        }
    }
    floydWarshall(mat);
}

void doesPathExist(int i, int j) {
    if (distancesMatrix[i][j]!=0) printf("True");
    else printf("False");
}

void shortestPath(int i, int j) {
    if (distancesMatrix[i][j]!=0) printf("%d", distancesMatrix[i][j]);
    else
        printf("-1");

//    while(i!=j){
//        printf("%d -->",i);
//        i = paths[i][j];
//    }
//    printf("%d",j);
}


void floydWarshall(int matrix[MATRIX_SIZE][MATRIX_SIZE]){
    // Initialize the distance matrix
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            distancesMatrix[i][j] = matrix[i][j];
            if (matrix[i][j] != 0 && i != j) //to check if we need to print the path or only the cost
                paths[i][j] = j;
            else
                paths[i][j] = -1;//to check if we need to print the path or only the cost
        }
    }

    // Compute shortest paths
    for (int k = 0; k < MATRIX_SIZE; k++) {
        for (int i = 0; i < MATRIX_SIZE; i++) {
            for (int j = 0; j < MATRIX_SIZE; j++) {
                if (distancesMatrix[i][k] != 0 && distancesMatrix[k][j] != 0 && distancesMatrix[i][k] + distancesMatrix[k][j] < distancesMatrix[i][j]) {
                    distancesMatrix[i][j] = distancesMatrix[i][k] + distancesMatrix[k][j];
                    paths[i][j] = paths[i][k]; //to check if we need to print the path or only the cost
                }
            }
        }
    }
}
