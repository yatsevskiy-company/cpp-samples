void f(char* p) {
  char s[] = "ABCD";            //1
  const char *       ps1 = s;           //2
  ps1[3] = '1';                  //3
  ps1 = p;                       //4 

        char * const ps2 = s;           //5
  ps2[3] = '2';                  //6
  ps2 = p;                       //7

  const char * const ps3 = s;    //8
  ps3[3] = '3';                 //9
  ps3 = p;                      //10
}

main(){f("");}
