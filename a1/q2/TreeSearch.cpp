#include <queue>
#include <stack>
#include "TreeSearch.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
 * Constructor to instantiate the array
 * @param size_ - number elements in tree
 */
BinaryTree::BinaryTree(int size_){
    // TODO
}

/**
 * Function to insert an element into the tree in level order
 * @param key - element to be inserted
 */
int BinaryTree::insert(int key){
    //TODO
    
}

/**
 * Function to find the key by performing a inorder order traversal of the tree
 * @param key - key to be searched for in the tree
 */
int BinaryTree::findByInOrder(int key){
	// TODO
}

/**
 * Function to find the key by performing a level order traversal of the tree
 * @param key - key to be searched for in the tree
 */
int BinaryTree::findByLevelOrder(int key){
	// TODO
}

/**
 * Optional: Extra Credit
 * Function to insert all elements as a sorted array
 * @param keys - elements to be inserted in sorted order
 */
int insertSorted(int* keys) {
	// TODO: optional
}

/**
 * Optional: Extra Credit
 * Function to find the key by performing a binary search over sorted array
 * @param key - key to be searched for in the sorted array
 */
int BinaryTree::findByBinarySearch(int key){
	// TODO: optional
}

		
int main(){
    // read from input number and query files using the file name passed in as inputs

    // insert each input number into the tree
	
	// iterate and search for each query number using inorder traversal
    // measure the total time taken to for all the number using inorder

	// iterate and search for each query number using level-order traversal
    // measure the total time taken to for all the number using inorder

	
    // output in the format "A2a:123,456,789" where:
	// 123<=m is the number matching query numbers found 
    // 456 is the totoal time taken in milliseconds to complete the search using inorder traversal, and 
	// 789 is the total time taken in milliseconds to complete this search using level-order traversal.
}