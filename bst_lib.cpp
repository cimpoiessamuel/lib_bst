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

Node* Node::insertI(int k){
    if(this == NULL) return new Node(k);

    Node* current = this;

    while(current != NULL){
        if(current->data == k){
            current->weight++;
            return this;
        }

        if(k > current->data){
            if(current->rchild == NULL){
                current->rchild = new Node(k);
                return this;
            }

            current = current->rchild;
        }else{
            if(current->lchild == NULL){
                current->lchild = new Node(k);
                return this;
            }

            current = current->lchild;
        }
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
    else return lchild->searchR(k);

    return NULL;
}

Node* Node::searchI(int k){
    if(this == NULL) return NULL;

    Node* current = this;

    while(current != NULL){
        if(current->data == k) return current;

        if(k > current->data) current = current->rchild;
        else current = current->lchild;
    }
    
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

void Node::preOrder(){
    if(this == NULL) return;

    cout << data << ' ';
    lchild->preOrder();
    rchild->preOrder();
}

void Node::postOrder(){
    if(this == NULL) return;

    lchild->postOrder();
    rchild->postOrder();
    cout << data << ' ';
}