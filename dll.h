#ifndef DLL_H
#define DLL_H

#include <iostream>
using namespace std;

struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
};

void insertDNode(dnode *&head, int index, int data);
void deleteDNode(dnode *&head, int index);

#endif
