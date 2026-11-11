class BrowserHistory {
private:
    struct Node{
        std::string url;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    Node* current = nullptr;

public:
    BrowserHistory(string homepage) {
        current = new Node{homepage};  
    }
    
    void visit(string url) {
        Node* page = new Node{url};
        page->prev = current;
        Node* oldForward = current->next;

        while(oldForward != nullptr){
            Node* next = oldForward -> next;
            delete oldForward;
            oldForward = next;
        }

        current->next = page;
        current = page;
    }
    
    string back(int steps) {
        while(steps > 0 && current->prev != nullptr){
            current = current->prev;
            --steps;
        }

        return current->url;
    }
    
    string forward(int steps) {
        while(steps > 0 && current->next != nullptr){
            current = current->next;
            --steps;
        }

        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */