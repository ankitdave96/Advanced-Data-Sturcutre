/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RBT.h
 * Author: ankitdave
 *
 * Created on March 27, 2018, 12:15 AM
 */




//struct rbtnode{
//        int jobID;
//        int colour;
//        int total_time;
//        int executed_time;
//        int rem_time;
//        rbtnode *left;
//        rbtnode *right;
//        rbtnode *parent;
//        mhnode *prt;
//        };
//        
//        struct mhnode{
//            int executed_time;
//            rbtnode *ptr;
//            
//        };
        

#ifndef RBT_H
#define RBT_H

#include "data_structure.h"

    
    
class RBT{
    
    rbtnode *root;
    static long global_time;
    
    
    
public:
    RBT();
    bool insert(rbtnode* i_job);
    rbtnode* search(rbtnode* s_job);
    bool remove(rbtnode* r_job);
    rbtnode* getroot(){
        return root;
    }
    rbtnode* maketree(rbtnode* i_job);
    static int putgloabltime(long gt);
    bool RL(rbtnode* i_job);
    bool RR(rbtnode* i_job);
    void PrintJobs(int val, int flag, ofstream &result);
    int TravRootnxt(rbtnode *tmp, int val, int flag, ofstream &result, int a);
    int TravRootprev(rbtnode *tmp, int val, int flag, ofstream &result, int a);
    void PrintJobRange(int start, int end,ofstream &result);
    int PrintJobRangecall(int start, int end, rbtnode* tmproot, ofstream &result, int a);
    
    
};


#endif /* RBT_H */

