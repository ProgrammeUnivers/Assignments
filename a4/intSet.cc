#include <iostream>
#include "intSet.h"
using namespace std;

intSet::intSet(){
    capacity = 4;
    size = 0;
    data = new int[capacity];
}

intSet::~intSet(){
    delete[] data;
}

bool intSet::contains(int x) const {
    for(int i = 0; i < size; i++){
        if(x == data[i])
            return true;
    }
    return false;
}

void intSet::add(int x) {

    if(contains(x)) return;
    
    if(capacity == size){
        capacity *=2;
        int *temp = new int[capacity];
        for(int i =0; i < size; i++){
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
    }       
    data[size] = x;
    size++;
}

void intSet::remove(int x){
    for(int i = 0; i < size; i++){
        if(x == data[i]){
            for(int j = i; j < size - 1; j++){
                data[j] = data[j+1];
            }
            size--;
            return;
        }
    }
}

ostream& operator<<(ostream &out, const intSet &s){
    int *temp = new int[s.size];
    for(int i = 0; i < s.size; i++){
        temp[i] = s.data[i];
    }

    for(int i = 0; i < s.size; i++){
        int min = i;
        for(int j = i + 1; j < s.size; j++){
            if(temp[j] < temp[min]){
                min = j;
            }
        }
        int tmp = temp[i];
        temp[i] = temp[min];
        temp[min] = tmp;
    }
    
    
    out << "("; 
    for(int i = 0; i < s.size; i++){
        out << temp[i];
        if(i< s.size - 1){
            out << ",";
        }
    }
    out << ")";
    delete[] temp;
    return out;
}

intSet& intSet::operator=(const intSet &other) {
    if(this == &other) return *this;
    delete[] data;

    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];

    for(int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

intSet::intSet(const intSet &other){
    size = other.size;
    capacity = other.capacity;
    data = new int[capacity];
    for(int i = 0; i < other.size; i++){
        data[i] = other.data[i];
    }

}

intSet::intSet(intSet &&other){
    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;


}

intSet& intSet::operator=(intSet &&other){
    if(this == &other) return *this;
    delete[] data;


    data = other.data;
    size = other.size;
    capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;

    return *this;

}

intSet intSet::operator|(const intSet &other) const {
    intSet result;
    for(int i = 0; i < size; i++){
        result.add(data[i]);
    }

    for(int i = 0; i < other.size; i++){
        result.add(other.data[i]);
    }

    return result;

}

intSet intSet::operator&(const intSet &other) const {
    intSet result;
    for(int i = 0; i < size; i++){
        if(other.contains(data[i])){
            result.add(data[i]);
        }
        else{
            continue;
        }
    }
    return result;
}

bool intSet::operator==(const intSet &other) const {
    if(size != other.size){
        return false;
    }
    for(int i = 0; i < size; i++){
        if(!other.contains(data[i])) return false;
    }
    return true;
}

bool intSet::isSubset(const intSet &s) const{
    for(int i = 0; i < s.size; i++){
        if(!contains(s.data[i])) return false;
        
    }
    return true;
}


