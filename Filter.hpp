#pragma once
#include <string>

class Filter {
protected:
    int order;
    std::string type;

public:
    Filter();
    Filter(int order, const std::string& type);
    virtual ~Filter();

    bool setOrder(int order);
    bool setType(const std::string& type);

    int getOrder() const;
    std::string getType() const;

    virtual void input();
    virtual void print() const;
};

