#include <iostream>
#include "Windows.h"
#include <fstream>
#include <string>
using namespace std;

struct User {
    string name;
    string forname;
    string id;
    string email;
};

// додати user
void addUser(User users[], int& userCount, int capacity, User& u) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (userCount < capacity) {
        users[userCount++] = u;
        cout << "Користувачу \"" << u.name << "\" додано.\n";
    }
    else {
        cout << "Досягнуто ліміту (" << capacity << ") користувачів в інтернеті.\n";
    }
}

// видалити user
void deleteUser(User users[], int& userCount, const string& title) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 0; i < userCount; ++i) {
        if (users[i].name == title) {
            for (int j = i; j < userCount - 1; ++j) {
                users[j] = users[j + 1];
            }
            --userCount;
            cout << "Користувача видалено.\n";
            return;
        }
    }
    cout << "Книгу з назвою \"" << title << "\" не знайдено.\n";
}

void letterUser(User users[], int userCount, ofstream& fout) {
    if (userCount == 0) {
        cout << "Список порожній.\n";
        fout << "Список порожній.\n";
        return;
    }
    for (int i = 0; i < userCount; ++i) {
        cout << "\nКористувач " << i + 1 << ":\n";
        cout << "Ім'я: " << users[i].name << "\n";
        cout << "Прізвище: " << users[i].forname << "\n";
        cout << "ID: " << users[i].id << "\n";
        cout << "Email: " << users[i].email << "\n";

        fout << "\nКористувач " << i + 1 << ":\n";
        fout << "Ім'я: " << users[i].name << "\n";
        fout << "Прізвище: " << users[i].forname << "\n";
        fout << "ID: " << users[i].id << "\n";
        fout << "Email: " << users[i].email << "\n";
    }
}

// пошук user
void searchUser(User users[], int& userCount, const string& title) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 0; i < userCount; ++i) {
        if (users[i].name == title) {
            cout << "\nЗнайдений користувач:\n";
            cout << "Ім'я: " << users[i].name << "\n";
            cout << "Прізвище: " << users[i].forname << "\n";
            cout << "ID: " << users[i].id << "\n";
            cout << "Електронна пошта: " << users[i].email << "\n";
            return;
        }
    }

    cout << "Користувач за іменем \"" << title << "\" не знайдено.\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int capacity = 100;
    User users[capacity];
    int userCount = 0;

    User newUser;

    cout << "Введіть ім'я: ";
    getline(cin, newUser.name);

    cout << "Введіть прізвище: ";
    getline(cin, newUser.forname);

    cout << "Введіть ID: ";
    getline(cin, newUser.id);

    cout << "Введіть email: ";
    getline(cin, newUser.email);

    addUser(users, userCount, capacity, newUser);

    ofstream fout("name_forname.txt");
    if (!fout.is_open()) {
        cout << "Не вдалося створити файл name_forname.txt\n";
        return 1;
    }

    letterUser(users, userCount, fout);

    cout << "\nВведіть ім'я користувача для пошуку: ";
    searchUser(users, userCount, newUser.name);

    cout << "\nВидалення користувача за іменем \"" << newUser.name << "\":\n";
    deleteUser(users, userCount, newUser.name);

    cout << "\nСписок після видалення:\n";
    letterUser(users, userCount, fout);

    if (userCount > 0) {
        fout << "Ім'я: " << users[0].name << "\n";
        fout << "Прізвище: " << users[0].forname << "\n";
        fout << "ID: " << users[0].id << "\n";
        fout << "Email: " << users[0].email << "\n";
    }
    else {
        fout << "Список користувачів порожній.\n";
    }

    fout.close();
    cout << "Інформацію збережено у файл name_forname.txt\n";

    return 0;
}

