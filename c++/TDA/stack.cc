#include <iostream>
#include "./stack.h"
using namespace std;

static bool stack_inizializzato = false;

static bool emptyp_stack( nodo_s *& s) {
    if(stack_inizializzato){
        return (s == NULL);
    }
    exit(1);
}


void init_stack(nodo_s *& s) {
    s = NULL;
    stack_inizializzato = true;
}

retval top_stack (char &n, nodo_s *& s) {
  retval res;
    if (emptyp_stack(s))
        res = FAIL;
    else {
        n = s -> val;
        res = OK;
    }
    return res;
}

void deinit_stack(nodo_s*& s) {
    while (!emptyp_stack(s))
        pop_stack(s);
    stack_inizializzato = false;
}


// memo: "new (nothrow) ..." restituisce NULL
// senza generare eccezioni se l'allocazione non va a buon fine
retval push_stack (char n,nodo_s *& s) {
    retval res;
    nodo_s * np = new (nothrow) nodo_s;
    if (np==NULL)
        res = FAIL;
    else {
        np -> val = n;
        np -> next = s;
        s = np;
        res = OK;
    }
    return res;
}


retval pop_stack(nodo_s * & s) {
  retval res;
  if (emptyp_stack(s))
    res=FAIL;
  else {
    nodo_s *first = s;
    s = s -> next;
    delete first; 	// liberare la memoria: cancella
    res=OK;             // l'oggetto puntato da first
  }		
  return res;
}

void print_stack( nodo_s * & s) 
{
  nodo_s *first = s;
  while (first!=NULL) {
    cout << first->val << endl;
    first = first -> next;
  }
}
