#include <stdlib.h>
#include <stdio.h>

struct s_Node
{
  struct s_Node* left;
  struct s_Node* right;
  int val;
};

struct s_BST
{
  struct s_Node* root;
  int size;
};

typedef struct s_Node Node;
typedef struct s_BST BST;


void bst_init(BST* t)
{
  t->root = NULL;
  t->size = 0;
}

void node_free(Node* node)
{
  if (!node)
    return;
  node_free(node->left);
  node_free(node->right);
  free(node);
}

void bst_free(BST* t)
{
  node_free(t->root);
}

/**
 * return ptr to node in tree with value x if found
 * otherwhise returns NULL
 */
Node* node_find(Node* node, int x)
{
  if (!node || node->val == x)
    return node;
  else if (x < node->val)
    return node_find(node->left, x);
  else
    return node_find(node->right, x);
}

int bst_find(BST* t, int x)
{
  return node_find(t->root, x) != NULL;
}

/**
 * Try to insert at the right position x in the tree
 * returns 1 if the insertion succeeded
 * 0 otherwhise (value already in tree)
 */
int bst_insert(BST* t, int x)
{
  Node** pred = &(t->root);
  while (*pred)
  {
    Node* node = *pred;
    if (x < node->val)
      pred = &(node->left);
    else if (x > node->val)
      pred = &(node->right);
    else
      return 0;
  }

  Node* next = malloc(sizeof(Node));
  next->left = NULL;
  next->right = NULL;
  next->val = x;
  *pred = next;
  t->size += 1;
  return 1;
}

Node* node_min(Node* node)
{
  while (node->left)
    node = node->left;
  return node;
}

Node* node_max(Node* node)
{
  while (node->right)
    node = node->right;
  return node;
}

/**
 * Try to remove x from the tree
 * returns 1 if the removal succeeded
 * 0 otherwhise (value not in tree)
 */
int node_remove(Node** pred, int x)
{
  //1: find node to delete (or NULL if no val)
  while (*pred && (*pred)->val != x)
    pred = x < (*pred)->val ? &((*pred)->left) : &((*pred)->right);
  if (!*pred)
    return 0;

  Node* node = *pred;
  if (!node->left) //2: if no left child, right child goes up
  {
    *pred = node->right;
    free(node);
    return 1;
  }

  if (!node->right)//2: if no right child, left child goes up
  {
    *pred = node->left;
    free(node);
    return 1;
  }

  //3: tree have  both child: cannot simply delete val
  //swap node value with minimum value of right child
  //recursively delete that node
  Node* min = node_min(node->right);
  node->val = min->val;
  min->val = x;
  return node_remove(&(node->right), x);
}

int bst_remove(BST* t, int x)
{
  int res = node_remove(&(t->root), x);
  if (res)
    --t->size;
  return res;
}
  


		  
int main()
{
  BST t;
  bst_init(&t);

  int vals[] = {12, 3, 6, 7, 8, 9, 11, -4, 13, 23, 18};
  int len = sizeof(vals) / sizeof(int);

  for (int i = 0; i < len; ++i)
    printf("insert: %d\n", bst_insert(&t, vals[i]));

  for (int i = 0; i < len; ++i)
    printf("find: %d\n", bst_find(&t, vals[i]));

  for (int i = 0; i < len; ++i)
    printf("insert again: %d\n", bst_insert(&t, vals[i]));

  printf("size: %d | %d\n", len, t.size);

  for (int i = 0; i < len; ++i)
    printf("remove: %d\n", bst_remove(&t, vals[i]));

  for (int i = 0; i < len; ++i)
    printf("find again: %d\n", bst_find(&t, vals[i]));

  printf("size: %d\n", t.size);
  
  bst_free(&t);
    
  return 0;
}
