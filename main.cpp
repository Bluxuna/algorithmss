#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//ბინარული ხის სტრუქტურა
struct node {
  int data;
  node* left;
  node* right;
  node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

//ჩასმა ბინარულ ხეში
void insert(node* &root, int data) 
{
  if (root == NULL) 
  
    root = new node(data);
  
  else if (data < root->data)

    insert(root->left, data);
  
  else insert(root->right, data);
  
}
//ძებნა ბინარულ ხეში
node* search(node* root, int data)
{
  if (root == NULL) return root;
  if (root->data == data) return root;
  else if(root->data < data) search(root->right, data);
  else search(root->left, data);
  return root;
}
//მინიმალურის მოძებნა ბინარულ ხეში
node* search_min(node* root)
{
  if(root == NULL) return NULL;
  else if(root->left != NULL)
      root->left = search_min(root->left);
  return root;
}
//მაქსიმალურის ძებნა
node* search_max(node* root)
{
  if(root == NULL) return NULL;
  else if(root->right != NULL)
    root->right = search_max(root->right);
  return root;
}
//მინიმალურის წაშლა ორობით ხეში
node* delete_min(node* root)
{
  if(root == NULL) return NULL;
  else if(root->left != NULL)
    root->left = delete_min(root->left);
  return root->right;
}
//მაქსიმალურის წაშლა ორობით ხეში
node* delete_max(node* root)
{
  if(root == NULL) return NULL;
  else if(root->right == NULL)
    return root->left;
   
  root->right = delete_max(root->right);
  return root;
}
//წაშლა ბინარულ ხეში
node* Delete(node* root, int data)
{
  if(root == NULL) return NULL;
  else if(root->data < data)
      root->right = Delete(root->right, data);
  else if (root->data > data)
      root->left = Delete(root->left, data);
  else
  {
    if(root->left == NULL)
        root = root->left;
    if(root->right == NULL)
       root = root->left;
    root->data = search_min(root->right)->data;
    root->right = Delete(root->right,data);
  }
  return root;
}


//ინორდერი ღრმა ძებნაში სტეკით
void Inorder_stack(node* root)
{
  if(root == NULL) return ;
  stack<node*> s;
  node* cur = root;
  while(cur != NULL || !s.empty())
    {
      while(cur != NULL)
        {
          s.push(cur);
          cur = cur->left;
        }
      cur = s.top();
      s.pop();
      cout<<cur->data<<" ";
      cur = cur->right;  
      
    }
}
//ინორდერი ღრმა ძებნაში რეკურსიით
void inorder_recursion(node* root)
{
  if(root == NULL)return;
  if(root->left)inorder_recursion(root->left);
  cout<<root->data<<" ";
  if(root->right) inorder_recursion(root->right);
}
//პრეორდერი ღრმა ძებნაში სტეკით
void Preorder_stack(node* root)
{
  if(root == NULL) return ;
  stack<node*> s;
  s.push(root);
  while(!s.empty())
    {
      node* cur = s.top();
      s.pop();
      cout<<cur->data<<" ";
      if(cur->right) s.push(cur->right);
      if(cur->left) s.push(cur->left);
      
    }
}
//პრეორდერი ღრმა ძებნაში რეკურსიით
void Preorder_recursion(node* root)
{
  if(root == NULL)return;
  cout<<root->data<<" ";
  if(root->left) Preorder_recursion(root->left);
  if(root->right) Preorder_recursion(root->right);
}
//პოსტორდერი ღრმა ძებნაში სტეკით
void Postorder_stack(node* root)
{
  if(root == NULL) return ;
  stack<node*> s1,s2;
  s1.push(root);
  while(!s1.empty())
    {
      node* cur = s1.top();
      s1.pop();
      s2.push(cur);
      if(cur->left) s1.push(cur->left);
      if(cur->right) s1.push(cur->right);
      cout<<cur->data<<" ";
    }
}
//პოსტორდერი ღრმა ძებნაში რეკურსიით
void Postorder_recursion(node* root)
{
  if(root == NULL) return;
  if(root->left) Postorder_recursion(root->left);
  if(root->right) Postorder_recursion(root->right);
  cout<<root->data<<" ";
}
int main()
{  
  node* root = NULL;
  insert(root, 10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 3);
  insert(root, 7);

  return 0;
}