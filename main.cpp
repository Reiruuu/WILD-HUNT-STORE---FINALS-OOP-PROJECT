// COMPROG FINAL PROJECT =======================================================================================
// PROJECT WILD HUNT STORE


// Simple Shop Inventory
// - Add a product
// - View all products
// - Sell a product (reduce quantity)

// ==============================================================================================================
// BUILT IN LIBRARIES
#include <iostream>
#include <fstream>
#include <vector>


// USER DEFINED LIBRARIES
#include "ObjEntity.h"    // BASE CLASS
#include "Items.h"        // DERIVED CLASS I
#include "Weapons.h"      // DERIVED CLASS II
#include "Shop.h"         // SOLO CLASS

// WILD HUNT STORE ==============================================================================================


//MENU FUNCTION__________________________________________________________________________________________________
void MenuNavigation(int Choice, Shop& A, bool& Shopping) {
    switch (Choice) {
        case 1:
            A.ShowStock();
            break;
        case 2:
            A.AddOBJ();
            break;
        case 3:
            A.RemoveOBJ();
            break;
        case 4:
            A.BuyOBJ();
            break;
        case 5:
            cout << endl;
            cout << "Program Exiting _ _ _" << endl;
            Shopping = false;
            break;
        default:
            cout << "That Feature Isn't Added Yet .  .  ." << endl << endl;
            break;
    }
};

// ==============================================================================================================

using namespace std;

int main()
{
    Shop shop;
    const string SHOPDATA = "stock.txt";
    bool Shopping = true;

    // LOAD FILE__________________________________________________________________________________________________
    shop.LoadShop(SHOPDATA);

    cout << "=== Welcome to the Wild Hunt Shop ===" << endl << endl;

    // MENU LOOP__________________________________________________________________________________________________
    do {
        int choice;
        cout << "SHOP - - - -" << endl
             << "--------------------------------" << endl
             << "1. Show Stock" << endl
             << "2. Add Item/Weapon" << endl
             << "3. Remove Item/Weapon" << endl
             << "4. Buy Item/Weapon" << endl
             << "5. Exit" << endl
             << "--------------------------------" << endl
             << "Enter your choice: ";
        cin >> choice;

        cin.ignore(1000, '\n');


        MenuNavigation(choice, shop, Shopping);

    } while (Shopping);

    // SAVE FILE (UPON EXIT)_____________________________________________________________________________________
    shop.SaveShop(SHOPDATA);

    cout << "Thank you for using the Shop Simulator!" << endl;
    return 0;
}
// ==============================================================================================================
// KYM ANDREI LEGASPI / BSCS 12A1
