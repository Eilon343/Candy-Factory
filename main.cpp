#include <iostream>
// Include the headers for your classes:
#include "SugerSupplier.hpp"
#include "ChocolateSupplier.hpp"
#include "CandyMaker.hpp"
#include "CandyBox.hpp"

void runTests() {
    std::cout << "--- Starting Edge Case Tests ---" << std::endl;

    // בדיקה 1: תיבה בגודל 1 - בדיקת גבולות קיבולת
    CandyBox<int> smallBox(1);
    if (smallBox.addItem(10)) std::cout << "Test 1.1 Passed" << std::endl;
    if (!smallBox.addItem(20)) std::cout << "Test 1.2 Passed (Box Full correctly)" << std::endl;

    // בדיקה 2: הסרה מתיבה ריקה
    CandyBox<std::string> emptyBox(5);
    if (!emptyBox.removeItem(0)) std::cout << "Test 2 Passed (Cannot remove from empty)" << std::endl;

    // בדיקה 3: בדיקת אינדקסים לא חוקיים (שלילי, גבוה מדי)
    CandyBox<double> doubleBox(10);
    doubleBox.addItem(5.5);
    if (!doubleBox.removeItem(-1) && !doubleBox.removeItem(1)) 
        std::cout << "Test 3 Passed (Invalid indices handled)" << std::endl;

    // בדיקה 4: CandyMaker עם שמות ארוכים מאוד ומצביעי Null
    CandyMaker extremeMaker("VeryVeryVeryLongSupplierNameThatMightCauseBufferOverflowIfManagedIncorrectly", nullptr);
    extremeMaker.makeCandy(nullptr); // בדיקה שלא קורס עם NULL
    extremeMaker.makeCandy("SuperMagicCandy");
    std::cout << "Test 4 Passed (Extreme strings handled)" << std::endl;

    // בדיקה 5: בדיקת ה-Shift בתיבה מלאה
    CandyBox<int> shiftBox(3);
    shiftBox.addItem(1);
    shiftBox.addItem(2);
    shiftBox.addItem(3);
    shiftBox.removeItem(0); // הסרת הראשון, ה-2 וה-3 צריכים לזוז שמאלה
    std::cout << "Test 5: Box after removing first item (should show 2, 3):" << std::endl;
    shiftBox.displayItems();
}

int main() {
    std::cout << "-----------Given Tests-----------" << std::endl;
    // 1. Create a CandyMaker with sugar and chocolate supplier names
    CandyMaker myCandyMaker("SugarCo", "ChocoDelight");

    // 2. Demonstrate supplySugar() and supplyChocolate()
    myCandyMaker.supplySugar();
    myCandyMaker.supplyChocolate();

    // 3. Make a candy
    myCandyMaker.makeCandy("Fudge Surprise");

    // 4. Create a CandyBox for storing candy names
    CandyBox<const char*> candyBox(5);

    // 5. Add items
    candyBox.addItem("SourLollipop");
    candyBox.addItem("MintChoco");
    candyBox.addItem("CaramelSwirl");

    // 6. Display contents
    std::cout << "Contents of CandyBox:" << std::endl;
    candyBox.displayItems();

    // 7. Remove an item and display again
    candyBox.removeItem(1); // removing "MintChoco"

    std::cout << "Contents of CandyBox after removal:" << std::endl;
    candyBox.displayItems();

    std::cout << "-------------Gemini Tests-------------" << std::endl;

    runTests();

    return 0;
}
