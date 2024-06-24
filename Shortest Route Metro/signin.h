struct logn{
	char username[25];
	char password[10];
};


int sign(){
	FILE *log;
	log=fopen("login.txt","a");
	struct logn l;
	
	printf("Enter the new username :\t");
	scanf("%s",&l.username);
	printf("Enter the password :\t");
	scanf("%s",&l.password);
	fwrite(&l,sizeof(l),1,log);
	printf("\n\n");
	fclose(log);
	printf("\t\t\t-->user created successfully\n\n");
	return 1;	
}
