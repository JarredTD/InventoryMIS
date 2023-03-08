#include "../include/product.h"

Product::Product() {
    this->price_ = 0;
    this->quantity_ = 0;
}

Product::Product(const std::string& name, const std::string& description, const double& price, const int& quantity, const std::string& supplier) {
    this->name_ = name;
    this->description_ = description;
    this->supplier_ = supplier;
    this->price_ = price;
}