#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    
    Node(int d){
        data = d;
        next = NULL;
    }
};


Node *head = NULL;


/**** add functions here ****/


void createLLUsingArray(int arr[],int n){
    
    if(n==0)
    {
        head = NULL;
        return;
    }
    
    Node *prev = new Node(arr[0]);
    head = prev;
    
    for(int i=1 ; i<n ; ++i){
        Node *temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
}

void printLL(){
    
    Node *curr = head;
    while(curr!=NULL){
        cout << curr->data << ' ';
        curr = curr -> next;
    }
    cout << endl;
}

void insertFront(int data){
    
    Node *temp = new Node(data);
    
    if(head == NULL){
        head = temp;
        return;
    }
    else{ 
        temp->next = head;
        head = temp;
    }
}

void insertNodeAfterGivenNode(int src,int data){
    Node *temp = new Node(data);
    
    Node *curr = head;
    
    
    while(curr!=NULL){
        if(curr->data == src){
            temp->next = curr->next;
            curr->next = temp;
            return;
        }
        curr = curr -> next;
    } 
    
    cout << src << " Node not Found!" << endl;  
}

void inserAtEnd(int data){
    Node *curr,*temp;
    
    curr = head;
    temp = new Node(data);
    
    if(head == NULL){
        head = temp;
        return;
    }
    
    while(curr->next != NULL){
        curr = curr -> next;
    }
    curr->next = temp;
    
}

void deleteFirstOccuranceIter(int src){
    if(head == NULL){
        cout << "List is Empty ..." << endl;
        return;
    }

    Node *curr = head;
    Node *temp = NULL;
    
    if(curr!=NULL && curr->data == src){
        head = curr->next;
        delete curr;
        return; 
    }
    
    while(curr->next != NULL){
        
        if(curr->next->data == src){
            // we need to delte that node
            temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return;
        }
        curr = curr->next;
    }
    
    cout << "No such occurance of : " << src << endl;
    
}

void deleteFirstOccuranceRecur(Node *&curr,int src){
    if(curr == NULL){
        cout << "No such element"<< endl;
        return;
    }
    
    if(curr->data == src){
        Node *temp = curr;
        curr = curr->next;
        
        delete temp;
        return;
    }
    deleteFirstOccuranceRecur(curr->next, src);
}

int lenOfLL(){
    Node *curr = head;
    int len = 0;
    while(curr!=NULL)
    {
        len++;
        curr = curr->next;
    }
    return len;
}


void deleteInPos(int pos){
    if(pos < 0 || pos >= lenOfLL()){
        cout << "Invalid posistion value " << endl;
        return;
    }
    
    Node *temp,*curr;
    curr = head;
    
    if(pos == 0){
        temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    for(int i=1 ; i<=pos-1 ; ++i){
        curr = curr->next;
    }
    temp = curr->next;
    curr->next = temp->next;
    delete temp;
    
}

void deleteList(){
    Node *temp,*curr;
    curr = head;
    
    while(curr!=NULL){
        temp = curr;
        curr = curr->next;
        cout << temp->data << " is deleted " << endl;
        delete temp;
    } 
    head = NULL;
      
}

int lenOfLLRecur(Node *curr){
    if(curr == NULL)
        return 0;
    return 1 + lenOfLLRecur(curr->next);
}

bool searchIter(int x){
    Node *curr = head;
    
    while(curr!=NULL){
        if(curr->data == x){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool searchRecur(Node *curr,int x){
    if(curr == NULL)
        return false;
    
    if(curr->data == x)
        return true;
    return searchRecur(curr->next,x);
}

int getNthNode(int n){
    
    Node *curr = head;
    int pos = 0;
    if(n==0)
        return curr->data;
    
    while(curr!=NULL){
        if(pos == n)
            return curr->data;
        pos++;
        curr = curr->next;   
    }
    
    return -1;
    
}
 

int main()
{
    int arr[] = {1,2,3,4,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    createLLUsingArray(arr,n);
    insertFront(0);
    insertNodeAfterGivenNode(0,0);
    printLL();
    inserAtEnd(6);
    printLL();
    
        
    cout << getNthNode(9);
    return 0;
}
