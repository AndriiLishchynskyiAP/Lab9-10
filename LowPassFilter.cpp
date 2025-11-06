#include "LowPassFilter.hpp"
#include <iostream>
#include <limits>

LowPassFilter::LowPassFilter() : Filter(), cutoffFreq(0.0) {}

LowPassFilter::LowPassFilter(int order, const std::string& type, double minTemp, double maxTemp, double cutoffFreq)
    : Filter(order, type, minTemp, maxTemp) {
    setCutoffFreq(cutoffFreq);
}

LowPassFilter::~LowPassFilter() {}

bool LowPassFilter::setCutoffFreq(double freq) {
    if (freq <= 0.0) return false;
    cutoffFreq = freq;
    return true;
}

double LowPassFilter::getCutoffFreq() const { return cutoffFreq; }

void LowPassFilter::input() {
    Filter::input();

    double f;
    std::cout << "Введіть частоту зрізу (Гц): ";
    while (!(std::cin >> f) || !setCutoffFreq(f)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка. Введіть додатне число: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void LowPassFilter::print() const {
    std::cout << "Тип фільтра: ФНЧ (Фільтр нижніх частот)\n";
    Filter::print();
    std::cout << "Частота зрізу: " << cutoffFreq << " Гц\n";
}
