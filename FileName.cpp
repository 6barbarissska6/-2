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
        // ����� �������� �������������
        int choice;

        cout << "�������� ��������:" << endl;
        cout << "1. ������� ������" << endl;
        cout << "2. ������������� ������" << endl;
        cout << "3. ����� �������� � �������" << endl;
        cout << "4. ������� ������� �������� ��������� � ��������" << endl;
        cout << "5. ���������� ���������� ��������� ������ a" << endl;
        cout << "6. ���������� ���������� ��������� ������ b" << endl;
        cout << "7. ����� ����� � �������" << endl;
        cout << "8. �������� ������� �������� �������" << endl;
        cout << "9. ���" << endl;

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


            cout << "��������������� ������: ";
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

            cout << "�����, ����������� �� ����������: " << elapsed_seconds.count() << " ������" << endl;
        }
              break;
        case 3:
        {
            int a = sizeof(arr) / sizeof(arr[0]);

            // ����������������� ������
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

            cout << "����������������� ������ - �����������: " << min_nesort << ", ������������: " << max_nesort << endl;
            cout << "����������� ����� ��� ������������������ �������: " << elapsed_seconds_unsorted.count() << " ������" << endl;

            // ���������� �������
            for (int i = 0; i < a - 1; i++) {
                for (int j = 0; j < a - i - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            // ��������������� ������
            auto start_sort = std::chrono::high_resolution_clock::now();
            int min_sort = arr[0];
            int max_sort = arr[a - 1];
            auto end_sort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_sorted = end_sort - start_sort;

            cout << "��������������� ������ - �����������: " << min_sort << ", ������������: " << max_sort << endl;
            cout << "����������� ����� ��� ���������������� �������: " << elapsed_seconds_sorted.count() << " ������" << endl;
        }
        break;
        case 4: {
            int a = sizeof(arr) / sizeof(arr[0]);

            // ����������������� ������
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
            cout << "����������������� ������ - �����������: " << min_nesort << ", ������������: " << max_nesort << endl;
            cout << "������� ��������: " << srednee_nesort << endl;
            cout << "����������� ����� ��� ������������������ �������: " << elapsed_seconds_unsorted.count() << " ������" << endl;


            // ��������������� ������
            auto start_sort = std::chrono::high_resolution_clock::now();
            int min_sort = arr[0];
            int max_sort = arr[a - 1];
            int srednee_sort;
            srednee_sort = round((max_sort + min_sort) / 2);
            auto end_sort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_sorted = end_sort - start_sort;

            cout << "��������������� ������ - �����������: " << min_sort << ", ������������: " << max_sort << endl;
            cout << "������� ��������: " << srednee_sort << endl;
            cout << "����������� ����� ��� ���������������� �������: " << elapsed_seconds_sorted.count() << " ������" << endl;


            // ������� ���� ��������� ������ ��������
            auto start = std::chrono::high_resolution_clock::now();
            int count = 0;
            cout << "������� ��������, ������ �������� ��������: ";
            for (int i = 0; i < a; i++) {
                if (arr[i] == srednee_sort) {
                    cout << i << " ";
                    count++;
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            cout << "���������� ��������: " << count << endl;
            cout << "�����, ����������� �� �����: " << elapsed_seconds.count() << " ������" << endl;

        }
              break;
        case 5: {
            // ���������� �������
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
            cout << "������� �����:";
            cin >> number;
            //������� ���������
            for (int i = 0; i < a; i++) {
                if (arr[i] < number) {
                    count++;
                }
            }

            cout << "���������� ���������, ������� ������ ��������� �����: " << count << endl;

        }
              break;
        case 6: {
            // ���������� �������
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
            cout << "������� �����:";
            cin >> number;
            //������� ���������
            for (int i = 0; i < a; i++) {
                if (arr[i] > number) {
                    count++;
                }
            }

            cout << "���������� ���������, ������� ������ ��������� �����: " << count << endl;

        }
              break;
        case 7: {
            int a = sizeof(arr) / sizeof(arr[0]);
            int x;
            cout << "������� ����� ��� ������: ";
            cin >> x;
            //������� �������
            auto start_nesort = std::chrono::high_resolution_clock::now();
            cout << "������� �������:" << endl;
            for (int i = 0; i < a - 1; i++) {
                if (arr[i] == x) {
                    cout << "����� " << x << " ������� � �������" << endl;
                    break;
                }


            }
            auto end_nesort = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds_unsorted = end_nesort - start_nesort;
            cout << "����������� ����� ��� ������: " << elapsed_seconds_unsorted.count() << " ������" << endl;
            // ���������� �������
            cout << "�������� �����:" << endl;
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
                cout << "����� " << x << " ������� � �������" << endl;
            }
            else {
                cout << "����� " << x << " � ������� �� ����������" << endl;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed_seconds = end - start;
            cout << "�����, ����������� �� ����� � ������� ��������� ������: " << elapsed_seconds.count() << " ������" << endl;


        }
        case 8: {
            int index_1, index_2;
            cout << "������� ������� �����: ";
            cin >> index_1 >> index_2;

            auto start = std::chrono::high_resolution_clock::now();

            // ����� ���������
            int temp = arr[index_1];
            arr[index_1] = arr[index_2];
            arr[index_2] = temp;

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;

            cout << "����������� ��������� ������ " << duration.count() * 1000 << " �����������" << std::endl;

            cout << "������ ����� �����������: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }

        }
        case 9: {
            int n = sizeof(arr) / sizeof(arr[0]);
            cout << "����������� ������: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << "������� �����: ";
            int number;
            cin >> number;
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 != 0) {
                    arr[i] -= number; // ��������� �������� ������� �� ��������� �������� (5 � ������ ������)
                    arr[i] *= (rand() % 9) + 1; // �������� �� ��������� ����� �� 1 �� 9
                }
            }
            cout << "���������� ������: ";
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

            cout << "���������� ���������, ������� ������ ������� �� 1, 2, 3, 4, 5, 6, 7, 8, 9: ";
            for (int i = 1; i <= 9; i++) {
                cout << count[i] << " ";
            }
            cout << endl;
            }
        }
    }
    return 0;
}
    
