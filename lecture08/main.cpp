// Cpp
#include <stdio.h>
#include <thread>

void foo() {
    printf("hello from the foo thread\n");
}


int main(int argc, char** argv) {
    std::thread t1(foo); // start foo() in a separate thread

    printf("hello from maint thread");

    t1.join(); // wait for t1 to finish

    return 0;

    std::thread* pool[10];

    for (int i = 0; i < 10; i++) {
        pool[i] = new std::thread(foo);
    }

    printf("Hello from the main thread\n");

    for (int i = 0; i < 10; i++) {
        pool[i]->join();
    }
}