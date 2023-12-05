#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <limits>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    const int N = 100;
    int arr[N]{};

    for (int i = 0; i < N; ++i) {
        arr[i] = rand() % 199 - 99;
    }


    while (true) {
        // Выбор действия пользователем
        int choice;

        cout << "Выберите действие:" << endl;
        cout << "1. Создать массив" << endl;
        cout << "2. Отсортировать массив" << endl;
        cout << "3. Найти максимум и минимум" << endl;
        cout << "4. Вывести среднее значение максимума и минимума" << endl;
        cout << "5. Подсчитать количество элементов меньше a" << endl;
        cout << "6. Подсчитать количество элементов больше b" << endl;
        cout << "7. Поиск числа в массиве" << endl;
        cout << "8. Поменять местами элементы массива" << endl;
        cout << "9. идз" << endl;

        std::cin >> choice;

        switch (choice) {
        case 1: {
            for (int i = 0; i < N; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
              break;
        case 2: {
            int n = sizeof(arr) / sizeof(arr[0]);

            auto start = std::chrono::high_resolution_clock::now();

            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;


            cout << "Отсортированный массив: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

            cout << "Время, затраченное на сортировку: " << elapsed_seconds.count() << " секунд" << endl;
        }
              break;
        case 3:
        {
            int a = sizeof(arr) / sizeof(arr[0]);

            // Неотсортированный массив
            auto start_nesort = std::chrono::high_resolution_clock::now();
            int min_nesort = 0;
            int max_nesort = -100;

            for (int i = 0; i < a; i++) {
                if (arr[i] < min_nesort) {
                    min_nesort = arr[i];
                }
                if (arr[i] > max_nesort) {
                    max_nesort = arr[i];
                }
            }

            auto end_nesort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_unsorted = end_nesort - start_nesort;

            cout << "Неотсортированный массив - минимальное: " << min_nesort << ", максимальное: " << max_nesort << endl;
            cout << "Затраченное время для неотсортированного массива: " << elapsed_seconds_unsorted.count() << " секунд" << endl;

            // Сортировка массива
            for (int i = 0; i < a - 1; i++) {
                for (int j = 0; j < a - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            // Отсортированный массив
            auto start_sort = std::chrono::high_resolution_clock::now();
            int min_sort = arr[0];
            int max_sort = arr[a - 1];
            auto end_sort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_sorted = end_sort - start_sort;

            cout << "Отсортированный массив - минимальное: " << min_sort << ", максимальное: " << max_sort << endl;
            cout << "Затраченное время для отсортированного массива: " << elapsed_seconds_sorted.count() << " секунд" << endl;
        }
        break;
        case 4: {
            int a = sizeof(arr) / sizeof(arr[0]);

            // Неотсортированный массив
            auto start_nesort = std::chrono::high_resolution_clock::now();
            int min_nesort = 0;
            int max_nesort = -100;
            int srednee_nesort;

            for (int i = 0; i < a; i++) {
                if (arr[i] < min_nesort) {
                    min_nesort = arr[i];
                }
                if (arr[i] > max_nesort) {
                    max_nesort = arr[i];
                }
            }

            srednee_nesort = round((max_nesort + min_nesort) / 2);
            auto end_nesort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_unsorted = end_nesort - start_nesort;
            cout << "Неотсортированный массив - минимальное: " << min_nesort << ", максимальное: " << max_nesort << endl;
            cout << "Среднее значение: " << srednee_nesort << endl;
            cout << "Затраченное время для неотсортированного массива: " << elapsed_seconds_unsorted.count() << " секунд" << endl;


            // Отсортированный массив
            auto start_sort = std::chrono::high_resolution_clock::now();
            int min_sort = arr[0];
            int max_sort = arr[a - 1];
            int srednee_sort;
            srednee_sort = round((max_sort + min_sort) / 2);
            auto end_sort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_sorted = end_sort - start_sort;

            cout << "Отсортированный массив - минимальное: " << min_sort << ", максимальное: " << max_sort << endl;
            cout << "Среднее значение: " << srednee_sort << endl;
            cout << "Затраченное время для отсортированного массива: " << elapsed_seconds_sorted.count() << " секунд" << endl;


            // Индексы всех элементов равных среднему
            auto start = std::chrono::high_resolution_clock::now();
            int count = 0;
            cout << "Индексы значений, равных среднему значению: ";
            for (int i = 0; i < a; i++) {
                if (arr[i] == srednee_sort) {
                    cout << i << " ";
                    count++;
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            cout << "Количество значений: " << count << endl;
            cout << "Время, затраченное на поиск: " << elapsed_seconds.count() << " секунд" << endl;

        }
              break;
        case 5: {
            // Сортировка массива
            int a = sizeof(arr) / sizeof(arr[0]);
            for (int i = 0; i < a - 1; i++) {
                for (int j = 0; j < a - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            int number, count = 0;
            cout << "Введите число:";
            cin >> number;
            //Подсчет элементов
            for (int i = 0; i < a; i++) {
                if (arr[i] < number) {
                    count++;
                }
            }

            cout << "Количество элементов, которые меньше веденного числа: " << count << endl;

        }
              break;
        case 6: {
            // Сортировка массива
            int a = sizeof(arr) / sizeof(arr[0]);
            for (int i = 0; i < a - 1; i++) {
                for (int j = 0; j < a - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            int number, count = 0;
            cout << "Введите число:";
            cin >> number;
            //Подсчет элементов
            for (int i = 0; i < a; i++) {
                if (arr[i] > number) {
                    count++;
                }
            }

            cout << "Количество элементов, которые больше веденного числа: " << count << endl;

        }
              break;
        case 7: {
            int a = sizeof(arr) / sizeof(arr[0]);
            int x;
            cout << "Введите число для поиска: ";
            cin >> x;
            //Обычный перебор
            auto start_nesort = std::chrono::high_resolution_clock::now();
            cout << "Обычный перебор:" << endl;
            for (int i = 0; i < a - 1; i++) {
                if (arr[i] == x) {
                    cout << "Число " << x << " имеется в массиве" << endl;
                    break;
                }


            }
            auto end_nesort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_unsorted = end_nesort - start_nesort;
            cout << "Затраченное время для поиска: " << elapsed_seconds_unsorted.count() << " секунд" << endl;
            // Сортировка массива
            cout << "Бинарный поиск:" << endl;
            int b = sizeof(arr) / sizeof(arr[0]);
            for (int i = 0; i < b - 1; i++) {
                for (int j = 0; j < b - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
            auto start = std::chrono::high_resolution_clock::now();


            int left = 0;
            int right = b - 1;
            bool found = false;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == x) {
                    found = true;
                    break;
                }
                else if (arr[mid] < x) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            if (found) {
                cout << "Число " << x << " имеется в массиве" << endl;
            }
            else {
                cout << "Числа " << x << " в массиве не обнаружено" << endl;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            cout << "Время, затраченное на поиск с помощью бинарного поиска: " << elapsed_seconds.count() << " секунд" << endl;


        }
        case 8: {
            int index_1, index_2;
            cout << "Введите индексы чисел: ";
            cin >> index_1 >> index_2;

            auto start = std::chrono::high_resolution_clock::now();

            // Смена элементов
            int temp = arr[index_1];
            arr[index_1] = arr[index_2];
            arr[index_2] = temp;

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;

            cout << "Перемещение элементов заняло " << duration.count() * 1000 << " миллисекунд" << std::endl;

            cout << "Массив после перемещения: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }

        }
        case 9: {
            int n = sizeof(arr) / sizeof(arr[0]);
            cout << "Изначальный массив: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << "Введите число: ";
            int number;
            cin >> number;
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 != 0) {
                    arr[i] -= number; // уменьшаем нечетный элемент на введенное значение (5 в данном случае)
                    arr[i] *= (rand() % 9) + 1; // умножаем на случайное число от 1 до 9
                }
            }
            cout << "Полученный массив: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }

            int count[10] = { 0 };

            for (int i = 0; i < n; i++) {
                for (int j = 1; j <= 9; j++) {
                    if (arr[i] % j == 0) {
                        count[j]++;
                    }
                }
            }

            cout << "Количество элементов, которые нацело делятся на 1, 2, 3, 4, 5, 6, 7, 8, 9: ";
            for (int i = 1; i <= 9; i++) {
                cout << count[i] << " ";
            }
            cout << endl;
            }
        }
    }
    return 0;
}
    
