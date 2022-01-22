#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Item
{
	int IDNum;
	char name[50];
	char mName[50];
	float price;
	int quantity;
	char flag[5];
};
struct Item ItemArr[10] = {
							{6, "Pepsi-Cola", "Pepsi-Co.", 60, 100, "YES"},
							{7, "Aquafina", "Nestle", 40, 100, "YES"},
							{8, "Lays", "Pepsi-Co.", 100, 200, "YES"},
							{9, "Colgate-Max-Fresh", "Colgate-Palmolive", 150, 170, "YES"},
							{10, "Safguard-Soap", "Safeguard", 60, 150, "YES"}
						};
void addItem();
void displayItem();
void listAllItems();
void listCountItem();
void deleteItem();

int noOfRecords = 10;

main()
{
	while(1)
	{
		int op;
		printf("\t\t\t\tINVENTORY MANAGEMENT SYSTEM\n");
		printf("\t\t\t\t===========================\n\n");
		printf("1. Add Item Information\n2. Display Item Information\n3. List All Items By Manufacturer\n4. List the Count of a Specific Item in the Store\n5. Delete Item from the Store\n6. Exit\n\n");
		printf("Please enter from the given choice (1 - 6): ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
				addItem();
				break;
			case 2:
				displayItem();
				break;
			case 3:
				listAllItems();
				break;
			case 4:
				listCountItem();
				break;
			case 5:
				deleteItem();
				break;
			case 6:
				exit(0);
				break;
		}
	}
}

void addItem()
{
	system("cls");
	int IDNum;
	char name[50];
	char mName[50];
	float price;
	int quantity;
	char flag[5];
	
	printf("\t\t\t\tADD ITEM INFORMATION\n");
	printf("\t\t\t\t====================\n\n");
	printf("=> Enter Item Accession Number: ");
	scanf("%d", &IDNum);
	printf("=> Enter Item Name: ");
	scanf("%s", &name);
	printf("=> Enter Item Manufacturer Name: ");
	scanf("%s", &mName);
	printf("=> Enter Item Price: ");
	scanf("%f", &price);
	printf("=> Enter Item Quantity: ");
	scanf("%d", &quantity);
	printf("=> Enter Item Availability (YES or NO): ");
	scanf("%s", &flag);
	
	ItemArr[IDNum-1].IDNum = IDNum;
	strcpy(ItemArr[IDNum-1].name, name);
	strcpy(ItemArr[IDNum-1].mName, mName);
	ItemArr[IDNum-1].price = price;
	ItemArr[IDNum-1].quantity = quantity;
	strcpy(ItemArr[IDNum-1].flag, flag);
	
	printf("\nITEM INFORMATION ADDED!\n\n");
}

void displayItem()
{
	system("cls");
	printf("\t\t\t\tDISPLAY ITEM INFORMATION\n");
	printf("\t\t\t\t========================\n\n");
	int num = 0;
	while(ItemArr[num].IDNum > 0)
	{
		printf("\n\nItem Accession Number: %d", ItemArr[num].IDNum);
		printf("\nItem Name: %s", ItemArr[num].name);
		printf("\nItem Manufacturer Name: %s", ItemArr[num].mName);
		printf("\nItem Price: %0.1f", ItemArr[num].price);
		printf("\nItem Quantity: %d", ItemArr[num].quantity);
		printf("\nItem Availability: %s", ItemArr[num].flag);
		num++;
	}
	printf("\n\n");
}

void listAllItems()
{
	system("cls");
	char mName[50];
	printf("\t\t\t\tLIST ALL ITEMS BY MANUFACTURER\n");
	printf("\t\t\t\t==============================\n\n");
	printf("Enter Manufacturer Name: ");
	scanf("%s", &mName);
	
	int num = 0;
	for(num = 0;num < 11;num++)
	{
		if(strcmp(ItemArr[num].mName, mName) == 0)
		{
			printf("\n\nItem Accession Number: %d", ItemArr[num].IDNum);
			printf("\nItem Name: %s", ItemArr[num].name);
			printf("\nItem Manufacturer Name: %s", ItemArr[num].mName);
			printf("\nItem Price: %0.1f", ItemArr[num].price);
			printf("\nItem Quantity: %d", ItemArr[num].quantity);
			printf("\nItem Availability: %s", ItemArr[num].flag);
		}
	}
	if(strcmp(ItemArr[num].mName, mName) != 0)
	{
		printf("\nSorry! Record not found");
	}
	printf("\n\n");
}
void listCountItem()
{
	system("cls");
	char name[50];
	printf("\t\t\t\tLIST COUNT OF SPECIFIC ITEM IN STORE\n");
	printf("\t\t\t\t==============================\n\n");
	printf("Enter Item Name: ");
	scanf("%s", &name);
	
	int num = 0;
	for(num = 0;num < 11;num++)
	{
		if(strcmp(ItemArr[num].name, name) == 0)
		{
			printf("The stock available for %s is %d", ItemArr[num].name, ItemArr[num].quantity);
		}
	}
	printf("\n\n");
}

void deleteItem()
{
	system("cls");
	int flag, IDNum;
	char name[50], delName[50], delmName[50], delFlag[5];
	printf("\t\t\t\tDELETE ITEM\n");
	printf("\t\t\t\t===========\n\n");
	printf("Enter Name of Item to Delete: ");
	scanf("%s", &name);
	
	for(IDNum = 0;IDNum < noOfRecords;IDNum++)
	{
		if(strcmp(ItemArr[IDNum].name, name) == 0)
		{
			flag = 1;
		}
		if(flag == 1)
		{
			ItemArr[IDNum].IDNum = 0;
			strcpy(ItemArr[IDNum].name, delName);
			strcpy(delName, "");
			strcpy(ItemArr[IDNum].mName, delmName);
			strcpy(delmName, "");
			ItemArr[IDNum].price = 0;
			ItemArr[IDNum].quantity = 0;
			strcpy(ItemArr[IDNum].flag, delFlag);
			strcpy(delFlag, "");
			
			printf("\nRecord Deleted Successfully!");
		}
	}
	printf("\n\n");
}
