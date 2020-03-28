#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

int i,j;
int main_exit;
struct date
{
    int month,day,year;
};

struct 
{
    char shop_name[60];
    int acc_no;
    char city[60];
    double phone;
    struct date open;
    char card_no[15];
    double total;
}add,upd,check,rem,detail;

struct 
{
    int quantity;
    double total ;
    double price;
}bill;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void login();
void menu();
void new_customer();
void billing();
void bill_print(double tot );
void edit();
void credit();
void erase();
void view_list();

int main()
{
    system("cls");
    login();  

    return 0;
}

void login()
{
    char pass[15],password[15]="welcome";
    int main_exit;

    printf("\n\n\n\t Enter the Password to Login : ");
    scanf("%s",pass);
    
    if(strcmp(pass,password)==0)
    {
        printf("\n\nPassword Match!");
        
		
        system("cls");
        
        menu();
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
        login_try:
             printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
             if (main_exit==1)
                    {

                        system("cls");
                        login();
                    }

            else if (main_exit==0)
                    {
                        system("cls");
                        close(0);
                    }
            else
                    {
                        printf("\nInvalid!");
                        sleep(3000);
                        system("cls");
                        goto login_try;
                    }
    }
}

void menu()
{
    int choice;
    system("cls");
    printf("\n\n\t\t\t\t\t KHATABOOK");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new customer\n\t\t2.Billing\n\t\t3.Credit\n\t\t4.Update information of existing customer\n\t\t5.Removing existing customer\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_customer();
        break;
        case 2:billing();
        break;
        case 3:credit();
        break;
        case 4:edit();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:exit(0);
        break;
        
    }
}

void new_customer()
{
  int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
        system("cls");
        printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
        printf("\n\n\nEnter today's date(dd/mm/yyyy):");
        scanf("%d/%d/%d",&add.open.month,&add.open.day,&add.open.year);
        printf("\nEnter the account number:");
        scanf("%d",&check.acc_no);  
        while(fscanf(ptr,"%d %s %d/%d/%d %s %lf \n",&add.acc_no,&add.shop_name,&add.open.day,&add.open.month,&add.open.year,&add.city,&add.phone)!=EOF)
        {
            if (check.acc_no==add.acc_no)
            {
                printf("Account no. already in use!");
                fordelay(1000000000);
                goto account_no;
            }
        }

    add.acc_no=check.acc_no;
    printf("\nEnter the shop name:");
    scanf("%s",add.shop_name);
    printf("\nEnter the city name:");
    scanf("%s",add.city);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
        
        fprintf(ptr,"%d %s %d/%d/%d %s %lf \n",add.acc_no,add.shop_name,add.open.day,add.open.month,add.open.year,add.city,add.phone);

    fclose(ptr);
    printf("\nAccount created successfully!");
        
	add_invalid:
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
                close();
        else
            {
                printf("\nInvalid!\a");
                goto add_invalid;
            }
        
}

void billing()
{
	int choice;
	int again;
    char p;
	FILE *prod,*print;
	
	printf("                    ****************************************\n                                  PRODUCTS\n                    ****************************************\n\n");
    prod=fopen("products.txt","rt");
	while((p=getc(prod))!=EOF)
        {
        	printf("%c",p);
		}
         fclose(prod);
    printf("\n\nEnter What You Want :");
	printf("\n\n");
    scanf("%d",&choice);
    bill.total=0;
    
    switch (choice)
    {
    case 1:
        printf("Quantity :  ");
		scanf("%d",&bill.quantity);
        bill.price = 0;
        bill.price = bill.quantity*200;
		bill.total=bill.total + 200*(bill.quantity); 
        print=fopen("bill.txt","a+");

        fprintf(print,"Paracetamol 500mg \t 100 Tablets \t %d \t %.2lf Rs. \n",bill.quantity,bill.price);
        fclose(print);

        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);

        switch (again)
        {
        case 1:
            system("cls");
            printf("\n\n");
			billing();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            bill_print(bill.total);
            break;        
        default:
            break;
        }             
        break;
        
    case 2:
        printf("Quantity :  ");
		scanf("%d",&bill.quantity);
        bill.price = 0;
        bill.price = bill.quantity*250;
		bill.total=bill.total + 250*(bill.quantity); 
        print=fopen("bill.txt","a+");

        fprintf(print,"Omee 20mg \t\t 100 Tablets \t %d \t %.2lf Rs. \n",bill.quantity,bill.price);
        fclose(print);

        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);

        switch (again)
        {
        case 1:
            system("cls");
            printf("\n\n");
			billing();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            bill_print(bill.total);
            break;        
        default:
            break;
        }             
        break;
        
	case 3:
        printf("Quantity :  ");
		scanf("%d",&bill.quantity);
        bill.price = 0;
        bill.price = bill.quantity*1125;
		bill.total=bill.total + 1125*(bill.quantity); 
        print=fopen("bill.txt","a+");

        fprintf(print,"Benadryl Syrup 100ml \t 12 Bottles \t %d \t %.2lf Rs. \n",bill.quantity,bill.price);
        fclose(print);

        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);

        switch (again)
        {
        case 1:
            system("cls");
            printf("\n\n");
			billing();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            bill_print(bill.total);
            break;        
        default:
            break;
        }             
        break;  
		
	case 4:
        printf("Quantity :  ");
		scanf("%d",&bill.quantity);
        bill.price = 0;
        bill.price = bill.quantity*850;
		bill.total=bill.total + 850*(bill.quantity); 
        print=fopen("bill.txt","a+");

        fprintf(print,"Gelusil 200ml \t\t 12 Bottles \t %d \t %.2lf Rs. \n",bill.quantity,bill.price);
        fclose(print);

        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);

        switch (again)
        {
        case 1:
            system("cls");
            printf("\n\n");
			billing();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            bill_print(bill.total);
            break;        
        default:
            break;
        }             
        break;
        
    case 5:
        printf("Quantity :  ");
		scanf("%d",&bill.quantity);
        bill.price = 0;
        bill.price = bill.quantity*1475;
		bill.total=bill.total + 1475*(bill.quantity); 
        print=fopen("bill.txt","a+");

        fprintf(print,"Candid-B Cream 10gm \t 12 Tubes \t %d \t %.2lf Rs. \n",bill.quantity,bill.price);
        fclose(print);

        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);

        switch (again)
        {
        case 1:
            system("cls");
            printf("\n\n");
			billing();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            bill_print(bill.total);
            break;        
        default:
            break;
        }             
        break;

	case 6:
        printf("Quantity :  ");
		scanf("%d",&bill.quantity);
        bill.price = 0;
        bill.price = bill.quantity*1050;
		bill.total=bill.total + 1050*(bill.quantity); 
        print=fopen("bill.txt","a+");

        fprintf(print,"Volini Cream 30 gm\t 12 Tubes \t %d \t %.2lf Rs. \n",bill.quantity,bill.price);
        fclose(print);

        printf("Press 1 To Order Again :\nPress 2 To Get Your Total:\n\nEnter Your Choice :");
		scanf("%d",&again);

        switch (again)
        {
        case 1:
            system("cls");
            printf("\n\n");
			billing();
            break;

        case 2:
            system("cls");
            printf("\n\n");
            bill_print(bill.total);
            break;        
        default:
            break;
        }             
        break;
				  
    default:
        break;
    }
}

void bill_print(double tot )
{
	detail.total = tot ;
    int choice;
    FILE *log,*bill,*credit;  
    char b;
    printf("\nEnter the account number:");
    scanf("%d",&detail.acc_no);
    printf("\nEnter the shop name:");
    scanf("%s",detail.shop_name);
    printf("\nEnter the city name:");
    scanf("%s",detail.city);
    printf("\n Billing Methods :");
    bill_invalid:
		printf("\n 1. Cash");
	    printf("\n 2. Card");
	    printf("\n 3. Credit");
	    printf("\nEnter the payment method:");
	    scanf("%d",&choice);
	
	    switch (choice)
	    {
	    case 1:
	       log = fopen("Orders.txt","a");
	       fprintf(log,"\nAccount No. :%d \nShop Name: %s \nCity Name : %s \nPayment Method : Cash\nGrand Total = %.2lf Rs\n ",detail.acc_no,detail.shop_name,detail.city,detail.total);
	       fclose(log);
	       system("cls");
	       printf("                    ****************************************\n                                  BILL\n                    ****************************************\n\n");
	       bill=fopen("bill.txt","rt");
		    while((b=getc(bill))!=EOF)
	        {
	        	printf("%c",b);
			}
	         fclose(bill);
	         remove("bill.txt");
	
	         printf("\n           TOTAL AMOUNT = %.2lf Rs. ",tot);        
	        
			printf("\n\nPress Any To The MainMenu");
    		if(getch())
        		menu();
	
	     case 2:
	       printf("\nEnter the Card No:");
	       scanf("%s",detail.card_no);
	       log = fopen("Orders.txt","a");
	       fprintf(log,"\nAccount No. :%d \nShop Name: %s \nCity Name : %s \nPayment Method : Card \nCard No : %s \nGrand Total = %.2lf Rs./n ",detail.acc_no,detail.shop_name,detail.city,detail.card_no,detail.total);
	       fclose(log);
	       system("cls");
	       printf("                    ****************************************\n                                  BILL\n                    ****************************************\n\n");
	       bill=fopen("bill.txt","rt");
		    while((b=getc(bill))!=EOF)
	        {
	        	printf("%c",b);
			}
	         fclose(bill);
	         remove("bill.txt");
	         
	         printf("\n           TOTAL AMOUNT = %.2lf Rs. ",tot); 
	         printf("\n\nPress Any To The MainMenu");
		     if(getch())
		        menu();
			 
	
	     case 3:
	       log = fopen("Orders.txt","a");
	       fprintf(log,"\nAccount No. :%d \nShop Name: %s \nCity Name : %s \nPayment Method : Credit \nGrand Total = %.2lf Rs.\n ",detail.acc_no,detail.shop_name,detail.city,detail.total);
	       fclose(log);
	       credit = fopen("Credit.txt","a");
	       fprintf(credit,"\nAccount No. :%d \n Shop Name: %s \n City Name : %s  \n Grand Total = %.2lf Rs.\n ",detail.acc_no,detail.shop_name,detail.city,detail.total);
	       fclose(credit);
	
	       system("cls");
	       printf("                    ****************************************\n                                  BILL\n                    ****************************************\n\n");
	       bill=fopen("bill.txt","rt");
		    while((b=getc(bill))!=EOF)
	        {
	        	printf("%c",b);
			}
	         fclose(bill);
	         remove("bill.txt");
	         
	         printf("\n           TOTAL AMOUNT = %.2lf Rs. ",tot);  		 
			       
	        printf("\n\nPress Any To The MainMenu");
		    if(getch())
		        menu();
			    
	    default:
	        printf("Invaid choice!!");
	        goto bill_invalid;
	        
    }
}


void edit()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %s %lf \n",&add.acc_no,&add.shop_name,&add.open.day,&add.open.month,&add.open.year,&add.city,&add.phone)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.City\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new city name:");
                scanf("%s",upd.city);
                fprintf(newrec,"%d %s %d/%d/%d %s %lf \n",add.acc_no,add.shop_name,add.open.day,add.open.month,add.open.year,add.city,add.phone);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %s %lf \n",add.acc_no,add.shop_name,add.open.day,add.open.month,add.open.year,add.city,add.phone);
                system("cls");
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %s %lf \n",add.acc_no,add.shop_name,add.open.day,add.open.month,add.open.year,add.city,add.phone);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}

void credit()
{
    FILE *old,*newrec,*view;
    int test=0,choice;
    
    printf("\n\n 1. Clear Credit  \n 2. View All Credits \n Enter your choice(1 for Clear Credit and 2 for Display Credit):");
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 1:
        old=fopen("Credit.txt","r");
        newrec=fopen("new.txt","w");
        printf("Enter the account no. of the customer you want to delete the credit records:");
        scanf("%d",&rem.acc_no);
        while (fscanf(old,"\nAccount No. :%d \nShop Name: %s \nCity Name : %s  \nGrand Total = %lf Rs.\n ",&detail.acc_no,&detail.shop_name,&detail.city,&bill.total)!=EOF)
        {
            if(detail.acc_no!=rem.acc_no)
                fprintf(newrec,"\nAccount No. :%d \nShop Name: %s \nCity Name : %s  \nGrand Total = %.2lf Rs.\n ",detail.acc_no,detail.shop_name,detail.city,bill.total);

            else
                {test++;
                printf("\nRecord deleted successfully!\n");            
                }
        }
        fclose(old);
        fclose(newrec);
        remove("Credit.txt");
        rename("new.txt","Credit.txt");   
        if(test==0)
            {
                printf("\nRecord not found!!\a\a\a");
                credit_invalid:
                printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                scanf("%d",&main_exit);

                    if (main_exit==1)
                        menu();
                    else if (main_exit==2)
                        close();
                    else if(main_exit==0)
                        credit();
                    else
                        {printf("\nInvalid!\a");
                        goto credit_invalid;}
            }
        else
            {printf("\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
                menu();
            else
                close();
            }
            break;

    case 2:
        view=fopen("Credit.txt","r");
        system("cls");

        while(fscanf(view,"\nAccount No. :%d \nShop Name: %s \nCity Name : %s  \nGrand Total = %lf Rs.\n ",&detail.acc_no,&detail.shop_name,&detail.city,&bill.total)!=EOF)
        {
            printf("\nAccount No. :%d \nShop Name: %s \nCity Name : %s  \nGrand Total = %.2lf Rs.\n ",detail.acc_no,detail.shop_name,detail.city,bill.total);
            test++;
        }

        fclose(view);
        if (test==0)
            {   system("cls");
                printf("\nNO RECORDS!!\n");}

        view_list_invalid:
        printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==1)
                menu();
            else if(main_exit==0)
                close();
            else
            {
                printf("\nInvalid!\a");
                goto view_list_invalid;
            }

    default:
        break;
    }
    
       

}

void erase()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %s %lf \n",&add.acc_no,&add.shop_name,&add.open.day,&add.open.month,&add.open.year,&add.city,&add.phone)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %s %lf \n",add.acc_no,add.shop_name,add.open.day,add.open.month,add.open.year,add.city,add.phone);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tCITY\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %s %lf \n",&add.acc_no,&add.shop_name,&add.open.day,&add.open.month,&add.open.year,&add.city,&add.phone)!=EOF)
       {
           printf("\n%3d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.shop_name,add.city,add.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

