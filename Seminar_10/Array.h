#pragma once
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() {
        List = nullptr;
        Capacity = 0;
        Size = 0;
    }; // Lista nu e alocata, Capacity si Size = 0


    ~Array() {
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
    }; // destructor


    Array(int capacity) {
        List = new T* [capacity];
        Capacity = capacity;
        Size = 0;
    }; // Lista e alocata cu 'capacity' elemente


    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T* [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = otherArray.List[i];
        }
    }; // constructor de copiere


    T& operator[] (int index) {
        try {
            if (index >= Size || index < 0) {
                throw "Index out of range.";
            }
            return List[index];
        }
        catch (const char* s) {
            cout << s << endl;
        }
    }; // arunca exceptie daca index este out of range


    const Array<T>& operator+=(const T& newElem) {
        Size++;
        List[Size] = new T(newElem); //valorea este newElem
        return *this;
    }; // adauga un element de tipul T la sfarsitul listei si returneaza this


    const Array<T>& Insert(int index, const T& newElem) {
        try {
            if (index >= Size || index < 0) {
                throw "Index out of range.";
            }
            Size++;
            if (Size > Capacity) {
                throw "Out of capacity.";
            }
            //RESIZING!!!
            T** newList = new T* [Size];
            for (int i = 0; i < initialSize; i++)
            {
                newList[i] = List[i];
            }
            for (int i = initialSize; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
            //!!!
            for (int i = Size - 1; i > index; i--) {
                List[i] = List[i - 1];
            }
            List[index] = new T(newElem);
            return *this;
        }
        catch (const char* s) {
            cout << s << endl;
        }

    }; // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    

    const Array<T>& Insert(int index, const Array<T> otherArray) {
        try {
            if (index >= Size || index < 0) {
                throw "Index out of range.";
            }
            int initialSize = Size;
            Size += otherArray.Size;
            if (Size > Capacity) {
                throw "Out of capacity.";
            }
            //RESIZING!!!
            T** newList = new T* [Size];
            for (int i = 0; i < initialSize; i++)
            {
                newList[i] = List[i];
            }
            for (int i = initialSize; i < Capacity; i++)
            {
                newList[i] = nullptr;
            }
            delete[] List;
            List = newList;
            //!!!
            for (int i = Size - 1; i > index + otherArray.Size; i--) {
                List[i] = List[i - otherArray.Size];
            }
            for (int i = 0; i < otherArray.Size; i++) {
                List[i + index] = new T(otherArray.List[i]);
            }
            return *this;
        }
        catch (const char* s) {
            cout << s << endl;
        }
    };// adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie


    const Array<T>& Delete(int index) {
        try {
            if (index >= Size || index < 0) {
                throw "Index out of range.";
            }
            delete List[index];
            for (int i = index; i < Size - 1; i++) {
                List[i] = List[i + 1];
            }
            Size--;
            return *this;
        }
        catch (const char* s) {
            cout << s << endl;
        }
    }; // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie


    bool operator=(const Array<T>& otherArray) {
        if (Size != otherArray.Size) {
            return false;
        }
        for (int i = 0; i < Size; i++) {
            if (List[i] != otherArray.List[i]) {
                return false;
            }
        }
        return true;
    }


    void Sort() {
        
    }; // sorteaza folosind comparatia intre elementele din T


    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) {
            if (List[i] == elem) {
                return i;
            }
        }
    }; // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

    int GetSize() {
        return Size;
    };
    int GetCapacity() {
        return Capacity;
    };

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};

