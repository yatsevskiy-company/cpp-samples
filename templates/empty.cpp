class A {
public:
  A();                        // default constructor
  A(const A & rhs);        // copy constructor
  ~A();                       // destructor — see below for whether it's virtual
  A & operator = (const A & rhs);    // assignment operator
  A * operator & ();             // address-of operators
  const A * operator & () const;
};