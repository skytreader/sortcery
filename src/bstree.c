#include "bstree.h"

void bst_insert(btree *bt, int data){
}

void bst_remove(btree *bt, int data){
}

void bst_merge(btree *bt1, btree *bt2){
}

void bst_search(btree *bt, int data){
}

/**
Takes in a copy of the structure to traverse (rather than the more common
pointer to a structure) because we don't ever want to modify that structure. On
one hand, assuming I understand C correctly, this is a good idea. On the other
hand, this is wasteful in memory---I should just assert that the btree is
unmodified after this function is called.
*/
int* traverse_inorder(btree bt){
    static int inorder[bt.count];
    bool lvisited[bt.count] = {false};
    bool rvistied[bt.count] = {false};
    int inorder_idx = 0;
    btree *roamer = &bt;

    while(inorder_idx != bt.count){
        if(roamer.lchild == NULL){
        }
    }

    return inorder;
}

void bt_eq(btree *bt1, btree *bt2){
}
