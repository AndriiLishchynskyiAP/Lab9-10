#include <iostream>
#include <vector>
#include <memory>
#include "Filter.hpp"
#include "LowPassFilter.hpp"
#include "BandPassFilter.hpp"

void showMenu() {
    std::cout << "\n--- Меню ---\n"
              << "1. Додати фільтр нижніх частот (ФНЧ)\n"
              << "2. Додати смуговий фільтр (СФ)\n"
              << "3. Показати всі фільтри\n"
              << "4. Видалити останній\n"
              << "0. Вихід\n"
              << "Ваш вибір: ";
}

int main() {
    std::vector<std::unique_ptr<Filter>> filters;
    int choice;

    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            auto filter = std::make_unique<LowPassFilter>();
            filter->input();
            filters.push_back(std::move(filter));
        } else if (choice == 2) {
            auto filter = std::make_unique<BandPassFilter>();
            filter->input();
            filters.push_back(std::move(filter));
        } else if (choice == 3) {
            if (filters.empty()) {
                std::cout << "Список фільтрів порожній.\n";
            } else {
                std::cout << "\n=== Список фільтрів ===\n";
                for (const auto& f : filters) {
                    f->print();
                    std::cout << "------------------------\n";
                }
            }
        } else if (choice == 4) {
            if (!filters.empty()) {
                filters.pop_back();
                std::cout << "Останній фільтр видалено.\n";
            } else {
                std::cout << "Немає фільтрів для видалення.\n";
            }
        } else if (choice != 0) {
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }

    } while (choice != 0);

    std::cout << "Програма завершена.\n";
    return 0;
}

