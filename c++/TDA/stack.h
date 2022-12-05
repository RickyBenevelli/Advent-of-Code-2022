#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

using namespace std;
#include <iostream>
#include "main.h"


struct nodo_s{
  char val;
  nodo_s *next;
};



void init_stack(nodo_s * & );
void deinit_stack(nodo_s *& );
retval push_stack(char, nodo_s *&);
retval top_stack(char &, nodo_s *&);
retval pop_stack(nodo_s *&);
void print_stack( nodo_s *&);

#endif
