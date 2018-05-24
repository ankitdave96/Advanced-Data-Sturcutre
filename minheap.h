/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MinHeap.h
 * Author: ankitdave
 *
 * Created on March 25, 2018, 9:10 PM
 */

#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
public:
    MinHeap();
    MinHeap(const MinHeap& orig);
    virtual ~MinHeap();
    int Insert(int data);
    int Delete(int data);
    int Heapify();
    int resize();
    int getcursize();
    int gettotalelements();
    int puttotalelements(int val);
    
    
private:
    int *arr;
    int total_size;
    int current_count;
    
    

};

#endif /* MINHEAP_H */

