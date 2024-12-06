#pragma once

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Queue
{
private:
    std::vector<T> data;
    int head;
    int tail;
    int sz;  

public:
    Queue() : head(0), tail(0), sz(0) {}

    bool empty() const {
        return sz == 0;
    }

    void push(const T& value) {
        data.push_back(value);
        tail = (tail + 1) % data.capacity();  
        sz++;
    }

    void pop() {
        if (empty()) throw "incorrect operation";
        head = (head + 1) % data.capacity(); 
        sz--;
    }

    T& front() {
        if (empty()) throw "incorrect operation";
        return data[head];
    }

    int size() const {
        return sz;
    }
};



