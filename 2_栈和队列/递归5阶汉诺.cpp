# include <iostream>

int count = 1;

void hanoi(int number,char start,char auxiliary, char target){
    if (number == 1) {
        std::cout<<"Step "<<count<<": move disk from "<<start<<" to "<<target<<std::endl;
        count++;
    } else {
        hanoi(number-1, start, target, auxiliary);
        std::cout<<"Step "<<count<<": move disk from "<<start<<" to "<<target<<std::endl;
        count++;   
        hanoi(number-1, auxiliary, target, start);     
    }
}

int main(){
    int number = 5;
    char start = 'A';
    char auxiliary = 'B';
    char target = 'C';

    hanoi(number, start, auxiliary, target);
    return 0;
}