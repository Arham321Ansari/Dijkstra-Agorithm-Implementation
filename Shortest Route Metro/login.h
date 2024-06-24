
struct login{
	char username[25];
	char password[10];
};
int Login(){
	char username[25],password[10];
	int a;
	FILE *log;
	log=fopen("login.txt","r");
	struct login l;
	printf("Enter the user name : \t");
	scanf("%s",&username);
	printf("Enter the password : \t");
	scanf("%s",&password);
	
	while(fread(&l,sizeof(l),1,log)){
		a=0;
		if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0){
			printf("\t\t\t-->Successfully login\n\n");
			a=a+1;
			break;
		}
		
	}
	if(a==1){
		fclose(log);
		return 1;
	}
	else if(a!=1){
		fclose(log);
		printf("\t\t\t!!!Enter the correct ID and Password!!!\n");
	}
	//fclose(log);
}

