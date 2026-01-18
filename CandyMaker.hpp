#pragma once
#include "SugerSupplier.hpp"
#include "ChocolateSupplier.hpp"

class CandyMaker : public SugerSupplier, public ChocolateSupplier
{
private:
    char* currCandy;
public:
    CandyMaker(const char* sugerSupplierName, const char* chocolateSupplierName);
    void makeCandy(const char* candyName);
    ~CandyMaker();
};
