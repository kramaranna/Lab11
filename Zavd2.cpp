#include <iostream>
#include <list>
#include <string>
#include <iomanip>
using namespace std;

struct Product {
    string name;
    string category;
    double price;
    int quantity;
};

bool compareByPriceDesc(Product a, Product b) {
    return a.price > b.price;
}

int main() {
    list<Product> products = {
        {"Ноутбук ", "  Техніка     ", 32000, 3},
        {"Мишка", "Аксесуари   ", 650, 10},
        {"Клавіатура   ", "Аксесуари   ", 1200, 0},
        {"Монітор ", "  Техніка     ", 8500, 4},
        {"Флешка", " Аксесуари   ", 400, 15}
    };

    // Виведення початкового списку
    cout << "Початковий список:\n";
    for (Product p : products) {
        cout << left << setw(18) << p.name
             << setw(15) << p.category
             << setw(10) << p.price
             << p.quantity << endl;
    }

    // Додавання запису на початок і кінець
    products.push_front({"Планшет ", "  Техніка     ", 12000, 6});
    products.push_back({"Навушники", "    Аксесуари   ", 1800, 2});

    cout << "\nПісля додавання:\n";
    for (Product p : products) {
        cout << left << setw(18) << p.name
             << setw(15) << p.category
             << setw(10) << p.price
             << p.quantity << endl;
    }

    // Фільтрація та виведення товарів з кількістю < 5
    cout << "\nТовари, яких на складі менше 5:\n";
    for (Product p : products) {
        if (p.quantity < 5) {
            cout << p.name << " - " << p.quantity << " шт.\n";
        }
    }

    // Видалення товарів з нульовою кількістю
    list<Product>::iterator it = products.begin();
    while (it != products.end()) {
        if (it->quantity == 0) {
            it = products.erase(it);
        } else {
            it++;
        }
    }

    cout << "\nПісля видалення:\n";
    for (Product p : products) {
        cout << left << setw(18) << p.name
             << setw(15) << p.category
             << setw(10) << p.price
             << p.quantity << endl;
    }

    // Сортування за ціною спаданням
    products.sort(compareByPriceDesc);

    cout << "\nПісля сортування за спаданням ціни:\n";
    for (Product p : products) {
        cout << left << setw(18) << p.name
             << setw(15) << p.category
             << setw(10) << p.price
             << p.quantity << endl;
    }

    return 0;
}
