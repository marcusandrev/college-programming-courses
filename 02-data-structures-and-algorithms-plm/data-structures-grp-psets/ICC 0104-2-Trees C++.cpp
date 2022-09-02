# include <stdio.h>
# include <malloc.h>
#include<iostream>

using namespace std;

struct node
{
	int info;
	struct node *left_child;
	struct node *right_child;
} *root;

void search (int item, struct node **par, struct node **loc)
{
	struct node *ptr, *ptrsave;

	   if (root == NULL){  /*tree empty*/
		   *loc = NULL;
		   *par = NULL;
		   return;
	   }
	   
	   if (item == root -> info)
	   { /*item is at root*/
		   *loc = root;
		   *par = NULL;
		   return;
	   }
	   
	/*Initialize ptr and ptrsave*/
	   if (item < root -> info)
		   ptr = root -> left_child;
	   else
		   ptr = root -> right_child;
	   ptrsave = root;

	   while (ptr != NULL){
		   if (item == ptr -> info)
		   {       
		       *loc = ptr;
			   *par = ptrsave;
			   return;
		   }
		   ptrsave = ptr;
		   if (item < ptr -> info)
			   ptr = ptr -> left_child;
		   else
			   ptr = ptr -> right_child;
	    }   /*End of while */
	    *loc = NULL;   /*item not found*/
	    *par = ptrsave;
}   /*End of search()*/

void insert (int item)
{          
   struct node *tmp, *parent, *location;
	   search (item, &parent, &location);
	   
	   if (location != NULL)
	   {
		   cout << "Item already present";
		   return;
	   }

	   tmp = (struct node *) malloc (sizeof(struct node));
	   tmp -> info = item;
	   tmp -> left_child = NULL;
	   tmp -> right_child = NULL;

 	   if (parent == NULL)
		   root = tmp;
	   else
		   if (item < parent -> info)
			   parent -> left_child = tmp;
		   else
			   parent -> right_child = tmp;
}   /*End of insert()*/


void case_a (struct node *par, struct node *loc ){
	
	
	   if (par == NULL) /*item to be deleted is root node*/
		   root = NULL;
	   else
		   if (loc == par -> left_child)
			   par -> left_child = NULL;
		   else
			   par -> right_child = NULL;
}   /*End of case_a()*/

void case_b(struct node *par,struct node *loc)
{
   struct node *child;

	/*Initialize child*/
	   if (loc -> left_child != NULL) /*item to be deleted has left_child */
		   child = loc -> left_child;
	   else                /*item to be deleted has right_child */
		   child = loc -> right_child;

	   if (par == NULL)   /*Item to be deleted is root node*/
		   root = child;
	   else
		   if (loc == par -> left_child)   /*item is left_child of its parent*/
			   par -> left_child = child;
		   else                  /*item is rchild of its parent*/
			   par -> right_child = child;
}   /*End of case_b()*/

void case_c (struct node *par,struct node *loc)
{
   struct node *ptr, *ptrsave, *succ, *parent_succ;

	/*search inorder successor and its parent*/
	   ptrsave = loc;
	   ptr = loc -> right_child;
	   while (ptr -> left_child != NULL)
	   {
		   ptrsave = ptr;
		   ptr = ptr -> left_child;
	   }
	   succ = ptr;
	   parent_succ = ptrsave;

	   if (succ -> left_child == NULL && succ -> right_child == NULL)
		   case_a (parent_succ, succ);
	   else
		   case_b (parent_succ, succ);

	   if (par == NULL)   /*if item to be deleted is root node */
		   root = succ;
	   else
		   if (loc == par -> left_child)
			   par -> left_child = succ;
		   else
			   par -> right_child = succ;

	   succ -> left_child = loc -> left_child;
	   succ -> right_child = loc -> right_child;
}   /*End of case_c()*/

int del (int item)
{
	struct node *parent, *location;
	
	   if (root == NULL){
		   cout << "Tree empty";
		   return 0;
	   }

	   search (item, &parent, &location);
	   if (location == NULL){
		   cout << "Item not present in tree";
		   return 0;
	   }

	   if (location -> left_child == NULL && location -> right_child == NULL)
		   case_a (parent, location);
	   if (location -> left_child != NULL && location -> right_child == NULL)
		   case_b (parent, location);
	   if (location -> left_child == NULL && location -> right_child != NULL)
		   case_b (parent, location);
	   if (location -> left_child != NULL && location -> right_child != NULL)
		   case_c (parent, location);
	   free (location);
}   /*End of del()*/

int preorder (struct node *ptr)
{	
	if (root == NULL){
		   cout << "Tree is empty";
		   return 0;
	   }
	   if (ptr != NULL)
	   {
		   cout << ptr -> info << " ";
		   preorder (ptr -> left_child);
		   preorder (ptr -> right_child);
	   }
}   /*End of preorder()*/

void inorder (struct node *ptr)
{
	
	if (root == NULL){
		
		   cout << "Tree is empty";
		   return;
	   }
	   if (ptr != NULL)
	   {
		   inorder (ptr -> left_child);
		   cout << ptr -> info << " ";
		   inorder (ptr -> right_child);
	   }
}   /*End of inorder()*/

void postorder (struct node *ptr){	

	if (root == NULL)
	{
		   cout << "Tree is empty";
		   return;
	   }
	if (ptr != NULL)
	{
		   postorder (ptr -> left_child);
		   postorder (ptr -> right_child);
		   cout << ptr -> info << " ";
	   }
}   /*End of postorder()*/

void display (struct node *ptr, int level)
{
	int i;
	
	   if (ptr != NULL)
	   {
		   display (ptr -> right_child, level + 1);
		   cout << endl;
		   for (i = 0; i < level; i++)
			   cout << " ";
		   cout << ptr -> info;
		   display (ptr -> left_child, level + 1);
	   }   /*End of if*/
}   /*End of display()*/

main()
{
	int choice, num;
	root = NULL;
	
	while (1)
	{
		   cout << "\n";
		   cout << "1. Insert\n";
		   cout << "2. Delete\n";
		   cout << "3. Inorder Traversal\n";
		   cout << "4. Preorder Traversal\n";
		   cout << "5. Postorder Traversal\n";
		   cout << "6. Display\n";
		   cout << "7. Quit\n";
		   cout << "Enter your choice : ";
		   cin >> choice;

		switch(choice)
		{
		 case 1:
			cout << "Enter the number to be inserted : ";
			cin >> num;
			insert (num);
			break;
		 case 2:
			cout << "Enter the number to be deleted : ";
			cin >> num;
			del (num);
			break;
		 case 3:
			inorder (root);
			break;
		 case 4:
			preorder (root);
			break;
		 case 5:
			postorder (root);
			break;
		 case 6:
			display (root, 1);
			break;
		 case 7:
            break;
		 default:
			cout << "Wrong choice!\n";
		}   /*End of switch */
	}   /*End of while */
}   /*End of main()*/
