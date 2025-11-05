#pragma once
#include "Filter.hpp"

class BandPassFilter : public Filter {
private:
    double lowFreq;
    double highFreq;

public:
    BandPassFilter();
    BandPassFilter(int order, const std::string& type, double lowFreq, double highFreq);
    ~BandPassFilter();

    bool setLowFreq(double freq);
    bool setHighFreq(double freq);

    double getLowFreq() const;
    double getHighFreq() const;

    void input() override;
    void print() const override;
};

