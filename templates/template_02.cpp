template <typename T> class clazz {
public:
    void f(T t) {
    }
};


template <typename T> class clazz<T *> {
public:
    void f(T *t) {
    }
};

template <typename T> class clazz<T &> {
public:
    void f(T &t) {
    }
};

template <typename T> class clazz<const T> {
public:
    void f(const T t) {
    }
};


template <typename T> class clazz<const T *> {
public:
    void f(const T *t) {
    }
};

template <typename T> class clazz<const T &> {
public:
    void f(const sT &t) {
    }
};
