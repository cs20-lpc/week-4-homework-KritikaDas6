#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include "linkedList.tpp"
using namespace std;

template <typename T>
class linkedList{
    private:
        int length;
        struct Node {
            T value;
            Node* next;

            Node(T v = T(), Node* n = nullptr)
            : value(v), next(n) { }
        };

       
        Node* head;

    public:
        // default constructor
        linkedList();

        // destructor
        ~linkedList();

        linkedList(const LinkedList<T>& other);

        linkedList<T>& operator=(const linkedList<T>& other);

        // add the argument to the end of the list
        void append(const T&);

        // remove all elements in the list, resetting to the initial state
        void clear();

        // return the element at the given position (argument)
        T getElement(int) const;

        // return the current length of the list
        int getLength() const;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        void insert(int, const T&);

        // determine if the list currently empty
        bool isEmpty() const;

        // remove the element at the given position (argument)
        void remove(int);

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        void replace(int, const T&);

        // overloaded stream insertion operator to make printing easier
        template <typename U>
        friend ostream& operator<<(ostream&, const LinkedList<U>&);
};


#endif