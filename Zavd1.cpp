#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;
    cout << "Введіть кількість елементів списку N: ";
    cin >> N;

    if (N <= 0) {
        cout << "Кількість елементів має бути додатним числом." << endl;
        return 0;
    }

    list<double> numbers;
    for (int i = 0; i < N; i++) {
        double value;
        cin >> value;
        numbers.push_back(value);
    }

    // Виведення початкового списку
    cout << "Початковий список: ";
    for (double x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    // Пошук першого додатного елемента
    double firstPositive = 0;
    int f = 0;
    list<double>::iterator it = numbers.begin();
    while (it != numbers.end()) {
        if (*it > 0) {
            firstPositive = *it;
            f = 1;
            break;
        }
        it++;
    }

    if (f == 0) {
        cout << "Додатних елементів немає." << endl;
    } 
    else {
        // Вставка першого додатного елемента після кожного від'ємного
        it = numbers.begin();
        while (it != numbers.end()) {
            if (*it < 0) {
                it++;
                numbers.insert(it, firstPositive);
            } 
            else {
                it++;
            }
        }
    }

    // Виведення результату
    cout << "\nРезультуючий список: ";
    for (double x : numbers) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}