#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

// Las funciones se declaran antes del main

// Void es si la funcion solo imprime datos
void imprimirCosas(){

    printf("Game over....");

}
//Clase padre
class Mage{
public:
    //Constructor
    Mage(int BasePower, int BaseHp, string name)
    {
        Power = BasePower;
        hp = BaseHp;
        Name = name;
    }
    float Damage()
    {
        return Power;
    }
    void GetDamage(int Value)
    {
        hp= hp-Value;
    }
    int life()
    {
        return hp;
    }
    string get_name()
    {
        return Name;
    }
protected:
    int Power, hp;
    string Name;
};

//Clase hija 1
class IceMage : public Mage
{
    public:
    IceMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower + 1;
        hp = BaseHp +1;
        Name = name;
    }
    int ice_attack(){

        return  (rand() % Power) + 1;
    }
};

//Clase hija 2
class FireMage : public Mage
{
    public:
    FireMage(int BasePower, int BaseHp, string name) : Mage(BasePower, BaseHp, name)
    {
        Power = BasePower;
        hp = BaseHp + 10;
        Name = name;
    }
    int fire_attack(){
        return  (rand() % Power) + 1;
    }
};
int main()
{
    Mage* Current_mage;
    Mage Harry(10, 100, "Harry");
    IceMage Dumbledore(11, 100, "Dumbledore");
    FireMage Gandalf(11,100, "Gandalf");
    //fuck_pointers();
    //imprimirCosas();
    bool chance = true;
    int attack_value;
    for (int i=0;i<10;i++){
        if (chance){
            Current_mage = &Dumbledore;
            attack_value = Dumbledore.ice_attack();
            cout<<" attack :"<<attack_value;
            Current_mage->GetDamage(attack_value);
            cout<<Current_mage->get_name()<<"- current life :"<<Current_mage->life()<<endl;
            chance = false;
        }
        else {
            Current_mage = &Gandalf;
            attack_value = Gandalf.fire_attack();
            cout<<" attack :"<<attack_value;
            Current_mage->GetDamage(attack_value);
            cout<<Current_mage->get_name()<<"- current life :"<<Current_mage->life()<<endl;
            chance = true;
        };
    }
    return 0;
}

