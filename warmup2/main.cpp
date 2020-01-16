#include "helper.h"  // Your file, with any C++ code that you need
#include "object.h"  // Your file with the CwC declaration of Object
#include "string.h"  // Your file with the String class
#include "list.h"    // Your file with the two list classes
 
void FAIL() {   exit(1);    }
void OK(const char* m) { std::cout << "OK: " << m << '\n'; }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

void test1() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  t_true(s->equals(s));
  t_false(s->equals(t));
  t_false(s->equals(u));
  OK("1");
}

void test2() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  t_true(l->get(0)->equals(s));
  OK("2");
}
 
void test3() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  SortedStrList * l2 = new SortedStrList();
  l2->sorted_add(s);
  l2->sorted_add(t);
  l2->sorted_add(u);
  t_true(l->equals(l2));
  t_true(l2->equals(l));
  t_true(l->hash() == l2->hash());
  OK("3");
}
 
void test4() {
  String * s = new String("Hello");
  String * t = new String("World");
  String * u = s->concat(t);
  SortedStrList * l = new SortedStrList();
  l->sorted_add(s);
  l->sorted_add(t);
  l->sorted_add(u);
  SortedStrList * l2 = new SortedStrList();
  l2->add_all(0,l);
  t_true(l->size() == l2->size());
  OK("4");
}

void push_back_test() {
  String* s = new String("s1");
  String* s2 = new String("s2");
  StrList* sl = new StrList();
  sl->push_back(s);
  sl->push_back(s2);
  t_true(sl->size() == 2);
  t_true(sl->get(0) == s);
  t_true(sl->get(1) == s2);
  t_true(sl->get(1999) == s2);
  OK("5");
}

void add_test() {
  String* s1 = new String("s1");
  String* s2 = new String("s2");
  String* s3 = new String("s3");
  String* s4 = new String("s4");
  StrList* sl = new StrList();
  sl->add(0, s1);
  sl->add(1000, s2);
  sl->add(1, s3);
  sl->add(2, s1);
  sl->add(0, s4);
  t_true(sl->size() == 5);
  t_true(sl->get(0) == s4);
  t_true(sl->get(1) == s1);
  t_true(sl->get(2) == s3);
  t_true(sl->get(3) == s1);
  t_true(sl->get(4) == s2);
  OK("6");
}

void add_all_test() {
  String* s1 = new String("s1");
  String* s2 = new String("s2");
  String* s3 = new String("s3");
  String* s4 = new String("s4");
  String* p1 = new String("p1");
  String* p2 = new String("p2");
  String* p3 = new String("p3");
  String* p4 = new String("p4");
  StrList* sl1 = new StrList();
  StrList* sl2 = new StrList();
  sl1->push_back(s1);
  sl1->push_back(s2);
  sl1->push_back(s3);
  sl1->push_back(s4);
  sl2->push_back(p1);
  sl2->push_back(p2);
  sl2->push_back(p3);
  sl2->push_back(p4);
  sl1->add_all(2,sl2);
  t_true(sl1->size() == 8);
  t_true(sl1->get(0) == s1);
  t_true(sl1->get(1) == s2);
  t_true(sl1->get(2) == p1);
  t_true(sl1->get(3) == p2);
  t_true(sl1->get(4) == p3);
  t_true(sl1->get(5) == p4);
  t_true(sl1->get(6) == s3);
  t_true(sl1->get(7) == s4);
  OK("7");
}

void clear_test() {
  String* s1 = new String("s1");
  String* s2 = new String("s2");
  StrList* sl1 = new StrList();
  sl1->push_back(s1);
  sl1->push_back(s2);
  t_true(sl1->size() == 2);
  t_true(sl1->get(0) == s1);
  t_true(sl1->get(1) == s2);
  sl1->clear();
  t_true(sl1->size() == 0);
  t_true(sl1->get(0) != s1);
  t_true(sl1->get(1983) != s2);
  OK("8");
}

void index_test() {
  String* s1 = new String("s1");
  String* s2 = new String("s2");
  StrList* sl1 = new StrList();
  sl1->push_back(s2);
  sl1->push_back(s1);
  sl1->push_back(s1);
  sl1->push_back(s2);
  t_true(sl1->index_of(s1) == 1);
  t_false(sl1->index_of(s1) == 2);
  t_true(sl1->index_of(nullptr) == sl1->size() + 1);
  t_true(sl1->index_of(new String("lol")) > sl1->size());
  t_true(sl1->index_of(new String("s1")) == 1);
  OK("9");
}

void remove_test() {
  String* s1 = new String("s1");
  String* s2 = new String("s2");
  String* s3 = new String("s3");
  StrList* sl1 = new StrList();
  sl1->push_back(s1);
  sl1->push_back(s2);
  sl1->push_back(s3);
  t_true(sl1->size() == 3);
  t_true(sl1->get(0) == s1);
  t_true(sl1->get(1) == s2);
  String* removed_string = sl1->remove(1);
  t_true(removed_string == s2);
  t_false(sl1->get(1) == s2);
  t_true(sl1->size() == 2);
  sl1->remove(24);
  t_false(sl1->get(24) == s3);
  t_true(sl1->size() == 1);
  OK("10");
}

void set_test() {
  String* s1 = new String("s1");
  String* s2 = new String("s2");
  String* s3 = new String("s3");
  StrList* sl1 = new StrList();
  sl1->push_back(s1);
  sl1->push_back(s1);
  sl1->push_back(s1);
  sl1->set(23, s3);
  String* old_string = sl1->set(1, s2);
  t_true(old_string == s1);
  t_true(sl1->get(0) == s1);
  t_true(sl1->get(1) == s2);
  t_true(sl1->get(2) == s3);
  OK("11");
}

void concat_test() {
  String* string1 = new String("lol ");
  String* string2 = new String("dude");
  String* combine = string1->concat(string2);
  t_true(combine->equals(new String("lol dude")));
  OK("12");
}

void my_test() {
  String* s1 = new String("hello");
	String* s2 = new String("Hell");
	String* s3 = new String("hello");
	String* s4 = new String("hell");
  String* string1 = new String("lol ");
  String* string2 = new String("dude");
  StrList* list1 = new StrList();
  list1->push_back(s1);
  list1->push_back(s2);
  list1->push_back(s3);
  list1->push_back(s4);
  list1->push_back(string1);
  list1->push_back(string2);
  list1->add(0, new String("add0"));
  list1->add(1, new String("add1"));
  list1->add(100, new String("add100"));
  t_true(list1->size() == 9);
  t_true(list1->get(0)->equals(new String("add0")));
  t_true(list1->get(1)->equals(new String("add1")));
  t_true(list1->get(2) == s1);
  t_true(list1->get(3) == s2);
  t_true(list1->get(4)->equals(s3));
  t_true(list1->get(5) == s4);
  t_true(list1->get(6) == string1);
  t_true(list1->get(7) == string2);
  t_false(list1->get(8) == new String("add100"));
  t_true(list1->get(8)->equals(new String("add100")));
  OK("13");
}

int main(int argc, char** argv) {
  test1();
  test2();
  test3();
  test4();
  push_back_test();
  add_test();
  add_all_test();
  clear_test();
  index_test();
  remove_test();
  set_test();
  concat_test();
  my_test();
  
  return 0;
}

