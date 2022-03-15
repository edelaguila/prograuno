#include <iostream>


using namespace std;


class Wizzard{
  // Base Wizzard
  public:

    Wizzard(int base_power, int base_hp, string base_name){
      power = base_power;
      hp = base_hp;
      name = base_name;

    }

    float Damage(){
      return power;

    }

    void GetDamage(int damage_value){
      hp -= damage_value;
      cout << name << " HP: " << hp << endl;
    }

    void Speak(string dialog){
      cout << name << ": " << dialog << endl;
    }

    int GetHp(){
      return hp;
    }



  protected:
    float power, hp;
    string name;
};


class FireWizzard:public Wizzard{
  // This wizzard has more power atack but less hp
  public:
    FireWizzard(int base_power, int base_hp, string base_name) : Wizzard(base_power, base_hp, base_name){
      power = base_power + 10;
      hp = base_hp - 30;
      name = base_name;
  }

};

class IceWizzard:public Wizzard{
  // This wizzard has more life but less power atack

  public:
    IceWizzard(int base_power, int base_hp, string base_name) : Wizzard(base_power, base_hp, base_name){
      power = base_power - 20;
      hp = base_hp + 20;
      name = base_name;
  }

};


int main(){
  // apuntador al wizzard actual.
  Wizzard* current_wizzard;
  // INIT HARRY
  Wizzard Harry(20, 100, "Harry");
  Harry.Speak("Hola bienvenidos al juego.");
  // INIT GANDALF
  IceWizzard Gandalf(20, 100, "Gandalf");
  // INIT DUMBLEDORE
  FireWizzard Dumbledore(20, 100, "Dumbledore");
  int round = 1;

  // PROCESS FIGHT
  while(Dumbledore.GetHp() > 0 && Gandalf.GetHp() > 0){
    if(round % 2){
      Harry.Speak("Dumbledore Recibe Dano!!");
      current_wizzard = &Dumbledore;
      current_wizzard->GetDamage(Gandalf.Damage());
    }else{
      Harry.Speak("Gandalf Recibe Dano!!");
      current_wizzard = &Gandalf;
      current_wizzard->GetDamage(Dumbledore.Damage());
    }
    cout << "***************************************" << endl;
    ++round;
  }

  // PRINTING WINNWE
  if(Dumbledore.GetHp() < 0){
    Harry.Speak("GANADOR!!! GANDALF");
  }else{
    Harry.Speak("GANADOR!!! DUMBLEDORE");
  }

  return 0;
}
