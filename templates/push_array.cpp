

int foo(int a[][1][1][1]) {return 0;}

int main(int argc, char *argv[]) {

  
  int a[1][1][1][1] = {{{{1}}}};

  foo(a);
  
  return 0;

}
