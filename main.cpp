#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
using namespace std;
ifstream myFile("input.txt");

class Compare {
public:
    bool operator() (pair<string, int> p1, pair<string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second > p2.second)
            return false;
        if (p1.first < p2.first)
            return false;
        return true;
    }
};

int main() {
    map<string, int>myMap;
    string sentence;
    string word;
    string delimiters = " ,.!?";

    if (!myFile)
    {
        printf("error la deschiderea fisierului: input.txt");
        return 0;
    }

    if (!getline(myFile, sentence)) {
        printf("error la citirea din fisier: input.txt");
        return 0;
    }

    int pos = 0;
    while ((pos = sentence.find_first_of(delimiters)) != string::npos) {
        word = sentence.substr(0, pos); //in word se va pune bucata de string care incepe de la pozitia 0 si care are in total "pos" caractere, adica fix inainte de virgula
        if (!word.empty()) {
            if (word[0] >= 'A' && word[0] <= 'Z') {
                word[0] += 32;
            }
            if (myMap.count(word) != 0) {
                myMap[word] += 1;
            }
            else {
                myMap[word] = 1;
            }
        }
        sentence.erase(0, pos + 1);
    }
    if (!sentence.empty()) {
        if (word[0] >= 'A' && word[0] <= 'Z') {
            word[0] += 32;
        }
        if (myMap.count(sentence) != 0) {
            myMap[sentence] += 1;
        }
        else {
            myMap[sentence] = 1;
        }
    }

    /*
    for (auto iterator = myMap.begin(); iterator != myMap.end(); iterator++) {
        printf("Cuvantul: %s apare de %d ori\n", iterator->first.c_str(), iterator->second);
    }
    */

    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> myQueue;

    for (auto iterator = myMap.begin(); iterator != myMap.end(); iterator++) {
        myQueue.push(pair<string, int>(iterator->first, iterator->second));
    }

    while (!myQueue.empty())
    {
        /*
        pair<char, int> popValue = myQueue.top();
        printf("%c | %d\n", popValue.first, popValue.second);
        */

        printf("%s => %d\n", myQueue.top().first.c_str(), myQueue.top().second);
        myQueue.pop();
    }

    return 0;
}

