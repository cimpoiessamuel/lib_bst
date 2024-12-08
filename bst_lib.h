#include <iostream>

using namespace std;

#ifndef bst_lib_h
#define bst_lib_h

class Node{
    private:
        int data;
        int weight;
        Node* lchild;
        Node* rchild;
    public:
        Node(int data, int weight = 1): data{data}, weight{weight}, lchild{nullptr}, rchild{nullptr}{}
        ~Node(){}
        Node* insertR(int k);
        Node* insertI(int k);
        int height();
        Node* searchR(int k);
        Node* searchI(int k);
        bool isBst();
        void inOrder();
        void preOrder();
        void postOrder();
};

#endif

/*
struct Node{
    int key;
    int weight = 1;
    Node* rchild;
    Node* lchild;

    Node(int c_key, int c_weight = 1, Node* c_rchild = nullptr, Node* c_lchild = nullptr){
        key = c_key;
        rchild = c_rchild;
        lchild = c_lchild;
    }
};


//create

Node* create_node(Node* r, int key){
    if(r == NULL) return new Node(key);

    if(r->key == key){
        r->weight++;
        return r;
    }

    if(key > r->key){
        r->rchild = create_node(r->rchild, key);
    }else{
        r->lchild = create_node(r->lchild, key);
    }

    return r;
}

Node* create_node_i(Node* r, int key){
    if(r == NULL){
        return new Node(key);
    }

    Node* current{r};

    while(current != NULL){
        if(current->key == key){
            current->weight++;
            return r;
        }

        if(key > current->key){
            if(current->rchild == NULL){
                current->rchild = new Node(key);
                return r;
            }else{
                current = current->rchild;
                continue;
            }
        }

        if(key < current->key){
            if(current->lchild == NULL){
                current->lchild = new Node(key);
                return r;
            }else{
                current = current->lchild;
                continue;
            }
        }
    }

    return r;
}


//search

Node* search_node(Node* r, int key){
    if(r == NULL) return NULL;

    if(key == r->key) return r;

    if(key > r->key) return search_node(r->rchild, key);

    if(key < r->key) return search_node(r->lchild, key);

    return NULL;
}


//print

void pre_order(Node* node){
    if(node == NULL) return;

    cout << node->key << " ";
    pre_order(node->lchild);
    pre_order(node->rchild);
}

void in_order(Node* node){
    if(node == NULL) return;

    in_order(node->lchild);
    cout << node->key << " ";
    in_order(node->rchild);
}

void post_order(Node* node){
    if(node == NULL) return;

    post_order(node->lchild);
    post_order(node->rchild);
    cout << node->key << " ";
}


//delete

Node*  next_node_in_order(Node* node){
    if(node->lchild == NULL) return node;

    node = next_node_in_order(node->lchild);

    return node;
}

Node* delete_node(Node* r, int key){
    if(r == NULL) return r;

    if(r->key == key){
        if(r->lchild == NULL){
            Node* temp = r->rchild;
            delete r;
            return temp;
        }

        if(r->rchild == NULL){
            Node* temp = r->lchild;
            delete r;
            return temp;
        }
        
        Node* temp = next_node_in_order(r->rchild);
        r->key = temp->key;
        r->rchild = delete_node(r->rchild, temp->key);

    }else{
        if(key > r->key){
            r->rchild = delete_node(r->rchild, key);
        }else{
            r->lchild = delete_node(r->lchild, key);
        }
    }

    return r;
}


//height

int height(Node* root){
    if(root == NULL) return 0;

    int l = height(root->lchild);
    int r = height(root->rchild);

    return max(l,r) + 1;
}


//verify

bool is_bst(Node* node){
    if(node == NULL) return true;

    if((node->lchild != NULL && node->lchild->key < node->key) && (node->rchild != NULL && node->rchild->key > node->key)){
        is_bst(node->lchild);
        is_bst(node->rchild);
    }else{
        return false;
    }

    return true;
}
*/