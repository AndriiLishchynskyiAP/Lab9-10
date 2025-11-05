#include "Filter.hpp"
#include <iostream>
#include <limits>

Filter::Filter() : order(0), type("невідомий") {}

Filter::Filter(int order, const std::string& type) {
    setOrder(order);
    setType(type);
}

Filter::~Filter() {}

bool Filter::setOrder(int o) {
    if (o <= 0) return false;
    order = o;
    return true;
}

bool Filter::setType(const std::string& t) {
    if (t != "аналоговий" && t != "цифровий") return false;
    type = t;
    return true;
}

int Filter::getOrder() const { return order; }
std::string Filter::getType() const { return type; }

void Filter::input() {
    std::string s;
    int o;

    std::cout << "Введіть порядок фільтра (ціле число > 0): ";
    while (!(std::cin >> o) || !setOrder(o)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка. Спробуйте ще раз: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введіть тип фільтра (аналоговий/цифровий): ";
    while (true) {
        std::getline(std::cin, s);
        if (setType(s)) break;
        std::cout << "Помилка. Введіть 'аналоговий' або 'цифровий': ";
    }
}

void Filter::print() const {
    std::cout << "Порядок фільтра: " << order << "\n";
    std::cout << "Тип фільтра: " << type << "\n";
}

