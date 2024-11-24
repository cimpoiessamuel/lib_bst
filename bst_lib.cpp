#include "bst_lib.h"

using namespace std;

Node* Node::insertR(int k){
    if(this == nullptr) return new Node(k);

    if(data == k){
        weight++;
        return this;
    }

    if(k > data){
        rchild = rchild->insertR(k);
    }else{
        lchild = lchild->insertR(k);
    }

    return this;
}

void Node::inOrder(){
    if(this == NULL) return;

    lchild->inOrder();
    cout << data << ' ';
    rchild->inOrder();
}