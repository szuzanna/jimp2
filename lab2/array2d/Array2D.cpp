//
// Created by Zuzanna on 08.03.2018.
//

#include "Array2D.h"



int **Array2D(int n_rows, int n_columns){

    if(n_columns <= 0 || n_rows <= 0) {
        return nullptr;
    }

    int **array = NewArray2D(n_rows, n_columns);

    FillArray2D(n_rows, n_columns, array);
    return array;
}


void FillArray2D(int n_rows, int n_columns, int *const *array) {
    for(int i = 0; i < n_rows; ++i){
        for(int j = 0; j<n_columns; ++j){
            array[i][j] = (i*n_columns +j +1);
        }
    }
}


int **NewArray2D(int n_rows, int n_columns) {
    int ** array = new int *[n_rows];

    for(int i = 0; i < n_rows; ++i){
        array[i] = new int [n_columns];
    }
    return array;
}


void DeleteArray2D(int **array, int n_rows, int n_columns){
    for (int i = 0; i<n_rows; ++i){
        delete [] array[i];
    }
    delete [] array;
}