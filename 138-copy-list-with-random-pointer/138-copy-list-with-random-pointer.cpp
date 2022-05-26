/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        
        Node *temp = head;
        
        unordered_map<Node*, Node*> deepc;
        
        while(temp){
            deepc[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp){
            deepc[temp]->next = deepc[temp->next];
            deepc[temp]->random = deepc[temp->random];
            
            temp = temp->next;
        }
        
        return deepc[head];
        
    }
};