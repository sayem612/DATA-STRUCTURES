 #include <iostream>
#include <cmath>
#include <vector>

using namespace std;
struct TreeNode {
int data;
TreeNode* left;
TreeNode* right;

TreeNode (int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
}

};
TreeNode* arr_to_tree(int *arr, int numbElem);// creates the binary tree
TreeNode* createBNode(int data);// this two lines are prototype
void printInorder (struct TreeNode* node);//prints Inorder
void printPreorder( struct TreeNode* node);//prints Preorder
void printPostOrder(TreeNode* node);//prints Postorder
int countNodes( TreeNode *root );//returns total number of nodes in the Binary tree
void nodeChildNumb(TreeNode * node);// prints the total number of children for each node
TreeNode* Insert (TreeNode* rooter, int datar);
void freeTree(TreeNode* rooter);//free the Tree






/**Creating Function to return a new node*/
TreeNode* createBNode(int data)
{return new TreeNode(data);
}


/** Creating a BINARY TREE*/
TreeNode* arr_to_tree(int *arr, int numbElem)
{
    cout << "I am the number of elements : " << numbElem << endl;
    TreeNode *newTree, *root;

    vector<TreeNode*> node_list;

    int i=0;

    root = createBNode(arr[0]);

    node_list.push_back(root);

    while(!node_list.empty())

    {
    newTree = node_list.front();
    node_list.erase(node_list.begin());
    if(2*i + 1 >= numbElem)
    break;

    newTree->left = createBNode(arr[2*i+1]);
    node_list.push_back(newTree->left);

     if(2*i+2 >= numbElem)
     break;

     newTree->right = createBNode(arr[2*i+2]);
     node_list.push_back(newTree->right);
    i+=1;
     }
    return root;
}










/** Function for Printing the Tree in Inorder*/
// Print the tree in-order
// Traverse the left sub-tree, root, right sub-tree
void printInorder (struct TreeNode* node)
{
    if (node!=NULL)
{/* first recur on left child */
    printInorder (node->left);

    /* then print the data of node */
    cout <<  node->data <<  "  ";

    /* now recur on right child */
    printInorder (node->right);

}
}



/** Function for Printing the Tree in Preorder*/
// Print the tree pre-order
// Traverse the root, left sub-tree, right sub-tree
void printPreorder( struct TreeNode* node)
{
     if ( node!=NULL )
    {
        cout << node->data << "  ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
}




/** Function for Printing the Tree in Postorder*/
// Print the tree post-order
// Traverse left sub-tree, right sub-tree, root
void printPostOrder(TreeNode* node) {
    if ( node!=NULL ) {
       printPostOrder(node->left);
       printPostOrder(node->right);
       cout << node->data << "  ";
    }
}




/** Function to Count- that returns the number of nodes in the tree*/
int countNodes( TreeNode *root ) {
           // Count the nodes in the binary tree to which
           // root points, and return the answer.
        if ( root == NULL )
           return 0;  // The tree is empty.  It contains no nodes.
        else {
           int count = 1;   // Start by counting the root.
           count += countNodes(root->left);  // Add the number of nodes
                                            //     in the left subtree.
           count += countNodes(root->right); // Add the number of nodes
                                            //    in the right subtree.
           return count;  // Return the total.
        }
     } // end countNodes()


       /** Function for Counting Number of Children */
       void nodeChildNumb(TreeNode * node){
       int counter=0;
       if(node->left){
          ++counter;
          }
       if(node->right){
        ++counter;
       }
   cout << node->data << " has " << counter <<  " children." << endl;
       if (node->left!=NULL){
           nodeChildNumb(node->left);
       }
       if (node->right!=NULL){
       nodeChildNumb(node->right);
       }
       }


       /**Function to free the Tree */
       void freeTree(TreeNode* rooter){
       if (rooter==NULL){              // Nothing to clear
        return;
       }
       else if(rooter->left!=NULL){
            freeTree(rooter->left);   // clears the left subtree
       }
       else if(rooter->right!=NULL){
            freeTree(rooter->right);  // clears the left subtree
       }
       delete rooter;
       return;
       }

     /** Function to Insert a Node in a Binary Tree */
     TreeNode* Insert (TreeNode* rooter, int datar){
     if (rooter==NULL){
      rooter=createBNode(datar);
        //rooter=new TreeNode();
      //  rooter->data=datar;
      //  rooter->left=rooter->right=NULL;
     }
     else if(datar<=rooter->data){
        rooter->left=Insert(rooter->left,datar);
     }
     else{
            rooter->right=Insert(rooter->right,datar);
     }
     return rooter;
     }


int Array[50];



int main()

{   cout << "Enter your set of numbers: "<< endl;
    int numbElements=0;
      int numbEntry;
     //based on data to be used

    cin>> numbEntry;
    while(numbEntry!=-999){
    Array[numbElements]=numbEntry;
    numbElements++;
    cin>> numbEntry;
    }

    cout << "Total number of inputs enter by the user: " << endl;
    for (int i=0; i<numbElements; i++) {
        cout << "I am the " << (i+1) << " entry -->" << Array[i]<< endl;
    }


  /** 1) Creating a Binary Tree*/
  TreeNode* Tree= arr_to_tree(Array, numbElements);



  /** 2) Printing Inorder,Preorder, PostOrder */
  cout<< "This is printing in (Inorder)" << endl;
  printInorder (Tree);
  cout << endl;

  cout<< "This is printing in (Preorder)" << endl;
  printPreorder(Tree);
  cout << endl;

  cout<< "This is printing in (Postorder)" << endl;
  printPostOrder(Tree);
  cout << endl;


  /** 3) Calling the subroutine "count" that returns the
        number of nodes in the binary */
   int nodeCounter=0;
  cout << "The Number of nodes in the tree count----> ";
   nodeCounter = countNodes( Tree);
  cout << nodeCounter << endl;


  /** 4) Calling the subroutine "children" which prints
         the number of children each node has */
    cout << "This is the number of children " << endl;
      nodeChildNumb(Tree);


  /** 5) Insert and delete several nodes according to the instruction given */
   cout << "To Insert press I or to Delete press D or press N for nothing" << endl;
   char IDN;  // char to get instruction from the user - Insert, Delete or Nothing
   int info=0; //the number the user want to Insert or Delete
   cin >>IDN;
   while(IDN!='N'){
    if (IDN=='I'){
        cout << "Please Enter the Number you want to Insert" << endl;
        cin >> info;
        Insert(Tree,info);
    }
    cout << "To Insert press I or to Delete press D or press N for nothing" << endl;
    cin>>IDN;
   }


  /** 6) Again, Prints the tree using Inorder, Preorder, PostOrder */
  cout<< "This is printing the new (Inorder)" << endl;
  printInorder (Tree);
  cout << endl;

  cout<< "This is printing the new (Preorder)" << endl;
  printPreorder(Tree);
  cout << endl;

  cout<< "This is printing the new (Postorder)" << endl;
  printPostOrder(Tree);
  cout << endl;



  /** 7) Again, Calling the subroutine "count" that returns the
        number of nodes in the binary */
  nodeCounter=0;
  cout << "The Number of nodes in the tree count----> ";
   nodeCounter = countNodes( Tree);
  cout << nodeCounter << endl;



  /** 8) Again, Calling the subroutine "children" which prints
         the number of children each node has */
  cout << "This is the number of children " << endl;
      nodeChildNumb(Tree);



  /** 9) Free the tree */
  //freeTree(Tree);

    return 0;
}

