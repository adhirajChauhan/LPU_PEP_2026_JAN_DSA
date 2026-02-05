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