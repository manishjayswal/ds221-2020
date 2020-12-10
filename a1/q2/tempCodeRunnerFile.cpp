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
 