/*  NEURO.H */

/* Initialisation of the struct neuro */

struct neuro {
  struct neuro *e1;
  struct neuro *e2;
  struct neuro *e3;
  double p;
  double l1;
  double l2;
  double l3;
};


struct neuro *init();

void get_values_learn(struct neuro *neuro,double arg1,double arg2,double arg3);

void calc_neuro(struct neuro *n);

void call_train(struct neuro *n);
