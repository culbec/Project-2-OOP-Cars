#pragma once

#include "LDI.h"

template<typename TElem>
class Node;

template<typename TElem>
class LDI;

template<typename TElem>
class IteratorLDI {
private:
    // referinta peste container-ul pe care o sa il iteram
    const LDI<TElem> &list;

    // referinta peste elementul curent din lista
    Node<TElem> *current;

public:
    // constructor implicit
    explicit IteratorLDI(const LDI<TElem> &ldi) : list(ldi), current(list.prim) {}

    // constructor cu specificare de pozitie
    IteratorLDI(const LDI<TElem> &ldi, Node<TElem> *pos) : list(ldi), current(pos) {}

    Node<TElem> *getCurrent() { return this->current; }

    IteratorLDI<TElem> operator+(const int &size) {
        for (int i = 0; i < size; i++)
            this->current = this->current->getNext();
        return *this;
    }

    IteratorLDI<TElem> operator-(const int &size) {
        for (int i = 0; i < size; i++)
            this->current = this->current->getPrev();
        return *this;
    }

    bool operator<=(const IteratorLDI<TElem> &iter) {
        return this->current != iter.current->getNext();
    }

    bool operator<(const IteratorLDI<TElem> &iter) {
        return this->current != iter.current;
    }

    // pt. ++iter -> increment, dupa efectueaza operatia
    void operator++() { this->current = this->current->getNext(); }

    TElem operator*() { return this->current->getData(); }

    bool operator!=(const IteratorLDI<TElem> &iter) {
        return this->current != iter.current;
    }
};