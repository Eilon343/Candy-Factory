#pragma once
#include <iostream>
#include <string.h>

class SugerSupplier
{
private:
    char* supplierName;
public:
    SugerSupplier(const char* supplierName);
    ~SugerSupplier();
    const char* getSugerName() const;
    void setSugerName(const char* newName);
    void supplySugar();
};