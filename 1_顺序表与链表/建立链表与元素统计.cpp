# include <iostream>

struct ListNode{
    int val;
    ListNode* next;
};

int febonacci(int n){
    if(n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return febonacci(n-1) + febonacci(n-2);
    }
}

int main(){
    int totalNumber = 16;
    ListNode* head = nullptr;
    ListNode* present = nullptr;

    for(int i = 0; i < totalNumber; i++){
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        if (!head){
            head = present = node;
            node->val = febonacci(i)%2;
            std::cout<<"febonacciDevidedBy2: "<<node->val<<' ';
        } else {
            present->next = node;
            present = node;
            node->val = febonacci(i)%2;
            std::cout<<' '<<node->val<<' ';
        }
    }

    ListNode* reader = (ListNode*)malloc(sizeof(ListNode));
    reader = head;
    int counter = 0;
    while(reader){
        if (reader->val == 0) counter++;
        reader = reader->next;
    }
    std::cout<<std::endl<<"number of zero is: "<<counter;
    return 0;
}