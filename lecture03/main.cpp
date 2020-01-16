#include 

int main(int argc, char** argv) {
    String* s = new String;
    f(); // If an exception is thrown here, it is UNSAFE, as the delete won't happen
    delete s;
    return 0;

}

