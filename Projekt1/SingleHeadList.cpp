// List.cpp
#include "SingleHeadList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

// Implementacja konstruktora wezla
List::Node::Node(int data) : data(data), next(nullptr) {}

// Konstruktor listy, wskaznik head jako nullptr
List::List() : head(nullptr) {}

// Destruktor listy, usuwa wszystkie elementy
List::~List() {
    while (head != nullptr) {
        removeFront();
    }
}

//Dodawanie na poczatek listy
void List::addFront(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

//Dodawanie na koniec listy
void List::addBack(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Dodawanie w wybranym miejscu listy
bool List::addAt(int index, int data) {
    if (index == 0) {
        addFront(data);
        return true;
    }
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return false;
    }
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return true;
}

//Usuwa element z poczatku listy, wypisuje komunikat o bledzie jesli lista jest pusta
bool List::removeFront() {
    if (head == nullptr)
    {
        std::cerr << "Blad: proba usuniecia elementu z pustej listy." << std::endl;
        return false;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}

// Usuwa element z koñca listy
bool List::removeBack() {
    if (head == nullptr) {
        std::cerr << "Blad: proba usuniecia elementu z pustej listy." << std::endl;
        return false;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return true;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return true;
}

//Usuwa element z wybranego miejsca listy
bool List::removeAt(int index) {
    if (head == nullptr) {
        std::cerr << "Blad: proba usuniecia elementu z pustej listy." << std::endl;
        return false;
    }
    if (index == 0) {
        return removeFront();
    }
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < index - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        return false;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return true;
}

//Wyswietlanie wszystkich elementow listy
void List::print() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

//Wczytywanie danych z pliku i dodawanie ich na koniec listy
void List::loadFromFile(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku: " << fileName << std::endl;
        return;
    }

    int value;
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        if (ss >> value) {
            addBack(value);
        }
        else {
            std::cerr << "Nieprawidlowa linia w pliku: " << line << std::endl;
        }
    }
    file.close();
}