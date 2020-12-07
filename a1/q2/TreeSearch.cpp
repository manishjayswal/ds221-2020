#include <queue>
#include <stack>
#include "TreeSearch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

/**
 * Constructor to instantiate the array
 * @param size_ - number elements in tree
 */
BinaryTree::BinaryTree(int size_){
    // TODO
    size = size_ ;
    treeArr = new int[size];
    sortedArr = new int[size];
}

/**
 * Function to insert an element into the tree in level order
 * @param key - element to be inserted
 * @return 0 if insert was success, -1 if it failed
 */

int BinaryTree::insert(int key){
    //TODO
    static int j=0;
    if(treeArr[j] = key)
    {
        j++;
        return 0;
    }
    return -1;
}


/**
 * Function to find the key by performing a inorder order traversal of the tree
 * @param key - key to be searched for in the tree
 * @return value - return the index of the key (starting at 1) if found else return -1
 */
int BinaryTree::findByInOrder(int key){
	// TODO
    for(int i=0;i<size;i++)
    {
        
    }
}

/**
 * Function to find the key by performing a level order traversal of the tree
 * @param key - key to be searched for in the tree
 * @return value - return the index of the key (starting at 1) if found else return -1
 */
int BinaryTree::findByLevelOrder(int key){
	// TODO
    for(int i=0; i<size; i++)
    {
        if(key==treeArr[i])
        return i;
    }
    return -1;
}

/**
 * Optional: Extra Credit
 * Function to insert all elements as a sorted array
 * @param keys - elements to be inserted in sorted order
 * @return 0 if insert was success, -1 if it failed
 */
int BinaryTree::insertSorted(int* keys) {
    sort(keys,keys+size);
    sortedArr = keys;
}

/**
 * Optional: Extra Credit
 * Function to find the key by performing a binary search over sorted array
 * @param key - key to be searched for in the sorted array
 * @return value - return the index of the key (starting at 1) if found else return -1
 */
int BinaryTree::findByBinarySearch(int key){
	// TODO: optional, extra credit
    int left = 0;
    int right = size-1;
    int mid =  left+ (right-left)/2;
    while(left<=right){
        if(sortedArr[mid]==key)
            return mid;
        else if(sortedArr[mid]<key)
            left = mid + 1;
        else 
            right = mid -1;
        mid =  left+ (right-left)/2;
    }
    return -1;
}

		
int main(){
    // read from input number and query files using the file name passed in as inputs
    string numberFile, queryFile;
    int n1, n2;
    cout<<"\nEnter the input number file name: " << endl;
    getline(cin,numberFile);
    ifstream numFilePtr, queryFilePtr;
    numFilePtr.open(numberFile);
    numFilePtr >> n1;
    int arr1[n1];
    for (int i = 0; i<n1; i++)
    {
        numFilePtr >> arr1[i];
    }
    numFilePtr.close();

    cout<<"\nEnter the query file name: ";
    getline(cin,queryFile);
    queryFilePtr.open(queryFile);
    queryFilePtr >> n2;
    int arr2[n2];
    for(int i = 0; i<n2; i++)
    {
        queryFilePtr >> arr2[i];
    }
    queryFilePtr.close();
    

    // insert each input number into the tree
    BinaryTree bt1(n1);
    for (int i = 0; i < n1; i++)
    {
        bt1.insert(arr1[i]);
    }
	
	// iterate and search for each query number using inorder traversal
    // measure the total time taken to for all the number using inorder

	// iterate and search for each query number using level-order traversal
    // measure the total time taken to for all the number using level-order
    int counter1 = 0;
    auto start_time = chrono::steady_clock::now();
    for (int i = 0; i < n2; i++)
    {   
        if (bt1.findByLevelOrder(arr2[i])==-1)
        continue;
        counter1++;
    }
    auto stop_time = chrono::steady_clock::now();
    cout<<"A2a:"<<counter1<<","<<","<<chrono::duration_cast<chrono::nanoseconds>(stop_time-start_time).count()<< endl;
    
    // output in the format "A2a:123,456,789" where:
	// 123<=m is the number matching query numbers found 
    // 456 is the total time taken in nanoseconds to complete the search using inorder traversal, and 
	// 789 is the total time taken in nanoseconds to complete this search using level-order traversal.

    //inserting given elements in an sorted array
    bt1.insertSorted(arr1);

    //searching given query elements using binary search
    auto start_time2 = chrono::steady_clock::now();
        for(int i=0; i<n2; i++)
    {   
        if(bt1.findByBinarySearch(arr2[i])==-1)
        continue;
    }
    auto stop_time2 = chrono::steady_clock::now();
    cout<<"A2c:"<<chrono::duration_cast<chrono::nanoseconds>(stop_time2-start_time2).count()<<endl;

    return 0;
}
