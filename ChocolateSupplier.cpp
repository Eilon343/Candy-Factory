#include "ChocolateSupplier.hpp"

ChocolateSupplier::ChocolateSupplier(const char *supplierName) : supplierName(nullptr)
{
    if (supplierName != nullptr)
    {
        this->supplierName = new char[strlen(supplierName) + 1];
        strcpy(this->supplierName, supplierName);
    }
}

ChocolateSupplier::~ChocolateSupplier()
{
    delete[] supplierName;
}

const char *ChocolateSupplier::getChocolateName() const
{
    return supplierName;
}

void ChocolateSupplier::setChocolateName(const char *newName)
{
if (newName == nullptr) return; 

    delete[] this->supplierName;
    this->supplierName = new char[strlen(newName) + 1];
    strcpy(this->supplierName, newName);
}

void ChocolateSupplier::supplyChocolate()
{
    std::cout << supplierName << " is now supplying chocolate." << std::endl;
}