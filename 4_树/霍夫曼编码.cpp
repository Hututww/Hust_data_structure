#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

std::map<char, double> frequencies = {
    {'A', 0.2}, {'B', 0.5}, {'C', 0.13}, 
    {'D', 0.04}, {'E', 0.10}, {'F', 0.02}, {'G', 0.01}
};
    
struct HuffmanNode{
    char data;
    double weight;
    HuffmanNode *left, *right;
    HuffmanNode(char d, double w) : data(d), weight(w), left(nullptr), right(nullptr) {}
};

// struct Compare{
//     bool operator()(HuffmanNode* l, HuffmanNode* r) {
//         return l->weight > r->weight;
//     }
// };

// HuffmanNode* buildHuffmanTree(std::map<char, double>& frequencies) {
//     std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> pq;

//     for (auto [ch, freq] : frequencies){
//         pq.push(new HuffmanNode(ch, freq));
//     }

//     while (pq.size() > 1){
//         HuffmanNode *left = pq.top(); 
//         pq.pop();
//         HuffmanNode *right = pq.top(); 
//         pq.pop();

//         HuffmanNode *parent = new HuffmanNode('\0', left->weight + right->weight);
//         parent->left = left;
//         parent->right = right;
//         pq.push(parent);
//     }
//     return pq.top();
// }

HuffmanNode* buildHuffmanTree(std::map<char, double>& frequencies) {
    std::vector<HuffmanNode*> nodes;
    for (auto &p : frequencies){
        nodes.push_back(new HuffmanNode(p.first, p.second));
    }

    while (nodes.size() > 1) {
        int min = 0, lessMin = 1;
        if (nodes[lessMin]->weight < nodes[min]->weight) std::swap(min, lessMin);
        for (int i = 2; i < nodes.size(); ++i) {
            if (nodes[i]->weight < nodes[min]->weight) {
                lessMin = min;
                min = i;
            } else if (nodes[i]->weight < nodes[lessMin]->weight) {
                lessMin = i;
            }
        }


        
        HuffmanNode *left = nodes[min];
        HuffmanNode *right = nodes[lessMin];
        HuffmanNode *parent = new HuffmanNode('\0', left->weight + right->weight);
        parent->left = left;
        parent->right = right;

        if (min > lessMin) std::swap(min, lessMin);
        nodes.erase(nodes.begin() + lessMin);
        nodes.erase(nodes.begin() + min);
        nodes.push_back(parent);
    }
    return nodes.empty() ? nullptr : nodes.front();
}

void deleteTree(HuffmanNode* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void generateCode(HuffmanNode* node, std::string code, std::map<char, std::string>& huffmanCodes) {
    if (!node) return;

    if (!node->left && !node->right) {
        huffmanCodes[node->data] = code;
    }

    generateCode(node->left, code + "0", huffmanCodes);
    generateCode(node->right, code + "1", huffmanCodes);
}

int main() {
    std::map<char, double> frequencies = {
        {'A', 0.2}, {'B', 0.5}, {'C', 0.13}, 
        {'D', 0.04}, {'E', 0.10}, {'F', 0.02}, {'G', 0.01}
    };

    HuffmanNode* root = buildHuffmanTree(frequencies);
    std::map<char, std::string> huffmanCodes;
    generateCode(root, "", huffmanCodes);

    std::cout<<"Huffman Codes: "<<std::endl;
    for (auto [ch, code] : huffmanCodes){
        std::cout<<ch<<": "<<code<<std::endl;
    }
    deleteTree(root);

    return 0;
}