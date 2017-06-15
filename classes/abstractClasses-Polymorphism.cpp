// solution: https://www.hackerrank.com/challenges/abstract-classes-polymorphism

class LRUCache : Cache {
    public:
    LRUCache(int _cp) {
        cp = _cp;
        tail = NULL;
        head = NULL;
    }
    
    void cacheOrder() {
        Node* item = head;
        
        cerr << "Order: ";
        while (item) {
            cerr << "(" << item->key << ", " << item->value << ")";
            item = item->next;
        }
        
        cerr << "\n";
    }
    
    void set(int _key, int _value) {
        Node* item;
            
        // cerr << "Before " << _key << " " << _value << " "; cacheOrder();
        if (mp.find(_key) == mp.end()) {
            // not found
            // get the links right, remove old key/value if necessary from map
            if (mp.size() < cp) {
                item = new Node(_key, _value);
                item->next = head;
                head = item;
                if (tail == NULL) {
                    tail = head;
                }
            } else {
                mp.erase(tail->key);
                // cerr << "Removing: " << tail->key << ", " << tail->value << "\n";
                item = tail;
                tail = item->prev;
                if (tail) {
                    tail->next = NULL;
                }
                if (head == item) {
                    head = NULL;
                }
                
                item->key = _key;
                item->value = _value;
            }
            
            mp[_key] = item;
        } else {
            // already exists, need to move to front
            item = mp[_key];
            item->value = _value;
            moveToFront(item);
        }
        // cerr << "    after: "; cacheOrder(); 
    }
    
    int get(int _key) {
        // cerr << "search " << _key << ": "; cacheOrder();
        if (mp.find(_key) != mp.end()) {
            Node* item = mp[_key];
            moveToFront(item);
            // cerr << "   after " << item->value << ": "; cacheOrder(); 
            return item->value;
        } else {
            return -1;
        }
    }
    
    private:
    void moveToFront(Node* item) {
        if (item != head) {
            Node* prev = item->prev;
            Node* next = item->next;
           
            if (prev) {
                prev->next = item;    
            }

            if (next) {
                next->prev = prev;
            } else {
                tail = prev;
            }
            
            item->next = head;
            head = item;
        } 
    }

};
