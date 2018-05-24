/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinHeap.cpp
 * Author: ankitdave
 * 
 * Created on March 25, 2018, 9:10 PM
 */

#include "MinHeap.h"

MinHeap::MinHeap() {
    total_size=1;
    current_count=0;
    arr=new int[1];
}

MinHeap::MinHeap(const MinHeap& orig) {
}

MinHeap::~MinHeap() {
}

int MinHeap::Insert(int data){
    
    
    redo:
    
    int tot=getcursize();
    int currentelement=gettotalelements();
    
    if(tot>currentelemt)
    {
    arr[currentelement]=data;
    puttotalelements(currentelement+1);
    }
    else
    {
        resize();
        goto redo;
    }
    return 1;
}

int Minheap::getcursize()
{
    return total_size;
}
int Minheap::gettotalelemets()
{
    return current_count;
}
int Minheap::resize()
{
    int cur=getcutsize();
    int newsiz=cur*2;
    int *newarr = new int[newsiz];
    
    for(int i=0;i<gettotalelemnts();i++)
    {
        newarr[i]=arr[i];
//        delete (arr+i);
    }
    int[cur] *k=arr;
    this->arr=newarr;
    delete[cur] k;
    current_size=current_size*2;
    
    
}

   