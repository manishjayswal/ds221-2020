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
    stack<int> iStack;
    int current=0;
    //place index to a tree node on the stack before traversing the node's left subtree 
    iStack.push(current);  
    while (iStack.empty()==false) 
    { 
        //Reach the index of left most Node of the current Node 
        while (2*current+1 < size) 
        { 
            current = 2*current + 1; // left child of node at index i is at 2*i+1 index
            iStack.push(current); 
        } 
  
        current = iStack.top(); 
        iStack.pop(); 
        if(treeArr[current]==key)
            return current; 

        if(iStack.empty()==false)
        { 
            current = iStack.top();
            iStack.pop();
            if(treeArr[current]==key)
                return current; 
            }
        else
        {
            break;
        }
        
        current = 2*current + 2; 
        if(current<size)
            iStack.push(current);
        else
        {   if(iStack.empty()== true)
                break;
            else
            {
                current = iStack.top();
                iStack.pop();
                if(treeArr[current]==key)
                    return current; 
            
                current = 2*current + 2;
                iStack.push(current);
            }          
        }
    }
    return -1;
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

		
int main(int argc, char **argv){
    // read from input number and query files using the file name passed in as inputs
    string numberFile(argv[1]);
    string queryFile(argv[2]);
    int n1, n2;
  //  getline(cin,numberFile);
    ifstream numFilePtr, queryFilePtr;
    numFilePtr.open(numberFile);
    numFilePtr >> n1;
    int arr1[n1];
    for (int i = 0; i<n1; i++)
    {
        numFilePtr >> arr1[i];
    }
    numFilePtr.close();

   // getline(cin,queryFile);
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
    int counter1 =0;
    auto start_time1 = chrono::steady_clock::now();
    for(int i = 0; i<n2; i++)
    {
        if(bt1.findByInOrder(arr2[i])==-1)
            continue;
        counter1++;
    }
    auto stop_time1 = chrono::steady_clock::now(); 

	// iterate and search for each query number using level-order traversal
    // measure the total time taken to for all the number using level-order
    int counter2 = 0;
    auto start_time2 = chrono::steady_clock::now();
    for (int i = 0; i < n2; i++)
    {   
        if (bt1.findByLevelOrder(arr2[i])==-1)
           continue;
        counter2++;
    }
    auto stop_time2 = chrono::steady_clock::now();

    cout<<"A2a:"<<counter1<<","<<chrono::duration_cast<chrono::nanoseconds>(stop_time1-start_time1).count()<<","<<chrono::duration_cast<chrono::nanoseconds>(stop_time2-start_time2).count()<< endl;
    
    // output in the format "A2a:123,456,789" where:
	// 123<=m is the number matching query numbers found 
    // 456 is the total time taken in nanoseconds to complete the search using inorder traversal, and 
	// 789 is the total time taken in nanoseconds to complete this search using level-order traversal.

    //inserting given elements in an sorted array
    bt1.insertSorted(arr1);

    //searching given query elements using binary search
    auto start_time3 = chrono::steady_clock::now();
        for(int i=0; i<n2; i++)
    {   
        if(bt1.findByBinarySearch(arr2[i])==-1)
        continue;
    }
    auto stop_time3 = chrono::steady_clock::now();
    cout<<"A2c:"<<chrono::duration_cast<chrono::nanoseconds>(stop_time3-start_time3).count()<<endl;

    return 0;
}
