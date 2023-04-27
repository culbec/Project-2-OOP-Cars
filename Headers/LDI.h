#pragma once

#include "IteratorLDI.h"
#include <string>

using std::string;

template<typename TElem>
class IteratorLDI;

// LDI - clasa parametrizata

template<typename TElem>
class Node {
private:
    // referinta catre precedentul & urmatorul nod
    Node<TElem> *prev;
    Node<TElem> *next;
    // informatia importanta
    TElem data;
public:
    /*
     * Node constructor
     * @pre: true
     * @post: se creeaza un nod
     */
    Node(TElem data, Node *prev, Node *next) : data{data}, prev{prev}, next{next} {}

    // getters & setters
    TElem getData() const { return this->data; }

    void setData(const TElem &elem) { this->data = elem; }

    Node *getPrev() const { return this->prev; }

    void setPrev(Node *prevS) {
        this->prev = prevS;
    }

    Node<TElem> *getNext() const { return this->next; }

    void setNext(Node *nextS) {
        this->next = nextS;
    }
};

template<typename TElem>
class LDI {
    friend class IteratorLDI<TElem>;

private:
    // clasa pentru nod -> elementul central din lista inlantuita

    // interfata contine o referinta catre primul nod
    Node<TElem> *prim;
    // interfata contine o referinta catre ultimul nod
    Node<TElem> *ultim;

    // si dimensiunea sa
    unsigned int sizeLDI;

    // functie de delete a listei inlantuite
    void deleteNodes(Node<TElem> *ref) {
        if (ref == ultim)
            return;
        deleteNodes(ref->getNext());
        delete ref;
    }

public:
    // constructor
    LDI<TElem>() : prim{nullptr}, ultim{nullptr}, sizeLDI{0} {}

    // constructor de copiere
    LDI<TElem>(const LDI<TElem> &other) : prim{nullptr}, ultim{nullptr}, sizeLDI{0} {
        Node<TElem> *refOther = other.prim; // parcurgem lista pentru a adauga noile elemente

        while (refOther != nullptr) {
            this->add(refOther->getData());

            refOther = refOther->getNext();
        }
    }

    // constructor de copiere (assignment)
    LDI<TElem> &operator=(const LDI<TElem> &other) {
        if (this == &other) // s-a facut L = L
            return *this;

        // distrugem instanta curenta
        this->deleteNodes(this->prim);
        this->prim = nullptr;
        this->ultim = nullptr;

        Node<TElem> *refOther = other.prim; // parcurgem lista pentru a adauga noile elemente

        while (refOther != nullptr) {
            this->add(refOther->getData()); // adaugam elementul

            refOther = refOther->getNext(); // iteram in continuare
        }
        this->sizeLDI = other.sizeLDI; // actualizam lungimea

        return *this; // returnam lista
    }

    // move constructor - fura datele de la other si il marcheaza pentru distrugere
    LDI<TElem>(LDI<TElem> &&other) noexcept: prim{other.prim}, ultim{other.ultim}, sizeLDI{other.sizeLDI} {
        // dealocam datele de la sursa de unde am mutat informatiile
        other.prim = nullptr;
        other.ultim = nullptr;
        other.sizeLDI = 0;
    }

    // move constructor (assignment) - distruge instanta curenta, fura datele de la other si il marcheaza
    //                                 pentru distrugere
    LDI<TElem> &operator=(LDI<TElem> &&other) noexcept {
        if (this == &other) // s-a facut L = L
            return *this;

        // stergem instanta curenta
        this->deleteNodes(this->prim);

        // 'furam' datele
        this->prim = other.prim;
        this->ultim = other.ultim;
        this->sizeLDI = other.sizeLDI;

        // il pregatim pe other pentru distrugere
        other.prim = nullptr;
        other.ultim = nullptr;
        other.sizeLDI = 0;

        return *this;
    }

    /**
     * @brief push_back pentru LDI
     * @pre true
     * @post se adauga elementul in lista inlantuita
     */

    void push_back(const TElem &elem) {
        // instantiem un nod nou
        auto *nod = new Node<TElem>(elem, nullptr, nullptr);

        // lista este goala
        if (this->prim == nullptr) {
            this->prim = nod;
            this->ultim = nod;
        }
            // lista nu este goala
        else {
            nod->setPrev(this->ultim);
            this->ultim->setNext(nod);
            this->ultim = nod;
        }
        // incrementam dimensiunea
        this->sizeLDI++;
    }

    void add(const TElem &elem) {
        this->push_back(elem);
    }

    // functie ce returneaza dimensiunea listei
    unsigned int size() const { return this->sizeLDI; }

    // functie pentru verificarea listei vide
    bool empty() const { return this->sizeLDI == 0; }

    /**
     * @brief Functia 'at' -> returneaza un element de pe o anumita pozitie
     * @param poz Pozitia elementului care va fi sters
     * @pre: poz -> pozitie valida din lista inlantuita
     * @post: elementul de pe pozitia poz sau
     */
    TElem at(unsigned int poz) const {
        // pastram o referinta catre primul element
        auto *ref = this->prim;

        // iteram pana cand gasim elementul
        for (unsigned int i = 0; i < poz; i++)
            ref = ref->getNext();

        // returnam elementul
        return ref->getData();
    }

    TElem get(unsigned int poz) const {
        auto *ref = this->prim;

        for (unsigned int i = 0; i < poz; i++)
            ref = ref->getNext();

        return ref->getData();
    }

    /**
     * @brief Functia 'erase' -> sterge un element de pe o anumita pozitie
     * @pre refElem -> referinta catre elementul de sters
     * @post elementul se va sterge din lista
     */

    void erase(Node<TElem> *refElem) {
        if (this->sizeLDI == 1) {
            delete refElem;
            this->prim = nullptr;
            this->ultim = nullptr;
            this->sizeLDI--;
        } else if (refElem == this->prim) {
            this->prim = refElem->getNext();
            this->prim->setPrev(nullptr);
            delete refElem;
            this->sizeLDI--;
        }
            // verificam daca se sterge ultimul element
        else if (refElem == this->ultim) {
            this->ultim = refElem->getPrev();
            this->ultim->setNext(nullptr);
            delete refElem;
            this->sizeLDI--;
        }
            // se sterge un element oarecare din lista
        else {
            refElem->getPrev()->setNext(refElem->getNext());
            refElem->getNext()->setPrev(refElem->getPrev());
            delete refElem;
            this->sizeLDI--;
        }
    }

    void swap(const unsigned int &thisPos, const unsigned int &otherPos) {
        // parcurgem lista pana la prima pozitie
        Node<TElem> *refThis = this->prim;

        for (unsigned int i = 0; i < thisPos; i++)
            refThis = refThis->getNext();

        // parcurgem lista pana la a doua pozitie
        Node<TElem> *refOther = this->prim;

        for (unsigned int i = 0; i < otherPos; i++)
            refOther = refOther->getNext();

        // swap intre elemente
        TElem temp = refThis->getData();
        refThis->setData(refOther->getData());
        refOther->setData(temp);
    }

    /**
     * @brief Functia 'begin' / end -> returneaza un iterator peste primul / ultimul element din lista
     * @pre: true
     * @post: referinta catre primul / ultimul element din lista
     */
    IteratorLDI<TElem> begin() const { return IteratorLDI<TElem>(*this); }

    IteratorLDI<TElem> end() const { return IteratorLDI<TElem>(*this, this->ultim->getNext()); }

    // destructor
    ~LDI() { this->deleteNodes(this->prim); }
};