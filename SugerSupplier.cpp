#include "SugerSupplier.hpp"

SugerSupplier::SugerSupplier(const char *supplierName) : supplierName(nullptr)
{
    if (supplierName != nullptr)
    {
        this->supplierName = new char[strlen(supplierName) + 1];
        strcpy(this->supplierName, supplierName);
    }
}

SugerSupplier::~SugerSupplier()
{
    delete[] supplierName;
}

const char *SugerSupplier::getSugerName() const
{
    return supplierName;
}

void SugerSupplier::setSugerName(const char *newName)
{
    if (newName == nullptr)
        return;

    delete[] this->supplierName;
    this->supplierName = new char[strlen(newName) + 1];
    strcpy(this->supplierName, newName);
}

void SugerSupplier::supplySugar()
{
    if (supplierName != nullptr)
    {
        std::cout << supplierName << " is now supplying sugar." << std::endl;
    }
}