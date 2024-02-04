//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node*removeLeadingZeros(Node*head){
   if(head!=NULL and head->data==0){
       return removeLeadingZeros(head->next);
   }
   else{
       return head;
   }
}
Node*reverseNode(Node*head){
   if(head==NULL or head->next==NULL)return head;
   Node*prev=NULL,*curr=head,*forw=NULL;
   while(curr!=NULL){
       forw=curr->next;
       curr->next=prev;
       prev=curr;
       curr=forw;
   }
   return prev;
}
int length(Node*head){
   Node*curr=head;
   int len=0;
   while(curr!=NULL){
       len++;
       curr=curr->next;
   }
   return len;
}
Node* subLinkedList(Node* l1, Node* l2)
{
   //Your code here
   l1=removeLeadingZeros(l1);
   l2=removeLeadingZeros(l2);
   if(l1==NULL&&l2==NULL) return new Node(0);
   else if(l1==NULL&&l2!=NULL) return l2;
   else if(l1!=NULL&&l2==NULL) return l1;
   int n1=length(l1);
   int n2=length(l2);
   if(n2>n1){
       swap(l1,l2);
   }
   else if(n1==n2){
       Node*c1=l1,*c2=l2;
       while(c1->data==c2->data){
           c1=c1->next;
           c2=c2->next;
           if(c1==NULL){
               return new Node(0);
           }
       }
       if(c2->data>c1->data){
           swap(l1,l2);
       }
   }
   Node*c1=reverseNode(l1);
   Node*c2=reverseNode(l2);
   Node*dummy=new Node(-1);
   Node*prev=dummy;
   int borrow=0;
  while(c1!=NULL){
      int diff=borrow+c1->data-(c2!=NULL?c2->data:0);
      if(diff<0){
          diff+=10;
          borrow=-1;
      }
      else{
          borrow=0;
      }
      prev->next=new Node(diff);
      prev=prev->next;
      if(c2!=NULL){
          c2=c2->next;
      }
      c1=c1->next;
  }
   Node*head=reverseNode(dummy->next);
   head=removeLeadingZeros(head);
   return head;
}
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends