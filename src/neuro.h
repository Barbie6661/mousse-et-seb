/*  NEURO.H */

/* Initialisation of the struct neuro */

struct neuro {
  struct neuro *e1;
  struct neuro *e2;
  struct neuro *e3;
  float *p;
  float *l1;
  float *l2;
  float *l3;
};


struct neuro *init_neuro();
