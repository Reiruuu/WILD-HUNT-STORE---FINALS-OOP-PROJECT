// COMPROG FINAL PROJECT =======================================================================================
// PROJECT WILD HUNT STORE


#ifndef SHOP_H_INCLUDED
#define SHOP_H_INCLUDED
using namespace std;


// SHOP CLASS ===================================================================================================

class Shop {
private:
    const int Max_OBJ = 10;
    vector<ObjEntity*> ObjEntities;

public:
    //DESTRUCTOR_________________________________________________________________________________________________
    ~Shop() {
        for (ObjEntity* obj : ObjEntities) {
            delete obj;
        }
        ObjEntities.clear();
    }

    void I_LineDecorDisp() const
    { cout << "--------------------------------" << endl; }
    void II_LineDecorDisp() const
    { cout << "================================" << endl; }




// SHOP MENU FUNCTION ===========================================================================================


    //___________________________________________________________________________________________________________
    void ShowStock() {
        if (NullStock()) return;
        int i = 1;
        II_LineDecorDisp();
        for (ObjEntity* O : ObjEntities) {
            cout << "[" << i++ << "] " << endl;
            O->ShowEntity();
            cout << endl;
        }
        II_LineDecorDisp();
        cout << endl << endl;
    }

    bool NullStock() const {
        if (ObjEntities.empty()) {
            cout << "There are no Items/Weapons currently stocked!" << endl;
            return true;
        }
        return false;
    }

    //___________________________________________________________________________________________________________
    void AddOBJ() {
        if (ObjEntities.size() >= Max_OBJ) {
            cout << "No more space in the shop!" << endl;
            return;
        }

        int Choice;
        cout << "[1] Item"   << endl
             << "[2] Weapon" << endl
             << "Pick: ";
        cin >> Choice;
        cin.ignore(1000, '\n');
        string Name, SubType;
        int Qty, Dmg;

        if (Choice != 1 && Choice != 2) {
            cout << "That Obj Type Isn't Implemented Yet . . ." << endl << endl;
        return;
    }

        cout << "Enter Name: ";
        getline(cin, Name);
        cout << "Enter Amount: ";
        cin >> Qty;
        cin.ignore(1000, '\n');

        if (Choice == 1) {
            cout << "Enter Item Type: ";
            getline(cin, SubType);
            ObjEntities.push_back(new Item(Name, Qty, true, SubType));
            cout << "---> Item Listed Successfully <---" << endl << endl;
        } else {
            cout << "Enter Weapon Type: ";
            getline(cin, SubType);
            cout << "Enter Damage Capabilities: ";
            cin >> Dmg;
            cin.ignore(1000, '\n');
            ObjEntities.push_back(new Weapon(Name, Qty, true, SubType, Dmg));
            cout << "---> Weapon Listed Successfully <---" << endl << endl;
        }
    }
    //___________________________________________________________________________________________________________
    void RemoveOBJ() {
        if (NullStock()) return;

        int i;
        cout << "Enter OBJ ID To Remove: ";
        cin >> i;
        i--;

        if (i < 0 || i >= (int)ObjEntities.size()) {
            cout << "Invalid ID!" << endl;
            return;
        }

        cout << "[ " << ObjEntities[i]->GetOBN() << " ] Removed From The Shelves"
             << endl
             << endl;
        delete ObjEntities[i];
        ObjEntities.erase(ObjEntities.begin() + i);
    }

    //___________________________________________________________________________________________________________
    void BuyOBJ() {
        if (NullStock()) return;

        ShowStock();
        int Choice, BuyAmount;
        cout << "Enter the number of the object to buy: ";
        cin >> Choice;
        Choice--;

        if (Choice < 0 || Choice >= (int)ObjEntities.size()) {
            cout << "Invalid selection!" << endl;
            return;
        }

        cout << "Enter quantity to buy: ";
        cin >> BuyAmount;

        if (ObjEntities[Choice]->SetBuyQTY(BuyAmount)) {
            cout << "Buyer Obtained "
                 << BuyAmount
                 << " [ "
                 << ObjEntities[Choice]->GetOBN()
                 << " ] "
                 << endl << endl;
        }
    }


// DATA FILE HANDLER ============================================================================================


    //FILE SAVING________________________________________________________________________________________________
    void SaveShop(const string& Filename) const {
        ofstream Out(Filename);
        if (!Out) {
            cout << "! Data Cannot Be Saved Due To Errors " << endl;
            return;
        }

        for (ObjEntity* obj : ObjEntities) {
            obj->SaveEntity(Out);
        }
        Out.close();
        cout << "Shop Data Saved To Files" << endl;
    }

    //FILE LOADER________________________________________________________________________________________________
    void LoadShop(const string& Filename) {
        ifstream In(Filename);
        if (!In) {
            cout << "--- No Previous Shop Data Found ---"
            << endl << endl;
            return;
        }

        string Tag;
        while (getline(In, Tag)) {
            if (Tag == "ITEM") {
                string Name, SubType;
                int Qty;
                getline(In, Name);
                getline(In, SubType);
                In >> Qty;
                In.ignore(1000, '\n');

                ObjEntities.push_back(new Item(Name, Qty, true, SubType));
            }
            else if (Tag == "WEAPON") {
                string Name, SubType;
                int Dmg, Qty;
                getline(In, Name);
                getline(In, SubType);
                In >> Dmg;
                In >> Qty;
                In.ignore(1000, '\n');

                ObjEntities.push_back(new Weapon(Name, Qty, true, SubType, Dmg));
            }
        }
        In.close();
        cout << "--- Shop Data Loaded Successfully ---" << endl << endl;
    }
};



#endif // SHOP_H_INCLUDED
// ==============================================================================================================
// KYM ANDREI LEGASPI / BSCS 12A1
