# include <iostream>
# include <vector>

void quickSort(std::vector<char> &a, int low, int high){
    if (low >= high) return;
    int left = low, right = high;

    char pivot = a[(left + right)/2];
    while (left <= right){
        while (a[left] < pivot) left++;
        while (a[right] > pivot) right--;
        if (left <= right){
            std::swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    if (low < right) quickSort(a, low, right);
    if (left < high) quickSort(a, left, high);
}

int binarySearch(std::vector<char> &a, char key){
    int index = -1;
    int low = 0, high = a.size() - 1;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == key) index = mid;
        if(a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return index;
}

int main(){
    std::vector<char> a(20);
    std::cout<<"input 20 digits or letters"<<std::endl;
    for(int i = 0; i<20; i++) std::cin>>a[i];

    quickSort(a, 0, a.size() - 1);

    std::cout<<std::endl<<"Sorted array: ";
    for(int i = 0; i<20; i++) std::cout<<a[i]<<' ';  

    char key;
    std::cout<<std::endl<<"Enter a key to search for: "<<std::endl;
    std::cin>>key;

    int idx = binarySearch(a, key);
    if(idx < 0) {
        std::cout<<std::endl<<"404 Not Found";
    } else {
        std::cout<<std::endl<<"Found at "<<idx;
    }

    return 0;
}