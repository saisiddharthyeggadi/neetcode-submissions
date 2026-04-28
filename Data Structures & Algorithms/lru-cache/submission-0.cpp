#include <unordered_map>
using namespace std;

class ListNode {
public:
    int key;
    int value;
    ListNode* prev;
    ListNode* next;

    ListNode(int k = 0, int v = 0) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, ListNode*> cache;
    ListNode* head;   // dummy head
    ListNode* tail;   // dummy tail

    // Remove node from list
    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert right after head (most recently used)
    void insertToFront(ListNode* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) {
        capacity = cap;

        head = new ListNode();
        tail = new ListNode();

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        ListNode* node = cache[key];

        removeNode(node);
        insertToFront(node);

        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update existing node
            ListNode* node = cache[key];
            node->value = value;

            removeNode(node);
            insertToFront(node);
        }
        else {
            if (cache.size() == capacity) {
                // Remove LRU (node before tail)
                ListNode* lru = tail->prev;

                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }

            ListNode* newNode = new ListNode(key, value);
            cache[key] = newNode;
            insertToFront(newNode);
        }
    }
};