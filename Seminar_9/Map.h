#pragma once

template<typename K, typename V>
struct Item {
    K key;
    V value;
    int index; // pentru iterare in for
};

template<typename K, typename V>
class Map {
private:
    Item<K, V>* myMap = new Item<K, V>[100];
    int maxSize = 100; // mi-am asumat size-ul pentru array^ pentru alocare dinamica, pentru Delete() de asemenea
    int size = 0; // pozitia la care ma aflu, la inceput vor fi 0 elemente!
public:
    void Set(K key, V value);
    bool Get(const K& key, V& value);
    int Count();
    void Clear();
    bool Delete(const K& key);
    bool Includes(const Map<K, V>& map);

};