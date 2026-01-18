#include "CandyMaker.hpp"

CandyMaker::CandyMaker(const char *sugarSupplierName, const char *chocolateSupplierName) : SugerSupplier(sugarSupplierName), ChocolateSupplier(chocolateSupplierName), currCandy(nullptr)
{
}

CandyMaker::~CandyMaker()
{
    delete[] currCandy;
}

void CandyMaker::makeCandy(const char *candyName)
{
    if (candyName == nullptr)
        return;

    delete[] currCandy;
    currCandy = new char[strlen(candyName) + 1];
    strcpy(currCandy, candyName);

    std::cout << "Using sugar and chocolate to create candy: " << currCandy << std::endl;

    supplySugar();
    supplyChocolate();
}