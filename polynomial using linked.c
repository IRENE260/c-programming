#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int e,c;
	struct poly*next;
};
struct poly*p,*p1,*p2,*current;
struct poly*t,*dum;


struct poly* insert(struct poly*p,int c,int e)       //inserting term
{ 
  t = (struct poly*) malloc(sizeof(struct poly));
  dum = (struct poly*) malloc(sizeof(struct poly));
  t->c=c;
  t->e=e;
  dum->next=p;
  current=dum;
  while(current->next!=NULL && current->next->e>e)
  	current=current->next;
  t->next=current->next;
  current->next=t;
  p=dum->next;
  dum->next=NULL;
  free(dum);
  dum=NULL;
  current=NULL;
  t=NULL;
  return p;
}


void display(struct poly*h)				//display
{
 current=h;
 while(current!=NULL)
 {
  printf("%dx^%d",current->c,current->e);
  current=current->next;
  if(current!=NULL)
       printf(" + ");
 }
}


void modify(struct poly*p)                     //simplifying resultant polynomial
{
	struct poly*temp,*current,*todelete;
	temp=p;
	while(temp!=NULL)
	{
		current=temp;
 		while(current->next!=NULL)
 		{
 			if(current->next->e==temp->e)
 			{
 			 temp->c=temp->c+current->next->c;
 			 todelete=current->next;
 			 current->next=todelete->next;
 			 todelete->next=NULL;
 			 free(todelete);
 			 todelete=NULL;
 			}
 			current=current->next;
 		}
 		temp=temp->next;
 	}
 	temp=NULL;
 	current=NULL;
}
 
 
struct poly* mlp_poly(struct poly*a1,struct poly*a2)   //multiplication
{
 int c;int e;
 struct poly*p2 = a2;
 struct poly*a = NULL;
 while(a1!=NULL)
 {
  	while(p2!=NULL)
  	{
  		c=a1->c*p2->c;
  		e=a1->e+p2->e;
  		a=insert(a,c,e);
  		p2=p2->next;
  	}
  	p2=a2;
  	a1=a1->next;
 }
 modify(a);
 return a;
}  


int main()
{
 int n1,n2,c,e,i;
 p = (struct poly*) malloc(sizeof(struct poly));
 printf("Polynomial 1--");
 printf("\nNo.of terms:");
 scanf("%d",&n1);
 printf("Enter the coefficient and exponent of first polynomial \n");
 for(i=0;i<n1;i++)
 {
  scanf("%d%d",&c,&e);
  p1=insert(p1,c,e);
 }
 printf("Polynomial 2--");
 printf("\nNo.of terms:");
 scanf("%d",&n2);
 printf("Enter the coefficient and exponent  of second polynomial\n");
 for(i=0;i<n2;i++)
 {
  scanf("%d%d",&c,&e);
  p2=insert(p2,c,e);
 }
 printf("poly 1:");
 display(p1);
 printf("\npoly 2:");
 display(p2);
 printf("\nResult:");
 p=mlp_poly(p1,p2);
 display(p);
 return 0;
}
output:
polynomial1:

Enter the number of term:

2
enter the exponent and coefficient :
2 3
3 4
polynomial 2:
enter the number of terms 2
enter the coefficent and exponent 
2 3

3 6 
polynomial 1:2x^3+3x^4
polynomial 2: 3x^3+3x^6
6x^3+3x^6+3x^4

#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int e,c;
	struct poly*next;
};
struct poly*p,*p1,*p2,*current;
struct poly*t,*dum;


struct poly* insert(struct poly*p,int c,int e)                    
{
  t = (struct poly*) malloc(sizeof(struct poly));
  dum = (struct poly*) malloc(sizeof(struct poly));
  t->c=c;
  t->e=e;
  dum->next=p;
  current=dum;
  while(current->next!=NULL && current->next->e>e)
  	current=current->next;
  t->next=current->next;
  current->next=t;
  p=dum->next;
  dum->next=NULL;
  free(dum);
  dum=NULL;
  current=NULL;
  t=NULL;
  return p;
}


struct poly* add_poly(struct poly*a1,struct poly*a2)    
{
	int c;int e;
	struct poly*a=NULL;
	while(a1!=NULL && a2!=NULL)
	{
		if(a1->e == a2->e)
		{
			c=a1->c+a2->c;
			e=a1->e;
			a1=a1->next;
			a2=a2->next;
		}
		else if(a1->e > a2->e)
		{
			c=a1->c;
			e=a1->e;
			a1=a1->next;
		}
		else
		{
			c=a2->c;
			e=a2->e;
			a2=a2->next;
		}
		if(c!=0)
			a=insert(a,c,e);
	}
	while(a1!=NULL)
	{
		a=insert(a,a1->c,a1->e);
		a1=a1->next;
	}
	while(a2!=NULL)
	{
		a=insert(a,a2->c,a2->e);
		a2=a2->next;
	}
	return a;
}


void display(struct poly*h)				
{
 current=h;
 while(current!=NULL)
 {
  printf("%dx^%d",current->c,current->e);
  current=current->next;
  if(current!=NULL)
       printf(" + ");
 }
}


int main()
{
 int n1,n2,c,e,i;
 p = (struct poly*) malloc(sizeof(struct poly));
 printf("Polynomial 1--");
 printf("\nNo.of terms:");
 scanf("%d",&n1);
 printf("Enter the coefficient and exponent of first polynomial\n");
 for(i=0;i<n1;i++)
 {
  scanf("%d%d",&c,&e);
  p1=insert(p1,c,e);
 }
 printf("Polynomial 2--");
 printf("\nNo.of terms:");
 scanf("%d",&n2);
 printf("Enter the coefficient and exponent of second polynomial\n");
 for(i=0;i<n2;i++)
 {
  scanf("%d%d",&c,&e);
  p2=insert(p2,c,e);
 }
 printf("Poly 1:");
 display(p1);
 printf("\nPoly 2:");
 display(p2);
 printf("\nResult:");
 p=add_poly(p1,p2);
 display(p);
 return 0;
}

output :
number of terms:3
enter the coefficient and exponent of 1st polynomial:
2 3
4 6
7 8
polynomial2:
number of terms:3
enter the coefficient and exponent of second polynomial
3 4
6 7
3 8
poly 1:2x^3+4x^6+7x^8
poly 2:3x^4+6x^7+3x^8

