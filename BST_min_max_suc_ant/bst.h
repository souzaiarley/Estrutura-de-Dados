#ifndef BST_H
#define BST_H
#include <stdexcept>
#include <iostream>

/*******************************
 * Definicao do struct Node
 *******************************/
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l, Node *r)
        : key(k), left(l), right(r) 
        { }

    ~Node() {
        std::cout << "Node removed: " << this->key << std::endl;
    }
};

/*******************************
 * class BST
 *******************************/
class BST { // classe BST (Binary Search Tree)
public:
    BST();
    ~BST();
    void bshow();
    void add(int key);       // Adicionar chave 
    bool contains(int key);  // contem chave key?
    int minimum();           // Devolve chave minima
    int maximum();           // Devolve chave maxima
    int successor(int k);    // Devolve chave sucessora de k
    int predecessor(int k);  // Devolve chave antecessora de k
private:
    Node *root;
    void bshow(Node *node, std::string heranca);
    Node *add(Node *node, int key);
    Node *search(Node *node, int key);
    Node *clear(Node *node);
    Node *minimum(Node *node);                          // ----> implementar
    Node *maximum(Node *node);                          // ----> implementar
    Node *sucessor(Node *x, Node *raiz);                // ----> implementar
    Node *predecessor(Node *x, Node* raiz);             // ----> implementar
    Node *ancestral_sucessor(Node *x, Node *raiz);      // ----> implementar
    Node *ancestral_predecessor(Node *x, Node* raiz);   // ----> implementar
};

BST::BST() {  // Construtor
    root = nullptr; 
} 
    
BST::~BST() {  // Destrutor
    root = clear(root);
} 

// Esta funcao recebe um ponteiro para um node e libera
// os nos da arvore enraizada nesse node. A funcao devolve
// nullptr apos apagar a arvore enraizada em node
Node *BST::clear(Node *node) {  
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }
    return nullptr;
}

// Esta funcao recebe um ponteiro para node e uma key e:
// (1) devolve nullptr caso key nao esteja na arvore;
// (2) devolve um ponteiro para o no contendo key caso contrario.
Node *BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key)
        return node;
    if(key > node->key)
        return search(node->right, key);
    else 
        return search(node->left, key);
} 

bool BST::contains(int key) {
    return search(root, key) != nullptr;
}
 
// Esta funcao insere o no com chave key na arvore
// enraizada em node, somente se a chave key nao for repetida.
// Devolve um ponteiro para a raiz da nova arvore 
// enraizada em node.
Node *BST::add(Node *node, int key) {
    if(node == nullptr) { // Condicao de Parada
        node = new Node(key, nullptr, nullptr);
        return node;
    }
    // Casos Gerais
    if(key > node->key)
        node->right = add(node->right, key);
    else if(key < node->key)
        node->left = add(node->left, key);
    return node;
} 

void BST::add(int key) {
    root = add(root, key);
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o minimo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::minimum(Node *node) { // TODO
    if (node == nullptr){
        return node;
    }
    else{
        if (node->left == nullptr){
            return node;
        }
        else {
            minimum(node->left);
        }
    }
}

// funcao publica. Devolve a chave minima da arvore
int BST::minimum() { // TODO
    if (minimum(root) == nullptr){
        throw std::runtime_error("erro: arvore vazia");
    }
    else {
        return minimum(root)->key;
    }
}

// Recebe um ponteiro para a arvore enraizada em node e:
// (1) devolve o ponteiro para o no contendo o maximo; ou
// (2) devolve nullptr se a arvore for vazia.
Node *BST::maximum(Node *node) { // TODO
    if (node == nullptr){
        return node;
    }
    else{
        if (node->right == nullptr){
            return node;
        }
        else {
            maximum(node->right);
        }
    }
}

// Funcao publica. Devolve a chave maxima da arvore
int BST::maximum() { // TODO
    if (maximum(root) == nullptr){
        throw std::runtime_error("erro: arvore vazia");
    }
    else {
        return maximum(root)->key;
    }
}

// Devolve o ponteiro para o no sucessor do no x
// passado como parametro. A funcao tambem recebe
// como parametro a raiz da arvore.
Node *BST::sucessor(Node *x, Node *raiz) { // TODO
    if (x == nullptr || raiz == nullptr){
        return nullptr;
    }
    else {
        if (x->right != nullptr){
            return minimum(x->right);
        }
        else {
            return ancestral_sucessor(x, raiz);
        }
    }
}

Node *BST::ancestral_sucessor(Node *x, Node *raiz) { // TODO
    if (search(root->left, x->key) == nullptr) {
        return nullptr;
    }

    if (maximum(raiz->left) == x){
        return raiz;
    }
    else if (maximum(raiz->left) != x){
        return ancestral_sucessor(x, raiz->left);
    }
}

int BST::successor(int k) { // TODO
    if (!contains(k) || sucessor(search(root, k), root) == nullptr){
        throw std::runtime_error("");
    }
    return sucessor(search(root, k), root)->key;
}

// Retorna o ponteiro para o no antecessor do no x
// passado como parametro. A funcao tambem recebe 
// como parametro a raiz da arvore.
Node* BST::predecessor(Node *x, Node* raiz) { // TODO
    if (x == nullptr || raiz == nullptr){
        return nullptr;
    }
    else {
        if (x->left != nullptr){
            return maximum(x->left);
        }
        else {
            return ancestral_predecessor(x, raiz);
        }
    }
}

Node *BST::ancestral_predecessor(Node *x, Node* raiz) { // TODO
    if (search(root->right, x->key) == nullptr) {
        return nullptr;
    }

    if (minimum(raiz->right) == x){
        return raiz;
    }
    else if (minimum(raiz->right) != x){
        return ancestral_predecessor(x, raiz->right);
    }
}

int BST::predecessor(int k) { // TODO
    if (!contains(k) || predecessor(search(root, k), root) == nullptr){
        throw std::runtime_error("");
    }
    return predecessor(search(root, k), root)->key;
}

#endif