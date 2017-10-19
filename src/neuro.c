#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "neuro.h"


struct neuro *init(){
  struct neuro *res = malloc(sizeof(struct neuro));
  res -> e1 = NULL;
  res -> e2 = NULL;
  res -> e3 = NULL;
  res -> p = 0;
  res -> l1 = 0;
  res -> l2 = 0;
  res -> l3 = 0;
  return res;
}


void set_values_learn(struct neuro *neuro,float arg1, float arg2,float arg3)
{
  struct neuro *e1 = init();
  e1 -> p = arg1;
  struct neuro *e2 = init ();
  e2 -> p = arg2;
  struct neuro *e3 = init ();
  e3 -> p = arg3;

  neuro -> e1 = e1;
  neuro -> e2 = e2;
  neuro -> e3 = e3;

  //L1 L2 L3

}

void calc_neuro (struct neuro *n)
{
  neuro->p=(float)(1/(1+exp((double)(n->e1+n->l1+n->e2*n->l2+n->e3*n->l3))));
}

void call_train(float arg1, float arg2)
{
  struct neuro *n1 = init();
  set_values_learn(n1,arg1,1.,arg2);
  calc_neuro(n1);
  struct neuro *n2 = init();
  set_values_neuro(n2,arg1,n1->p,arg2);
  calc_neuro(n2);

}


