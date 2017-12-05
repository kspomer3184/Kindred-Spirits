//  Data Structures & Algorithms - Fall 2017
//  Programming Assignment #3: Reflections and Kindred Spirits
//
//  KindredSpirits.c
//
//  Added Data Structures:  listNode
//  Added Helper Functions: node *createTreeNode(int data)
//                          listNode *newNode(listNode **tail, int data)
//                          void preorderTraversal(node *root, listNode **tail)
//                          void postorderTraversal(node *root, listNode **tail)
//                          compareLists(listNode *head1, listNode *head2)
//                          void freeLists(listNode *head)
//
//  Created by Kyle Spomer(U0000003184) on 12/2/17.
//  Copyright © 2017 Kyle Spomer. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "KindredSpirits.h"


//  This node structure will be used with the linked lists that capture the traversals of
//  the given trees (named listNode to make distinction with tree nodes)
typedef struct listNode {
    int data;
    
    struct listNode *next;
    
}listNode;

//  creates (and returns a pointer to) a new (tree)node
node *createTreeNode(int data){
    node *n = malloc(sizeof(node));
    
    n->data = data;
    n->left = n->right = NULL;
    
    return n;
};


//  creates (and returns a pointer to) a new listNode
listNode *newNode(listNode **tail, int data){
    listNode* node = malloc(sizeof(struct listNode));
    
    node->data = data;
    node->next = NULL;
    if (*tail == NULL) {
        tail = &node;
    }
    else {
        (*tail)->next = node;
    }
        return(node);
};


//  takes the preorder traversal of a given root node(tree)
//  and appends it to the given tail node(list)
void preorderTraversal(node *root, listNode **tail){
    
    if (root == NULL)
        return;
    
    *tail = newNode(tail, root->data);
    preorderTraversal(root->left, tail);
    preorderTraversal(root->right, tail);
};


//  takes the postorder traversal of a given root node(tree)
//  and appends it to the given tail node(list)
void postorderTraversal(node *root, listNode **tail){
    
    if (root == NULL)
        return;
    
    postorderTraversal(root->left, tail);
    postorderTraversal(root->right, tail);
    *tail = newNode(tail, root->data);
};


//  traverses two lists simultaneously and returns 0 if any discrepancies occur between them (1 otherwise)
int compareLists(listNode *head1, listNode *head2){
    if (head1 == NULL && head2 == NULL)
        return 1;
        
    else if (head1 == NULL || head2 == NULL)
        return 0;
    
    
    if (head1->data == head2->data)
        return compareLists(head1->next, head2->next);
    
    else
        return 0;
    
};


//  frees up allocated memory for a given list
void freeLists(listNode *head){
    if (head == NULL)
        return;
    
    freeLists(head->next);
    free(head);
    
    return;
}


int isReflection(node *a, node *b){
    if (a == NULL && b == NULL)
        return 1;
    else if (a == NULL && b != NULL)
        return 0;
    else if (a != NULL && b == NULL)
        return 0;
    else if (a->data != b->data)
        return 0;
    
    else{
        if (isReflection(a->left,b->right) == 1 && isReflection(a->right, b->left) == 1)
            return 1;
        else{
            return 0;
        }
    }
};


node *makeReflection(node *root){
    if (root == NULL)
        return NULL;
    
    node *new = createTreeNode(root->data);
    
    if(root->right != NULL)
        new->left = makeReflection(root->right);
    if(root->left != NULL)
        new->right = makeReflection(root->left);
    
    return new;
};


int kindredSpirits(node *a, node *b){
    //initialize list heads and get traversals
    listNode *listA = NULL;
    preorderTraversal(a, &listA);
    listNode *listB = NULL;
    postorderTraversal(b, &listB);
    
    if (compareLists(listA, listB)){
        freeLists(listA);
        freeLists(listB);
        
        return 1;
    }
    else{
        //free up the lists
        freeLists(listA);
        freeLists(listB);
        
        //try the other way
        listNode *listA = NULL;
        postorderTraversal(a, &listA);
        listNode *listB = NULL;
        preorderTraversal(b, &listB);
        
        if (compareLists(listA, listB)){
            freeLists(listA);
            freeLists(listB);
        
            return 1;
        }
    }
    return 0;
};


double difficultyRating(void){
    return 2.5;
};


double hoursSpent(void){
    return 5;
};



