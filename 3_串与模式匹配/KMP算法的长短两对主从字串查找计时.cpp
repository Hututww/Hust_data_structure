#include <iostream>
#include <string>
#include <chrono>
#include <vector>

std::vector<int> buildNext(std::string sub){
    std::vector<int> next(sub.size());
    next[0] = 0;
    if(sub.size() == 1) return next;
    
    next[1] = 1;
    int matchLen = 0;
    for (int i = 2; i < sub.size(); ++i){
        while (matchLen > 0 && sub[i - 1] != sub[matchLen]){
            matchLen = next[matchLen] - 1;
        }
        if (sub[i - 1] == sub[matchLen]){
            matchLen++;
        }
        next[i] = matchLen + 1;
    }
    return next;
}

void KMP(std::string &full, std::string &sub){
    // bool found = 0;

    int i = 0;
    int j = 0;
    std::vector<int> next = buildNext(sub);

    while(i < full.size()){
        if(full[i] == sub[j]){
            i++;
            j++;
            if (j == sub.size()){
                // found = 1;
                break;
            }
        } else if (j > 0){
            j = next[j-1];
        } else {
            i++;
        }
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
        KMP(A, subA);
        counter++;
    }
    auto endA = std::chrono::high_resolution_clock::now();

    auto totalTimeA = std::chrono::duration_cast<std::chrono::microseconds>(endA - startA).count();

    std::cout<<"100 x pairing time for string: "<<A<<" is "<<totalTimeA<<" us"<<std::endl;

    counter = 0;

    auto startB = std::chrono::high_resolution_clock::now();
    while(counter < 100){
        KMP(B, subB);
        counter++;
    }
    auto endB = std::chrono::high_resolution_clock::now();

    auto totalTimeB = std::chrono::duration_cast<std::chrono::microseconds>(endB - startB).count();

    std::cout<<"100 x pairing time for string: "<<B<<" is "<<totalTimeB<<" us"<<std::endl;
    return 0;
}