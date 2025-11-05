#include "BandPassFilter.hpp"
#include <iostream>
#include <limits>

BandPassFilter::BandPassFilter() : Filter(), lowFreq(0.0), highFreq(0.0) {}

BandPassFilter::BandPassFilter(int order, const std::string& type, double lowFreq, double highFreq)
    : Filter(order, type) {
    setLowFreq(lowFreq);
    setHighFreq(highFreq);
}

BandPassFilter::~BandPassFilter() {}

bool BandPassFilter::setLowFreq(double freq) {
    if (freq <= 0.0) return false;
    lowFreq = freq;
    return true;
}

bool BandPassFilter::setHighFreq(double freq) {
    if (freq <= 0.0 || freq <= lowFreq) return false;
    highFreq = freq;
    return true;
}

double BandPassFilter::getLowFreq() const { return lowFreq; }
double BandPassFilter::getHighFreq() const { return highFreq; }

void BandPassFilter::input() {
    Filter::input();

    double lf, hf;

    std::cout << "Введіть нижню частоту смуги (Гц): ";
    while (!(std::cin >> lf) || !setLowFreq(lf)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка. Введіть додатне число: ";
    }

    std::cout << "Введіть верхню частоту смуги (Гц): ";
    while (!(std::cin >> hf) || !setHighFreq(hf)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка. Введіть число більше нижньої частоти: ";
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void BandPassFilter::print() const {
    std::cout << "Тип фільтра: СФ (Смуговий фільтр)\n";
    Filter::print();
    std::cout << "Нижня частота: " << lowFreq << " Гц\n";
    std::cout << "Верхня частота: " << highFreq << " Гц\n";
}
