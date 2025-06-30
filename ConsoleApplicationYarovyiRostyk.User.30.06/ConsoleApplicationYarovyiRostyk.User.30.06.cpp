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

// ������ user
void addUser(User users[], int& userCount, int capacity, User& u) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    if (userCount < capacity) {
        users[userCount++] = u;
        cout << "����������� \"" << u.name << "\" ������.\n";
    }
    else {
        cout << "��������� ���� (" << capacity << ") ������������ � ��������.\n";
    }
}

// �������� user
void deleteUser(User users[], int& userCount, const string& title) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 0; i < userCount; ++i) {
        if (users[i].name == title) {
            for (int j = i; j < userCount - 1; ++j) {
                users[j] = users[j + 1];
            }
            --userCount;
            cout << "����������� ��������.\n";
            return;
        }
    }
    cout << "����� � ������ \"" << title << "\" �� ��������.\n";
}

void letterUser(User users[], int userCount, ofstream& fout) {
    if (userCount == 0) {
        cout << "������ �������.\n";
        fout << "������ �������.\n";
        return;
    }
    for (int i = 0; i < userCount; ++i) {
        cout << "\n���������� " << i + 1 << ":\n";
        cout << "��'�: " << users[i].name << "\n";
        cout << "�������: " << users[i].forname << "\n";
        cout << "ID: " << users[i].id << "\n";
        cout << "Email: " << users[i].email << "\n";

        fout << "\n���������� " << i + 1 << ":\n";
        fout << "��'�: " << users[i].name << "\n";
        fout << "�������: " << users[i].forname << "\n";
        fout << "ID: " << users[i].id << "\n";
        fout << "Email: " << users[i].email << "\n";
    }
}

// ����� user
void searchUser(User users[], int& userCount, const string& title) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i = 0; i < userCount; ++i) {
        if (users[i].name == title) {
            cout << "\n��������� ����������:\n";
            cout << "��'�: " << users[i].name << "\n";
            cout << "�������: " << users[i].forname << "\n";
            cout << "ID: " << users[i].id << "\n";
            cout << "���������� �����: " << users[i].email << "\n";
            return;
        }
    }

    cout << "���������� �� ������ \"" << title << "\" �� ��������.\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int capacity = 100;
    User users[capacity];
    int userCount = 0;

    User newUser;

    cout << "������ ��'�: ";
    getline(cin, newUser.name);

    cout << "������ �������: ";
    getline(cin, newUser.forname);

    cout << "������ ID: ";
    getline(cin, newUser.id);

    cout << "������ email: ";
    getline(cin, newUser.email);

    addUser(users, userCount, capacity, newUser);

    ofstream fout("name_forname.txt");
    if (!fout.is_open()) {
        cout << "�� ������� �������� ���� name_forname.txt\n";
        return 1;
    }

    letterUser(users, userCount, fout);

    cout << "\n������ ��'� ����������� ��� ������: ";
    searchUser(users, userCount, newUser.name);

    cout << "\n��������� ����������� �� ������ \"" << newUser.name << "\":\n";
    deleteUser(users, userCount, newUser.name);

    cout << "\n������ ���� ���������:\n";
    letterUser(users, userCount, fout);

    if (userCount > 0) {
        fout << "��'�: " << users[0].name << "\n";
        fout << "�������: " << users[0].forname << "\n";
        fout << "ID: " << users[0].id << "\n";
        fout << "Email: " << users[0].email << "\n";
    }
    else {
        fout << "������ ������������ �������.\n";
    }

    fout.close();
    cout << "���������� ��������� � ���� name_forname.txt\n";

    return 0;
}

