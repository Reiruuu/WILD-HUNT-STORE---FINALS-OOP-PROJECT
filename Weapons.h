// COMPROG FINAL PROJECT =======================================================================================
// PROJECT WILD HUNT STORE

#ifndef WEAPONS_H_INCLUDED
#define WEAPONS_H_INCLUDED
using namespace std;



// DERIVED CLASS WEAPONS =======================================================================================
class Weapon : public ObjEntity {
private://ENCAPSULATION_________________________________________________________________________________________
    string WPType;
    int Damage;

public:
    //DEFAULT CONSTRUCTOR_______________________________________________________________________________________
    Weapon() :
        ObjEntity(),
        WPType(""),
        Damage(0) {}

    //CONSTRUCTOR_______________________________________________________________________________________________
    Weapon(string OBN, int AMT, bool AVAIL, string WTP, int DMG)
        : ObjEntity(OBN, AMT, AVAIL), WPType(WTP), Damage(DMG) {}


    //POLYMORPHISM______________________________________________________________________________________________
    void ShowEntity() const override {
        cout << "| Name: " << GetOBN() << endl
             << "| Type: " << WPType << endl
             << "| Damage Stat: " << Damage << endl
             << "| Stock: " << GetQTY() << endl;
    }

    //DATA SAVING TO FILE FOR WEAPONS__________________________________________________________________________
    void SaveEntity(ofstream& out) const override {
        out << "WEAPON" << endl;
        out << GetOBN() << endl;
        out << WPType << endl;
        out << Damage << endl;
        out << GetQTY() << endl;
    }
};
#endif // WEAPONS_H_INCLUDED
// ==============================================================================================================
// KYM ANDREI LEGASPI / BSCS 12A1
