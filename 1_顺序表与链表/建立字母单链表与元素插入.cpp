# include <iostream>

struct ListNode{
    char val;
    ListNode* next;
};

int main(){
    int totalNumber = 26;
    ListNode* head = nullptr;
    ListNode* present = nullptr;

    for(int i = 0; i < totalNumber; i++){
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        if (!head){
            head = present = node;
            node->val = 'a';
            std::cout<<"vocab list: "<<node->val;
        } else {
            present->next = node;
            present = node;
            node->val = 'a' + i;
            std::cout<<node->val;
        }
    }

    std::cout<<std::endl<<"list after insert: ";

    ListNode* catcher = head;
    while(catcher){
        std::cout<<catcher->val;
        if(catcher->val != 'n'){
            catcher = catcher->next;
        } else {
            ListNode* newI = (ListNode*)malloc(sizeof(ListNode));
            newI->val = 'i';
            newI->next = catcher->next;
            catcher->next = newI;
            std::cout<<' '<<newI->val<<' ';
            catcher = newI->next;
        }
    }
    return 0;
}