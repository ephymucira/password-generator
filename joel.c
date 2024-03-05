
//password generator
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

int main(){
	
	int length=16;
	char *password = malloc(length +1);
	
	char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *lower = "abcdefghijklmnopqrstuvwxyz";
	char *num = "0123456789";
	char *symbol = "<>,.?/}][{+_-)(*&^$#@!=";
	
	int upper_length = strlen(upper);
	int lower_length = strlen(lower);
	int num_length = strlen(num);
	int symbol_length = strlen(symbol);
	
	srand(time(NULL) * getpid());
	
	for (int i = 0;i< length; i++)
	{
		int c_type = rand() % 4;
		if(c_type ==0)
		  password[i] = num[rand()%num_length];
		else if (c_type ==1)
		  password[i] = lower[rand()%lower_length];
		else if (c_type== 2)
		  password[i] =upper[rand() % upper_length];
		else
		  password[i] =symbol[rand() % symbol_length];
		  
	}
	
	password[length] = '\0';
	
	printf("%s\n", password);
	
	free(password);
	return 0;
}