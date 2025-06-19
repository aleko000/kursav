#include "library.h"
#include <iostream>
#include <string>
#include <windows.h>

const char* menu =
"\n"
"1. Поиск книги по названию\n"
"2. Поиск книги по дате издания\n"
"3. Поиск книги по автору\n"
"4. Добавление книги в библиотеку\n"
"5. Удаление книги из библиотеки\n"
"6. Список всех книг\n"
"7. Сортировать книги по автору\n"
"8. Сортировать книги по году издания\n"
"9. Поиск по части названия\n"
"10. Сохранить библиотеку в файл\n"
"11. Загрузить библиотеку из файла\n"
"0. Выход\n\n"
"Ваш выбор: ";

int main(int argc, const char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ExtendedLibrary lib;

    lib.append(Book(1885, "Ницше", "По ту сторону добра и зла"));
    lib.append(Book(1842, "Ницше", "Так говорил Заратустра"));
    lib.append(Book(1781, "Кант", "Критика чистого разума"));
    lib.append(Book(1935, "Достоевский", "Преступление и наказание"));
    lib.append(Book(1935, "Булгаков", "Иван Васильевич"));

    int choice;
    std::string what;
    int year;
    Book book;
    Library::Bookcase::iterator it;

    do {
        std::cout << menu;
        std::cin >> choice;
        std::cin.ignore();
        std::cout << std::endl;

        switch (choice) {
        case 1:
            std::cout << "Укажите название книги: ";
            getline(std::cin, what);
            it = lib.begin();
            do {
                it = lib.findByTitle(what, it);
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                    ++it;
                }
            } while (it != lib.end());
            break;
        case 2:
            std::cout << "Укажите год издания книги: ";
            std::cin >> year;
            std::cin.ignore();
            it = lib.begin();
            do {
                it = lib.findByYear(year, it);
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                    ++it;
                }
            } while (it != lib.end());
            break;
        case 3:
            std::cout << "Укажите автора книги: ";
            getline(std::cin, what);
            it = lib.begin();
            do {
                it = lib.findByAuthor(what, it);
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                    ++it;
                }
            } while (it != lib.end());
            break;
        case 4:
            inputBook(book);
            lib.append(book);
            break;
        case 5:
            inputBook(book);
            if (lib.remove(book))
                std::cout << "книга удалена\n";
            else
                std::cout << "книга не найдена\n";
            break;
        case 6:
            it = lib.begin();
            do {
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                }
                it = lib.nextBook(it);
            } while (it != lib.end());
            break;
        case 7:
            lib.sortByAuthor();
            std::cout << "Книги отсортированы по автору.\n";
            break;
        case 8:
            lib.sortByYear();
            std::cout << "Книги отсортированы по году издания.\n";
            break;
        case 9:
            std::cout << "Укажите часть названия книги: ";
            getline(std::cin, what);
            it = lib.begin();
            do {
                it = lib.findByPartialTitle(what, it);
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                    ++it;
                }
            } while (it != lib.end());
            break;
        case 10:
            std::cout << "Введите имя файла для сохранения: ";
            getline(std::cin, what);
            if (lib.saveToFile(what)) {
                std::cout << "Библиотека успешно сохранена в файл.\n";
            }
            else {
                std::cout << "Ошибка при сохранении в файл.\n";
            }
            break;
        case 11:
            std::cout << "Введите имя файла для загрузки: ";
            getline(std::cin, what);
            if (lib.loadFromFile(what)) {
                std::cout << "Библиотека успешно загружена из файла.\n";
            }
            else {
                std::cout << "Ошибка при загрузке из файла.\n";
            }
            break;
        case 0:
            break;
        default:
            std::cout << "\nНе попал ((\n\n";
        }
    } while (choice != 0);

    return 0;
}
