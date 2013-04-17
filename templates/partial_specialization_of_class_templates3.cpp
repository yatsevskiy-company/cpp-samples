template <typename T> class vector {};
template <          > class vector <bool> {};

template <typename T> class sortedVector {
public:
    void insert (T val) {
        if ( length == vec_size ) { // length is the number of elements
            vec_size *= 2;    // we'll just ignore overflow possibility!
            vec_data = new T[vec_size];
        }
        ++length;  // we are about to add an element

        // we'll start at the end, sliding elements back until we find the
        // place to insert the new element
        int pos;
        for( pos = length; pos > 0 && val > vec_data[pos - 1]; --pos ) {
            vec_data[pos] = vec_data[pos - 1];
        }
        vec_data[pos] = val;
    }
    // other functions...
private:
    T *vec_data;
    int length;
    int vec_size;
};


template <typename T>
class sortedVector<T *> {
public:

    void insert( T *val ) {
        if ( length == vec_size ) {
            vec_size *= 2;
            vec_data = new T[vec_size];
        }
        ++length;

        int pos;
        for( pos = length; pos > 0 && *val > *vec_data[pos - 1]; --pos ) {
            vec_data[pos] = vec_data[pos - 1];
        }
        vec_data[pos] = val;
    }

private:
    T **vec_data;
    int length;
    int vec_size;
};

int main(int argc, char*argv[]){
  return 0;
}
