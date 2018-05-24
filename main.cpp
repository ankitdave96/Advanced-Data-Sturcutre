/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ankitdave
 *
 * Created on March 25, 2018, 9:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include "minheapa.h"
#include "data_structure.h"
#include "RBT.h"

using namespace std;

/*
 * 
 */


streampos preschedule(RBT &joblist, MinHeap &scheduler, ifstream &check, ofstream &result){
    
    mhnode b;
    
    char cmdins[]="Insert";
    char cmdprint[]="PrintJob";
    char cmdnxt[]="NextJob";
    char cmdprev[]="PreviousJob";
    char delim[]=" ,():";
    char *token;
    string *str;
    streampos oldpos;
    char *cstr1;
    
    here:
    rbtnode *c = new rbtnode();
    str= new string();
    oldpos = check.tellg();
    
    
        
    
    
    getline (check,*str);
    
    cstr1=new char[str->length()];
    
    strcpy(cstr1,str->c_str());
    
    if((token=strtok(cstr1, delim))==NULL)
    {
        return oldpos;
    }
    
    
    
 
    if(atoi(token)==0){
        
        
        token=strtok(NULL, delim);
        //cout<<token;
        
        if(strcmp(token,cmdins)==0)
        {
            
            //cout<< " this count";
           token=strtok(NULL, delim);
           
           
    
            c->jobID=atoi(token);
    
            
            token=strtok(NULL, delim);
            
            //cout<<"\n last val"<<token<<endl;
    
            c->total_time=atoi(token);
    
            c->executed_time=0;
    
            c->rem_time=c->total_time-c->executed_time;
    
            b.executed_time=c->executed_time;
    
    
    
    
    
            c->ptr=NULL;
    
            joblist.insert(c);
    
            b.ptr=joblist.search(c);
    
    
    
    //joblist.insert(a);
    
            scheduler.Insert(b);
            
            goto here;
           
       }
        else if(strcmp(token,cmdprint)==0)
        {
            token=strtok(NULL, delim);
            c->jobID=atoi(token);
            if((token=strtok(NULL, delim))==NULL)
            {
            
            rbtnode *temp=joblist.search(c);
            if(temp!=NULL)
            {
                cout<<"the print command did:";
                cout<<endl<<temp->jobID<<endl<<temp->executed_time<<endl;
            result <<"(";    
            result << temp->jobID;
            result << ",";
            result <<temp->executed_time;
            result << ",";
            result <<temp->total_time;
            result << ") \n";
            result.flush();
            }
            
            goto here;
            }
            else
            {
                int start=c->jobID;
                int end=atoi(token);
                joblist.PrintJobRange(start,end,result);
                goto here;
            }
                
        }
        else if(strcmp(token,cmdnxt)==0)
        {
            token=strtok(NULL, delim);
            int param=atoi(token);
            //rbtnode * temp= new rbtnode();
            c->jobID = param;
            
//            while(temp!=NULL)
//            {
//                if(temp->jobID<=param)
//                {
//                    temp=temp->right;
//                    //cout<<"something";
//                }
//                
//            }
            joblist.PrintJobs(param,0, result);
            
            goto here;
        }
        else if(strcmp(token,cmdprev)==0)
        {
            token=strtok(NULL, delim);
            int param=atoi(token);
            //rbtnode * temp= new rbtnode();
            c->jobID = param;
            
//            while(temp!=NULL)
//            {
//                if(temp->jobID<=param)
//                {
//                    temp=temp->right;
//                    //cout<<"something";
//                }
//                
//            }
            joblist.PrintJobs(param,1, result);
            
            goto here;
        }
        else
        {
            cout<<"something wrong with compare";
            return oldpos;
        }
        
        
        
        
    }
    
    
    
    else
    {
        
        check.seekg (oldpos);
        
    }
    
    
    
    
    
    //check.close();
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // old code for input.txt
    
    
    
    
    
//    int inputstream;
//    //rbtnode *a = new rbtnode();
//    
//    
//    
//   
//    
//    
//    label:
//    
//    rbtnode *a = new rbtnode();
//    
//    
//    
//    tasklist >> inputstream;
//    
//    a->jobID=inputstream;
//    
//    tasklist >> inputstream;
//    
//    a->total_time=inputstream;
//    
//    a->executed_time=0;
//    
//    a->rem_time=a->total_time-a->executed_time;
//    
//    b.executed_time=a->executed_time;
//    
//    
//    
//    
//    
//    a->ptr=NULL;
//    
//    joblist.insert(a);
//    
//    b.ptr=joblist.search(a);
//    
//    
//    
//    //joblist.insert(a);
//    
//    scheduler.Insert(b);
//    
//    
//    
//    //delete a;
//    
//    
//    if(tasklist.eof()!=1)
//    tasklist >> inputstream;
//    else
//        return -1;
//            
//    
//    if(inputstream==0)
//        goto label;
//    else
//        return inputstream;
    
    
    
    
    
    return oldpos;
    
    
    
    
}








int main(int argc, char** argv) {
    
    
    
    //Start our process scheduler from here
    long gt_time=0;
    streampos flag=0;
    int isoccupied=0;
    int inputstream;
    int current_execution=0;
    mhnode next_process;
    RBT joblist;
    MinHeap scheduler;
    
    
    ifstream check;
    ofstream result ("output_file.txt");
    char cmdins[]="Insert";
    char cmdprint[]="PrintJob";
    char cmdnxt[]="NextJob";
    char cmdprev[]="PreviousJob";

    char delim[]=" ,():";
    char *token;
    string *str;
   
   streampos oldpos;
   char *cstr1;
   mhnode b;
   
   
   
   
   
   
   
    
    
    
    
    
    
    
    joblist.putgloabltime(0);
    scheduler.setglobaltime(0);
    
    
    if(argc<2)
    check.open("input_main.txt");
    else
       check.open(argv[1]);
//    
    
    
    
    
    flag=preschedule(joblist, scheduler, check, result);
    
    
    
    check.seekg(flag);
    
    //scheduler.print();
    
    for(gt_time=0; gt_time<2147483646; gt_time++)
    {
        //All processes now take place with respect to current time
        
        //cout<<" \n \n The global time is : "<<gt_time<<"\n";
        //scheduler.print();
        

        
        //We schedule for a particular time here
        
        start:
        if(isoccupied==0)
        {
            
            getnew:
            next_process=scheduler.extractmin();
            if (next_process.executed_time==-2)
                goto here_main;
            
            if(next_process.ptr->rem_time!=0 )
            {
                isoccupied=1;
                next_process.executed_time+=1;
                next_process.ptr->executed_time+=1;
                next_process.ptr->rem_time-=1;
                current_execution++;
                
                
            }
            else
            {
                isoccupied=0;
                goto getnew;
            }
            
        }
        else if(isoccupied==1)
        {   //process is in CPU, but has done less than 5ms
            if(current_execution<5)
            {
                if(next_process.ptr->rem_time!=0 )
            {
                next_process.executed_time+=1;
                next_process.ptr->executed_time+=1;
                next_process.ptr->rem_time-=1;
                current_execution++;
                isoccupied=1;
                
            }
                else
                {
                    isoccupied=0;
                    goto start;
                    current_execution=0;
                }
            }
            else
            {
                //if the process has done 5ms of ecexcution
                isoccupied=0;
                
                if(next_process.ptr->rem_time!=0 )
            {
//                next_process.executed_time+=1;
//                next_process.ptr->executed_time+=1;
//                next_process.ptr->rem_time-=1;
                current_execution=0;
                
                scheduler.Insert(next_process);
                goto start;
                
            }
                else
                {
                    current_execution=0;
                    goto start;
                }
                
            }
        }
        
        
        
//        cout<<" The process that is currently in the CPU is :\n";
//        
//        cout<<next_process.executed_time;
//        cout<<"\n";
//        cout<<next_process.ptr->jobID;
//        cout<<"\n";
//        cout<<next_process.ptr->rem_time;
//        //cout<<"yes";
//        cout<<"\n";
        
        
        
        //Algorithm to check for new input
        
//        if(gt_time==flag)
//        {
//            
//         
//    //rbtnode *a = new rbtnode();
//    
//    mhnode b;
//    
//    
//    label:
//    
//    rbtnode *a = new rbtnode();
//    
//    
//    
//    tasklist >> inputstream;
//    
//    a->jobID=inputstream;
//    
//    tasklist >> inputstream;
//    
//    a->total_time=inputstream;
//    
//    a->executed_time=0;
//    
//    a->rem_time=a->total_time-a->executed_time;
//    
//    b.executed_time=a->executed_time;
//    
//    
//    
//    
//    
//    a->ptr=NULL;
//    
//    joblist.insert(a);
//    
//    b.ptr=joblist.search(a);
//    
//    
//    
//    //joblist.insert(a);
//    
//    scheduler.Insert(b);
//    
//    
//    
//    //delete a;
//    
//    
//    if(tasklist.eof()!=1)
//    {
//    tasklist >> inputstream;
//    }
//    else
//        inputstream = -1;
//            
//    
//    if(inputstream==flag)
//        goto label;
//    else
//        flag = inputstream;
//   
//            
//        }
//        
//        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
       
        
        
        
        
        
        
//      Main algorithm to check for commands in this time
        
        
      
    here_main:
        
    rbtnode *c = new rbtnode();
    str= new string();
       
     
       
    
    
    
    
        
    oldpos = check.tellg();  
    
    
    
    getline (check,*str);
    cstr1=new char[str->length()];
    
    
    strcpy(cstr1,str->c_str());
    
    
    if((token=strtok(cstr1, delim))==NULL)
        break;
    
//    cout<<atoi(token);
//    token=strtok(NULL, delim);
//    cout<<token;
//    token=strtok(NULL, delim);
//    cout<<atoi(token);
//    token=strtok(NULL, delim);
//    cout<<atoi(token);
    
    
//    
//    while(atoi(token)==0)
//    {
//        goto here;
//    }
    
    
    if(atoi(token)==gt_time){
        
    
        
        
        
        
        if((token=strtok(NULL, delim))==NULL)
        continue;
        //cout<<token;
        //cout<<strcmp(token,cmdins);
        if(strcmp(token,cmdins)==0)
        {
            
           //cout<< " this count";
           token=strtok(NULL, delim);
           
           
    
            c->jobID=atoi(token);
    
            
            token=strtok(NULL, delim);
            
            //cout<<"\n last val"<<token<<endl;
    
            c->total_time=atoi(token);
    
            c->executed_time=0;
    
            c->rem_time=c->total_time-c->executed_time;
    
            b.executed_time=c->executed_time;
    
    
    
    
    
            c->ptr=NULL;
    
            joblist.insert(c);
    
            b.ptr=joblist.search(c);
    
    
    
    //joblist.insert(a);
    
            scheduler.Insert(b);
            
            goto here_main;
           
       }
        else if(strcmp(token,cmdprint)==0)
        {
            ///cout<<"print here";
            token=strtok(NULL, delim);
            c->jobID=atoi(token);
            if((token=strtok(NULL, delim))==NULL)
            {
            
            rbtnode *temp=joblist.search(c);
            if(temp!=NULL)
            {
//                cout<<"the print command did:";
//                cout<<endl<<temp->jobID<<endl<<temp->executed_time<<endl;
                
            result <<"(";    
            result << temp->jobID;
            result << ",";
            result <<temp->executed_time;
            result << ",";
            result <<temp->total_time;
            result << ") \n";
            result.flush();
            //result << "\n';
            }
            

            
            goto here_main;
            }
            else
            {
                int start=c->jobID;
                int end=atoi(token);
                joblist.PrintJobRange(start,end,result);
                goto here_main;
            }
                
        }
        else if(strcmp(token,cmdnxt)==0)
        {
            token=strtok(NULL, delim);
            int param=atoi(token);
            //rbtnode * temp= new rbtnode();
            c->jobID = param;
            
//            while(temp!=NULL)
//            {
//                if(temp->jobID<=param)
//                {
//                    temp=temp->right;
//                    //cout<<"something";
//                }
//                
//            }
            joblist.PrintJobs(param,0, result);
            
            goto here_main;
        }
        else if(strcmp(token,cmdprev)==0)
        {
            token=strtok(NULL, delim);
            int param=atoi(token);
            //rbtnode * temp= new rbtnode();
            c->jobID = param;
            
//            while(temp!=NULL)
//            {
//                if(temp->jobID<=param)
//                {
//                    temp=temp->right;
//                    //cout<<"something";
//                }
//                
//            }
            joblist.PrintJobs(param,1,result);
            
            goto here_main;
        }
        else
        {
            cout<<"something wrong with compare";
            continue;
        }
        
        
        
        
    }
    
    
    
    
    else
    {
        if(check.eof()!=1)
        check.seekg (oldpos);
        
        continue;
        
    }
    
    
//    if(check.eof()!=1)
//    {
//        cout<<"break";
//        break;
//        
//    }
    
    
    //end:
    
    
    //check.close();
    
    
    
    }    
    
       
        
        
      
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
   
        
        
        
        
        
        
        
        
        
        
        
    
    
    
    
    
    
    
    
     
    
    
    
    check.close();
    result.close();
    return 0;
}

