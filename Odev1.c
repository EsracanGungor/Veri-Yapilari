#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10

struct stack
{
	int arr[STACKSIZE];   
	int top;
};

struct stack mystack;

struct nodetype
{
	int info;
	struct nodetype *left;
	struct nodetype *right;
	};

typedef struct nodetype *NODEPTR;

NODEPTR getnode(void) {
	NODEPTR p;
	p = (NODEPTR)malloc(sizeof(struct nodetype));
	return (p);

}

NODEPTR maketree(int x) {
	NODEPTR p;
	p = getnode();
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return (p);
}

NODEPTR ptree;
NODEPTR p, q;
void agacadonustur() {

	int number;
	number = pop();
	ptree = maketree(number);
	while (number != -1) {
		number = pop();
		if (number == -1) {
			return;
		}
		p = q = ptree;
		while (number != p->info &&q != NULL) {
			p = q;
			if (number < p->info)
				q = p->left;
			else
				q = p->right;
		}

		if (number == p->info)
			printf("%d bu eleman zaten var", number);

		else if (number < p->info) {//setleft
			if (p == NULL)
				printf(" void insertion");
			else if (p->left != NULL)
				printf("invalid insertion");
			else
				p->left = maketree(number);
		}
		else {//setright
			if (p == NULL)
				printf("void insertion");
			else if (p->right != NULL)
				printf("invalid insertion");
			else
				p->right = maketree(number);

		}
	}
}

		void intrav(NODEPTR tree)
		{
			if (tree != NULL) {
				intrav(tree->left);
				printf("%d\n", tree->info);
				intrav(tree->right);
			}
		}

		void push(int);
		int pop(void);
		void display(void);

	
		int main()
		{
			int selection, tmp;
			mystack.top = -1;

			while (1)
			{
				printf("*** *** ***\n");
				printf("      1    -->   Yigita eleman ekle                     \n");
				printf("      2    -->   Yigittan eleman cikar                  \n");
				printf("      3    -->   Yigittaki elemanlari yazdir            \n");
				printf("      4    -->   Elamanlari ikili agaca tasi ve yazdir  \n");
				printf("*** *** ***\n");

				printf("Seciminizi giriniz: ");
				scanf("%d", &selection);
				switch (selection)
				{
				case 1:
					tmp = 0;
					printf("Eklenecek eleman:");
					scanf("%d", &tmp);
					push(tmp);
					break;
				case 2:
					pop();
					break;
				case 3:
					display();
					break;
				case 4:
					agacadonustur();
					printf("---LDR formundaki agac---\n");
					void intrav(ptree);
					printf(" \n-----------------------\n");
					break;
				}
			}
		    system("pause");

			return 0;
	}

void push(int x) {
	if (mystack.top == (STACKSIZE - 1))    
	{
		printf("Stack tamamen dolu\n");  
		return;
	}
	else
	{
		(mystack.top)++; 
		mystack.arr[mystack.top] = x; 
	}
	return;
}

int pop() {

	int tmp;
	if (mystack.top == -1)      
	{
		printf("Stack boþ\n");  
		return -1;
	}
	else
	{
		tmp = mystack.arr[mystack.top]; 
		printf("'%d' stackten cikarildi\n", tmp);
		mystack.top = mystack.top - 1;  
	}
	return(tmp);
}
void display()
{
	int i;
	if (mystack.top == -1)
	{
		printf("Stackte görüntülenecek eleman yok !\n");
		return;
	}
	else 
	{
		printf("\n *** STACK *** \n");
		for (i = mystack.top; i >= 0; i--)
			printf("%d\n", mystack.arr[i]);
	}
	printf("\n");
}
