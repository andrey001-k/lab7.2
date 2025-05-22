#include <iostream>
#include <vector>
using namespace std;

// Функція для виводу матриці на екран
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// Завдання 1: Знайти номер першого стовпця, містить лише непарні числа
int findFirstOddColumn(const vector<vector<int>>& matrix) {
    int m = matrix.size();    // Кількість строк
    if (m == 0) return 0;     // Перевірка на пусту матриці

    int n = matrix[0].size(); // Кількість стовпців

    // Перевірка кожного стовпця
    for (int j = 0; j < n; j++) {
        bool allOdd = true;

        // Перевірка, чи є всі елементи стовпця непарними
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] % 2 == 0) { // Якщо знайдено парне число
                allOdd = false;
                break;
            }
        }

        // Якщо всі числа у стовпці непарні, повертаємо номер стовпця (с 1)
        if (allOdd) {
            return j + 1; // Повертаємо номер стовпця (нумерація с 1)
        }
    }

    // Якщо не знайдено стовпця з тільки непарними числами
    return 0;
}

// Завдання 2: Видалити стовпець K із матриці
vector<vector<int>> deleteColumn(const vector<vector<int>>& matrix, int k) {
    int m = matrix.size();    // Кількість строк
    if (m == 0) return {};    // Перевірка на пусту матрицю

    int n = matrix[0].size(); // Кількість стовпців

    // Перевірка, чи знаходиться K у допустимих межах
    if (k < 1 || k > n) {
        cout << "Error: K must be between 1 and " << n << endl;
        return matrix;
    }

    // Створюємо нову матрицю з кількістю стовпців на 1 менше
    vector<vector<int>> result(m, vector<int>(n - 1));

    // Копируємо елементи із ісходної матриці, пропускаючи стовпець K
    for (int i = 0; i < m; i++) {
        for (int j = 0, newCol = 0; j < n; j++) {
            if (j != k - 1) { // k-1, так як нумерація стовбців у задачі з 1, а в C++ з 0
                result[i][newCol++] = matrix[i][j];
            }
        }
    }

    return result;
}

int main() {
    
    int choice;
    bool continueProgram = true;

    while (continueProgram) {
        cout << "\n=== PROGRAM MENU ===" << endl;
cout << "Select a task:\n";
cout << "1 - Find the number of the first column with odd numbers\n";
cout << "2 - Remove column K from the matrix\n";
cout << "0 - Exit the program\n";
cout << "Your choice: ";
cin >> choice;

        if (choice == 0) {
            continueProgram = false;
            cout << "The program is complete." << endl;
            continue;
        }

        if (choice != 1 && choice != 2) {
            cout << "Invalid task selection! Please select 1, 2 or 0 to exit.\n" << endl;
            continue;
        }

        int m, n;
cout << "Enter the matrix dimensions (M and N): ";
cin >> m >> n;

        // Перевірка коректності ведених розмірів
        if (m <= 0 || n <= 0) {
            cout << "Error: matrix dimensions must be positive numbers" << endl;
            continue;
        }

        // Створення матриці
        vector<vector<int>> matrix(m, vector<int>(n));

        cout << "Enter the matrix elements:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << "\nOriginal matrix:" << endl;
        printMatrix(matrix);

        if (choice == 1) {
            // Завдання 1: Пошук першого стовпця з непарними числами
            int result = findFirstOddColumn(matrix);
            cout << "\nThe number of the first column containing only odd numbers: " << result;
            if (result == 0) {
                cout << " (there are no such columns)";
            }
            cout << endl;
        }
        else if (choice == 2) {
            // Завдання 2: Видалення стовпця K
            int k;
            cout << "\nEnter column number K to delete (1 <= K <= " << n << "): ";
            cin >> k;

            // Перевірка, чи знаходиться K у допустимих межах
            if (k < 1 || k > n) {
                cout << "Error: K must be between 1 and" << n << endl;
                continue;
            }

            vector<vector<int>> result = deleteColumn(matrix, k);

            cout << "\nMatrix after removing a column " << k << ":" << endl;
            printMatrix(result);
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(); // Очищення буфера
        cin.get();    // Очікування натискання клавіш
    }

    return 0;
} 
