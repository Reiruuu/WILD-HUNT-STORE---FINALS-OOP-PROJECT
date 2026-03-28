// COMPROG FINAL PROJECT =======================================================================================
// PROJECT WILD HUNT STORE


#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED
using namespace std;


// DERIVED CLASS ITEMS ==========================================================================================
class Item : public ObjEntity {
private://ENCAPSULATION__________________________________________________________________________________________
    string Type;

public:
    //DEFAULT CONSTRUCTOR________________________________________________________________________________________
    Item() :
        ObjEntity(),
        Type("") {}
    //CONSTRUCTOR________________________________________________________________________________________________
    Item(string OBN, int AMT, bool AVAIL, string TP)
        : ObjEntity(OBN, AMT, AVAIL), Type(TP) {}


    //POLYMORPHISM_______________________________________________________________________________________________
    void ShowEntity() const override {
        cout << "| Name: " << GetOBN() << endl
             << "| Type: " << Type << endl
             << "| Stock: " << GetQTY() << endl;
    }

    // DATA SAVING TO FILE FOR ITEMS_____________________________________________________________________________
    void SaveEntity(ofstream& out) const override {
        out << "ITEM" << endl;
        out << GetOBN() << endl;
        out << Type << endl;
        out << GetQTY() << endl;
    }
};
#endif // ITEMS_H_INCLUDED
// ==============================================================================================================
// KYM ANDREI LEGASPI / BSCS 12A1
