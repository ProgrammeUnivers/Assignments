#ifndef MYMAP_H
#define MYMAP_H

#include <vector>
#include <utility>
using namespace std;

template <typename K, typename V>
class Map {
private:
    vector<pair<K, V>> data;

public:
    Map(){}

    Map(const Map &other) = default;
    Map(Map &&other) = default;
    Map& operator=(const Map &other) = default;
    Map& operator=(Map &&other) = default;
    ~Map() = default;

    // operators and iterator - your turn!
    V& operator[](const K &key){
        for(int i = 0; i < data.size(); i++){
            if(data[i].first == key){
                return data[i].second;
            }
        }

        for(int i = 0; i < data.size(); i++){
            if(key < data[i].first){
                data.insert(data.begin() + i, make_pair(key, V{}));
                return data[i].second;
            }
        }

        data.push_back(make_pair(key, V{}));
        return data.back().second;
    }
    V operator()(const K &key) const{

    }
    

    // iterator
    struct Iterator {
        typename vector<pair<K,V>>::iterator current;

        Iterator(typename vector<pair<K,V>>::iterator it) : current(it) {}

        // dereference returns the KEY
        K& operator*() { return current->first; }

        // prefix increment
        Iterator& operator++() {
            ++current;
            return *this;
        }

        // not equal
        bool operator!=(const Iterator &other) const {
            return current != other.current;
        }
    };

    Iterator begin() { return Iterator(data.begin()); }
    Iterator end()   { return Iterator(data.end()); }





}

#endif