#pragma once
template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    Array<T>* ArrayPtr;
public:
    ArrayIterator() {
        Current = 0;
        ArrayPtr = nullptr;
    };
    ArrayIterator& operator ++ () {
        ++Current;
        return *this;
    };
    
    ArrayIterator& operator -- () {
        --Current;
        return *this;
    };
    bool operator= (ArrayIterator<T>&) {
        return ArrayPtr == other.ArrayPtr && Current == other.Current;
    };
    bool operator!=(ArrayIterator<T>&) {
        return !(*this == other);
    };
    T* GetElement() {
        return &ArrayPtr->operator[](Current);

    };
};

