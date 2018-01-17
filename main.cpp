#include <iostream>
#include "Queue.h"

int main() {

    Queue <int>queue;
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.dequeue();
    Queue <int>queue1(queue);
    queue.displayQueue();
    queue1.displayQueue();



    return 0;
}