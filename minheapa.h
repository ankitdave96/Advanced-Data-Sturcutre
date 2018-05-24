/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   minheapa.h
 * Author: ankitdave
 *
 * Created on March 26, 2018, 4:20 PM
 */

#ifndef MINHEAPA_H
#define MINHEAPA_H

#include "data_structure.h"

class MinHeap {
public:
    MinHeap();
    MinHeap(const MinHeap& orig);
    virtual ~MinHeap();
    int Insert(mhnode &data);
    int Delete(mhnode &data);
    int Heapify(int root);
    int resize();
    int getcursize();
    int gettotalelements();
    int puttotalelements(int val);
    void print();
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
    int min(int a, int b){
        if(arr[a].executed_time < arr[b].executed_time)
            return a;
        else
            return b;
    }
    //void swap(mhnode &x, int &y);
    mhnode extractmin();
    int setglobaltime(long gt);
//    mhnode* getminptr()
//    {
//        return arr;
//    }
 
    
    
private:
    mhnode *arr;
    int total_size;
    int current_count;
    long global_time;
    
    

};




#endif /* MINHEAPA_H */

