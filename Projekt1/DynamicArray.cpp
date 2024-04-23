//DynamicArray.cpp
#include "DynamicArray.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

DynamicArray::DynamicArray(int initialCapacity) : size(0), capacity(initialCapacity) {
    array = new int[capacity];          // Pocz¹tkowo tablica ma pojemnoœæ 1
}

DynamicArray::~DynamicArray() {
    delete[] array;     // Zwalniamy pamiêæ przydzielon¹ na tablicê
}

// Funkcja pomocnicza do zwiêkszenia pojemnoœci tablicy
void DynamicArray::resize() {
    capacity *= 2;  //Podwajamy pojemnoœæ
    int* newArray = new int[capacity];  //Tworzymy now¹ i wiêksz¹ tablicê
    for (int i = 0; i < size; i++) {    //Kopiujemy istniej¹ce elementy do nowej tablicy
        newArray[i] = array[i];
    }
    //Zwalniamy pamiêæ i przypisujemy now¹ tablicê do wskaŸnika
    delete[] array;
    array = newArray;
}


//Dodawanie elementu w dowolnym miejscu
bool DynamicArray::add(int index, int value) {
    if (index < 0 || index > size) {
        return false; //Indeks jest wiêkszy ni¿ rozmiar, wyszed³ poza zakres
    }
    if (size == capacity) {
        resize();
    }
    //Przesuwamy elementy, aby zrobiæ miejsce na nowy
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value;
    size++;
    return true;
}

//Dodawanie elementu na pocz¹tek
void DynamicArray::addFront(int value) {

    //add(0,value);    //inny sposob na dodanie elementu na poczatek, bez implementowania nowej funkcji

    if (size == capacity) {
        resize();   //zwiekszamy pojemnosc tablicy, jesli jest pelna
    }
    //Przesuwamy wszystkie elementy
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
    size++;
}

//Dodawanie elementu na koniec
void DynamicArray::addBack(int value) {
    if (size == capacity) {
        resize();   //zwiekszamy pojemnosc tablicy, jesli jest pelna
    }

    //add(size,value);    //inny sposob na dodanie elementu na koniec, bez implementowania nowej funkcji

    array[size++] = value;
}

//Usuwanie elementu z pocz¹tku
void DynamicArray::removeFront() {
    if (size == 0) return;
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

//Usuwanie elementu z koñca
void DynamicArray::removeBack() {
    if (size > 0) size--;
}


//Usuwanie elementu z dowolnego miejsca
bool DynamicArray::removeAt(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Blad: proba usuniecia elementu spoza listy." << std::endl;
        return false;   //Indeks jest wiêkszy ni¿ rozmiar, wyszed³ poza zakres
    }
    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
    return true;
}


//wyswietlanie zawartosci
void DynamicArray::print() {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


//Wczytywanie danych z pliku
void DynamicArray::loadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);   //otwieramy plik
    int value;

    if (!file.is_open()) {
        std::cerr << "Nie mo¿na otworzyæ pliku: " << fileName << std::endl;
        return;
    }

    while (file >> value) { //czytamy kazda linie pliku
        addBack(value);     //dodajemy wartosc na koniec tablicy
    }
    file.close();   //zamykamy plik
}