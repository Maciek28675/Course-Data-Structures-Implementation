//DynamicArray.cpp
#include "DynamicArray.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

DynamicArray::DynamicArray(int initialCapacity) : size(0), capacity(initialCapacity) {
    array = new int[capacity];          // Pocz�tkowo tablica ma pojemno�� 1
}

DynamicArray::~DynamicArray() {
    delete[] array;     // Zwalniamy pami�� przydzielon� na tablic�
}

// Funkcja pomocnicza do zwi�kszenia pojemno�ci tablicy
void DynamicArray::resize() {
    capacity *= 2;  //Podwajamy pojemno��
    int* newArray = new int[capacity];  //Tworzymy now� i wi�ksz� tablic�
    for (int i = 0; i < size; i++) {    //Kopiujemy istniej�ce elementy do nowej tablicy
        newArray[i] = array[i];
    }
    //Zwalniamy pami�� i przypisujemy now� tablic� do wska�nika
    delete[] array;
    array = newArray;
}


//Dodawanie elementu w dowolnym miejscu
bool DynamicArray::add(int index, int value) {
    if (index < 0 || index > size) {
        return false; //Indeks jest wi�kszy ni� rozmiar, wyszed� poza zakres
    }
    if (size == capacity) {
        resize();
    }
    //Przesuwamy elementy, aby zrobi� miejsce na nowy
    for (int i = size; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value;
    size++;
    return true;
}

//Dodawanie elementu na pocz�tek
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

//Usuwanie elementu z pocz�tku
void DynamicArray::removeFront() {
    if (size == 0) return;
    for (int i = 0; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    size--;
}

//Usuwanie elementu z ko�ca
void DynamicArray::removeBack() {
    if (size > 0) size--;
}


//Usuwanie elementu z dowolnego miejsca
bool DynamicArray::removeAt(int index) {
    if (index < 0 || index >= size) {
        std::cerr << "Blad: proba usuniecia elementu spoza listy." << std::endl;
        return false;   //Indeks jest wi�kszy ni� rozmiar, wyszed� poza zakres
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
        std::cerr << "Nie mo�na otworzy� pliku: " << fileName << std::endl;
        return;
    }

    while (file >> value) { //czytamy kazda linie pliku
        addBack(value);     //dodajemy wartosc na koniec tablicy
    }
    file.close();   //zamykamy plik
}