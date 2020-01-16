#include <stdio.h>
#include <string.h>

class String : public Object { // This means it inherits from the object class
public:
    char* val_; // owned
    size_t size_;

    String(char* c) {
        size_ = strlen(c);
        val_ = new char[size_];
        for (size_t i=0; i < size_; i++) {
            val_[i] = c[i];
        }
    }
    
     String(const char* c) {
        size_ = strlen(c);
        val_ = new char[size_];
        for (size_t i=0; i < size_; i++) {
            val_[i] = c[i];
        }
    }

    size_t hash_me_() {
        size_t res = 0;
        for(size_t ii = 0; ii < size_; ii++) {
            res += val_[ii];
        }
        return res;
    }

    bool equals(Object* other) {
        if (other == nullptr) return false;
        String* s = dynamic_cast<String*>(other);
        if (s == nullptr) return false;

        return strcmp(val_, s->val_) == 0;
    }

    ~String() {
        Cout* c = new Cout();
        c->p(" destructing: ")->pln(val_);
        delete c;
        delete[] val_;
    }
};

class ColorString : public String {
public:
    char color_;

    // This is very similiar to the super constructor in Java
    ColorString(char* s, char color) : String(s) , color_(color) {}
};