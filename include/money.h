#ifndef MONEY_H
#define MONEY_H

#include <math.h>

class Money {
public:
    Money();
    Money(double amont);
    int getDollar() const;
    int getChange() const;

private:
    int dollar;
    int change;
};

#endif