#include "BST.h"
#include "BSTNode.h"
#include <vector>
#include <queue>
#include <stack>
#include <stdexcept>
#include <iostream>
#include <algorithm>

using namespace std;

BST::BST() {
    this->root = nullptr;
    this->size = 0;
}

BST::~BST() {
    this->destructTree(this->root);
}

bool BST::isEmpty() const {
    return this->size == 0;
}

int BST::getSize() const {
    return this->size;
}
bool BST::isBalanced() const {
    BSTNode * leftHeight=this->root->left;
    BSTNode * rightHeight=this->root->right;
    int  HL,HR;
    HL=getHeight_h(leftHeight); //gets the height of both trees to compare them to each other.
    HR=getHeight_h(rightHeight);
    return HL == HR || HR - HL == 1 || HR - HL == -1;

}

int BST::getHeight() const {
    BSTNode * curr= this->root;
    int totalHeight=getHeight_h(curr);
    int const finalHeight=totalHeight;
    return finalHeight;

}
int BST::getHeight_h(BSTNode * curr) const { //recursive function to get height of tree
    if(curr==nullptr){
        return 0;
    }
    int ln = getHeight_h(curr->left);  //for left
    int rn = getHeight_h(curr->right);  //for right
    return 1 + maxOfNodes_h(ln,rn);  //returns whichever height is greater plus one
}

int BST::maxOfNodes_h(int ln, int rn) const{   // compares two nodes on the tree to count height.
    if (ln > rn){
        return ln;
    }
    else{
        return rn;
    }
}

+
    //throw runtime_error("BST::insert, not yet implemented");


}

BSTNode* BST::find(int key) {
   // BSTNode * maxPTR;  //checking getMax in here cause function is private.
   // maxPTR=getMax(this->root);
    //cout << "This is the pointer for MAX and the key " << maxPTR << " and the key : "<< maxPTR->key;
    BSTNode* location = find_h(key, this->root);
    if (location == nullptr) {
        throw runtime_error("BST::find, key not present in BST");
    }
    return location;
}

void BST::remove(int key){
    BSTNode * curr = this->root;
    if(key==this->root->key){ //in case key is root terminates program cause there's no other purpose.
    }
    remove_h( key, curr);

}
void BST::remove_h(int key, BSTNode * curr) {
    queue<int> valQueue;
    bool found=false;
    if (curr != nullptr){ //stores values of tree into queue
        valQueue.push(curr->key);
    }
    queue<int> newQueue;
    while (!valQueue.empty()) { //stores values of tree into queue
        BSTNode *newCurr;
        newCurr = find(valQueue.front());
        if (newCurr->left != nullptr) {
            valQueue.push(newCurr->left->key);
        }
        if (newCurr->right != nullptr) {
            valQueue.push(newCurr->right->key);
        }
        newQueue.push(valQueue.front());
        if(key == newQueue.back()){
            found=true;
        }
        valQueue.pop();
    }
    this->root->left = nullptr;
    this->root->right = nullptr;
    for (int i = 0; i < size; i++){
        if (newQueue.front() != key && newQueue.front() != this->root->key){ //deletes values from old queue and inserts them into a new ordered queue.
            insert(newQueue.front());
            newQueue.pop();
            size --;
        }
        else{
            newQueue.pop();
        }
    }
    if(!found){
        __throw_runtime_error("Error, key not in list");
    }
    size --;
}

bool BST::contain(int key) {
    BSTNode* location = find_h(key, this->root);
    return location != nullptr;
}

vector<int> BST::preOrder() {
    vector<int> vals;
    this->preOrder_h(this->root, vals);
    return vals;
}

vector<int> BST::inOrder() {
    vector<int> vals;
    this->inOrder_h(this->root, vals);
    return vals;
}

vector<int> BST::postOrder() {
    vector<int> vals;
    this->postOrder_h(this->root, vals);
    return vals;
}

// Helper functions
BSTNode* BST::insert_h(int key, BSTNode *curr) {
    // TODO: complete insert_h
    size++;
    BSTNode * theHead = new BSTNode(key);
    return theHead;

    //throw runtime_error("BST::insert_h, not yet implemented");
}

BSTNode* BST::find_h(int key, BSTNode *curr) {

    BSTNode * rootPTR=this->root;
    BSTNode * searcherCurr = curr;
    if(key==rootPTR->key){
        return rootPTR;
    }
    while(true) {

        if (!isEmpty() && key > searcherCurr->key ) { //if I found the value I'm looking for
            if (searcherCurr->right->key == key){
                return searcherCurr->right;

            }
            if (key > searcherCurr->key && searcherCurr->right != nullptr ) { //if val of what I'm looking for is higher move right
                searcherCurr = searcherCurr->right;
            }


        }
        if (!isEmpty() && key < searcherCurr->key){
            if(searcherCurr->left->key == key){ //if I found the value I'm looking for
                return searcherCurr->left;
            }
            if (key < searcherCurr->key && searcherCurr->left != nullptr) { //if val of what I'm looking for is lower move left
                searcherCurr = searcherCurr->left;
            }

        }
        if(isEmpty() || (searcherCurr->left == nullptr && searcherCurr->right == nullptr)){
                __throw_runtime_error("Not in tree"); //if not found
        }

    }
}

BSTNode* BST::getMax(BSTNode *curr) {
    BSTNode * theMax = curr;
    if(isEmpty()){
        __throw_runtime_error("Tree empty");
    }
    while(theMax->right != nullptr){
        theMax=theMax->right;
    }
    return theMax;
}

void BST::preOrder_h(BSTNode *curr, vector<int> &v) {
    if (curr != nullptr) {
        v.push_back(curr->key);
        this->preOrder_h(curr->left, v);
        this->preOrder_h(curr->right, v);
    }
}

void BST::inOrder_h(BSTNode *curr, vector<int> &v) {
    if (curr != nullptr) {
        this->inOrder_h(curr->left, v);
        v.push_back(curr->key);
        this->inOrder_h(curr->right, v);
    }
}

void BST::postOrder_h(BSTNode *curr, vector<int> &v) {
    if (curr != nullptr) {
        this->postOrder_h(curr->left, v);
        this->postOrder_h(curr->right, v);
        v.push_back(curr->key);
    }
}
vector<int> BST::levelOrder(){
    vector<int> vals;
    this->levelOrder_h(this->root, vals);
    return vals;
}
void BST::levelOrder_h(BSTNode *curr, vector<int> &v) {
    queue<int> Queue;
    if (curr != nullptr){
        Queue.push(curr->key); ////populates queue with initial value
    }
    while (!Queue.empty()) {
        BSTNode *newCurr;
        newCurr = find(Queue.front());
        if (newCurr->left != nullptr) {
            Queue.push(newCurr->left->key); //populates queue from top down
        }
        if (newCurr->right != nullptr) {
            Queue.push(newCurr->right->key); //populates queue from top down
        }
        v.push_back(Queue.front());
        Queue.pop();
    }
}
vector<int> BST::inOrderNonRecursive(){
    vector<int> vals;
    this->inOrderNonRecursive_h(this->root, vals);
    return vals;
}

void BST::inOrderNonRecursive_h(BSTNode *curr, vector<int> &v) {
    queue<int> Queue;  //makes Queue
    if (curr != nullptr){
        Queue.push(curr->key);
    }
    queue<int> newQueue;  //makes second queue to copy
    int MAX; bool maxDefined = false; //makes min and max to later use as reference.
    int MIN; bool minDefined = false;
    while (!Queue.empty()) { //populates queue
        BSTNode *newCurr;
        newCurr = find(Queue.front());
        if (newCurr->left != nullptr) {
            Queue.push(newCurr->left->key);
            if (!minDefined){
                MIN = newCurr->left->key;
                minDefined = true; //gets min
            }
            if (newCurr->left->key < MIN){
                MIN = newCurr->left->key; //compares min
            }
        }
        if (newCurr->right != nullptr) {
            Queue.push(newCurr->right->key);
            if (!maxDefined){
                MAX = newCurr->right->key; //gets max
                maxDefined = true;
            }
            if (newCurr->right->key > MAX){
                MAX = newCurr->right->key;  //compares max
            }
        }
        newQueue.push(Queue.front()); //populates second queue
        Queue.pop();
    }
    int Array[size];
    for (int i = 0; i < size; i++){
        Array[i] = newQueue.front();
        newQueue.pop();
    }
    int Avg = sizeof(Array)/ sizeof(Array[0]);
    sort(Array, Array + Avg); //sorts array for order.
    for (int i = 0; i < size; i++){
        v.push_back(Array[i]);
    }
}
bool BST::leftInVec_h(BSTNode * curr, vector<int> valVector){ //checks if the value below curr on the left is already in the array.
    if(curr==nullptr){
        return false;
    }
    int vSize;
    vSize = valVector.size();
    for(int j=0; j<vSize;j++){
        if(curr->key == valVector[j]){ //finds if key in vector already
            return true;
        }
    }
    return false;


}
bool BST::rightInVec_h(BSTNode * curr, vector<int> valVector){ //checks if the value below curr on the right is already in the array.
    if(curr==nullptr){
        return false;
    }
    int vSize;
    vSize = valVector.size();
    for(int j=0; j<vSize;j++){
        if(curr->key == valVector[j]){ //finds if key in vector already
            return true;
        }
    }
   return false;
}
vector<int> BST::postOrderNonRecursive(){
//if curr left and right are nullptr or if values of children are in array add the number. After a number is added traverse rest of tree. If you've seen a key go to other option.
    vector<int> valVector;
    valVector.push_back(0);
    BSTNode * curr=this->root;
    bool done=false;
    while (!done){
        if(valVector.size() == size ){
            //to stop the loop once it is reordered.
            done=true;
        }
        if(((!leftInVec_h(curr->left,valVector) && !rightInVec_h(curr->right,valVector)) && (curr->left != nullptr && curr->right != nullptr))){
            //at the start, both the left and right node are not in the vector, so I just make it go left to start the process.
            curr=curr->left;
        }
        if((curr->left == nullptr && curr->right == nullptr) || (leftInVec_h(curr->left,valVector) && curr->right==nullptr) ||  (rightInVec_h(curr->right,valVector) && curr->left==nullptr) || (rightInVec_h(curr->right,valVector) && leftInVec_h(curr->left,valVector))){
            //Excepts all possible cases of when a node could be accepted into the array
            valVector.push_back(curr->key);
            curr=this->root;
        }
        if((leftInVec_h(curr->left,valVector) || curr->left==nullptr) && curr->right != nullptr && !rightInVec_h(curr->right,valVector)){
            //if the left is in the vector or there is no left node, progress to the right.
            curr=curr->right;
        }
        if((rightInVec_h(curr->right,valVector) || curr->right == nullptr) && !leftInVec_h(curr->left,valVector) && curr->left != nullptr){
            //if the right is in the vector or there is no right node, progress to the left.
            curr=curr->left;
        }

    }
    valVector.erase(valVector.begin());
    return valVector;
}

void BST::destructTree(BSTNode *curr) {
    if (curr != nullptr) {
        destructTree(curr->left);
        destructTree(curr->right);
        delete curr;
    }
}