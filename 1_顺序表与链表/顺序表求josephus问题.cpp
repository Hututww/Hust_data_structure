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

    for (int j = start; removed < number - 1;){
        j += distance;
        a[j] = 0;
        removed++;

        if (j > number) j -=number;
        while (a[j] = 0) j++;
    }

    for (int k = 0; k < number; k++){
        if(a[k] != 0){
            std::cout<<"final survivor index: "<<k;
            break;
        }
    }
    return 0;
}