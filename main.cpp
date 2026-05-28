#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Занятие 7

// Задача 1
void swap_no_temp(int& x, int& y) {
    if (x != y) { x = x + y; y = x - y; x = x - y; }
}

// Задача 2
float f1(float x) { return sin(x) / x; }
float f2(float y) { return y * y + 2 * pow(y, 1.5); }
float f3(float z) { return (z + 2) * (z + 1) * z; }
float R(float x, float y, float z) { return f1(x) + f2(y) * f3(f2(z)); }

void print(float x, float (*func)(float)) {
    cout << func(x) << endl;
}

// Задача 3
float min_arr(float arr[], int k) {
    float m = arr[0];
    for (int i = 1; i < k; i++) {
        if (arr[i] < m) {
            m = arr[i];
        }
    }
    return m;
}
float max_arr(float arr[], int k) {
    float m = arr[0];
    for (int i = 1; i < k; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    return m;
}

// Задача 4
double series_val(double x, double e) {
    double sum = 0, term = x; int n = 1;
    while (abs(term) >= e) {
        sum += term;
        n++;
        term = pow(x, 2.0 * n - 1) / (2.0 * n - 1);
    }
    return sum;
}
void series_ptr(double x, double e, double* res) {
    *res = series_val(x, e);
}
double& series_ref(double x, double e, double& res) {
    res = series_val(x, e); return res;
}

// Занятие 8
// Задача 1
double sqrt_rec(double a, int tochnost) {
    if (tochnost == 0) {
        return (1.0 + a) / 2.0;
    }
    else {
        double x_prev = sqrt_rec(a, tochnost - 1);
        return 0.5 * (x_prev + a / x_prev);
    }
}

// Задача 2
double prod_rec(int n) {
    if (n == 0) return 1.0;
    double term = (n % 2 != 0) ? (n + 1.0) / n : n / (n + 1.0);
    return prod_rec(n - 1) * term;
}

// Задача 3
void print_rev(int* arr, int n) {
    if (n == 0) return;
    cout << arr[n - 1] << " ";
    print_rev(arr, n - 1);
}

// Задача 4
bool isPowOfTwo(int n) {
    if (n == 1) return true;
    if (n == 0 || n % 2 != 0) return false;
    return isPowOfTwo(n / 2);
}

// Задача 5
int ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

// Задача 6
double fast_pow(double x, int a) {
    if (a == 0) return 1;
    if (a % 2 == 0) {
        double half = fast_pow(x, a / 2);
        return half * half;
    }
    return x * fast_pow(x, a - 1);
}

// Задача 7
int sum_digits(int n) {
    if (n == 0) return 0;
    return n % 10 + sum_digits(n / 10);
}

// Задача 8
void max_count(int max_val, int count) {
    int n;
    cin >> n;
    if (n == 0) {
        cout << count << endl; return;
    }
    if (n > max_val) {
        max_count(n, 1);
    }
    else if (n == max_val) {
        max_count(max_val, count + 1);
    }
    else max_count(max_val, count);
}


int main() {
    string menu[] = {
        "0. Выход",
        "1. Занятие 7, Задача 1",
        "2. Занятие 7, Задача 2",
        "3. Занятие 7, Задача 3",
        "4. Занятие 7, Задача 4",
        "5. Занятие 8, Задача 1",
        "6. Занятие 8, Задача 2",
        "7. Занятие 8, Задача 3",
        "8. Занятие 8, Задача 4",
        "9. Занятие 8, Задача 5",
        "10. Занятие 8, Задача 6",
        "11. Занятие 8, Задача 7",
        "12. Занятие 8, Задача 8"
    };

    int choice = -1;
    while (choice != 0) {
        cout << "Выберите задачу: ";
        cin >> choice;

        switch (choice) {
            case 0:
                break;
            case 1: {
                int x = 5, y = 10;
                cout << "До обмена: x = " << x << ", y = " << y << endl;
                swap_no_temp(x, y);
                cout << "После: x = " << x << ", y = " << y << endl;
                break;
            }
            case 2: {
                cout << "R(0.6, 0.3, 0.1) = " << R(0.6f, 0.3f, 0.1f) << endl;
                cout << "print(0.6, f1): "; print(0.6f, f1);
                break;
            }
            case 3: {
                float a1[] = {1.2, 5.5, 0.3, 7.1};
                float a2[] = {4.1, 2.2, 9.9};
                cout << "Произведение минимумов: " << min_arr(a1, 4) * min_arr(a2, 3) << endl;
                cout << "Среднее геом. максимумов: " << sqrt(max_arr(a1, 4) * max_arr(a2, 3)) << endl;
                break;
            }
            case 4: {
                double x = 0.20, e = 0.5 * pow(10, -4), res_ptr, res_ref_val;
                cout << "По значению: " << series_val(x, e) << endl;
                series_ptr(x, e, &res_ptr);
                cout << "По указателю: " << res_ptr << endl;
                cout << "По ссылке: " << series_ref(x, e, res_ref_val) << endl;
                break;
            }
            case 5: {
                double x = 2; int t = 6;
                cout << "Рекурсивный sqrt(" << x << ") = " << sqrt_rec(x, t) << endl;
                break;
            }
            case 6: {
                int n; cout << "Введите n (четное): "; cin >> n;
                cout << "Произведение: " << prod_rec(n) << endl;
                break;
            }
            case 7: {
                int arr[] = {1, 2, 3, 4, 5};
                cout << "Массив: "; print_rev(arr, 5); cout << endl;
                break;
            }
            case 8: {
                int n; cout << "Введите n: "; cin >> n;
                cout << (isPowOfTwo(n) ? "YES" : "NO") << endl;
                break;
            }
            case 9: {
                int m, n;
                cout << "Введите m и n: ";
                cin >> m >> n;
                cout << "A(m,n) = " << ackermann(m, n) << endl;
                break;
            }
            case 10: {
                double x; int a; cout << "Введите x и a: "; cin >> x >> a;
                cout << "x^a = " << fast_pow(x, a) << endl;
                break;
            }
            case 11: {
                int n; cout << "Введите N: "; cin >> n;
                cout << "Сумма цифр: " << sum_digits(n) << endl;
                break;
            }
            case 12: {
                cout << "Вводите числа: ";
                int first;
                cin >> first;
                if (first == 0) cout << "0" << endl;
                else max_count(first, 1);
                break;
            }
            default: cout << "Ошибка"<< endl;
        }
    }
}