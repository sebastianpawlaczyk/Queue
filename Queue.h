#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#include "cmake-build-debug/Node.h"

template<typename T>
class Queue {

private:

    Node<T> *last; // the last item to delete in the queue;
    Node<T> *first; // first item to delete in the queue;

public:

    Queue(){

        last = nullptr;
        first = nullptr;
    }

    Queue(const Queue & pattern){

       auto pom = pattern.first;
        last = nullptr;
        first = nullptr;
        while(pom != nullptr){

            enqueue(pom->item);
            pom = pom->next;
        }
    }

    ~Queue(){

        Node<T> *tode;// *tode = to delete

        while(first != nullptr){

            tode = first;
            first = first->next;
            delete tode;
        }
    }

    bool enqueue(T data){

        Node<T> *node = new Node<T>(data, nullptr);

        if(last == nullptr){

            last = node;
            first = node;
            return true;
        }
        else{

            last->next = node;
            last = node;
            return true;
        }
    }

    bool dequeue(){

        if(last == nullptr){
            return false;
        }

        else{
           auto pom = first;

            first = first->next;
            delete pom;
        }
    }

    int size(){

        auto pom = last;
        int sum = 0;

        while(pom != nullptr){
            pom = pom->next;
            sum++;
        }
        return sum;
    }

    void displayQueue(){

        auto pom = first;

        while(pom != nullptr) {

            std::cout << " <- " << pom->item;
            pom = pom->next;
        }
        std::cout<<std::endl;
    }
};


#endif //QUEUE_QUEUE_H
