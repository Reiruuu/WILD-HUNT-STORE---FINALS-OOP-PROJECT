// COMPROG FINAL PROJECT =======================================================================================
// PROJECT WILD HUNT STORE

#ifndef OBJENTITY_H_INCLUDED
#define OBJENTITY_H_INCLUDED
using namespace std;


// BASE CLASS ===================================================================================================
class ObjEntity {
private://ENCAPSULATION__________________________________________________________________________________________
    string ObjName;
    int Amount;
    bool InStock;

public:
    //DEFAULT CONSTRUCTOR________________________________________________________________________________________
    ObjEntity() : ObjName(""), Amount(0), InStock(true) {}

    //CONSTRUCTOR________________________________________________________________________________________________
    ObjEntity(string OBN, int AMT, bool AVAIL) {
        this->ObjName = OBN;
        this->Amount = AMT;
        this->InStock = AVAIL;
    }

    //MEMBER FUNCTIONS___________________________________________________________________________________________
    virtual void ShowEntity() const = 0;
    virtual void SaveEntity(ofstream& out) const = 0; // ABSTRACTION [PURE VIRTUAL FUNCTION] --------------------

    //SETTER_____________________________________________________________________________________________________
    bool SetBuyQTY(int BuyAmount) {
        if (BuyAmount <= 0) {
            cout << "Invalid amount!" << endl;
            return false;
        }
        if (BuyAmount > Amount) {
            cout << "Not enough stock!" << endl;
            return false;
        }

        Amount -= BuyAmount;
        if (Amount == 0) {
            InStock = false;
        }
        return true;
    }

    //GETTERS____________________________________________________________________________________________________
    string GetOBN() const { return ObjName; }
    int    GetQTY() const { return Amount;  }
    bool   GetSTK() const { return InStock; }

    //VIRTUAL DESTRUCTOR_________________________________________________________________________________________
    virtual ~ObjEntity() {}
};


#endif // OBJENTITY_H_INCLUDED
// ==============================================================================================================
// KYM ANDREI LEGASPI / BSCS 12A1
