#include <iostream>
#include <string>
#include <chrono>

void BF(std::string full, std::string sub){
    // bool found = 0;

    for(int i = 0; i <= full.size() - sub.size(); i++){
        int j = 0;
        for(; j < sub.size(); j++){
            if(sub[j] != full[i + j]) {
                break;
            }
        }
        // if (j == sub.size()){
        //     found = 1;
        //     break;
        // }
    }

    // if(!found) {
    //     std::cout << "pairing failed" << std::endl;
    // } 
}

int main(){
    std::string A = "goodgoogoodgoogle";
    std::string subA = "google";

    std::string B = "aaaaaaaaaaaabcdefghijaaaaaaaaaaaaaaaaaayaaaaaaaaaaaxabcdefgnvubiopzaaaaaaaaaaaayaaaaaaaaxcrt";
    std::string subB = "aaaaax";

    int counter = 0;

    auto startA = std::chrono::high_resolution_clock::now();
    while(counter < 100){
        BF(A, subA);
        counter++;
    }
    auto endA = std::chrono::high_resolution_clock::now();

    auto totalTimeA = std::chrono::duration_cast<std::chrono::microseconds>(endA - startA).count();

    std::cout<<"100 x pairing time for string: "<<A<<" is "<<totalTimeA<<" us"<<std::endl;

    counter = 0;

    auto startB = std::chrono::high_resolution_clock::now();
    while(counter < 100){
        BF(B, subB);
        counter++;
    }
    auto endB = std::chrono::high_resolution_clock::now();

    auto totalTimeB = std::chrono::duration_cast<std::chrono::microseconds>(endB - startB).count();

    std::cout<<"100 x pairing time for string: "<<B<<" is "<<totalTimeB<<" us"<<std::endl;
    return 0;
}