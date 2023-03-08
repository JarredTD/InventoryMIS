#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    
    // Constructors
    Product();
    Product(const std::string& name, const std::string& description, const double& price, const int& quantity, const std::string& supplier);

    // Getters
    const std::string& getName() const;
    const std::string& getDescription() const;
    const std::string& getSupplier() const;
    int getPrice() const;
    int getQuantity() const;

    //Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setSupplier(const std::string& supplier);
    void setPrice(double price);
    void setQuantity(int quantity);
        

private:
    // Data
    int price_;
    int quantity_;
    std::string name_;
    std::string description_;
    std::string supplier_;
};

#endif