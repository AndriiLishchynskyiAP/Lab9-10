#include "Filter.hpp"
#include <iostream>
#include <limits>

Filter::Filter() : order(0), type("невідомий"), minTemp(0.0), maxTemp(0.0) {}

Filter::Filter(int order, const std::string& type, double minTemp, double maxTemp) {
    setOrder(order);
    setType(type);
    setMinTemp(minTemp);
    setMaxTemp(maxTemp);
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

bool Filter::setMinTemp(double t) {
    minTemp = t;
    return true;
}

bool Filter::setMaxTemp(double t) {
    if (t <= minTemp) return false;
    maxTemp = t;
    return true;
}

int Filter::getOrder() const { return order; }
std::string Filter::getType() const { return type; }
double Filter::getMinTemp() const { return minTemp; }
double Filter::getMaxTemp() const { return maxTemp; }

void Filter::input() {
    std::string s;
    int o;
    double t1, t2;

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

    std::cout << "Введіть мінімальну робочу температуру (°C): ";
    std::cin >> t1;
    setMinTemp(t1);

    std::cout << "Введіть максимальну робочу температуру (°C): ";
    while (!(std::cin >> t2) || !setMaxTemp(t2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка. Введіть число більше мінімальної температури: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Filter::print() const {
    std::cout << "Порядок фільтра: " << order << "\n";
    std::cout << "Тип фільтра: " << type << "\n";
    std::cout << "Робоча температура: від " << minTemp << "°C до " << maxTemp << "°C\n";
}
