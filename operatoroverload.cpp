#include "iostream"
using namespace std;


//Funktor
class Counter{
    int count = 0;
    public:
    Counter():count(0){}

    int operator()(){
        return ++count;
    }
};



class Student{
    string name;
    int alter;

    public:
    Student(string name_, int alter_):name(name_), alter(alter_){}
    
    //Kopie Konstruktor, wird auch automatisch vom Compiler geschrieben
    /*
    Student(Student &other){
        name = other.name;
        alter = other.alter;
    }
    */

    void printStudent(){
        cout << "Name: " << this->name << endl;
        cout << "Alter: " << this->alter << endl;
    }

    
    



};


//Klasse zur Demonstration der Überladungen
class Messwert{
    int messwert;
    public:
    //Konstruktor
    Messwert(int _messwert):messwert(_messwert){}
    
    //Ausgabefunktion ohne Überladung
    void printMesswert(){
        cout << "Der Messwert: " << this->messwert << endl;
    }
    
    
    
    
    //Operatoren +,-,*,/, %
    Messwert operator+(Messwert &other){
        return Messwert(this->messwert + other.messwert);
    }

    Messwert operator-(Messwert &other){
        return Messwert(this->messwert - other.messwert);
    }
    
    Messwert operator*(Messwert &other){
        return Messwert(this->messwert * other.messwert);
    }
    
    Messwert operator/(Messwert &other){
        return Messwert(this->messwert / other.messwert);
    }

    Messwert operator%(Messwert &other){
        return Messwert(this->messwert % other.messwert);
    }
    
    
    //Präfix
    Messwert operator++(){
        messwert++;
        return *this;
    }

    Messwert operator--(){
        messwert --;
        return *this;
    }
    
    // Postfix Operatorüberladung
    Messwert operator++(int){
        Messwert temp = *this;
        messwert++;
        return temp;
    }

    Messwert operator--(int){
        Messwert temp = *this;
        messwert++;
        return temp;
    }




    
    
    //Überladung Ausgabeoperator
    friend ostream& operator<<(ostream& lhs, Messwert const &rhs){
        lhs << "Messwert: " << rhs.messwert;
        return lhs;
    } 

    //Überladung Eingabeoperator
    friend istream& operator>>(istream& lhs, Messwert &rhs){
        lhs >> rhs.messwert;
        return lhs;
    }



    //Überladung der Vergleichsoperatoren

    bool operator<(const Messwert& other) const {
        return this->messwert < other.messwert;
    }

    bool operator>(const Messwert& other) const {
        return this->messwert > other.messwert;
    }
    bool operator==(const Messwert& other) const {
        return this->messwert == other.messwert;
    }
    bool operator!=(const Messwert& other) const {
        return this->messwert != other.messwert;
    }
    bool operator<=(const Messwert& other) const {
        return this->messwert <= other.messwert;
    }
    bool operator>=(const Messwert& other) const {
        return this->messwert >= other.messwert;
    }

};

    



int main(){
    
    
    Messwert m1 = 10;
    Messwert m2 = 5;

    

    
//************************************************************************************* 
//*************************************************************************************    
    //Operatorüberladungen

    cout << "Überladung des Eingabeoperators:\nBitte die Werte für M1, dann für M2 eingeben:" << endl;
    cout << "\n";

    //Eingabeoperator Überladung
    cin >> m1;
    cin >> m2;
    cout << "\n";

    //Ausgabe der Ursprungswerte:
    cout << "M1" << m1 << endl; 
    cout << "M2" << m2 << endl;
    cout << "\n";

    //Berechnungsoperatoren +,-,*,/
    cout << "M1 + M2 = " << m1+m2 << endl;
    cout << "M1 - M2 = " << m1-m2 << endl;
    cout << "M1 * M2 = " << m1*m2 << endl;
    cout << "M1 / M2 = " << m1/m2 << endl;
    cout << "M1 % M2 = " << m1%m2 << endl;
    cout << "\n";

    //Vergleichsoperatoren
    cout << "Operator M1 > M2 :" << (m2 > m1) << endl;
    cout << "Operator M1 < M2 :" << (m2 < m1) << endl;
    cout << "Operator M1 <= M2 :" << (m2 <= m1) << endl;
    cout << "Operator M1 >= M2 :" << (m2 >= m1) << endl;
    cout << "Operator M1 == M2 :" << (m2 == m1) << endl;
    cout << "Operator M1 != M2 :" << (m2 != m1) << endl;
    cout << "\n";

    //Präfix
    cout << "Value vor Präfix: " << m1 << endl;
    cout << "Präfix ++M1 : " << ++m1 << endl;
    cout << "Präfix --M1 : " << --m1 << endl;
    cout << "\n";

    //Postfix
    cout << "Value vor Postfix: " << m1 << endl;
    cout << "Postfix M1++ : " << m1++ << endl;
    cout << "Postfix M1-- : " << m1-- << endl;
    cout << "\n";

}