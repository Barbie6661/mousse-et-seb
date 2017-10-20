#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "neuro.h"


struct neuro *init(){
  struct neuro *res = malloc(sizeof(struct neuro));
  res -> e1 = NULL;
  res -> e2 = NULL;
  res -> e3 = NULL;
  res -> p = 0.;
  res -> l1 = 0.;
  res -> l2 = 0.;
  res -> l3 = 0.;
  return res;
}


void set_values_learn(struct neuro *neuro,double arg1,double arg2,double arg3)
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
  n->p=(float)(1/(1+exp((double)
	  (n->e1->p * n->l1+n->e2->p * n->l2+n->e3->p * n->l3))));
}

void call()
{
  struct neuro *n1 = init();
  struct neuro *n2 = init();
  for (int i = 0 ; i < 15 ; i++){
    set_values_learn(n1,1.,1.,1.);
    calc_neuro(n1);
    set_values_learn(n2,1.,n1->p,1.);
    calc_neuro(n2);
    set_new_values(n1,0.,0.1);
    set_new_values(n2,0.,0.1);
    printf("1 | 1 -> %f",n2->p);
  }

}

void set_new_values (struct neuro *n,double target,double v) //v est le pas 
{
  double error = (target- n->p)*n->p*(1-n->p);
  n->l1 = v*error*n->p;
  n->l2 = v*error*n->p;
  n->l3 = v*error*n->p;
}
