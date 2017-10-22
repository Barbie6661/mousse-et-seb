#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*void get(double *l11,double *l12, double *l13,double *l21,double *l22,double *l23,
	       	double *ls11,double *ls12,double *ls21,double *ls22);

void set(double *l11,double *l12, double *l13,double *l21,double *l22,double *l23,
		                                double *ls11,double *ls12,double *ls21,double *ls22);
*/

int xor(double e1, double e2);
void learn_xor();

int main()
{
	learn_xor();
	return 1;
}

int xor(double e1, double e2){
	double e3 = 1.;
	double s1, s2;
	double l11, l12,l13, l21, l22,l23;
	s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
	s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
	if (s1 > s2)
		return 0;
	return 1;
}

void learn_xor()
{
	double e1;
	double e2;
	double e3 = 1;
        double s1, s2;
        double l11, l12,l13, l21, l22,l23;
	l11 = 0.78;
	l12 = 0.157;
	l13 = 0.254;
	l21 = 0.852;
	l22 = 0.45;
	l23 = 0.15;
	
	for(size_t i = 0; i < 1; i++)
	{
		printf("l11 : %f |l12 : %f |l13 : %f \n", l11,l12,l13);
		printf("l21 : %f |l22 : %f |l23 : %f \n \n", l21,l22,l23);
		e1 = 0.;
		e2 = 0.;
		s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
        	s2 = 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
		l11 = (1.-s1) * s1*(1.-s1) * 2+l11;
		l12 = (1.-s1) * s1*(1.-s1) * 2+l12;
		l13 = (1.-s1) * s1*(1.-s1) * 2+l13;
		l21 =  -s2 * s2 *(1.-s2) * 2+l21;
		l22 =  -s2 * s2 *(1.-s2) * 2+l22;
		l23 =  -s2 * s2 *(1.-s2) * 2+l23;
		
		printf("s1 : %f | s2 : %f \n", s1,s2);

		e1 = 1.;
		e2 = 1.;
		s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
		s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
		l11 = (1.-s1) * s1*(1.-s1) * 2+ l11;
		l12 = (1.-s1) * s1*(1.-s1) * 2+ l12;
		l13 = (1.-s1) * s1*(1.-s1) * 2+ l13;
		l21 =  -s2 * s2 *(1.-s2) * 2+l21;
		l22 =  -s2 * s2 *(1.-s2) * 2+l22;
		l23 =  -s2 * s2 *(1.-s2) * 2+l23;

		e1 = 0.;
		e2 = 1.;
		s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
		s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
		l11 = (-s1) * s1*(1.-s1) * 2+ l11;
		l12 = (-s1) * s1*(1.-s1) * 2+ l12;
		l13 = (-s1) * s1*(1.-s1) * 2+ l13;
		l21 = (1. -s2) * s2 *(1.-s2) * 2+l21;
		l22 =  (1.-s2) * s2 *(1.-s2) * 2+l22;
		l23 = ( 1.-s2) * s2 *(1.-s2) * 2+l23;

		e1 = 1.;
		e2 = 0.;	
		s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
		s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
		l11 = (-s1) * s1*(1.-s1) * 2+ l11;
		l12 = (-s1) * s1*(1.-s1) * 2+ l12;
		l13 = (-s1) * s1*(1.-s1) * 2+ l13;
		l21 =  (1.-s2) * s2 *(1.-s2) * 2+l21;
		l22 =  (1.-s2) * s2 *(1.-s2) * 2+l22;
		l23 =  (1.-s2) * s2 *(1.-s2) * 2+l23;
		}

	e1 = 0.;
	e2 = 0.;
	s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
	s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
	printf("%f | %f -> 0 : %f | 1 : %f \n", e1, e2,s1,s2);
        
	e1 = 0.;
	e2 = 1.;
	s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
	s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
	printf("%f | %f -> 0 : %f | 1 : %f \n", e1, e2,s1,s2);

	e1 = 1.;
	e2 = 0.;
	s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
	s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
	printf("%f | %f -> 0 : %f | 1 : %f \n", e1, e2,s1,s2);

	e1 = 1.;
	e2 = 1.;
	s1 = 1./(1.+exp(-(l11*e1+l12*e2+l13*e3)));
	s2= 1./(1.+exp(-(l21*e1+l22*e2+l23*e3)));
	printf("%f | %f -> 0 : %f | 1 : %f \n", e1, e2,s1,s2);

		

}



/*void set(double *l11,double *l12, double *l13,double *l21,double *l22,double *l23,
		double *ls11,double *ls12,double *ls21,double *ls22)
{	
	FILE* file = NULL;
	file = fopen("value.txt", "w");
	if(file != NULL){
		fputs(l11 ,file);
		fputs("\n", file);
		fputs(l12 ,file);
		fputs("\n", file);
		fputs(l13 ,file);
		fputs("\n", file);
		fputs(l21 ,file);
		fputs("\n", file);
		fputs(l22 ,file);
		fputs("\n", file);
		fputs(l23 ,file);
		fputs("\n", file);
		fputs(ls11,file);
		fputs("\n", file);
		fputs(ls12,file);
		fputs("\n", file);
		fputs(ls21,file);
		fputs("\n", file);
		fputs(ls22,file);
	}
	else
	{
		printf("Le fichier txt n'a pas put être ouvert.");
	}
	fclose(file);

}

void get(double *l11,double *l12, double *l13,double *l21,double *l22,double *l23,
		                double *ls11,double *ls12,double *ls21,double *ls22)
{
	FILE* file = NULL;
	file = fopen("value.txt","r");
	if(file != NULL)
	{
		char chaine[10] = "";
		fgets(chaine, 10, file);
		*l11 = char_to_double(chaine);

		char chaine2[10] = "";
		fgets(chaine2, 10, file);
		*l12 = char_to_double(chaine2);
		
		char chaine3[10] = "";
		fgets(chaine3, 10, file);
		*l13 = char_to_double(chaine3);
		
		char chaine4[10] = "";
		fgets(chaine4, 10, file);
		*l21 = char_to_double(chaine4);
		
		char chaine5[10] = "";
		fgets(chaine5, 10, file);
		*l22 = char_to_double(chaine5);
		
		char chaine6[10] = "";
		fgets(chaine6, 10, file);
		*l23 = char_to_double(chaine6);
		
		char chaine7[10] = "";
		fgets(chaine7, 10, file);
		*ls11 = char_to_double(chaine7);
		
		char chaine8[10] = "";
		fgets(chaine8, 10, file);
		*ls12 = char_to_double(chaine8);
		
		char chaine9[10] = "";
		fgets(chaine9, 10, file);
		*ls21 = char_to_double(chaine9);
		
		char chaine10[10] = "";
		fgets(chaine10, 10, file);
		*ls22 = char_to_double(chaine10);
						
	}
	else
	{
		printf("Can't load txt");
	}
	fclose(file);
}

double *char_to_double(char c[])
{
	double *res = 0;
	size_t i =0;
	float j = 10;
	while( i < 10 && c[i] != '.') 
	{
		res = res * 10. + c[i];
		i++;
	}
	if (i < 10){
		i++;
		while(i < 10){
			res = res + c[i]/(10.*j);
			i++;
			j += 10.;
		}
	}
	return res;	
}*/
