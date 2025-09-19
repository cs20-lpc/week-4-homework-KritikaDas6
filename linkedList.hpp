#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
using namespace std;

template <typename T>
class linkedList {
protected:
    struct Node {
        T value;
        Node* next;
        Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) {}
    };

    Node* head;
    int length;

private:
    void copy(const linkedList<T>&);

public:
    linkedList();
    linkedList(const linkedList<T>&);
    linkedList<T>& operator=(const linkedList<T>&);
    virtual ~linkedList();

    virtual void append(const T&);
    virtual void clear();
    virtual T& getElement(int) const;
    virtual int getLength() const;
    virtual void insert(int, const T&);
    virtual bool isEmpty() const;
    virtual void remove(int);
    virtual void replace(int, const T&);

    template <typename U>
    friend ostream& operator<<(ostream&, const linkedList<U>&);
};

#include "linkedList.tpp"
#endif
