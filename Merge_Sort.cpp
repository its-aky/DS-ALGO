class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    
    Node* middleNode(Node* head) {
        Node *fast=head->next; //Change to return the first middle in case of even length
        Node *slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    
    Node* merger(Node* left,Node* right){
        
        Node *dummy=new Node(-1);
        Node *temp=dummy;
        
        while(left!=NULL && right!=NULL){
            
            if(left->data < right->data){
                
                temp->next=left;
                temp=left;
                left=left->next;
                
            }
            else{
                
                temp->next=right;
                temp=right;
                right=right->next;
                
            }
        }
        
        if(left!=NULL)temp->next=left;
        else temp->next=right;
        
        
        return dummy->next;
    }
    
    Node* mergeSort(Node* head) {
        
        if(head==NULL || head->next==NULL)return head;
        
        Node *middle=middleNode(head);
        Node *left_head=head;
        Node *right_head=middle->next;
        middle->next=NULL;
        
        left_head=mergeSort(left_head);
        right_head=mergeSort(right_head);
        
        return merger(left_head,right_head);
        
        
    }
};
