# include <iostream>

int fibonacci(int n){
    if (n == 0){
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        int total = fibonacci(n-1) + fibonacci(n-2);
        return total;
    }
}

int main(){
    int n = 40;
    for (int i = 0; i <= n; i++){
        std::cout<<fibonacci(i)<<' ';        
    }
    return 0;
}