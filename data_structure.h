/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   data_structure.h
 * Author: ankitdave
 *
 * Created on March 27, 2018, 12:41 AM
 */

#ifndef DATA_STRUCTURE_H
#define DATA_STRUCTURE_H

//#include "data_structure_two.h"

#include <iostream>

using namespace std;

struct mhnode;

struct rbtnode{
        int jobID;
        int colour;
        int total_time;
        int executed_time;
        int rem_time;
        rbtnode *left;
        rbtnode *right;
        rbtnode *parent;
        mhnode *ptr;
        
        rbtnode()
        {
            left=right=parent=NULL;
            ptr=NULL;
        }
        };
        
        
        struct mhnode{
            int executed_time;
            rbtnode *ptr;
            mhnode()
        {
                ptr=NULL;
        }
            
        };
 
        
        
        
    



#endif /* DATA_STRUCTURE_H */

