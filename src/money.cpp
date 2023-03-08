#include "../include/money.h"

Money::Money(){
    this->change = 0;
    this->dollar = 0;
}

Money::Money(double amount){
    this->change = fmod(amount, floor(amount)) * 100;
    this->dollar = floor(amount);
}

int Money::getDollar() const{
    return this->dollar;
}

int Money::getChange() const{
    return this->change;
}
