#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int choice=0;
	int idSet;
	int i,j,position,check,min;
	int list_length=5;
	char findDish[50];
	char temp[50];
	struct Dish{
		int id;
		char name[50];
		int price;
		
	};
	struct Dish menu[100]={
			{1,"thit cho",50},
			{2,"thit meo",60},
			{3,"rau xao",100},	
			{4,"coca",20},
			{5,"banh pudding",15},
	};
	while(choice!=7){
			printf("\n\nMENU \n");	
			printf("1.In ra cac phan tu trong menu\n");
			printf("2.Them mot phan tu \n");
			printf("3.Sua mot phan tu\n");
			printf("4.Xoa mot phan tu\n");
			printf("5.Sap xep phan tu tang dan theo price\n");
			printf("6.Tim kiem mot phan tu\n");
			printf("7.Thoat\n");
			printf("moi nhap lua chon: ");
			scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("\n Thuc don cua nha hang gom:\n");
			for (i=0;i<list_length;i++){
				printf("%d. %s: %d $ \n",menu[i].id, menu[i].name, menu[i].price);		
			}	
			break;
			
		case 2:
				printf("moi nhap vi tri muon them: ");
				scanf("%d", &position);
			if(position<1 || position >list_length){
				printf("vi tri khong hop le.");
			break;	
			}else{
				position--;
				for (i=list_length;i>position;i--){
					strcpy(menu[i].name, menu[i-1].name);
					menu[i].price=menu[i-1].price;
				}
				fflush(stdin);
				printf("moi nhap ten cho mon an muon them: ");
				fgets(menu[position].name,sizeof(menu[position].name),stdin);
				menu[position].name[strcspn(menu[position].name, "\n")]='\0';
				printf("moi nhap gia: ");
				scanf("%d", &menu[position].price);
				list_length++;
				idSet=0;
				for (i=0;i<list_length;i++){
					idSet++;
					menu[i].id=idSet;
				}
			}
			break;
			
		case 3:
			printf("moi nhap id mon an can sua: ");
			scanf("%d", &position);
			if(position<1 || position >list_length){
				printf("vi tri khong hop le.");
			break;	
			}else{
				position--;
				fflush(stdin);
				printf("moi nhap ten cho mon an muon sua: ");
				fgets(menu[position].name,sizeof(menu[position].name),stdin);
				menu[position].name[strcspn(menu[position].name, "\n")]='\0';
				printf("moi nhap gia muon sua: ");
				scanf("%d", &menu[position].price);
			}
			break;
		case 4:
				printf("moi nhap id mon an can xoa: ");
				scanf("%d", &position);
			if(position<1 || position >list_length){
				printf("vi tri khong hop le.");	
			}else{
				position--;
				for(i=position;i<list_length;i++){
					strcpy(menu[i].name, menu[i+1].name);
					menu[i].price=menu[i+1].price;
				}	
				list_length--;		
				idSet=0;
				for (i=0;i<list_length;i++){
					idSet++;
					menu[i].id=idSet;
				}
			}
			break;
			
		case 5:
			for(i=0;i<list_length;i++){
				min= menu[i].price;
				for(j=i+1;j<list_length;j++){
					if(menu[j].price<min){
						min= menu[j].price;
						menu[j].price=menu[i].price;
						menu[i].price=min;
						strcpy(temp, menu[j].name);
						strcpy(menu[j].name, menu[i].name);
						strcpy(menu[i].name, temp);
					}
				}
			}	
				printf("\nmang sau khi sap xep:\n");
				for (i=0;i<list_length;i++){
					printf("%d. %s: %d $ \n",menu[i].id, menu[i].name, menu[i].price);		
				}	
		
			break;
		case 6:
			check=0;
			printf("moi nhap mon an muon tim: ");
			fflush(stdin);
			fgets(findDish,sizeof(findDish),stdin);	
			findDish[strcspn(findDish, "\n")]='\0';
			for(i=0;i<list_length;i++){
				if(strcmp(menu[i].name,findDish)==0){
				printf("mon an ban muon tim co id la: %d", menu[i].id);
				check++;
				}
			}
			if(check==0){
				printf("mon an ban muon tim khong co trong menu");
			}
			break;
	
		default:
			printf("lua chon khong hop le");		
	}
	}
	
	
   return 0;
}



