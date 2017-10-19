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


void set_values_learn(struct neuro *neuro,float arg1, float arg2)
{
  struct neuro *e1 = init();
  e1 -> p = arg1;
  struct neuro *e2 = init ();
  e2 -> p = 1.;
  struct neuro *e3 = init ();
  e3 -> p = arg2;

  neuro -> e1 = e1;
  neuro -> e2 = e2;
  neuro -> e3 = e3;
}

void calc_neuro (struct neuro *neuro)
{
  neuro -> p = (float)(1/(1+exp((double)(e1*l1+e2*l2+e3*l3))));
}
