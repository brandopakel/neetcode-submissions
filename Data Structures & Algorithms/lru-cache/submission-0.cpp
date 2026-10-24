#include <unordered_map>

class LRUCache {
private:
    struct Node{
        int key = 0;
        int value = 0;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    int limit;
    std::unordered_map<int, Node*> lookup;
    Node head;
    Node tail;

    void detach(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void append(Node* node){
        node->prev = tail.prev;
        node->next = &tail;

        tail.prev->next = node;
        tail.prev = node;
    }
public:
    LRUCache(int capacity) : limit(capacity) {
        head.next = &tail;
        tail.prev = &head;
    }
    
    int get(int key) {
        auto it = lookup.find(key);

        if (it == lookup.end()){ //if key is missing return -1
            return -1;
        }

        Node* node = it->second; // get Node address from key
        detach(node); //detach node
        append(node); //append node as most-recent

        return node->value;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);
        if (it != lookup.end()){
            Node* node = it->second;
            node->value = value;
            detach(node);
            append(node);
            return;
        } else {
            Node* node = new Node{key, value};
            lookup[key] = node;
            append(node);
            if (static_cast<int>(lookup.size()) > limit){
                Node* lru = head.next;
                detach(lru);
                lookup.erase(lru->key);
                delete lru;
            }
        }
    }

    ~LRUCache(){
        for(const auto& entry : lookup){
            delete entry.second;
        }

    }

    LRUCache(const LRUCache&) = delete;
    LRUCache& operator=(const LRUCache&) = delete;
};
