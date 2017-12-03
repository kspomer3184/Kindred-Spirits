//
//  main.c
//  Kindred Spirits Xcode
//
//  Created by Kyle Spomer on 12/2/17.
//  Copyright © 2017 Kyle Spomer. All rights reserved.
//

#include <stdio.h>
#include "KindredSpirits.h"
#include <stdlib.h>





int isReflection(node *a, node *b){

    if (a == NULL && b == NULL)
        return 1;
    else if (a->data == b->data){
        if (isReflection(a->left,b->right) == 1 && isReflection(a->right, b->left) == 1)
            return 1;
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
};

node *makeReflection(node *root){
    node *new = malloc(sizeof(node));
    
    new->data = root->data;
    
    if(root->right != NULL)
        new->left = makeReflection(root->right);
    if(root->left != NULL)
        new->right = makeReflection(root->left);
    
    return new;
};



int kindredSpirits(node *a, node *b);

double difficultyRating(void);

double hoursSpent(void);



