#include <iostream>
#include "Map.h"
using namespace std;

template<typename K, typename V>
void Map<K, V>::Set(K key, V value) {
	int ok = 0;
	for (int i = 0; i < size; i++) {
		if (myMap[i].key == key) {
			myMap[i].value = value;
			ok = 1; //sau sa fac cu return;
			break;
		}
	}
	if (ok == 0) {
		myMap[size] = { key,value,size };
		size++;
	}
}

template<typename K, typename V>
bool Map<K, V>::Get(const K& key, V& value) {
	for (int i = 0; i < size; i++) {
		if (myMap[i].key == key) {
			value = myMap[i].value;
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
int Map<K, V>::Count() {
	return size;
}

template<typename K, typename V>
void Map<K, V>::Clear() {
	size = 0;
	maxSize = 0;
	delete[] myMap;
}

template<typename K, typename V>
bool Map<K,V>::Delete(const K& key) {
	for (int i = 0; i < size; i++) {
		if (myMap[i].key == key) {
			//facem stergere din array:	
			for (int j = i; j < size - 1; j++){
				myMap[j] = myMap[j + 1];
			}
			size--;
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
bool Map<K, V>::Includes(const Map<K, V>& map) {
	if (map.size > this->size) return 0; // verificam daca mapa "map" se afla in mapa curenta "m"
	int ok;
	for (int i = 0; i < map.size; i++) {
		ok = 0;
		for (int j = 0; j < this->size; j++) {
			if (map.myMap[i].key == this->myMap[j].key) {
				ok = 1;
				break;
			}
		}
		if (ok == 0) return 0;
	}
	return 1;
}
