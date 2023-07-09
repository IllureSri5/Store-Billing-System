#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

struct Product {
	int productNo;
	char productName[10];
	int quantity;
	int price;
};

struct Item {
	int productNo;
	char productName[10];
	int quantity;
	int price;
	int amount;
};

struct Temporary {
	int productNo;
	char productName[10];
	int quantity;
	int price;
	int amount;
};

struct Item item;
struct Item cst[100];
struct Temporary cstr[100];
int t=0;
int n=0; //used in Quantity and Records.txt
int k=0;
int ba=0;
int ti=0;

void create() {
	int i=0;
	FILE *fp;
	fp=fopen("Records.txt","w");
	if(fp==NULL) {
		printf("Error\n");
	}
	printf("\tEnter the Number of Records:");
	scanf("%d",&n);
	printf("\n");
	FILE *fpq;
	fpq=fopen("Quantity.txt","w");
	fprintf(fp,"productNo\t,ProductName\t, Quantity\n, Price\t");
	fprintf(fpq,"%d",n);
	fclose(fpq);
	while(i<n) {
		printf("\tEnter Product Code:");
		scanf("%d",&item.productNo);
		printf("\tEnter Product Name:");
		scanf("%s",item.productName);
		printf("\tEnter Quantity:");
		scanf("%d",&item.quantity);
		printf("\tEnter Price:");
		scanf("%d",&item.price);
		printf("\n");
		i++;
		fprintf(fp,"%d\t%s\t%d\t%d\t",item.productNo,item.productName,item.quantity,item.price);
	}
	fclose(fp);
	printf("\tRecords are Created");
	printf("\n");
	printf("\n");
}

void bill() {
	int na=0;  //used for product number in scanf function
	int a=0;	
	int cont=0;
	int r=0;
	int w=0;
	int ch=0;
	int l=0;	
	int bi=0;
	int ln=0;
	l3 : printf("Enter the Product Number:");
	scanf("%d",&na);
	printf("\n");
	FILE *fp;
	fp=fopen("Records.txt","w");
	FILE *fptr;
	fptr=fopen("temp.txt","w");
	while(!(feof(fp))) {
		l++;
		fscanf(fp,"%d",&item.productNo);
		fscanf(fp,"%s",item.productName);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		if(item.productNo == na) {
			ln++;
			if(ln==2)
			break;
			printf("Enter the Quantity:");
			scanf("%d",&a);
			if(a <= item.quantity) {
				cst[ti].productNo=item.productNo;
				strcpy(cst[ti].productName,item.productName);
				cst[ti].quantity=a;
				cst[ti].price=item.price;
				item.quantity=item.quantity-a;
				ti++;
			}
			else {
				printf("Sorry Out of Stock\n");
				bi++;
			}
		}
		else {
			cont++;
			fprintf(fptr,"%d\t",item.productNo);
			fprintf(fptr,"%s\t",item.productName);
			fprintf(fptr,"%d\t",item.quantity);
			fprintf(fptr,"%d\t",item.price);
			continue;
		}
		fprintf(fptr,"%d\t",item.productNo);
		fprintf(fptr,"%s\t",item.productName);
		fprintf(fptr,"%d\t",item.quantity);
		fprintf(fptr,"%d\t",item.price);
	}
	if(l==cont)
	printf("Error:Choose Properly\n");
	fclose(fptr);
	fclose(fp);
	remove("Records.txt");
	rename("temp.txt","Records.txt");
	ln=0;
	printf("Do you Want to Shop More:\nPress 1 for More\nPress 2 to Exit");
	scanf("%d",&k);
	if(k==1)
	goto l3;
}

void display() {
	int nk=0;
	FILE *fp;
	fp=fopen("Records.txt","r");
	if(feof(fp)) {
		printf("Error in Opening Files\n");
	}
	printf("\t==============================================================\n");
	printf("\t|Product Number\t|Product Name\t|Quantity\t|Price\t\n");
	printf("\t==============================================================\n");
	while(nk!=n) {
		nk++;
		fscanf(fp,"%d",&item.productNo);
		if(item.productNo==0) {
			printf("\tThere are no items in Cart");
			printf("\n");
			break;
		}
		fscanf(fp,"%s",item.productName);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n",item.productNo,item.productName,item.quantity,item.price);
	}
	fclose(fp);
}

void edit() {
	FILE *fp;
	FILE *fptr;
	FILE *fpk;
	int h;
	int found=0;
	int ka=0;
	int p;
	fp=fopen("Records.txt","r");
	fptr=fopen("temp1.txt","w");
	printf("\tEnter the Product Number to Delete: ");
	scanf("%d",&h);
	printf("\n");
	p=n;
	while(!(ka==p)) {
		ka++;
		fscanf(fp,"%d",&item.productNo);
		if(item.productNo==h) {
			found=1;
			fscanf(fp,"%s",item.productName);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			n--;
			printf("\tProduct has been Successfully Deleted\n");
		}
		else {
			fscanf(fp,"%s",item.productName);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			fprintf(fptr,"%d\t%s\t%d\t%d\t",item.productNo,item.productName,item.quantity,item.price);
		}
	}
	fprintf(fpk,"%d",n);
	fclose(fpk);
	fclose(fptr);
	fclose(fp);
	if(found==0) {
		printf("\tProduct no Found");
		printf("\n");
		printf("\n");
	}
	remove("Quantity.txt");
	rename("temp2.txt","Quantity.txt");
	remove("Records.txt");
	rename("temp1.txt","Records.txt");
}

void invoice() {
	int j;
	int o;
	float gt=0;
	if(ti==0) {
		printf("There are No Products in your Cart");
		printf("\n");
	}
	printf("\n\n");
	printf("****************************INVOICE**************************");
	printf("\n\n");
	printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
	printf("*************************************************************\n");
	for(o=0;o<ti;o++) {
		cst[o].amount=0;
		cst[o].amount=((cst[o].price)*(cst[o].quantity));
		gt=gt+cst[o].amount;
	}
	for(j=0;j<ti;j++) {
		printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",cst[j].productNo,cst[j].productName,cst[j].price,cst[j].quantity,cst[j].amount);
	}
	printf("\nAmount Payable:%f",gt);
	printf("\```c
void mdelete() {
	int i=0;
	int j=0;
	int f=0;
	int g=0;
	int ag=0;
	int aj=0;
	char ab[100];
	FILE *fw;
	FILE *fq;
	printf("\tEnter the Product Number to be Deleted:");
	scanf("%d",&f);
	printf("\n");
	for(i=0;i<ti;i++) {
		if(cst[ti].productNo==f) {
			aj=cst[i].quantity;
			printf("\tProduct Deleted Successfully");
			printf("\n");
		}
		continue;
		cstr[g].productNo=cst[i].productNo;
	  	strcpy(cstr[g].productName,cst[i].productName);
	  	cstr[g].quantity=cst[i].quantity;
	  	cstr[g].price=cst[i].price;
	  	g++;
	}
	for(j=0;j<g;j++) {
		cst[j].productNo=cstr[j].productNo;
 	 	strcpy(cst[j].productName,cstr[j].productName);
	  	cst[j].quantity=cstr[j].quantity;
	  	cst[j].price=cstr[j].price;
	}
	ti=g;
	printf("\n%d",aj);
	fq=fopen("shop.txt","r");
	fw=fopen("temp4.txt","w");
	for(j=0;j<n;j++) {
		fscanf(fq,"%d",&item.productNo);
		fscanf(fq,"%s",item.productName);
		fscanf(fq,"%d",&item.quantity);
		fscanf(fq,"%d",&item.price);
		if(item.productNo==f) {
		    ag=aj+item.quantity;
            fprintf(fw,"%d\t%s\t%d\t%d\t",item.productNo,item.productName,ag,item.price);
        }
        else {
        	fprintf(fw,"%d\t%s\t%d\t%d\t",item.productNo,item.productName,item.quantity,item.price);
        }
	}
	fclose(fq);
	fclose(fw);
	remove("Records.txt");
	rename("temp4.txt","Records.txt");
}

void mdisplay() {
	int i;
	int j;
	int o;
	printf("================================================================================\n");
	printf("product number\t|product name\t|quantity\t|price\t\n");
	printf("================================================================================\n");
	for(o=0;o<ti;o++) {
		printf("%14d\t|%12s\t|%6d\t|%6d\n",cst[o].productNo,cst[o].productName,cst[o].quantity,cst[o].price);
	}
}

int main() {
	char ch,password[10],q[10]="progto";
	int s=0;
	int y=0;
	int w=1;
	int i;
	FILE *fpe;
	fpe=fopen("Quantity.txt","r");
	fscanf(fpe,"%d",&n);
	fclose(fpe);
	printf("\n");
	printf("************************************************************************************************************************");
	printf("\n");
	printf("*****************************************    WELCOME TO DENIMXPRESS    *************************************************");
	printf("\n");
	printf("\t                               YOU ARE LUCKY TO BE SHOPPING HERE");
	printf("\n\n");
	printf("\t\t\tPlease note that all the Product's Price are Discounted and are Genuine");
	printf("\n");
	printf("\t\t\t\t\t");
    printf("      Reference Number: %d\n",n);
    
q: printf("\n\t");
    printf("****************************");
    printf("\n");
    printf("\t");
    printf("Please Select an Option: ");
    printf("\n");
    printf("\t");
    printf("****************************");
    printf("\n");
    printf("\t");
	printf("01. ADMINISTRATOR");
	printf("\n\t");
	printf("02. CUSTOMER");
	printf("\n\t");
	printf("03. EXIT");
	printf("\n");
	printf("\n\t");
	printf("Please Enter an Option: ");
	scanf("%d",&s);

	switch(s) {
		case 1: printf("\tEnter Password:\t");
              for(i=0;i<6;i++) {
              ch = getch();
              password[i] = ch;
              ch = '*' ;
               printf("%c",ch);
              }
              password[i]='\0';
              if(strcmp(password,q)) {
                  printf("\n\tWrong Password Please Try Again");
                  printf("\n\n");
                  goto q;
             }
               else
               goto l3;
        l3: printf("\n\tAccess Granted\n");
               printf("\n\n");
               printf("\t****************************");
               printf("\n");
               printf("\tPlease Select an Option: ");
               printf("\n");
               printf("\t****************************");
               printf("\n");
		       printf("\t01.CREATE");
		       printf("\n\t");
		       printf("02.DELETE/MODIFY");
		       printf("\n\t");
		       printf("03.DISPLAY");
		       printf("\n\t");
		       printf("04.MAIN MENU");
		       printf("\n");
		       printf("\n");
		       printf("\tPlease Enter an Option: ");
		        scanf("%d",&y);
		        switch(y) {
        			case 1:create();
        			      goto q;
  			      case 2:edit();
  			             goto q;
                  case 3:display();
                         goto q;
                  case 4: goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         break;

       case 2: printf("\n");
               printf("\t****************************");
               printf("\n");
               printf("\tPlese Select an Option: ");
               printf("\n");
               printf("\t****************************");
               printf("\n");
               printf("\t01.BILL");
               printf("\n\t");
               printf("02.INVOICE");
               printf("\n\t");
               printf("03.DISPLAY");
               printf("\n\t");
               printf("04.MYCART");
               printf("\n\t");
               printf("05.MAIN MENU");
               printf("\n\t");
               printf("06.DELETE ITEMS IN CART\n");
               printf("\n\t");
               printf("Please Enter an Option: ");
               scanf("%d",&y);
               printf("\n");
               switch(y) {
                    case 1 : bill();
        			         goto q;

                    case 2 : invoice();
                             goto q;

                    case 3 : display();
                             goto q;

                    case 4 : mdisplay();
                             goto q;

                    case 5 : goto q;

                    case 6 : mdelete();
                             goto q;

                    default : printf("Error\n");
                              goto q;
        		}
		         break;
      case 3: printf("\tExiting...\n");
      break;
      default : printf("error\n");
      break;
	}
}
