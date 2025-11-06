#pragma once
#include <string>

class Filter {
protected:
    int order;
    std::string type;
    double minTemp;
    double maxTemp;

public:
    Filter();
    Filter(int order, const std::string& type, double minTemp, double maxTemp);
    virtual ~Filter();

    bool setOrder(int order);
    bool setType(const std::string& type);
    bool setMinTemp(double t);
    bool setMaxTemp(double t);

    int getOrder() const;
    std::string getType() const;
    double getMinTemp() const;
    double getMaxTemp() const;

    virtual void input();
    virtual void print() const;
};
