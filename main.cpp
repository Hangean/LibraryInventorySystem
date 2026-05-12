#include <iostream>
#include "LibraryInventory.h"
#include "Helper.h"

using namespace std;

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    LibraryInventory libraryInventory;

    // load items from file
    cout << "----------------------------------------" << endl;
    cout << "       Loading items from file          " << endl;
    cout << "----------------------------------------" << endl;
    loadItemsFromFile("items.txt", libraryInventory);
    cout << "Items loaded successfully." << endl << endl;

    //print items currently in storage
    cout << "----------------------------------------" << endl;
    cout << "         Items Currently in Storage     " << endl;
    cout << "----------------------------------------" << endl;
    libraryInventory.printStoredItems();
    cout << endl;

    //checkout a book, movie, or magazine
    cout << "----------------------------------------" << endl;
    cout << "            Checking Out Items          " << endl;
    cout << "----------------------------------------" << endl;

    string borrower1 = "Snow White";
    string dueDate1  = "2026-06-01";
    libraryInventory.checkOutItem("B001", borrower1, dueDate1);
    cout << endl;

    string borrower2 = "Cinderella";
    string dueDate2  = "2026-06-10";
    libraryInventory.checkOutItem("M003", borrower2, dueDate2);
    cout << endl;

    string borrower3 = "Mulan";
    string dueDate3  = "2026-06-15";
    libraryInventory.checkOutItem("MAG005", borrower3, dueDate3);
    cout << endl;

    //checked out items
    cout << "----------------------------------------" << endl;
    cout << "          Checked Out Items             " << endl;
    cout << "----------------------------------------" << endl;
    libraryInventory.printCheckOutItems();
    cout << endl;

    //check in item
    cout << "----------------------------------------" << endl;
    cout << "            Checking In Items           " << endl;
    cout << "----------------------------------------" << endl;
    libraryInventory.checkInItem("B001");
    cout << endl;

    

    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the <b>lang</b> variable name to see how CLion can help you rename it.

    const auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        // TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.
        std::cout << "i = " << i << std::endl;
    }

    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}
