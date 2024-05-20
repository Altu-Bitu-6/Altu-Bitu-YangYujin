#include <iostream>
#include <vector>

using namespace std;

typedef struct Node{
    int key;
    struct Node *left, *right;
} Node;

Node* makeTree(Node* node, int key){
    if(node == NULL){
        Node* new_node = new Node();
        new_node->key = key;
        new_node->left = new_node->right = NULL;
        return new_node;
    }
    if(key < node->key){
        node->left = makeTree(node->left, key);
    }
    else if(key > node->key){
        node->right = makeTree(node->right, key);
    }
    return node;
}

void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->key << endl;
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a;
    vector<int> keys;
    Node* root = NULL;
    
    while(cin >> a){
        keys.push_back(a);
    }
    
    for(int i = 0; i < keys.size(); i++){
        root = makeTree(root, keys[i]);
    }
    
    postorder(root);

    return 0;
}
