#include<bits/stdc++.h>

using namespace std;

class treeNode{
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int val)
    {
        data = val;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void printTree(treeNode* root,int level);
void spacePrint(int level);
void inOrder(treeNode* root, string&chk);
void preOrder(treeNode* root, string&chk);
void postOrder(treeNode* root, string&chk);
void levelOrderTraversal(treeNode* root, string &chk);
treeNode* insertionBST(treeNode* root, int value);

void inOrder(treeNode* root, string&chk){ //left-> root -> right

    if(root == NULL) return;

    inOrder(root->leftChild,chk);
    chk+=(to_string(root->data) + " ");
    inOrder(root->rightChild,chk);
}

void preOrder(treeNode* root, string&chk){ //root -> left -> right

    if(root == NULL) return;

    chk+=to_string(root->data);
    preOrder(root->leftChild,chk);
    preOrder(root->rightChild,chk);
}

void postOrder(treeNode* root, string&chk){ //left -> right -> root

    if(root == NULL) return;

    postOrder(root->leftChild,chk);
    postOrder(root->rightChild,chk);
    chk+=to_string(root->data);
}

void printTree(treeNode* root,int level)
{
    if(root == NULL){
        return;
    }

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        cout<< root->data << endl;
        return;
    }

    else{
        cout<<endl;
        spacePrint(level);
        cout<<"Root:"<< " "<<root->data<<endl;
    }

    if(root->leftChild != NULL)
    {
        spacePrint(level);
        cout<<"Left: ";
        printTree(root->leftChild,level+1);
    }
    
    if(root->rightChild != NULL)
    {
        spacePrint(level);
        cout<<"Right: ";
        printTree(root->rightChild,level+1);

    }
    
}

void spacePrint(int level){
    for(int i=0;i<level;i++){
        cout<<"  ";
    }
}

void levelOrderTraversal(treeNode* root, string &chk)
{
    if(root == NULL){
        return;
    }

    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        treeNode* chkNode = q.front();
        q.pop();
        if(chkNode != NULL)
        {
            //cout<< chkNode->data <<" ";
            chk+= to_string(chkNode->data) + " ";
            if(chkNode->leftChild!=NULL)
            {
                q.push(chkNode->leftChild);
            }
            if(chkNode->rightChild!=NULL)
            {
                q.push(chkNode->rightChild);
            }
        }
        else{
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }

}

void printLeaves(treeNode* root){

    if(root==NULL) return;
    if(root->leftChild==NULL && root->rightChild==NULL){
        cout<<root->data<<" ";
        return;
    }

    printLeaves(root->leftChild);
    printLeaves(root->rightChild);
}

void printLeftNonLeaves(treeNode* root){

    if(root==NULL) return;
    if(root->leftChild != NULL){
        cout<< root->data<<" ";
        printLeftNonLeaves(root->leftChild);

    }
    else if(root->rightChild != NULL){
        cout<< root->data<<" ";
        printLeftNonLeaves(root->rightChild);
    }
}

void printRightNonLeaves(treeNode* root){
    
    if(root==NULL) return;
    if(root->rightChild != NULL){
        cout<< root->data<<" ";
        printLeftNonLeaves(root->rightChild);

    }
    else if(root->leftChild != NULL){
        cout<< root->data<<" ";
        printLeftNonLeaves(root->leftChild);
    }
}

void boundaryTraversal(treeNode* root){

    if(root==NULL) return;
    cout<<root->data<<" ";

    //LB Non-Leaves
    printLeftNonLeaves(root->leftChild);
    //LB Leaves
    printLeaves(root->leftChild);
    //RB Leaves
    printLeaves(root->rightChild);
    //RB Non-Leaves
    printRightNonLeaves(root->rightChild);
}

treeNode* insertionBST(treeNode* root, int value){
    treeNode* newNode = new treeNode(value);

    if(root == NULL){
        root = newNode;
        return root;
    }

    //value<root->data
    if(value<root->data){
        root->leftChild = insertionBST(root->leftChild,value);
    }
    else if(value > root->data){
        root->rightChild = insertionBST(root->rightChild,value);
    }

    return root;
}

treeNode* searchBST(treeNode* root,int value){

    if(root == NULL){
        return NULL;
    }

    if(root->data == value){
        cout<<root->data;
        return root;
    }

    else if(root->data>value){
        cout<<root->data<<"->";
        searchBST(root->leftChild,value);
    }
    
    else{
        cout<<root->data<<"->";
        searchBST(root->rightChild,value);
    }

    return NULL;
}

treeNode* inordersucc(treeNode* root){
    treeNode* curr = root;
    while(curr->leftChild != NULL){
        curr = curr->leftChild;
    }
    return curr;
}

treeNode* deletionBST(treeNode* root,int value){

    if(value < root->data){
        root->leftChild = deletionBST(root->leftChild,value);
    }
    else if(value > root->data){
        root->rightChild = deletionBST(root->rightChild,value);
    }
    else{
        if(root->leftChild == NULL){
            treeNode* temp = root->rightChild;
            free(root);
            return temp;
        }
        else if(root->rightChild == NULL){
            treeNode* temp = root->leftChild;
            free(root);
            return temp;
        }
        else{
            treeNode* temp = inordersucc(root->rightChild);
            root->data = temp->data;
            root->rightChild = deletionBST(root->rightChild,temp->data);
        }

        return root;
    }
    return root;
}

void zigzagTraversal(treeNode* root){
    stack<treeNode*>currentLevel,nextLevel;
    bool lefttoRight = true ;

    currentLevel.push(root);

    while(!currentLevel.empty()){
        treeNode* temp = currentLevel.top();
        currentLevel.pop();
        
        cout<<temp->data<<" ";

        if(lefttoRight){
            if(temp->leftChild){
                 nextLevel.push(temp->leftChild);
            }
            if(temp->rightChild){
                 nextLevel.push(temp->rightChild);
            }
        }

        else{
            if(temp->rightChild){
                 nextLevel.push(temp->rightChild);
            }
           if(temp->leftChild){
                 nextLevel.push(temp->leftChild);
            }
        }
        
        if(currentLevel.empty()){
            lefttoRight = !lefttoRight;
            swap(currentLevel,nextLevel);
        }
        
    }
}

int main()
{
    int n;
    cin>>n;
    treeNode *root =NULL;
    for( int i=0;i<n;i++)
    {
        int value;
        cin>>value;
        root = insertionBST(root,value);
    }

    /* string traversal = " ";
    inOrder(root,traversal);
    cout<<traversal<<endl;
    zigzagTraversal(root); */

    /* cout<<traversal<<endl;
    int key;
    cin>>key;
    if(searchBST(root,key)==NULL)
        cout<<endl<<"value doesn't exists"<<endl;
    else
        cout<<endl<<"the given value exists"<<endl; 
    */
    /* int key1;
    cin>>key1;
    root = deletionBST(root,key1);
    int value;
    cin>>value;
    root = insertionBST(root,value);
    int key;
    cin>>key;
    root = deletionBST(root,key); */
    string traversal = " ";
    levelOrderTraversal(root,traversal);

    cout<<traversal<<endl;
    return 0;
}

/*
13
7 5 12 3 6 9 15 1 4 8 10 13 17  
*/
