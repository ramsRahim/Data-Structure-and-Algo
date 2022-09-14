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
void inOrderTrav(treeNode* root, string&chk);
void preOrderTrav(treeNode* root, string&chk);
void postOrderTrav(treeNode* root, string&chk);
void levelOrderTraversal(treeNode* root, string &chk);

void inOrderTrav(treeNode* root, string&chk){ //left-> root -> right

    if(root == NULL) return;

    inOrderTrav(root->leftChild,chk);
    chk+=to_string(root->data);
    inOrderTrav(root->rightChild,chk);
}

void preOrderTrav(treeNode* root, string&chk){ //root -> left -> right

    if(root == NULL) return;

    chk+=to_string(root->data);
    preOrderTrav(root->leftChild,chk);
    preOrderTrav(root->rightChild,chk);
}

void postOrderTrav(treeNode* root, string&chk){ //left -> right -> root

    if(root == NULL) return;

    postOrderTrav(root->leftChild,chk);
    postOrderTrav(root->rightChild,chk);
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

int searchInorder(int inOrder[],int current,int start,int end)
{
    for(int i=start;i<=end;i++){
        if(inOrder[i]==current){
            return i;
        }
    }

    return -1;
}

treeNode* buildTreePreIn(int preOrder[],int inOrder[],int start,int end)
{
    static int id = 0;

    int current = preOrder[id];
    id++;

    treeNode* newNode = new treeNode(current);
    if(start == end){
        return newNode;
    }
    int pos = searchInorder(inOrder,current,start,end);

    newNode->leftChild = buildTreePreIn(preOrder,inOrder,start,pos-1);
    newNode->rightChild = buildTreePreIn(preOrder,inOrder,pos+1,end);

    return newNode;

}

int main()
{
    int n;
    cin>>n;
    int preOrder[n],inOrder[n];
    for(int i=0;i<n;i++)
    {
        cin>>preOrder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>inOrder[i];
    }

    treeNode* root = buildTreePreIn(preOrder,inOrder,0,n-1);
    string chkpre = "";
    preOrderTrav(root,chkpre);
    cout<<chkpre<<endl<<endl;
    return 0;
}

/*
9
0 1 3 4 2 5 7 8 6
3 1 4 0 7 5 8 2 6

*/