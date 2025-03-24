#include <iostream>

const int M = 20, N = 20;

void printMatrix(int matr1[][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << matr1[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int findFirstOddColumn(int matr1[][N], int row, int col) {
    for (int j = 0; j < col; j++) {
        bool allOdd = true;
        for (int i = 0; i < row; i++) {
            if (matr1[i][j] % 2 == 0) {
                allOdd = false;
                break;
            }
        }
        if (allOdd) return j + 1; // Повертаємо номер стовпця (від 1)
    }
    return 0;
}

void deleteColumn(int matr1[][N], int& row, int& col, int K) {
    if (K < 1 || K > col) {
        std::cout << "Неправильний номер стовпця!" << std::endl;
        return;
    }

    for (int i = 0; i < row; i++) {
        for (int j = K - 1; j < col - 1; j++) {
            matr1[i][j] = matr1[i][j + 1];
        }
    }
    col--; // Зменшуємо кількість стовпців
}

int main() {
    int row, col, K;
    std::cout << "Введіть кількість рядків (2-20): ";
    std::cin >> row;
    std::cout << "Введіть кількість стовпців (2-20): ";
    std::cin >> col;

    if (row < 2 || row > 20 || col < 2 || col > 20) {
        std::cout << "Помилка: невірні розміри матриці!" << std::endl;
        return 1;
    }

    int matr1[M][N];

    std::cout << "Введіть елементи матриці:" << std::endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cin >> matr1[i][j];
        }
    }

    std::cout << "Початкова матриця:" << std::endl;
    printMatrix(matr1, row, col);

    int firstOddColumn = findFirstOddColumn(matr1, row, col);
    std::cout << "Номер першого стовпця з непарними числами: " << firstOddColumn << std::endl;

    std::cout << "Введіть номер стовпця для видалення (1-" << col << "): ";
    std::cin >> K;

    deleteColumn(matr1, row, col, K);

    std::cout << "Матриця після видалення стовпця " << K << ":" << std::endl;
    printMatrix(matr1, row, col);

    return 0;
}
