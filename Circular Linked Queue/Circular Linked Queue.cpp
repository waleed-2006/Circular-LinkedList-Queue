// Circular Linked Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename V>
class CNode {
    V _value;
    CNode<V>* _next;
    template <typename V>
    friend class CLinkedListQueue;
public:
    CNode(const V& v) {
        _value = v;
        _next = nullptr;
    }
    CNode() {
        _next = nullptr;
    }
};

template <typename V>
class CLinkedListQueue
{
    CNode<V>* _cursor;
    int _capacity;
    int _N;
public:
    CLinkedListQueue
    (int capacity) {
        _cursor = NULL;
        _capacity = capacity;
        _N = 0;
    }
    bool empty() {
        return _cursor == NULL;
    }
    void enqueue(const V& v) {
        CNode<V>* New = new CNode<V>(v);
        if (empty()) {
            New->_next = New;
            _cursor = New;
            return;
        }

        New->_next = _cursor->_next;
        _cursor->_next = New;
        _cursor = New;
        _N++;
    }
    //void Advance() {
    //    if (empty()) {
    //        throw runtime_error("The Linkedlist is Empty");
    //    }
    //    else {
    //        _cursor=_cursor->_next;
    //    }
    //}
    void dequeue() {
        CNode<V>* old = _cursor->_next;
        if (old == _cursor) {
            _cursor = NULL;
            return;
        }
        
        _cursor->_next = old->_next;
        
        delete old;
        _N--;
       
    }
    CNode<V>* front() {
        if (empty()) {
            throw runtime_error("The Linkedlist is Empty");
        }
        return _cursor->_next;
    }
    //void enqueue(const V& v) {
    //    if (_N == _capacity) {
    //        throw runtime_error("the queue is full")
    //    }
    //    AddLast(v);
    //    Advance();
    //    _N++;
    //}

    int size() {
        return _N;
    }
};


int main()
{
    CLinkedListQueue<int> queue(4);
    queue.enqueue(2);
    queue.enqueue(4);

}

