#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            // map the key to the node in the linked list
    int cp;                         // capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;       // get function
};

// class LRUCache : public Cache
// {
// public:
//     LRUCache(int capacity)
//     {
//         cp = capacity;
//     }

//     void set(int key, int val) override
//     {
//         try
//         {
//             Node *target_node = mp.at(key);
//             if (target_node->prev)
//             {
//                 Node *prev_node = (target_node->prev);
//                 prev_node->next = target_node->next;
//             }
//             if (target_node->next)
//             {
//                 Node *next_node = target_node->next;
//                 next_node->prev = target_node->prev;
//             }
//             head->next = target_node;
//             target_node->next = head;
//             head = target_node;
//             target_node->value = val;
//         }

//         catch (out_of_range e)
//         {
//             if (mp.size() == cp)
//             {
//                 int tail_key = tail->key;
//                 Node *tail_node = tail;
//                 mp.erase(tail->key);
//                 tail = tail->next;
//                 delete tail_node;
//             }
//             Node *new_node = new Node(key, val);
//             if (head)
//             {
//                 new_node->prev = head;
//                 head->next = new_node;
//             }
//             head = new_node;
//             if (mp.size() == 0)
//             {
//                 tail = new_node;
//             }
//             mp.insert({key, new_node});
//         }
//     }

//     int get(int key) override
//     {
//         try
//         {
//             Node *target_node = mp.at(key);
//             return target_node->value;
//         }
//         catch (out_of_range e)
//         {
//             return -1;
//         }
//     }
// };
class LRUCache : public Cache
{
public:
    LRUCache(int capacity)
    {
        cp = capacity;
    }

    void set(int key, int val) override
    {
        // check if the key exists
        try
        {
            // if key exists: replace the value
            Node *target_node = mp.at(key);
            if (target_node->prev)
            {
                Node *prev_node = (target_node->prev);
                prev_node->next = target_node->next;
            }

            if (target_node->next)
            {
                Node *next_node = target_node->next;
                next_node->prev = target_node->prev;
            }

            // place the current node at the top of the linked list
            head->next = target_node;
            target_node->prev = head;
            target_node->next = NULL;
            // make the target node at the head of the cache
            head = target_node;
            target_node->value = val;
        }

        catch (out_of_range e)
        {
            // if not: add a new value
            //      if the Cache is at capacity, discard the last node
            if (mp.size() == cp)
            {
                int tail_key = tail->key;
                // delete the tail from the map
                Node *tail_node = tail;
                mp.erase(tail->key);
                // dereference the tail; from the linked list
                tail = tail->next;
                // free the memory
                delete tail_node;
            }

            // construct a new node
            Node *new_node = new Node(key, val);
            if (head)
            {
                // backwards link to old head
                new_node->prev = head;
                // establish a forward reference between the old and new head
                head->next = new_node;
            }

            // move the head pointer to the new head
            head = new_node;
            //  if there is no existing elements, the new node is both the tail and head
            if (mp.size() == 0)
            {
                tail = new_node;
            }

            // add the node to the map
            mp.insert({key, new_node});
        }
    }

    int get(int key) override
    {
        try
        {
            // fetch the node
            Node *target_node = mp.at(key);

            return target_node->value;
        }

        catch (out_of_range e)
        {
            // return -1 if no node exists
            return -1;
        }
    }
};
int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
