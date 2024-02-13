#include <iostream>
#include <stdlib.h>

#define ROW 5
#define COLUMN 5

int count_of_object(int matrix[ROW][COLUMN]);
void dfs(int matrix[ROW][COLUMN], int row, int column, int i, int j);

int main()
{
    int matrix[ROW][COLUMN] = {
        {1, 1, 0, 0, 1},
        {1, 0, 1, 1, 0},
        {0, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 1, 0, 0}
    };

    int count = count_of_object(matrix);

    std::cout << count;

}

int count_of_object(int matrix[ROW][COLUMN])
{
    int objects = 0;

    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COLUMN; ++j)
        {
            if(matrix[i][j] == 1)
            {
                ++objects;
                dfs(matrix, ROW, COLUMN, i, j);
            }
        }
    }

    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COLUMN; ++j)
        {
            if (matrix[i][j] == 2)
            {
                matrix[i][j] = 1;
            }
        }
    }
    return objects;
}

void dfs(int matrix[ROW][COLUMN], int row, int column, int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= column || matrix[i][j] == 0 || matrix[i][j] == 2)
    {
        return;
    }

    matrix[i][j] = 2;

    dfs(matrix, row, column, i + 1, j);
    dfs(matrix, row, column, i - 1, j);
    dfs(matrix, row, column, i, j + 1);
    dfs(matrix, row, column, i, j - 1);
    return;
}