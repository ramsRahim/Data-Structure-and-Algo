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

void inOrder(treeNode* root, string&chk){ //left-> root -> right

    if(root == NULL) return;

    inOrder(root->leftChild,chk);
    chk+=to_string(root->data);
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
            chk+= to_string(chkNode->data);
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

void verticalOrder(treeNode* root,int D,map<int,vector<int>> &M){
    if (root == NULL){
        return;
    }

    M[D].push_back(root->data);
    verticalOrder(root->leftChild,D-1,M);
    verticalOrder(root->rightChild,D+1,M);
}

int main()
{
    int n;
    cin>>n;
    treeNode* allNodes[n];

    for(int i=0;i<n;i++)
    {
        allNodes[i] = new treeNode(-1);
    }

    for(int i=0;i<n;i++)
    {
        int value, left,right;
        cin>>value>>left>>right;
        allNodes[i]->data = value;
        if(left>n-1 || right>n-1)
        {
            cout<<"Invalid Index"<<endl;
            break;
        }
        if(left!=-1){
            allNodes[i]->leftChild = allNodes[left];
        }
        if(right!=-1){
            allNodes[i]->rightChild = allNodes[right];
        }
    }


    map<int,vector<int>> M;

    verticalOrder(allNodes[0],0,M);

    map<int,vector<int>> :: iterator it;

   /*  for(it = M.begin();it!=M.end();it++){
        for(int j=0;j<i.size();j++)
    } */

    for (auto i:M){

        cout<< i.first<<": ";
        for(int j=0;j<(i.second).size();j++){
            cout<<(i.second)[j]<<" ";
        }

        cout<< endl;
    }

    cout<< endl << endl;

    return 0;
}

/*

9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

*/