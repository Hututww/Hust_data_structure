# include <iostream>

int main(){
    int number = 5;
    int start = 0;
    int distance = 2;
    int removed = 0;

    int a[number];
    for (int i = 0; i < number; i++){
        a[i] = 1;
    }

    int j = start; 
    while(removed < number - 1){
        j += (distance - 1);
        j %= number;
        a[j] = 0;
        removed++;

        if (j > number) j -=number;
        while (a[j] == 0){
            j++;
            j %= number;
        }
    }

    for (int k = 0; k < number; k++){
        if(a[k] != 0){
            std::cout<<"final survivor index: "<<k + 1;     //转换成1开始的序号
            break;
        }
    }
    return 0;
}