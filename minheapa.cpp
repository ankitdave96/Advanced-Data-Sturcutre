/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "minheapa.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap() {
    total_size=1;
    current_count=0;
    arr=new mhnode[1];
}

MinHeap::MinHeap(const MinHeap& orig) {
}

MinHeap::~MinHeap() {
}

int MinHeap::Insert(mhnode &data){
    
    
    redo:
    
    int tot=getcursize();
    int currentelement=gettotalelements();
    
    if(tot>currentelement)
    {
    arr[currentelement]=data;
    puttotalelements(currentelement+1);
    }
    else
    {
        resize();
        goto redo;
    }
    
    
    
    
    int i = gettotalelements()-1;
//    harr[i] = k;
    if(i!=0)
    {
    label:
    if(arr[parent(i)].executed_time>arr[i].executed_time)
    {
        mhnode temp;
        temp=arr[parent(i)];
        arr[parent(i)]=arr[i];
        arr[i]=temp;
        i=parent(i);
        if (i>0)
            goto label;
    }
    }
    
    
    return 1;
}

int MinHeap::getcursize()
{
    return total_size;
}
int MinHeap::gettotalelements()
{
    return current_count;
}
int MinHeap::resize()
{
    int cur=getcursize();
    int newsiz=cur*2;
    mhnode *newarr = new mhnode[newsiz];
    
    for(int i=0;i<gettotalelements();i++)
    {
        newarr[i]=arr[i];
//        delete (arr+i);
    }
    mhnode *k=arr;
    arr=newarr;
    delete k;
    total_size=total_size*2;
    
    
}
int MinHeap::puttotalelements(int val){
    current_count=val;
}
void MinHeap::print(){
    for(int i=0;i<gettotalelements();i++)
    {
        cout<<" THe job id : "<<(arr[i].ptr)->jobID<<"    ";
        cout<<" has executed for : "<<arr[i].executed_time<<"    \n";
        cout<<" with remaining execution time  : "<<(arr[i].ptr)->rem_time<<"    \n";
    }
}

//void MinHeap::swap(int &x, int &y)
//{
//    int temp = x;
//    x = y;
//    y = temp;
//}
mhnode MinHeap::extractmin(){
    
    if(gettotalelements()==0)
    {   
        //cout<<" THe scheduler queue is empty";
        //
        //
        mhnode temp;
        temp.executed_time=-2;
        return temp;
        //
        //
        //exit(0);
        
        
    }
        
    
    
    mhnode ret=arr[0];
    
    
    arr[0]=arr[gettotalelements()-1];
    puttotalelements(gettotalelements()-1);
    
    
    if(Heapify(0)==1)
        return ret;
    
    
}


int MinHeap::Heapify(int root)
{   
        
        
    
    
    if((arr[root].executed_time)>(arr[min(left(root),right(root))].executed_time) && (right(root)<gettotalelements()))
    {
        int newroot=min(left(root),right(root));
        mhnode temp;
        temp=arr[root];
        arr[root]=arr[min(left(root),right(root))];
        arr[min(left(root),right(root))]=temp;
        
        
        
        Heapify(newroot);
        
    }
    
    if(left(root)<gettotalelements() && arr[root].executed_time>arr[(left(root))].executed_time)
    {
        mhnode temp;
        temp=arr[root];
        arr[root]=arr[left(root)];
        arr[left(root)]=temp;
        
        
    }
    
    
    return 1;
    
    
    
}

int MinHeap::setglobaltime(long tm)
{
    global_time=tm;
}
    
    
    
    
    
    
    
    
    
  
    
    
    
    
    
    
    
