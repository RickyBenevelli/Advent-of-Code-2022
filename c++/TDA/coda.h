#ifndef CODA_H
#define CODA_H

#include <iostream>
#include "main.h"
using namespace std;

struct node_c {
    char val;
    node_c * next;
};

struct queue 
{
  node_c * tail;
  node_c * head;
};




void init_queue(queue &);
void deinit_queue(queue &);
retval enqueue(char,queue &);
retval first_of_queue(char &,const queue &);
retval dequeue(queue &);
void print_queue(const queue &);


#endif