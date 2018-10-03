// LRU
class LRUCache {
    int capacity;
    unordered_map<int, list<pair<int,int>>::iterator > m;
    list<pair<int,int>> l;
public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int get(int key) {
        auto iter = m.find(key);
        if(iter!=m.end()){
            l.splice(l.begin(), l, iter->second);
            return iter->second->second;
        }
        return -1;
    }
    void put(int key, int value) {
        pair<int,int> node = make_pair(key, value);
        if(m.find(key)!=m.end()){
            auto iter = m.find(key);
            l.splice(l.begin(), l, iter->second);
            iter->second->second = value;
            return;
        }
        if(l.size()==capacity){
            int key_to_rm = l.back().first;
            l.pop_back();
            m.erase(key_to_rm);
        }
        l.push_front(node);
        m[node.first] = l.begin();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */