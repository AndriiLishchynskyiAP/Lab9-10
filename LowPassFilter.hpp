#pragma once
#include "Filter.hpp"

class LowPassFilter : public Filter {
private:
    double cutoffFreq;

public:
    LowPassFilter();
    LowPassFilter(int order, const std::string& type, double cutoffFreq);
    ~LowPassFilter();

    bool setCutoffFreq(double freq);
    double getCutoffFreq() const;

    void input() override;
    void print() const override;
};

