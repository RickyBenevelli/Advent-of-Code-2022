#include <iostream>
using namespace std;

#include "coda.h"

static bool inizializzata = false;

static bool emptyp_queue (const queue & Q){
    if(inizializzata){
        return (Q.head == NULL);
    }
    exit(1);
}

void init_queue(queue & Q){  
    inizializzata = true; 
    Q.head = NULL;
}

void deinit_queue(queue & Q) {
    while (!emptyp_queue(Q))
        dequeue(Q);
    inizializzata = false;
}

retval enqueue(char,queue &);
retval first_of_queue(int &,const queue &);
retval dequeue(queue &);
void print_queue(const queue &);

retval enqueue(char n, queue & Q)
{
  retval res;
  node_c * np = new (nothrow) node_c;
  if (np==NULL)
    res = FAIL;
  else {
    np->val=n;
    np->next=NULL;
    if (emptyp_queue(Q)) 
      Q.head=np;
    else 
      Q.tail->next=np;
    Q.tail=np;
    res = OK;
  }
  return res;
}

retval first_of_queue(char &n,const queue & Q)
{ 
  retval res;
  if (emptyp_queue(Q))
    res = FAIL;
  else {
    n = Q.head->val;
    res = OK;
  }
  return res;
}

retval dequeue(queue & Q)
{ 
  retval res;
  if (emptyp_queue(Q))
    res=FAIL;
  else {
    node_c * first;
    first = Q.head;
    Q.head = Q.head->next;
    delete first; 
    res=OK;
  }
  return res;
}

void print_queue(const queue & Q) 
{ 
  if (!emptyp_queue(Q)) {
    node_c * first=Q.head;
    do {
      cout << first->val << endl;
      first = first->next;
    } while (first != NULL);
  }
}