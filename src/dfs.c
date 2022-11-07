/*
 * Search an expression using DFS.
 */

#include <stdio.h>   /* scanf, printf */
#include <stdlib.h>  /* abort */
#include <stdbool.h> /* bool, true, false */
#include "dfs.h"

void DFT(node *root)
{
  // Implement DFS
  // Hint: You can use print_node, print_tree and/or print_stack.

  printf("| "); // Purely for aesthetics when printing the final result of the search

  stack *s = malloc(sizeof(stack)); // Create a stack for the purposes of holding the nodes to be searched through

  s->node = root; // Initializing the stack
  s->next = NULL;

  /*The condition for the search, is that as long
  as there is an element in the stack, meaning the
  tree isn't empty, the search of nodes in the tree will continue*/
  while (!isEmpty(s)) // Loops until no nodes are left to seach for
  {
    node *temp = NULL; // Creating a temporary node, that will hold the data of the node that is being checked (checked meaning that the program will check to see if this particular node has any children nodes)
    temp = top(s);     // Making sure that the node being checked is the one being stored at the top of the stack
    s = pop(s);        // We pop the top element on the stack, signifying that it has been found in the search and that the next time the loop is run, that the next node will be checked
    print_node(temp);  // Printing the value of the node just being checked, to see at the end if it has searched in the correct order

    if (temp->rchild != NULL) // Checks if node has a right child, if so it will push that node to the top of the stack, so it may be checked later
    {
      s = push(s, temp->rchild);
    }

    if (temp->lchild != NULL) // Same for the left child of the node
    {
      s = push(s, temp->lchild);
    }

    free(temp); // The memory allocated for the temporary node is freed, as the node is done being checked, meaning we no longer need it's data

    printf("| "); // Aesthetic reasons again
  }

  printf("\nDFS is complete\n");

  // Recursive solution?
  /*
    if (root != NULL)
    {

      print_node(root);

      pop(root);

      if (root->rchild != NULL)
      {
        push(root, root->rchild);
      }

      if (root->lchild != NULL)
      {
        push(root, root->lchild);
      }

      DFT(root->lchild);
      DFT(root->rchild);

    }
    */
}

node *make_node(int num, node *left, node *right) // Used to make the tree to be searched
{

  node *temp = malloc(sizeof(node));
  temp->num = num;
  temp->visited = false;
  temp->lchild = left;
  temp->rchild = right;
  return temp;
}

void free_node(node *p)
{
  // Not used, as free() has same function
}

void print_node(node *p) // Prints value of a node
{

  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d ", p->num);
}

void print_tree(node *p, int depth) // Prints entire tree
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node) // Pushes a node of a tree on to the stack
{

  stack *s = malloc(sizeof(stack)); // Create temporary stack (technically not correct name, as it should be a temp node, that is pushed onto a stack, but the effects are the same)
  s->next = topp;                   // temp's next element is the previous top node
  s->node = node;                   // temp's data is the data to be pushed to the top of the stack
  return s;                         // Returns a pointer to the top element of the new stack
}

bool isEmpty(stack *topp) // If the top node of the stack exists it is not empty, else it is empty
{
  if (topp == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

node *top(stack *topp) // Returns a pointer to the data held in the top node of the stack
{
  return topp->node;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp) // Pops the top node of the stack
{
  stack *temp = topp; // Creates a temporary copy of the top node of the stack

  topp = topp->next; // The new top of the stack is the second most top node of the stack

  free(temp);  // Frees the temporary node
  return topp; // Returns a pointer to the new top of the stack
}

void print_stack(stack *topp) // Prints the current stack
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}
