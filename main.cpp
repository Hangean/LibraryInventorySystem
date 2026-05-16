#include <iostream>
#include <memory>
#include <stdexcept>

#include "LibraryInventory.h"
#include "Helper.h"
#include "Book.h"

using namespace std;

int main() {
    LibraryInventory libraryInventory;

    cout << "/************************************************************\n"
            << " * Load Items Demo: load books, movies, and magazines from  *\n"
            << " * the items.txt file into the library inventory system.    *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should load all valid items from file.\n"
            << "------------------------------------------------------------\n";

    loadItemsFromFile("items.txt", libraryInventory);
    cout << "File loading completed.\n";


    cout << "\n/************************************************************\n"
            << " * Print Stored Items Demo: display all items that are      *\n"
            << " * currently checked into the library storage system.       *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display all available items.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.printStoredItems();


    cout << "\n/************************************************************\n"
            << " * Array Access Demo: use libraryInventory[shelf][slot] to  *\n"
            << " * access one specific item from the storage system.        *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display item at shelf 0, slot 0.\n"
            << "------------------------------------------------------------\n";

    try {
        Item *item = libraryInventory[0][0];

        if (item != nullptr) {
            cout << *item << endl;
        } else {
            cout << "That compartment is empty.\n";
        }
    } catch (const out_of_range &e) {
        cout << "Caught exception: " << e.what() << endl;
    }


    cout << "\n/************************************************************\n"
            << " * Add Item Demo: manually add a new Book object to shelf 3,*\n"
            << " * compartment 0, then display the item using [][] access.  *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should add and display a new book.\n"
            << "------------------------------------------------------------\n";

    try {
        libraryInventory.addItem(
            3,
            0,
            make_unique<Book>(
                "Book Item",
                "Extra test book added manually",
                "B999",
                "Manual Test Book",
                "Test Author",
                "2026"
            )
        );

        cout << "Manual item added successfully.\n";
        cout << *libraryInventory[3][0] << endl;
    } catch (const out_of_range &e) {
        cout << "Caught exception: " << e.what() << endl;
    }


    cout << "\n/************************************************************\n"
            << " * Checkout By Location Demo: check out one book, one movie,*\n"
            << " * and one magazine using shelf and compartment locations.  *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should show three successful checkouts.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.checkOutItemAtLocation(0, 0, "Alice", "2026-06-01");
    libraryInventory.checkOutItemAtLocation(1, 2, "Bob", "2026-06-10");
    libraryInventory.checkOutItemAtLocation(2, 4, "Cathy", "2026-06-15");


    cout << "\n/************************************************************\n"
            << " * Print Checked-Out Items Demo: display all checked-out    *\n"
            << " * items with borrower names and due dates.                 *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display the three checked-out items.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.printCheckOutItems();


    cout << "\n/************************************************************\n"
            << " * Checkin By Location Demo: return the item from shelf 0,  *\n"
            << " * compartment 0 back into storage.                         *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should show a successful checkin.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.checkInItemAtLocation(0, 0);


    cout << "\n/************************************************************\n"
            << " * Checkout By ID Demo: check out an item by its unique ID. *\n"
            << " * This is an extra feature beyond location checkout.       *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should check out item B002 by ID.\n"
            << "------------------------------------------------------------\n";

    string borrower1 = "David";
    string dueDate1 = "2026-06-20";
    libraryInventory.checkOutItemById("B002", borrower1, dueDate1);


    cout << "\n/************************************************************\n"
            << " * Checkin By ID Demo: return an item by its unique ID.     *\n"
            << " * This is an extra feature beyond location checkin.        *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should check in item B002 by ID.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.checkInItemById("B002");


    cout << "\n/************************************************************\n"
            << " * Swap Items Demo: swap two valid compartments that both   *\n"
            << " * contain library items.                                   *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should swap shelf 0 slot 1 with shelf 3 slot 0.\n"
            << "------------------------------------------------------------\n";

    try {
        libraryInventory.swapItems(0, 1, 3, 0);

        cout << "After swap, shelf 0, compartment 1 contains:\n";
        Item *item1 = libraryInventory[0][1];
        Item *item2 = libraryInventory[3][0];

        if (item1 != nullptr) {
            cout << "After swap, shelf 0, compartment 1 contains:\n";
            cout << *item1 << endl;
        } else {
            cout << "Shelf 0, compartment 1 is empty.\n";
        }

        if (item2 != nullptr) {
            cout << "After swap, shelf 3, compartment 0 contains:\n";
            cout << *item2 << endl;
        } else {
            cout << "Shelf 3, compartment 0 is empty.\n";
        }
    } catch (const out_of_range &e) {
        cout << "Caught exception: " << e.what() << endl;
    }


    cout << "\n/************************************************************\n"
            << " * Remove Item Demo: remove an item from one compartment    *\n"
            << " * and confirm that the compartment becomes empty.          *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should remove item at shelf 3, slot 0.\n"
            << "------------------------------------------------------------\n";

    try {
        libraryInventory.removeItem(3, 0);

        Item *item = libraryInventory[3][0];

        if (item == nullptr) {
            cout << "Shelf 3, compartment 0 is now empty.\n";
        } else {
            cout << "Shelf 3, compartment 0 still has an item:\n";
            cout << *item << endl;
        }
    } catch (const out_of_range &e) {
        cout << "Caught exception: " << e.what() << endl;
    }


    cout << "\n/************************************************************\n"
            << " * Error Test: attempt to check out an item that is already *\n"
            << " * checked out.                                             *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display an already checked-out error.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.checkOutItemAtLocation(1, 2, "Emma", "2026-07-01");


    cout << "\n/************************************************************\n"
            << " * Error Test: attempt to check in an item that is already  *\n"
            << " * checked in.                                              *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display an already checked-in error.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.checkInItemAtLocation(0, 0);


    cout << "\n/************************************************************\n"
            << " * Error Test: attempt to check out from an empty           *\n"
            << " * compartment.                                             *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display an empty compartment error.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.checkOutItemAtLocation(4, 0, "Frank", "2026-07-10");


    cout << "\n/************************************************************\n"
            << " * Error Test: attempt to check in from an empty            *\n"
            << " * compartment.                                             *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display an empty compartment error.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.checkInItemAtLocation(4, 1);


    cout << "\n/************************************************************\n"
            << " * Error Test: attempt to swap one filled compartment with  *\n"
            << " * one empty compartment.                                   *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display a swap error.\n"
            << "------------------------------------------------------------\n";

    try {
        libraryInventory.swapItems(0, 2, 4, 0);
    } catch (const out_of_range &e) {
        cout << "Caught exception: " << e.what() << endl;
    }


    cout << "\n/************************************************************\n"
            << " * Error Test: attempt to access a shelf that does not      *\n"
            << " * exist in the library inventory.                          *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should catch an invalid shelf exception.\n"
            << "------------------------------------------------------------\n";

    try {
        Item *item = libraryInventory[10][0];

        if (item != nullptr) {
            cout << *item << endl;
        }
    } catch (const out_of_range &e) {
        cout << "Caught exception: " << e.what() << endl;
    }


    cout << "\n/************************************************************\n"
            << " * Error Test: attempt to access a compartment that does    *\n"
            << " * not exist on a valid shelf.                              *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should catch an invalid compartment exception.\n"
            << "------------------------------------------------------------\n";

    try {
        Item *item = libraryInventory[0][20];

        if (item != nullptr) {
            cout << *item << endl;
        }
    } catch (const out_of_range &e) {
        cout << "Caught exception: " << e.what() << endl;
    }


    cout << "\n/************************************************************\n"
            << " * Final State Demo: display the final stored items and the *\n"
            << " * final checked-out items after all tests are complete.    *\n"
            << " ************************************************************/\n";

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display the final stored items.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.printStoredItems();

    cout << "------------------------------------------------------------\n"
            << " Output: The program should display the final checked-out items.\n"
            << "------------------------------------------------------------\n";

    libraryInventory.printCheckOutItems();

    return 0;
}
