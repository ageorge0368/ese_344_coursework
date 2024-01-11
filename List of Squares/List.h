//#ifndef LIST_H
#define LIST_H

#include <algorithm>
//#include "Const_iterator.h"
//#include "Iterator.h"
//#include "Node.h"
using namespace std;

//template <typename Object> class iterator;

//template <typename Object> class const_iterator;


///////////////////////////////////////////////////////// Change this list class into a SINGLY-LINKED LIST! /////////////////////////////////////////////////////

template <typename Object>
class List
{
private:
    // The basic doubly linked list node.
        // SHOULD BE A SINGLY-LINKED LIST //
 
    // Nested inside of List, can be public
    // because the Node is itself private
//    template <typename Object>
    struct Node
    {
        Object  data;
//        Node* prev;
        Node* next;

        Node(const Object& d = Object{ }, Node* n = nullptr)
            : data{ d }, next{ n } { }

        Node(Object&& d, Node* n = nullptr)
            : data{ std::move(d) }, next{ n } { }

    };

public:
//    template<typename Object>
//    class const_iterator
//    {
//    public:
//        
//        // Public constructor for const_iterator.
//        const_iterator() : current{ nullptr }
//        { }
//
//        // Return the object stored at the current position.
//        // For const_iterator, this is an accessor with a
//        // const reference return type.
//        const Object& operator* () const
//        {
//            return retrieve();
//        }
//
//        const_iterator& operator++ ()
//        {
//            current = current->next;
//            return *this;
//        }
//
//        const_iterator operator++ (int)
//        {
//            const_iterator old = *this;
//            ++(*this);
//            return old;
//        }
//
//        const_iterator& operator-- ()
//        {
////            current = current->prev;
////            return *this;
//        
//
////            Node<Object>* ptr = this->theList->head->next;      // starting from the first node on the linked list
//            
//            Node* ptr = this->head->next;      // starting from the first node on the linked list
//            while (ptr->next != this->current) {// check for other boundary conditions here
//                ptr = ptr->next;
//            }
//            this->current = ptr;
//            return *this;
//
//        }
//
//        const_iterator operator-- (int)
//        {
//            const_iterator old = *this;
//            --(*this);
//            return old;
//        }
//
//        bool operator== (const const_iterator& rhs) const
//        {
//            return current == rhs.current;
//        }
//
//        bool operator!= (const const_iterator& rhs) const
//        {
//            return !(*this == rhs);
//        }
//
//    protected:
////        const List<Object>* theList;                    // the list for which the head belongs 
//        Node* head;                                     // head of the list for which the iterator belongs (if theList doesn't work!)
//        Node* current;
//
//
//        // Protected helper in const_iterator that returns the object
//        // stored at the current position. Can be called by all
//        // three versions of operator* without any type conversions.
//        Object& retrieve() const
//        {
//            return current->data;
//        }
//
//        // Protected constructor for const_iterator.
//        // Expects a pointer that represents the current position.
////        const_iterator(const List<Object>& lst, const Node<Object>* p) : theList{ &lst }, current { p }
////        { }
//
//
//
//        const_iterator(Node* p, Node* h) : current{ p }, head{ h }
//        { }
//
//        friend class List<Object>;
//    };

    class iterator
    {
    public:
//        using const_iterator::const_iterator;
 
        // Public constructor for iterator.
        // Calls the base-class constructor.                                    
        // (Base class: const_iterator, Derived class: iterator)

        // Must be provided because the private constructor
        // is written; otherwise zero-parameter constructor
        // would be disabled.



        // Data Fields
        Node* head;                                     // head of the list for which the iterator belongs (if theList doesn't work!)
        Node* current;

        // Constructor
        iterator(Node* p = nullptr, Node* h = nullptr) {
            current = p;
            head = h;
        }


        Object& operator* ()
        {
            return current->data;
        }

        // Return the object stored at the current position.
        // For iterator, there is an accessor with a
        // const reference return type and a mutator with
        // a reference return type. The accessor is shown first.
        //const Object& operator* () const
        //{
        //    return const_iterator::operator*();
        //}

        iterator& operator++ ()
        {
            this->current = this->current->next;
            return *this;
            
        }

        iterator operator++ (int)
        {
            iterator old = *this;
            ++(*this);
            return old;
        }
        
        iterator& operator-- ()
        {
            Node* ptr = this->head;      // starting from the first node on the linked list
            while (ptr->next != this->current) {// check for other boundary conditions here
                ptr = ptr->next;
            }
            this->current = ptr;
            return *this;

        }

        iterator operator-- (int)
        {
            //////////////////////////////////////////////////////////////// Add code here! ////////////////////////////////////////////////////////////////////

            iterator old = *this;
            --(*this);
            return old;
        }

//    protected:
        // Protected constructor for iterator.
        // Expects the current position.
//        iterator(List<Object>& lst, Node<Object>* p) : const_iterator<Object>(lst, p) {}
//        { }
//        iterator(Node* p, Node* h) : const_iterator(p, h) {}
 //       iterator(Node* p = nullptr, Node* h = nullptr) : const_iterator(p, h) {}
//        friend class List<Object>;
    };

private:
    // Data fields of the list
    int   theSize;
    Node* head;
    Node* tail;

    // In creating a new linked list (from the beginning)
    // Make a new init function for just a singly-linked list
    void init()
    {
        theSize = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

public:
    // CONSTRUCTOR
    List()              
    {
        init();
    }

    //// DESTRUCTOR
    //~List()
    //{
    //    clear();
    //    delete head;
    //    delete tail;
    //}

    // Copy Constructor (FOR PROJECT)
    List(const List& rhs)
    {
        init();
        for (auto& x : rhs) {
            push_back(x);
        }
    }

    // Assignment Operator (FOR PROJECT)
    List& operator= (const List& rhs)
    {
//        theSize = rhs.theSize;
        Node* newNode = new Node{};

        Node* rhsPtr = rhs.head;
        while (rhsPtr != nullptr) {
            newNode->data = rhsPtr->data;

            this->push_back(newNode->data);

            // iterate rhsPtr
            rhsPtr = rhsPtr->next;
        }

        return *this;
    }


    List(List&& rhs)
        : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
    {
        rhs.theSize = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }

    // Assignment operator
    List& operator= (List&& rhs)
    {
        theSize = rhs.theSize;
        Node* newNode = new Node{};
        Node* rhsPtr = rhs.head->next;
        while (rhsPtr != nullptr) {
            newNode->data = rhsPtr->data;
            this->push_back(newNode);
            rhsPtr = rhsPtr->next;
        }

        return *this;
    }

    // Return iterator representing beginning of list.
    // Mutator version is first, then accessor version.
    iterator begin()
    {
        return iterator(head, head);
    }

    //const_iterator begin() const
    //{
    //    return const_iterator(head->next, head);
    //}

    // Return iterator representing endmarker of list.
    // Mutator version is first, then accessor version.
    iterator end()
    {
        return iterator(tail, head);
    }

    //const_iterator end() const
    //{
    //    return const_iterator(tail, head);
    //}

    // Return number of elements currently in the list.
    int size() const
    {
        return theSize;
    }

    // Return true if the list is empty, false otherwise.
    bool empty() const
    {
        return size() == 0;
    }

    // Clear (FOR PROJECT)
        // DONE
    void clear()
    {
        while (!empty())
            pop_front();
    }

    // front, back, push_front, push_back, pop_front, and pop_back
    // are the basic double-ended queue operations.
    Object& front()
    {
        return *begin();
    }

    const Object& front() const
    {
        return *begin();
    }

    Object& back()
    {
        return *--end();
    }

    const Object& back() const
    {
        return *--end();
    }

    // Stack and Queue Operations (FOR PROJECT)
        // DONE???
    void push_front(const Object& x)
    {
        insert_front(begin(), x);
    }

    // Stack and Queue Operations (FOR PROJECT)
        // DONE???
    void push_back(const Object& x)
    {
        insert_back(end(), x);
    }

    //void push_front(Object&& x)
    //{
    //    insert_front(begin(), std::move(x));
    //}
    //    // DONE???
    //void push_back(Object&& x)
    //{
    //    insert_back(end(), std::move(x));
    //}

    // Stack and Queue Operations (FOR PROJECT)
        // DONE???
    void pop_front()
    {
        erase(begin());
    }

    // Stack and Queue Operations (FOR PROJECT)
        // DONE???
    void pop_back()
    {
        erase(end());
    }

    iterator insert_front(iterator itr, const Object& x) {
        // Inserting at head

        // If head == nullptr

        if (itr.current == nullptr) {
            Node* newNode = new Node{ x };

            head = newNode;
            tail = head;
            ++theSize;
            return iterator(head, head);
        }

        // If head == a value that exists

        Node* newNode = new Node{ x };

        newNode->next = head;
        head = newNode;
        ++theSize;
        return iterator(head, head);
    }


    // Insert x before itr.
    iterator insert_back(iterator itr, const Object& x)
    {
        
        // itr == nullptr
        if (itr.current == nullptr) {
            Node* newNode = new Node{ x };

            head = newNode;
            tail = head;
            ++theSize;
            return iterator(head, head);
        }

        // itr == is an exisitng value

        Node* newNode = new Node{ x };
        itr.current->next = newNode;
        tail = newNode;
        ++theSize;
        return iterator(tail, head);
    }

    iterator insert_between(int position, const Object& x)
    {
        // when p = 0; p => insert at the head node
        Node* newNode = new Node{ x };

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            ++theSize;
            return iterator(head, head);
        }

        // when p = L3.size() => inserting at last element
        if (position == this->size()) {
            tail->next = newNode;
            newNode->next = nullptr;
            tail = newNode;
//            newNode = tail;

            ++theSize;
            return iterator(tail, head);
        }

        // when p = any other valid number
        
        iterator ptr = this->begin();
        for (int i = 0; i < position; i++) {
            ++ptr;
        }

        iterator oneItrBehind = this->begin();
        for (int i = 0; i < (position - 1); i++) {
            ++oneItrBehind;
        }

        newNode->next = ptr.current;
        oneItrBehind.current->next = newNode;


        ++theSize;
        return iterator(newNode, head);
    }

    // Erase item at itr.
    iterator erase(iterator itr)
    {
        Node* p = itr.current;

        // Case if the node to be deleted is the head
        if (head == p) {
            head = head->next;

            delete p;
            --theSize;
//            head->next = p->next;
            return iterator(head, head);
        }

        // Case if the node to be deleted is the tail (last node)
        if (p == tail) {
            Node* oneBehind = head;
            while (oneBehind->next != p) {
                oneBehind = oneBehind->next;
            }

//            oneBehind = tail;
            tail = oneBehind;
            tail->next = nullptr;
            delete p;
            --theSize;

            return iterator(tail, head);
        }

//        iterator retVal(p->next);
        
        // Middle cases
        // Gets to node one behind node that gets erased
        Node* oneBehind = head;
        while (oneBehind->next != p) {
            oneBehind = oneBehind->next;
        }

        oneBehind->next = p->next;
        delete p;
        --theSize;

        return iterator(oneBehind, head);
    }

    iterator erase(iterator from, iterator to)
    {
        for (iterator itr = from; itr != to; )
            itr = erase(itr);

        return to;
    }

    void deleteOdds() {
        int maxListSize = this->size();
        iterator listItr = this->begin();

        // Deleting all Odd Nodes
        for (int i = 0; i < maxListSize * 2; i++) {
            bool checkDec = true;

            if (listItr.current == nullptr) {
                break;            // end of the deletions (end of loop)
            }

            if ((listItr.current->data.getSide() % 2) == 1) {           // if side length is odd
                if (listItr.current == head) {
                    checkDec = false;
                }
                
                iterator deletingItr = listItr;

                ++listItr;

                erase(deletingItr);

                if (checkDec == false) {
                    continue;
                }
                else {
                    // Going back One Node
                    iterator prevNode = --listItr;                                  // decrement listItr
                    if (prevNode.current != nullptr) {
                        cout << prevNode.current->data << endl;
                    }
                }
            }

            ++listItr;

        }
    }

    void printList() {
        iterator listItr = this->begin();
        
        while (listItr.current != nullptr) {
            cout << listItr.current->data << endl;
            ++listItr;
        }
    }

    bool checkSquareExists(const Object& x) {
        iterator listItr = this->begin();
        while (listItr.current != nullptr) {
            if (listItr.current->data == x) {
                return true;
            }
        }

        return false;
    }
};

//#endif