# Refactoring
+ It's important to have as small as a code base as possible, because it becomes much harder to add features and maintain the larger the code base

+ Any functions that are not used should be removed, as it only adds bloat

+ Jan wants things sunk into 1 liners if you can (remove brackets for 1 liner if statements too)

+ Remove comments if they're obvious, **seriously remove obvious comments**

+ Comments should be **meaningful statements** only

+ `if (l == nullptr || l->length() != size_) return false;`

+ Refactoring function comments (like removing @param) is totally okay and helps remove code

+ `if (idx < 0 || idx >= size_)` should instead be `if (idx >= size_)` because idx is a `size_t`

+ for resize array functions, you can simply allocate the new array on the stack (I was worried this won't work because the stack allocation will disappear outside the function, but hey, maybe it's fine)

+ Jan removed all IntArray, FloatArray, etc. because they were *dead*, it'll be a little harder for us

+ Don't be afraid to throw `assert(false)` inside functions you don't want to deal with right away

+ Any **heap** allocated fields in a class should now be shanged to **stack** allocated fields (`Array* dude = new Array(10)` vs. `Array dude(10)` respectively)

+ Here's a constructor to make a ColumnList: `ColumnList(Array& arr) : arr_(arr) { }`. You will need a copy constructor for Arrays though:
```
// Example of Jan's Array copy constructor
Array(Array& arr) {
    for (size_t i = 0; i < arr.size; i++)
        push_back(arr.get(i));
}
```

+ For a set method, it should be index first, then the value, like this: `Object* set(size_t index, Object* value)`, that is considered proper

+ Early in the class, we decided to make seperate IntArray, FloatArray, etc. because we didn't have the right tools, **now is the time to fight it**

+ In order to represent Double, Ints, Booleans, and Strings, we will use a DFData with a union (used in C that let's you hold multiple types)

```
union Payload {
    int i;
    double d;
    bool b;
    String* s;
}

class DFData {
    bool missing_;
    Payload payload_;
}
```
+ Here's how a union is used in a StringList:
```
void push_back(String* val) {
    DFData dfd;
    dfd.payload_.s = val;
    dfd.missing_ = false;
    arr_.push_back(dfd);
}
```
+ Use a `BaseList` to keep track of things that all the other Lists deal with (especially manipulating the array inside). Use this as a constructor: `BaseList(char type) : arr_(10), type_(type) { }`

+ You can serialize a union by simply using `serializer.serialize_int(dfd.payload_.i)`, and in fact, if you keep track of type with a char, you can use a switch case for serialize() inside `BaseList` and then dynamically cast later on a deserialize
```
// Jan's deserialize method inside the parent class
static BaseList* deserialize(Deserialize* d) {
    char* c = d->readChar();
    BaseList* result;
    switch(c) {
        case 'S': result = new StringList; break;
        case 'I': result = new IntList; break;
        case 'D': result = new DoubleList; break;
        case 'B': result = new BoolList; break;
    }
    size_t num = d->readSizeT();
    for (size_t i = 0; i < num; i++) {
        DFD dfd;
        dfd.missing_ = s->readBool();
        if (c != 'S')
            dfd.payload_.d = s->readDouble();
        else 
            dfd.payload_.s = s->readString();
        result->push_back(dfd);
    }
    return result;
}
```

+ Now, each DoubleList, IntList, etc only has `get`, `set`, and `push_back`, here's an example with StringList:
```
class StringList : public Object {
public:
    StringList() : BaseList('S');

    void push_back(String* val) {
        DFData dfd;
        dfd.payload_.s = val;
        dfd.mising_ = false;
        arr_.push_back( dfd );
    }

    String* get(size_t idx) {
        DFData dfd = arr_.get(idx);
        if (dfd.missing_) return nullptr;
        return dfd.pauoad_.s;
    }

    void set(size_t idx, String* val) {
        DFData dfd;
        dfd.payload_.s = val;
        dfd.missing_ = false;
        arr_.set(idx, dfd);
    }
}
```

