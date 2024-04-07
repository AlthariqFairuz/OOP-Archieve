// main.cpp
#include "A.hpp"
#include "B.hpp"

void set(A &a, int n){
  a.setValue(n);
}

int main() {
  B b; /** ANDA HARUS MENGGUNAKAN DEFAULT CONSTRUCTOR */

  set(b, 888);
  b.print();
  b.setValue(10888);

  b.print(); // OUTPUT: (888, 10888)
  return 0;
}