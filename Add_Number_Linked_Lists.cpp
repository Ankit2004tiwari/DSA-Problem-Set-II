//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    
    void reverse(Node* &head)
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while(current)
        {
           next = current->next;
           current->next = prev;
           prev = current;
           current = next;
        }
        head = prev;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        
        if(num1 == NULL) return num2;
        if(num2 == NULL) return num1;
        
        reverse(num1);
        reverse(num2);
        
        Node* head = nullptr;
        Node* dummy = nullptr;
        
        int sum = 0;
        int carry = 0;
        
        while(num1 != NULL && num2 != NULL)
        {
            sum = num1->data + num2->data + carry;
            carry = 0;
            if(sum > 9)
            {
                int Remainder = sum % 10;
                Node * temp = new Node(Remainder);
                carry = 1;
                
                if(head == nullptr) 
                {
                    head = temp;
                    dummy = temp;
                }
                else
                {
                    dummy->next = temp;
                    dummy = dummy->next;
                }
            }
            else
            {
                Node* temp = new Node(sum);
                if(head == nullptr) 
                {
                    head = temp;
                    dummy = temp;
                }
                else
                {
                    dummy->next = temp;
                    dummy = dummy->next;
                }
            }
            num1 = num1->next;
            num2 = num2->next;
        }
        
        while(num1 != NULL)
        {
           sum = num1->data + carry;
           carry = 0;
           
           Node * temp = nullptr;
           
           if(sum > 9)
           {
               int Remainder = sum % 10;
               temp = new Node(Remainder);
               carry = 1;
           }
           else temp = new Node(sum);
            
            dummy->next = temp;
            dummy = dummy->next;
            num1 = num1->next;
        }
        
        while(num2 != NULL)
        {
           sum = num2->data + carry;
           carry = 0;
           
           Node* temp = nullptr;
           
           if(sum > 9)
            {
                int Remainder = sum % 10;
                temp = new Node(Remainder);
                carry = 1;
            }
            else temp = new Node(sum);
            
            dummy->next = temp;
            dummy = dummy->next;
            num2 = num2->next;
        }
        
        if(carry != 0)
        {
            Node * temp = new Node(carry);
            dummy->next = temp;
            dummy = dummy->next;
        }
        reverse(head);
        while(head->data == 0) head = head->next;
        return head;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends