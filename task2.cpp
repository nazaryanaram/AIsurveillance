#include <iostream>
#include <stdlib.h>

void initalization_matrix (int** matrix, int row, int column);
void print_matrix (int** matrix, int row, int column);
void reverse_matrix (int** matrix, int row, int column);
void invert_matrix (int** matrix, int row, int column);
void reInserted_matrix (int** matrix, int row, int column);

int main()
{
    int row = 0;
    int column = 0;

    do {
        std::cout << "Enter row: ";
        std::cin >> row;
        std::cout << "Enter column: ";
        std::cin >> column;

        if (row < 0 || column < 0)
        {
            std::cout << "Invalid input" << std::endl;
        }
    } while (row < 0 || column < 0);

    int** matrix = (int**) malloc(row * sizeof(int*));

    for (int i = 0; i < row; ++i)
    {
        matrix[i] = (int*) malloc(column * sizeof(int));
    }

    initalization_matrix(matrix, row, column);
    std::cout << "\tNormal matrix" << std::endl;
    print_matrix(matrix, row, column);
    std::cout << std::endl;
    reInserted_matrix(matrix, row, column);
    std::cout << "\tReinserted matrix" << std::endl;
    print_matrix(matrix, row, column);
    return 0;
}

void reInserted_matrix(int** matrix, int row, int column)
{
    reverse_matrix(matrix, row, column);
    invert_matrix(matrix, row, column);
    return;
}

void initalization_matrix (int** matrix, int row, int column)
{
    srand(time(0));
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = 0 + rand() % 2;
        }
    }
    return;
}

void print_matrix(int** matrix, int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        std::cout << std::endl;
        for (int j = 0; j < column; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
    }
}

void reverse_matrix(int** matrix, int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column / 2; ++j)
        {                           
            int tmp = matrix[i][j];                     
            matrix[i][j] = matrix[i][column - j - 1];
            matrix[i][column - j - 1] = tmp;
        }
    }
    return;
}

void invert_matrix(int** matrix, int row, int column)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            matrix[i][j] = !matrix[i][j];
        }
    }
    return;
}
