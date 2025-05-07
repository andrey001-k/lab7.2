#include <iostream>
#include <vector>
using namespace std;

// Функция для вывода матрицы на экран
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// Задание 1: Найти номер первого столбца, содержащего только нечетные числа
int findFirstOddColumn(const vector<vector<int>>& matrix) {
    int m = matrix.size();    // Количество строк
    if (m == 0) return 0;     // Проверка на пустую матрицу

    int n = matrix[0].size(); // Количество столбцов

    // Проверка каждого столбца
    for (int j = 0; j < n; j++) {
        bool allOdd = true;

        // Проверка, являются ли все элементы столбца нечетными
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] % 2 == 0) { // Если найдено четное число
                allOdd = false;
                break;
            }
        }

        // Если все числа в столбце нечетные, возвращаем номер столбца (с 1)
        if (allOdd) {
            return j + 1; // Возвращаем номер столбца (нумерация с 1)
        }
    }

    // Если не найдено столбцов с только нечетными числами
    return 0;
}

// Задание 2: Удалить столбец K из матрицы
vector<vector<int>> deleteColumn(const vector<vector<int>>& matrix, int k) {
    int m = matrix.size();    // Количество строк
    if (m == 0) return {};    // Проверка на пустую матрицу

    int n = matrix[0].size(); // Количество столбцов

    // Проверка, находится ли K в допустимых пределах
    if (k < 1 || k > n) {
        cout << "Ошибка: K должно быть в пределах от 1 до " << n << endl;
        return matrix;
    }

    // Создаем новую матрицу с количеством столбцов на 1 меньше
    vector<vector<int>> result(m, vector<int>(n - 1));

    // Копируем элементы из исходной матрицы, пропуская столбец K
    for (int i = 0; i < m; i++) {
        for (int j = 0, newCol = 0; j < n; j++) {
            if (j != k - 1) { // k-1, так как нумерация столбцов в задаче с 1, а в C++ с 0
                result[i][newCol++] = matrix[i][j];
            }
        }
    }

    return result;
}

int main() {
    
    setlocale(LC_ALL, "Russian");

    int choice;
    bool continueProgram = true;

    while (continueProgram) {
        cout << "\n=== МЕНЮ ПРОГРАММЫ ===" << endl;
        cout << "Выберите задание:\n";
        cout << "1 - Найти номер первого столбца с нечетными числами\n";
        cout << "2 - Удалить столбец K из матрицы\n";
        cout << "0 - Выйти из программы\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        if (choice == 0) {
            continueProgram = false;
            cout << "Программа завершена." << endl;
            continue;
        }

        if (choice != 1 && choice != 2) {
            cout << "Неверный выбор задания! Пожалуйста, выберите 1, 2 или 0 для выхода.\n" << endl;
            continue;
        }

        int m, n;
        cout << "Введите размеры матрицы (M и N): ";
        cin >> m >> n;

        // Проверка корректности введенных размеров
        if (m <= 0 || n <= 0) {
            cout << "Ошибка: размеры матрицы должны быть положительными числами" << endl;
            continue;
        }

        // Создание матрицы
        vector<vector<int>> matrix(m, vector<int>(n));

        cout << "Введите элементы матрицы:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << "\nИсходная матрица:" << endl;
        printMatrix(matrix);

        if (choice == 1) {
            // Задание 1: Поиск первого столбца с нечетными числами
            int result = findFirstOddColumn(matrix);
            cout << "\nНомер первого столбца, содержащего только нечетные числа: " << result;
            if (result == 0) {
                cout << " (таких столбцов нет)";
            }
            cout << endl;
        }
        else if (choice == 2) {
            // Задание 2: Удаление столбца K
            int k;
            cout << "\nВведите номер столбца K для удаления (1 <= K <= " << n << "): ";
            cin >> k;

            // Проверка, находится ли K в допустимых пределах
            if (k < 1 || k > n) {
                cout << "Ошибка: K должно быть в пределах от 1 до " << n << endl;
                continue;
            }

            vector<vector<int>> result = deleteColumn(matrix, k);

            cout << "\nМатрица после удаления столбца " << k << ":" << endl;
            printMatrix(result);
        }

        cout << "\nНажмите Enter для продолжения...";
        cin.ignore(); // Очистка буфера
        cin.get();    // Ожидание нажатия клавиши
    }

    return 0;
}
