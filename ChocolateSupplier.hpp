#pragma once
#include <iostream>
#include <string.h>

class ChocolateSupplier
{
private:
    char* supplierName;
public:
    ChocolateSupplier(const char* supplierName);
    ~ChocolateSupplier();
    const char* getChocolateName() const;
    void setChocolateName(const char* newName);
    void supplyChocolate();
};