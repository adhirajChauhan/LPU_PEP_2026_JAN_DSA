https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
};




https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = NULL;
        ListNode *currNode = head;
        ListNode *nextNode = NULL;

        while(currNode!= NULL){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;    
        }
        return prevNode;


    }
};




https://leetcode.com/problems/palindrome-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prevNode = NULL;
        ListNode* currNode = head;
        ListNode* nextNode = NULL;

        while(currNode !=NULL){
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

    bool isPalindrome(ListNode* head) {
        
        //find the middle
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);
        ListNode* p1 = head;
        ListNode* p2 = slow;

        while(p2){
            if(p1 -> val != p2->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;

        }
        return true;
        

    }
};




https://www.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
        Node* newNode = new Node(key);
        
        //1 -> insert at beginning
        if(head == NULL || key < head->data){
            newNode->next = head;
            return newNode;
            
        }
        
        //2-> Insert in middlle
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr != NULL && curr->data <= key){
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
        
        return head;
    }
};




https://leetcode.com/problems/intersection-of-two-linked-lists/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int findLength(ListNode* head){
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = findLength(headA);
        int lenB = findLength(headB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        int diffInLength = abs(lenA - lenB);

        if(lenB > lenA){
            while(diffInLength--){
                tempB = tempB->next;
            }
        }
        else{
             while(diffInLength--){
                tempA = tempA->next;
            }
        }
        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};





https://leetcode.com/problems/linked-list-cycle/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) return true;
        }

        return false;

    }
};




https://leetcode.com/problems/odd-even-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firstEven = even;

        while(even!= NULL && even->next != NULL){
            odd->next = even->next;
            odd= odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = firstEven;
        return head;
    }
};



https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        //move the fast ahead by n steps
        for(int i = 0; i < n;i++){
            fast = fast->next;
        }

        //if fast is null -> remove head
        if(fast == NULL) return head->next;

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    //slow->next is the node to be removed
    ListNode* toDel = slow->next;
    slow->next = slow->next->next;
    delete toDel;

    return head;

    }


};


https://leetcode.com/problems/partition-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //Dummy nodes
        ListNode* left = new ListNode(-1);
        ListNode* right = new ListNode(-1);

        ListNode* lp = left;
        ListNode* rp = right;

        ListNode* p1 = head;


        while(p1 != NULL){
            if(p1->val < x){
                left->next = p1;
                left = left->next;
            }else{
                right->next = p1;
                right = right->next;
            }
            p1 = p1->next;

        }
        right->next = NULL;

        left->next = rp->next;

        return lp->next;
    }
};




https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
       int count0 = 0, count1 = 0, count2 = 0;
       
       //step 1 -> count how many nodes have 0 and update count0 , similarly do for 1 and 2
       Node* temp = head;
       
       while(temp != NULL){
           if(temp->data == 0) count0++;
           else if (temp->data == 1) count1++;
           else count2++;
           
           temp= temp->next;
       }
       
       // step 2 -> iterate again and overwrite the list with sorted values
       
       temp = head;
       while(temp != NULL){
           if(count0 > 0){
               temp->data = 0;
               count0--;
           }
           else if(count1 > 0){
               temp->data = 1;
               count1--;
           }
           
           else temp->data = 2;
           count2--;
           
           temp = temp->next;
       }
       
       return head;
    }
};




https://leetcode.com/problems/reverse-nodes-in-k-group/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        //step 1 -> count the k nodes, 
            //check if there are atleast k noed remaining
            //if no then do not reverse juist return the current head
            // count
            // while(count < k) -> one pointer that will move till j

        // step 2 -> reverese exactly k nodes
            //use that previously done iterative method for k nodes only

        // recursilvely process the remaining LL
            //connect the reversed group's last node pointer to the next group


            ListNode* curr = head;
            int count = 0;

            while(curr != NULL && count < k){
                curr = curr ->next;
                count++;
            }

            if(count == k){
                //reverse first k node
                ListNode* prevNode = NULL;
                ListNode* currNode = head;
                ListNode* nextNode = NULL;
                int count2 = 0;

                while(count2< k){
                    nextNode = currNode->next;
                    currNode->next = prevNode;
                    prevNode = currNode;
                    currNode = nextNode;
                    count2++;
                }

                head->next = reverseKGroup(curr, k);
                return prevNode;

            }
            return head;
        
    }
};





https://leetcode.com/problems/lru-cache/
class LRUCache {
public:

    class Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int key, int value){
            this->key = key;
            this->value = value;
            prev = NULL; next = NULL;
        }
    };
    unordered_map<int, Node*> cache;
    int cap;
    Node* head;
    Node* tail;

    void addToFront(Node* node){
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node){
        Node* left = node->prev;
        Node* right = node->next;
        left->next = right;
        right->prev= left;
    }

    void moveToFront(Node* node){
        removeNode(node);
        addToFront(node);
    }
    


    LRUCache(int capacity) {
         cap = capacity;
        head = new Node(-1,-1); //dummy1
        tail = new Node(-1,-1); //dummy2
        head->next = tail;
        tail->prev = head;

        
    }
    
    int get(int key) {
        //find the key in map
            //if not found -> return -1
        
        // node with that key and value 
        // i will move that node to front
        //return node->val;
        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node* node = cache[key];
        moveToFront(node);
        return node->value;

    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
        moveToFront(node);
        return;
        }
        if(cache.size() == cap){
            Node* toDel = tail->prev;
            cache.erase(toDel->key);
            removeNode(toDel);
            delete toDel;
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        addToFront(newNode);

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */





https://leetcode.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        //slow and fast pointer approach to find the middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow now points to the mid node
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                tail->next = l1;
                l1= l1->next;
            }
            else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if(l1 != NULL) tail->next = l1;
        if(l2 != NULL) tail->next = l2;

        return dummy.next;


    }
    ListNode* sortList(ListNode* head) {

        //base case
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* mid = getMiddle(head);
        ListNode* left = head;
        ListNode* right = mid->next;

        //Disconnecting the left half and right half
        mid->next = NULL;

        ListNode* sortedLeft = sortList(left);
        ListNode* sortedRight = sortList(right);

        return merge(sortedLeft, sortedRight);
    }
};




https://leetcode.com/problems/copy-list-with-random-pointer/

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
        //i have to clone nodes and insert them right after the original nodes
        Node* curr = head;
        while(curr!=NULL){
        Node* dummy = new Node(curr->val);
        dummy->next = curr->next;
        curr->next = dummy;
        curr = dummy ->next;
    }
    //then we have to set the random pointer of the cloned nodes
    curr = head;
    while(curr != NULL){
        if(curr->random != NULL){
                curr->next->random = curr->random->next;
        }

        curr = curr->next->next;
    }

    //the restore thr original list and segregaete the cloned list
    Node* dummy = new Node(0);
    Node* tail = dummy;

    curr= head;
    while(curr!= NULL){
        Node* copyNode = curr->next;
        curr->next = copyNode->next;

        tail->next = copyNode;
        tail = tail->next;

        curr = curr->next;
    }
    return dummy->next;

    }
};