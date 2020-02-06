

class Array; // Object 

class Int : Object {
    int v_;
    Int(int val) : v_(val) {}
    int get() { return v_; }
};

class IA_internal {
    Array vals_;
    void push_back(int v) { vals_.push_back(new Int(v)); };
    int get(size_t idx) { 
        Object* o = vals_.get(idx);
        Int* res = dynamic_cast<Int*>(o);
        return res->get();
        val_->get(idx); 
    };

    void remove(size_t idx, int v){

    }
};


class IA_Ext : public Array { };


v1.
    IA_int* a = new IA_int();
    a->push_back(43);

assert(a->get(0)==43);


v2.
IA_ext* a = new IA_ext();
a->push_back(new Int(42));
Object* o = a->get(0);
Int* io = dynamic_cast<Int*>(o);
assert(io->get() == 43);



===============


class Array {
    void push_back(Object* o) { ... }

};

class IA : Array {
    void push_back(String* s) { ... }
};

v1.
void usecase(IA* a) {
    a->push_back(new Window());
}

v2.
