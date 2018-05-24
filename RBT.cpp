/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Black is defined as 0
// Red is defined as 1

#include "RBT.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <cstdlib>

#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "minheapa.h"
#include "data_structure.h"
#include "RBT.h"


using namespace std;

long RBT::global_time=0;

RBT::RBT(){
    root = NULL;
    //global_time=0;
    }

int RBT::putgloabltime(long gt)
{
    global_time=gt;
}

bool RBT::insert(rbtnode* i_job)
{   
    rbtnode* tmproot=getroot();
    rbtnode* tmpparent=NULL;
    int flag=-1;
    
    if (tmproot == NULL)
    {
        tmproot=new rbtnode();
        tmproot=i_job;
        tmproot->colour=0;
        //tmproot->executed_time=i_job->executed_time;
        tmproot->left=NULL;
        tmproot->parent=NULL;
        tmproot->right=NULL;
        //cout<<" \n root ins"<<tmproot->jobID;
        root=tmproot;
        //maketree(tmproot);
        return true;
        
        
    }
    
    while(tmproot!=NULL)
    {
        if((tmproot->jobID)>=(i_job->jobID))
        {
            tmpparent=tmproot;
            tmproot=tmproot->left;
            flag=1;
        }
            
        else
        {
            tmpparent=tmproot;
            tmproot=tmproot->right;
            flag=2;
            
        }
            
        
    }
    
    if (tmproot == NULL)
    {
        tmproot=new rbtnode();
        tmproot=i_job;
        //cout<<tmproot->jobID;
        tmproot->parent=tmpparent;
        tmproot->colour=1;
        tmproot->left=NULL;
        //tmproot->parent=NULL;
        tmproot->right=NULL;
        
        if(flag==1)
        {
            tmpparent->left=tmproot;
            maketree(tmpparent->left);
        }
        if(flag==2)
        {
            tmpparent->right=tmproot;
            maketree(tmpparent->right);
        }
//        tmproot=i_job;
//        cout<<tmproot->jobID;
//        tmproot->parent=tmpparent;
//        tmproot->colour=1;
//        tmproot->left=NULL;
//        //tmproot->parent=NULL;
//        tmproot->right=NULL;
        
        //maketree(tmpparent);
        //cout<<root->jobID;
        
        return true;
    }
    
    
    
    return false;
    
    
    
    
    
       
}

rbtnode* RBT::search(rbtnode* s_job){
    
    
    rbtnode* tmproot=getroot();
    //cout<<" root value : \n"<<tmproot->right->left->jobID;
    //rbtnode* tmpparent=NULL;
    
    if (tmproot == NULL)
    {
        //cout<<" this";
        return NULL;
        
        
    }
    
    while(tmproot!=NULL)
    {
        if((tmproot->jobID)<(s_job->jobID) && (tmproot->right)==NULL)
        {
            //tmpparent=tmproot;
            //cout<<"this";
            return NULL;
        }
        else if((tmproot->jobID)>(s_job->jobID) && (tmproot)->left==NULL)
        {   //cout<<"this";
            return NULL;
        }
        
        else if((tmproot->jobID)<(s_job->jobID))
        {
            //cout<<"this";
            //tmpparent=tmproot;
            tmproot=tmproot->right;
        }
        else if((tmproot->jobID)>(s_job->jobID))
        {   //cout<<"this";
            tmproot=tmproot->left;
        }
        
            
        else
        {
            return tmproot;
            
        }
            
        
    }
    
    return NULL;
    
    
    
    
}

rbtnode* RBT::maketree(rbtnode* i_job)
{
    rbtnode *tmproot=getroot();
    rbtnode *parent = NULL;
    rbtnode *grandparent = NULL;
    
 
    while ((i_job != tmproot) && (i_job->colour != 0) &&
           (i_job->parent->colour == 1))
    {
 
        parent = i_job->parent;
        grandparent = i_job->parent->parent;
 
      
        if (parent == grandparent->left)
        {
 
            rbtnode *uncle = grandparent->right;
 
            
            if (uncle != NULL && uncle->colour == 1)
            {
                grandparent->colour = 1;
                parent->colour = 0;
                uncle->colour = 0;
                i_job = grandparent;
            }
 
            else
            {
                
                if (i_job == parent->right)
                {
                    RL(parent);
                    i_job = parent;
                    parent = i_job->parent;
                }
                RR(grandparent);
                
                int tmp=0;
                tmp=parent->colour;
                parent->colour=grandparent->colour;
                grandparent->colour=tmp;
                
                i_job = parent;
            }
        }
 
        
        else
        {
            rbtnode *uncle = grandparent->left;
 
            
            if ((uncle != NULL) && (uncle->colour == 1))
            {
                grandparent->colour = 1;
                parent->colour = 0;
                uncle->colour = 0;
                i_job = grandparent;
            }
            else
            {
                
                if (i_job == parent->left)
                {
                    RR(parent);
                    i_job = parent;
                    parent = i_job->parent;
                }
 
               
                RL(grandparent);
                int tmp=0;
                tmp=parent->colour;
                parent->colour=grandparent->colour;
                grandparent->colour=tmp;
                i_job = parent;
            }
        }
    }
 
    tmproot->colour = 0;
    //root=tmproot;
}

bool RBT::RL(rbtnode* i_job)
{
    rbtnode* tmproot=getroot();
    
    rbtnode *pt_right = i_job->right;
 
    i_job->right = pt_right->left;
 
    if (i_job->right != NULL)
        i_job->right->parent = i_job;
 
    pt_right->parent = i_job->parent;
 
    if (i_job->parent == NULL)
        root = pt_right;
 
    else if (i_job == i_job->parent->left)
        i_job->parent->left = pt_right;
 
    else
        i_job->parent->right = pt_right;
 
    pt_right->left = i_job;
    i_job->parent = pt_right;
    
}

bool RBT::RR(rbtnode* i_job)
{
    rbtnode* tmproot=getroot();
    rbtnode *pt_left = i_job->left;
 
    i_job->left = pt_left->right;
 
    if (i_job->left != NULL)
        i_job->left->parent = i_job;
 
    pt_left->parent = i_job->parent;
 
    if (i_job->parent == NULL)
        root = pt_left;
 
    else if (i_job == i_job->parent->left)
        i_job->parent->left = pt_left;
 
    else
        i_job->parent->right = pt_left;
 
    pt_left->right = i_job;
    i_job->parent = pt_left;
}

bool RBT::remove(rbtnode* r_job)
{
    return true;
    
}


void RBT::PrintJobs(int val, int flag, ofstream &result)
{
    //cout<<"the job id \n\n"<<val;
    
    
    rbtnode *tmproot=getroot();
    
    //cout<<"The root jobid"<<tmproot->jobID;
    
    int a=0;
//    if (tmp == NULL)
//        return;
    
   
    
//    while(tmproot->right!=NULL)
//            {
//        //cout<<"something";
//                if(tmproot->jobID<val)
//                {
//                    tmproot=tmproot->right;
//                    //cout<<"something";
//                }
//                
//                else
//                    break;
//                
//            }
    if(flag==0)
    {
    while(tmproot!=NULL)
    {
        if(tmproot->jobID<val)
            tmproot=tmproot->right;
        else
            break;
    }
    
    a= TravRootnxt(tmproot,val,flag, result, a);
    }
    else
    {
        while(tmproot!=NULL)
    {
        if(tmproot->jobID>val)
            tmproot=tmproot->left;
        else 
            break;
    }
        
        a= TravRootprev(tmproot,val,flag, result, a);
    }
    
    if(a==2)
    {
        
    long pos = result.tellp();
    result.seekp (pos-1);
    result.write ("\n",1);
    //result <<"\n";
    result.flush();
    }
    else if(a==0)
    {
            result <<"(";    
            result <<0;
            result << ",";
            result <<0;
            result << ",";
            result <<0;
            result << ")\n";
            result.flush();
    }
 
    
}
int RBT::TravRootnxt(rbtnode *tmp, int val, int flag, ofstream &result, int a)
{
    if(a==2)
        return a;
       
    else if (tmp==NULL)
        return a;
    
    else if(tmp->jobID<=val && flag==0 && tmp->right==NULL)
        return a;
    
    a=TravRootnxt(tmp->left,val,flag, result,a);
    
    if(tmp->rem_time>0 && tmp->jobID>val && a!=2)
    {
        a=2;
    //cout << "\n The result is : "<<tmp->jobID << "  ";
            result <<"(";    
            result << tmp->jobID;
            result << ",";
            result <<tmp->executed_time;
            result << ",";
            result <<tmp->total_time;
            result << "),";
            result.flush();
    }
    a=TravRootnxt(tmp->right,val,flag, result,a);
    
    
    
    
    
    return a;
    result <<"\n";
    result.flush();
}
int RBT::TravRootprev(rbtnode *tmp, int val, int flag, ofstream &result, int a)
{
    if(a==2)
        return a;
    
    else if (tmp==NULL)
        return a;
    
    else if(tmp->jobID>=val && flag==1 && tmp->left==NULL)
        return a;
    
    
    
    
    
    a=TravRootprev(tmp->right,val,flag, result,a);
    
    if(tmp->rem_time>0 && tmp->jobID<val && a!=2)
    {
        a=2;
    //cout << "\n The result is : "<<tmp->jobID << "  ";
            result <<"(";    
            result << tmp->jobID;
            result << ",";
            result <<tmp->executed_time;
            result << ",";
            result <<tmp->total_time;
            result << "),";
            result.flush();
    }
    
    
    
    
    a=TravRootprev(tmp->left,val,flag, result,a);
    
    return a;
    
}
void RBT::PrintJobRange(int start, int end, ofstream &result)
{
    rbtnode* tmproot=getroot();
    //cout<<"range check"<<start<<end;
    int a=0;
    a= PrintJobRangecall(start,end,tmproot, result, a);
    if(a==1)
    {
    long pos = result.tellp();
    result.seekp (pos-1);
    result.write ("\n",1);
    //result<<"\n";
    result.flush();
    
    
    }
    else
    {
            result <<"(";    
            result << 0;
            result << ",";
            result <<0;
            result << ",";
            result <<0;
            result << ")\n";
            result.flush();
    }
    
}
int RBT::PrintJobRangecall(int start, int end, rbtnode * tmproot, ofstream &result, int a)
{
    
    if (tmproot==NULL)
        return a;
    
    if(tmproot->jobID>end && tmproot->left==NULL)
        return a;
    if(tmproot->jobID<start && tmproot->right==NULL)
        return a;
    
    
    
    
    
    a=PrintJobRangecall(start,end,tmproot->left, result,a);
    
    if(tmproot->rem_time>0 && tmproot->jobID<=end && tmproot->jobID>=start)
    {
        a=1;
    //cout << "\n The result is : "<<tmproot->jobID << "  ";
            result <<"(";    
            result << tmproot->jobID;
            result << ",";
            result <<tmproot->executed_time;
            result << ",";
            result <<tmproot->total_time;
            result << "),";
            result.flush();
    }
    
    a=PrintJobRangecall(start,end,tmproot->right, result,a);
    
    return a;
}

