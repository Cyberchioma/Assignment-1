#include <vector>
#include <list>
#include <set>
#include <unordered_set>

class arraySet{
    private:
       std::vector<int> dataset;
    public:
      arraySet(int* l, int count){
        for(int i=0; i<count; i++){
            dataset.push_back(l[i]);
        }
      }
       bool find(int key){
        for(int k: dataset){
            if(k == key){
                return true;
            }
        }
        return false;
       }
       bool insert(int key){
        if(find(key)){
            return false;
        }
        dataset.push_back(key);
        return true;
       }
       bool remove(int key){
            for(std::vector<int>::iterator it = dataset.begin();
                it != dataset.end(); it++){
                    if(*it == key){
                        dataset.erase(it);
                        return true;
                    }
            }
            return false;
       }
       int size (){
        return dataset.size();
       }
};

class ListSet{
    private:
       std::list<int> dataset;
    public:
      ListSet(int* l, int count){
        for(int i=0; i<count; i++){
            dataset.push_back(l[i]);
        }
      }
       bool find(int key){
        for(int k: dataset){
            if(k == key){
                return true;
            }
        }
        return false;
       }
       bool insert(int key){
        if(find(key)){
            return false;
        }
        dataset.push_back(key);
        return true;
       }
       bool remove(int key){
            for(std::list<int>::iterator it = dataset.begin();
                it != dataset.end(); it++){
                    if(*it == key){
                        dataset.erase(it);
                        return true;
                    }
            }
            return false;
       }
       int size (){
        return dataset.size();
       }
};

class treeSet{
    private:
       std::set<int> dataset;
    public:
    treeSet(int* l, int count){
        for(int i=0; i<count; i++){
            dataset.insert(l[i]);
        }
      }
       bool find(int key){
        for(int k: dataset){
            if(k == key){
                return true;
            }
        }
        return false;
       }
       bool insert(int key){
        if(find(key)){
            return false;
        }
        dataset.insert(key);
        return true;
       }
       bool remove(int key){
            for(std::set<int>::iterator it = dataset.begin();
                it != dataset.end(); it++){
                    if(*it == key){
                        dataset.erase(it);
                        return true;
                    }
            }
            return false;
       }
       int size (){
        return dataset.size();
       }
       };

class hashSet{
    private:
       std::unordered_set<int> dataset;
    public:
    hashSet(int* l, int count){
        for(int i=0; i<count; i++){
            dataset.insert(l[i]);
        }
      }
       bool find(int key){
        for(int k: dataset){
            if(k == key){
                return true;
            }
        }
        return false;
       }
       bool insert(int key){
        if(find(key)){
            return false;
        }
        dataset.insert(key);
        return true;
       }
       bool remove(int key){
            for(std::unordered_set<int>::iterator it = dataset.begin();
                it != dataset.end(); it++){
                    if(*it == key){
                        dataset.erase(it);
                        return true;
                    }
            }
            return false;
       }
       int size (){
        return dataset.size();
       }
       };
