#include "helper.h"
#include "object.h"
#include "string.h"

int main(int argc, char** argv) {
	std::cout << "big lol";
	Cout * c = new Cout();
	String* s = new String("hello");
	String* s2 = new String("Hell");
	c->pln("hell world");
    c->p(" this program received ")->p(argc - 1)->pln(" arguments");

	c->p(" hell == hello? ")->pln(s->equals(s2));

	String* s3 = new String("hello");
	c->p(" hello == hello? ")->pln(s->equals(s3));
	delete s;
	delete s2;
	delete s3;
	
	// This is actually allocated onto the heap
	String* s4 = new String("hell");
	delete s4;

	// This is only allocated for the function, and disappears once it's done
	size_t i;
	// This will automatically deconstruct
	String s5("new man blowing up lol");
	return 0;
}
