/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
    struct Node* get_tail(struct Node* head){
        while(head->next){
            head=head->next;
        }
        return head;
    }
    
    void sorter(struct Node *head,struct Node *tail){
        
        if(head==NULL || tail==NULL || head==tail)return;
        
        struct Node *pivot=partition(head,tail);
        sorter(head,pivot);
        sorter(pivot->next,tail);
    }
    
    struct Node *partition(struct Node *head,struct Node *tail){
        
        struct Node *pivot=head;
        struct Node *curr=head->next;
        struct Node *prev=head;
        
        while(curr!=tail->next){
            
            if(curr->data < pivot->data){
                swap(prev->next->data,curr->data);
                prev=prev->next;
            }
            
            curr=curr->next;
        }
        
        swap(prev->data,pivot->data);
        return prev;
        
        
    }
    
    struct Node* quickSort(struct Node* head) {
        
        if(head == NULL || head->next==NULL)return head;
        struct Node *tail=get_tail(head);
        
        sorter(head,tail);
        
        return head;
        
        
        
    }
};
