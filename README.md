Die **Operatorüberladung** in C++ ermöglicht es, `Operatoren` wie `+, -, *, /` und andere für benutzerdefinierte Datentypen (`Objekte von Klassen`) zu definieren. Dies erlaubt es, objektorientierten Code lesbarer und intuitiver zu gestalten, indem sich Operationen auf Objekte von benutzerdefinierten Klassen genauso verwenden lassen wie auf den eingebauten Datentypen. Dieses Beispiel zeigt alle möglichen Operatorüberladungen in C++. *(noch nicht Vollständig!)*


## Alle Beispiele basieren auf dieser Klasse:
```c++
class Messwert{
int messwert;
public:
//Konstruktor
Messwert(int _messwert):messwert(_messwert){}
/*...*/
```

## 1. Arithmethische Operatoren
Diese Operatoren lassen sich durch dieses Schema überladen:
```c++
Messwert operator+(Messwert &other){
return Messwert(this->messwert + other.messwert);
}
```
Das `+` kann dabei durch die Operatoren `(-, *, /, %)` ersetzt werden.

## 2. Präfix / Postfix Operatoren
Die `Präfix`  Operatoren können wie folgt überschrieben werden:
```c++
Messwert operator++(){
messwert++;
return *this;
}
```
...und Postfix Operatoren:
```c++
Messwert operator++(int){
Messwert temp = *this;
messwert++;
return temp;
}
```
`Plus (++)` kann auch durch `Minus (--)` ersetzt werden.


## 3. Vergleichsoperatoren
Die Vergleichsoperatoren `<, >, ==, !=, <= und >=` können wie folgt überladen werden:
```c++
bool operator>(const Messwert& other) const {
return this->messwert > other.messwert;
}
bool operator==(const Messwert& other) const {
return this->messwert == other.messwert;
}
bool operator>=(const Messwert& other) const {
return this->messwert >= other.messwert;
}
```
Auch hier können die Beispiele einfach durch die restlichen Vergleiche ersetzt werden.

## 4. Ausgabe/ Eingabeoperatoren Überladung

...ermöglicht es, Objekte von Klassen durch den `<<`-Operator auszugeben oder durch den `>>`-Operator Werte einzulesen und in den Objekten zu speichern. Dabei gibt es einige Dinge, die zu beachten sind:
* Die `Überladung` kann entweder als `Memberfunktion` der Klasse oder als freie Funktion erfolgen. Bei der Ausgabeüberladung ist es häufig sinnvoll, sie als freie Funktion zu implementieren, während die Eingabeüberladung oft als Mitgliedsfunktion erfolgt.
* Die Funktionen für die Ausgabe- und Eingabeüberladung sollten im Allgemeinen einen Rückgabetyp von `std::ostream&` bzw. `std::istream&` haben, um die Verkettung von Ein- oder Ausgaben zu ermöglichen.

#### Beispiele:
```c++
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
```



