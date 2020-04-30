#include <iostream>
#include "BST.h"
/* Name: (Alexander Vazquez)
* Date: (12/6/19)
* Section: (1)
* Assignment: (8)
* Due Date: (12/6/19)
* About this project: (This project creates a binary tree and performs various functions associated with manipulating the tree. Worked with Jack Otis as some of the functions were easier to do together)
* Comments: (Code compiles and runs without errors)
* (deleting the root will throw a runtime error.)
* Honor Pledge: I have abided by the Wheaton Honor Code and all work below
* was performed by (Alexander Vazquez).
*/
using namespace std;
/* void insert(int key) [x]
 * BSTNode* find(int key)[x]
 * void remove(int key)[x]
 * BSTNode* getMax(BSTNode* curr)[x]
 * int getHeight()[x]
 * bool isBalanced()[x]
 * vector<int> inOrderNonRecursive()[x]
 * vector<int> postOrderNonRecursive() [x]
 * vector<int> levelOrder()[x]
*/

void print(vector<int> v) {
    cout << "vec: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main() {
    BST tree;
    BSTNode * ans;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(12);
    tree.insert(11);
    tree.insert(14);
    /*tree.insert(15);
     * tree.insert(16);
     * tree.insert(17);
     * tree.insert(18);
     * tree.insert(19);
     * tree.insert(20);
     * // to make tree unbalanced
     * */
    cout <<  "Done with inserts";
 //tree.remove(10); //removes a number in tree
    //tree.remove(230); removes a number not in tree
   //ans= tree.find(2);  // works for finding an element
// cout << " \n Checking find " << ans << "<--- is Pointer  " << ans->key << "<---- is Key";
  //  cout << "getting height ";
   // cout << tree.getHeight();   //works for getting height
  //  cout << " got height ";
 //  cout << tree.isBalanced() << "Tree is balanced?";// works when tree is balanced and unbalanced
   vector<int> v1 = tree.preOrder();
    cout << " \n This is pre \n";
    print(v1);
    vector<int> v2 = tree.inOrder();
    cout << " \n This is in order \n";
    print(v2);
    vector<int> v3 = tree.postOrder();
    cout << " \n This is post \n";
    print(v3);
    cout << " printing tree.levelOrder \n ";
    vector<int> v4 = tree.levelOrder();
    print(v4);
    cout << " printing inOrderNonRecursive \n ";
    vector<int> v5 = tree.inOrderNonRecursive();
    print(v5);
    cout << " printing postOrderNonRecursive \n ";
    vector<int> v6 = tree.postOrderNonRecursive();
    print (v6);

    /* try to run all the traversals on your tree
     * the preOrder should give you: [10,5,2,15,12,11,14]
     * the inOrder should give you: [2,5,10,11,12,14,15]
     * the postOrder should give you: [2,5,11,14,12,15,10] if curr left and right are nullptr or if values of children are in array add the number. After a number is added traverse rest of tree. If you've seen a key go to other option.
     * the levelOrder should give you: [10,5,15,2,12,11,14]
     **/



    return 0;
}