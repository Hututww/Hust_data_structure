# include <iostream>

struct ListNode{
    int val;
    ListNode* next;
};

int main(){
    int number = 5;
    int start = 0;
    int distance = 3;
    int removed = 0;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < number; i++){
        ListNode* node = (ListNode*)malloc(sizeof(ListNode));
        node->val = i + 1;
        node->next = nullptr;
        if(!head){
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    tail->next = head;

    int j = start;
    while(j != 0){
        head = head->next;
        j--;
    }

    while(removed < number - 1){
        for (int k = 1; k < distance - 1; k++){
            head = head->next;
        }                                          //到达前一个位置
        ListNode* garbage = head->next;
        head->next = head->next->next;
        removed++;
        free(garbage);
    }

    std::cout<<"final survivor index: "<<head->val;
    return 0;
}