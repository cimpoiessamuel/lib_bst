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

int Node::height(){
    if(this == NULL) return 0;

    int r = rchild->height();
    int l = lchild->height();

    return max(r,l) + 1;
}

Node* Node::searchR(int k){
    if(this == NULL) return NULL;

    if(k == data) return this;

    if(k > data) return rchild->searchR(k);
    if(k < data) return lchild->searchR(k);

    return NULL;
}

bool Node::isBst(){
    if(this == NULL) return true;

    if(rchild != NULL){
        if(rchild->data > data){
            rchild->isBst();
        }else{
            return false;
        }
    }

    if(lchild != NULL){
        if(lchild->data < data){
            lchild->isBst();
        }else{
            return false;
        }
    }

    return true;
}

void Node::inOrder(){
    if(this == NULL) return;

    lchild->inOrder();
    cout << data << ' ';
    rchild->inOrder();
}
