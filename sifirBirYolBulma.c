#include <stdio.h>
#include <stdlib.h>

#define MATRIXSIZE 10

int process(int matrix[MATRIXSIZE][MATRIXSIZE], int x, int y, size_t count);

void setMatrix(int matrix[MATRIXSIZE][MATRIXSIZE]);

int main(){
    int matrix[MATRIXSIZE][MATRIXSIZE];
    //x row y is column
    int x = 0 , y = 0;
    size_t countStep = 0;
    setMatrix(matrix);
    int count = process(matrix, x, y, countStep);
    if(count != 0){
        printf("\n%d step need to reach location of [9][9]", count);
    }
    return 0;
}
void setMatrix(int matrix[MATRIXSIZE][MATRIXSIZE]){
    for(int i = 0; i < MATRIXSIZE; i++){
        for(int j = 0; j <MATRIXSIZE; j++){
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = 1; matrix[1][0] = 1; matrix[2][0] = 1;
    matrix[2][1] = 1; matrix[2][1] = 1; matrix[2][1] = 1;
    matrix[2][1] = 1; matrix[2][2] = 1; matrix[2][3] = 1;
    matrix[3][3] = 1; matrix[4][3] = 1; matrix[5][3] = 1;
    matrix[5][2] = 1; matrix[5][1] = 1; matrix[6][1] = 1;
    matrix[7][1] = 1; matrix[7][2] = 1; matrix[7][3] = 1;
    matrix[7][4] = 1; matrix[7][5] = 1; matrix[7][6] = 1;
    matrix[6][6] = 1; matrix[5][6] = 1; matrix[4][6] = 1;
    matrix[3][6] = 1; matrix[2][6] = 1; matrix[1][6] = 1;
    matrix[1][5] = 1; matrix[1][4] = 1; matrix[1][7] = 1;
    matrix[1][8] = 1; matrix[1][9] = 1; matrix[5][7] = 1;
    matrix[5][8] = 1; matrix[4][6] = 1; matrix[6][8] = 1;
    matrix[7][8] = 1; matrix[8][8] = 1; matrix[9][8] = 1;
    matrix[9][9] = 1; //matrix[9][9] = 0;
    
    printf("current location is: [0][0]");
    for(int i = 0; i < MATRIXSIZE; i++){
        printf("\n");
        for(int j = 0; j <MATRIXSIZE; j++){
            printf(" %d ", matrix[i][j]);
        }
    }
}

int process(int matrix[MATRIXSIZE][MATRIXSIZE], int x, int y, size_t count){
    //--------------RIGHT------------------
    if( (y+1 < MATRIXSIZE) && matrix[x][y+1] == 1){ 
        ++count;
        matrix[x][y] = -1; 
        y = y+1;
        if(x == (int)MATRIXSIZE-1 && y == (int)MATRIXSIZE-1)
            return count;
        return process(matrix, x, y, count);
    }
    //--------------LEFT--------------------
    else if(y-1 >= 0 && matrix[x][y-1] == 1){ 
        ++count;
        matrix[x][y] = -1; 
        y = y-1;
        if(x == MATRIXSIZE-1 && y == MATRIXSIZE-1)
            return count;
        return process(matrix, x, y, count);
    }
    //-----------------UP--------------------
    else if(x-1 >= 0 && matrix[x-1][y] == 1){ 
        ++count;
        matrix[x][y] = -1; 
        x = x-1;
        if(x == MATRIXSIZE-1 && y == MATRIXSIZE-1)
            return count;
        return process(matrix, x, y, count);
    }
    //---------------DOWN-------------------
    else if(x+1 < MATRIXSIZE && matrix[x+1][y] == 1){ 
        ++count;
        matrix[x][y] = -1; 
        x = x+1;
        if(x == MATRIXSIZE-1 && y == MATRIXSIZE-1)
            return count;
        return process(matrix, x, y, count);
    }
    else {
        printf("\nthere is no exit way");
        return 0;
    }
}