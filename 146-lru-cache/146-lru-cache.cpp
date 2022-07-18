class LRUCache {
public:
    
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        
        Node(int k, int v){
            key = k;
            val = v;
        }
    };
    
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    
    int cap;
    unordered_map<int, Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(Node * newnode) {
        Node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deletenode(Node * delnode) {
        Node * delprev = delnode -> prev;
        Node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }
    
    int get(int k) {
        if(mp.find(k) != mp.end()){
            Node* resnode = mp[k];
            int res = resnode->val;
            mp.erase(k);
            deletenode(resnode);
            addnode(resnode);
            mp[k] = head->next;
            return res;
        }
        
        return -1;
    }
    
    void put(int k, int v) {
        if (mp.find(k) != mp.end()) {
          Node * existingnode = mp[k];
          mp.erase(k);
          deletenode(existingnode);
        }
        if (mp.size() == cap) {
          mp.erase(tail -> prev -> key);
          deletenode(tail -> prev);
        }

        addnode(new Node(k, v));
        mp[k] = head -> next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */