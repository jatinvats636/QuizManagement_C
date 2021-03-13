#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <dos.h>
#include <dir.h>
#include <stdlib.h>
#include <malloc.h>
#include <ctype.h>
#define tot_ques 33  // no of total ques in file
#define easy_ques 3 // no of easy ques to print
#define hard_ques 10 // no of hard ques to print
#define size 300 // store size of options' char array

void delay(float sec) 
{  // to provide delay in storing values
    float msec = 2 * sec; 
  	clock_t start_time = clock(); 
  	while (clock() < start_time + msec) ; 
} 

// char** rmp(){  // demo
// int i; 
//     char** result; 
//     char filePath[2][30] = {"Questions/RMP.txt","Results/rmpResult.txt"}; 
//     result = malloc (sizeof(char *) * 2); 
//     for (i=0; i<2; i++) { 
//         result[i] = malloc(sizeof(char) * 2); 
//         strcpy(result[i], filePath[i]); 
//     } 
//     return result; 
// }

char **rmp(){
        char ** result = malloc(10 * sizeof(char *));
        char *filePath[] = {"Questions/RMP.txt","Results/rmpResult.txt"};
        int i, j = 0;
        for(i = 0; i < 2; i++){
               result[j] = malloc(50 * sizeof(char));
               result[j] = filePath[i];
               j++;
        }
        return result;
}
char **mcp(){
char ** result = malloc(10 * sizeof(char *));
        char *filePath[] = {"Questions/MCP.txt","Results/mcpResult.txt"};
        int i, j = 0;
        for(i = 0; i < 2; i++){
               result[j] = malloc(50 * sizeof(char));
               result[j] = filePath[i];
               j++;
        }
        return result;
}
char **android(){
char ** result = malloc(10 * sizeof(char *));
        char *filePath[] = {"Questions/ANDROID.txt","Results/androidResult.txt"};
        int i, j = 0;
        for(i = 0; i < 2; i++){
               result[j] = malloc(50 * sizeof(char));
               result[j] = filePath[i];
               j++;
        }
        return result;
}
char **game(){
char ** result = malloc(10 * sizeof(char *));
        char *filePath[] = {"Questions/GAME.txt","Results/gameResult.txt"};
        int i, j = 0;
        for(i = 0; i < 2; i++){
               result[j] = malloc(50 * sizeof(char));
               result[j] = filePath[i];
               j++;
        }
        return result; 
}
char **ios(){
char ** result = malloc(10 * sizeof(char *));
        char *filePath[] = {"Questions/IOS.txt","Results/iosResult.txt"};
        int i, j = 0;
        for(i = 0; i < 2; i++){
               result[j] = malloc(50 * sizeof(char));
               result[j] = filePath[i];
               j++;
        }
        return result;
}

void ask_ans(char c_option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,int *score)
	{ // to ask answer from user and store same in result file
	char check; // variable to check option input (ABCD only)
	getOption:
		printf("\033[1;36m");
		printf("Your Answer : ");
		scanf("%s",&c_option[0]);
		c_option[1] = '\0';
		strupr(c_option);
		check = c_option[0];
		printf("\033[0m");
		char correctanswer[size];
		char wronganswer[size];
			
		if (check=='A' || check=='B' || check=='C' ||check=='D'){
		fprintf(fp,"%s \n",category);
			
		if (c_option[0] == correct[0])
		{
			if (c_option[0] == option1[0])
				fprintf(fp,"You entered correct answer : %s  \n", option1);
			if (c_option[0] == option2[0])
				fprintf(fp,"You entered correct answer : %s  \n", option2);
			if (c_option[0] == option3[0])
				fprintf(fp,"You entered correct answer : %s  \n", option3);
			if (c_option[0] == option4[0])
				fprintf(fp,"You entered correct answer : %s  \n", option4);
				
			*score += 1;
				
			fprintf(fp,"1 mark for correct answer.");
		}
		else
		{
		
			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,size-1);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,size-1);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,size-1);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,size-1);
			
			correctanswer[size-1] = '\0';
		
			if (c_option[0] == option1[0])
				strncpy(wronganswer, option1,size-1);
			if (c_option[0] == option2[0])
				strncpy(wronganswer, option2,size-1);
			if (c_option[0] == option3[0])
				strncpy(wronganswer, option3,size-1);
			if (c_option[0] == option4[0])
				strncpy(wronganswer, option4,size-1);

			wronganswer[size-1] = '\0';
			
			fprintf(fp,"You entered     : %s", wronganswer);
			fprintf(fp,"Correct answer  : %s \n", correctanswer);
			fprintf(fp,"You get 0 marks for wrong answer.");
		}
		
			fprintf(fp,"\n\n######################################################################################################################################################################\n\n");
	}
		else{
			printf("\033[1;31m");
			printf("Please choose right option !!!\n\n");
			system("pause");
			printf("\033[0m");
			goto getOption;
		}
}

void logo_fast(){
	system("cls");
	printf("\n\n");
	printf("\n\n");
	delay(5);
	printf("\t\t\t\t\t\t _______  __   __  ___   _______    _______  _______  __   __  _______ \n\t\t\t\t\t\t|       ||  | |  ||   | |       |  |       ||   _   ||  |_|  ||       |\n\t\t\t\t\t\t|   _   ||  | |  ||   | |____   |  |    ___||  |_|  ||       ||    ___|\n\t\t\t\t\t\t|  | |  ||  |_|  ||   |  ____|  |  |   | __ |       ||       ||   |___ \n\t\t\t\t\t\t|  |_|  ||       ||   | | ______|  |   ||  ||       ||       ||    ___|\n\t\t\t\t\t\t|      | |       ||   | | |_____   |   |_| ||   _   || ||_|| ||   |___ \n\t\t\t\t\t\t|____||_||_______||___| |_______|  |_______||__| |__||_|   |_||_______|\n");
	}
void logo_slow(){
	system("cls");
	// printf("\033[1;35m");
	printf("\n\n");
	delay(1);
	printf("\t\t\t\t\t\t\t  ________  ___  ___  ___  ________                       \n");
	delay(4);
	printf("\t\t\t\t\t\t\t |\\   __  \\|\\  \\|\\  \\|\\  \\|\\_____  \\                      \n");
	delay(8);
	printf("\t\t\t\t\t\t\t \\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\\\|___/  /|                     \n");
	delay(12);
	printf("\t\t\t\t\t\t\t  \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\   /  / /                     \n");
	delay(16);
	printf("\t\t\t\t\t\t\t   \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \\  \\ /  /_/__                    \n");
	delay(20);
	printf("\t\t\t\t\t\t\t    \\ \\_____  \\ \\_______\\ \\__\\________\\                  \n");
	delay(24);
	printf("\t\t\t\t\t\t\t     \\|___| \\__\\|_______|\\|__|\\|_______|                  \n");
	delay(28);
	printf("\t\t\t\t\t\t\t         __\\|__|_  ________  _____ ______   _______       \n");
	delay(32);
	printf("\t\t\t\t\t\t\t        |\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\      \n");
	delay(36);
	printf("\t\t\t\t\t\t\t        \\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|     \n");
	delay(40);
	printf("\t\t\t\t\t\t\t         \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__   \n");
	delay(44);
	printf("\t\t\t\t\t\t\t          \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\  \n");
	delay(48);
	printf("\t\t\t\t\t\t\t           \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\ \n");
	delay(52);
	printf("\t\t\t\t\t\t\t            \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______| \n\n\n");
	delay(56);
	// printf("\033[0m");
	}

void displayscore(){
	getSub:
		system("cls");
		logo_fast();
		char sub;
		int count = 0;
		char subject[50];
		int basic_marks;
		int main_marks;
		char strTemp[256];
		FILE * highMarks = fopen("Results/highFile.txt","r");
		if(!highMarks)
		{
		printf("\n\n\n \t\t\t Marks File Can't Be OPENED \t\t\t \n\n\n");
		getch();
		goto getSub;
		}
		printf("\n\n Choose a subject to see highest score:-\n\n  A. RMP\n  B. MCP\n  C. Android\n  D. Game Programming\n  E. iOS\n\n Enter your choice : ");
		sub = toupper(getch());
		if(sub == 'A'){
				while (fgets(strTemp, sizeof(strTemp), highMarks) != NULL) // read a line
    		{
        if (count == 0)
        {
						fscanf(highMarks,"%s %d %d",&subject,&basic_marks,&main_marks);
						printf("\n\n\n  +-----------+---------------+--------------+\n  |  Subject  |  Basic Marks  |  Main Marks  |\n  |-----------|---------------|--------------|\n  |    %s    |       %d       |      %d       |\n  +-----------+---------------+--------------+",subject,basic_marks,main_marks);
						fclose(highMarks);
						printf("\n\n Press any key to go to Homepage.....");
						// getch();
						// goto getSub;
        }
        else
        {
            count++;
        }
    		}
		}
		else if(sub=='B'){
			while (fgets(strTemp, sizeof(strTemp), highMarks) != NULL) // read a line
    		{
        if (count == 1)
        {
						fscanf(highMarks,"%s %d %d",&subject,&basic_marks,&main_marks);
						printf("\n\n\n  +-----------+---------------+--------------+\n  |  Subject  |  Basic Marks  |  Main Marks  |\n  |-----------|---------------|--------------|\n  |    %s    |       %d       |      %d       |\n  +-----------+---------------+--------------+",subject,basic_marks,main_marks);
						fclose(highMarks);
						printf("\n\n Press any key to go to Homepage.....");
						// getch();
						// goto getSub;
        }
        else
        {
            count++;
        }
    		}
		}
		else if(sub=='C'){
			while (fgets(strTemp, sizeof(strTemp), highMarks) != NULL) // read a line
    		{
        if (count == 2)
        {
						fscanf(highMarks,"%s %d %d",&subject,&basic_marks,&main_marks);
						printf("\n\n\n  +-----------+---------------+--------------+\n  |  Subject  |  Basic Marks  |  Main Marks  |\n  |-----------|---------------|--------------|\n  |  %s  |       %d       |      %d       |\n  +-----------+---------------+--------------+",subject,basic_marks,main_marks);
						fclose(highMarks);
						printf("\n\n Press any key to go to Homepage.....");
						// getch();
						// goto getSub;
        }
        else
        {
            count++;
        }
    		}
		}
		else if(sub=='D'){
			while (fgets(strTemp, sizeof(strTemp), highMarks) != NULL) // read a line
    		{
        if (count == 3)
        {
						fscanf(highMarks,"%s %d %d",&subject,&basic_marks,&main_marks);
						printf("\n\n\n  +-----------+---------------+--------------+\n  |  Subject  |  Basic Marks  |  Main Marks  |\n  |-----------|---------------|--------------|\n  |    %s    |       %d       |      %d       |\n  +-----------+---------------+--------------+",subject,basic_marks,main_marks);
						fclose(highMarks);
						printf("\n\n Press any key to go to Homepage.....");
						// getch();
						// goto getSub;
        }
        else
        {
            count++;
        }
    		}
		}
		else if(sub=='E'){
			while (fgets(strTemp, sizeof(strTemp), highMarks) != NULL) // read a line
    		{
        if (count == 4)
        {
						fscanf(highMarks,"%s %d %d",&subject,&basic_marks,&main_marks);
						printf("\n\n\n  +-----------+---------------+--------------+\n  |  Subject  |  Basic Marks  |  Main Marks  |\n  |-----------|---------------|--------------|\n  |    %s    |       %d       |      %d       |\n  +-----------+---------------+--------------+",subject,basic_marks,main_marks);
						fclose(highMarks);
						printf("\n\n Press any key to go to Homepage.....");
						// getch();
						// goto getSub;
        }
        else
        {
            count++;
        }
    		}
		}
		else{
		printf("\033[1;31m");
		printf("\n Please choose correct option !!!\n ");
		system("pause");
		printf("\033[0m");
		// getch();
		// system("cls");
		// logo_fast();
		goto getSub;
		}
}
void writescore(float mscore, char plnm[20]){}

void help()
{
	system("cls");
	logo_fast();
	printf("\n\n\n\n\t\t\t\t\t\t\t\t\t      Help Page");
	printf("\n\n\t\t\t\t\t\t#######################################################################");
	printf("\n\n\t\t\t\t\t\t   1. Start the game by pressing 'S'.");
	printf("\n\t\t\t\t\t\t   2. Enter your name (make sure it is correct).");
	printf("\n\t\t\t\t\t\t   3. Choose the subject.");
	printf("\n\t\t\t\t\t\t   4. There will be 2 rounds (Basic Round & Main Round).");
	printf("\n\t\t\t\t\t\t   5. You can reach Main Round only after clearing the Basic Round.");
	printf("\n\t\t\t\t\t\t   6. Score atleast 2 points out of 3 to clear Basic Round.");
	printf("\n\t\t\t\t\t\t   7. Score atleast 7 points out of 10 to clear Main Round.");
	printf("\n\t\t\t\t\t\t   8. Report will be generated in the end.");
	printf("\n\t\t\t\t\t\t   9. Score will be calculated in the end.");
	printf("\n\n\t\t\t\t\t\t   Press any key to go to Homepage.....");
	}

void info()
{ // to show start page 
	// system("cls");
	// logo_fast();
	printf("\t\t\t\t\t\t\t\t\t Welcome to the Quiz Game :- \n\n");
	printf("\t\t\t\t\t\t\t     ###############################################\n\n");
	printf("\t\t\t\t\t\t\t\t Enter 'S' to Start Game \n");
	printf("\t\t\t\t\t\t\t\t Enter 'V' to View High Score \n");
	printf("\t\t\t\t\t\t\t\t Enter 'H' for Help \n");
	printf("\t\t\t\t\t\t\t\t Enter 'Q' to Quit \n\n");
	printf("\t\t\t\t\t\t\t     ###############################################\n");
	// system("pause");
	// system("cls");				
}
	
void main()
{
	char text[size],option1[size], option2[size], option3[size], option4[size], c_option[size], correct[size], category[size];
	char pname[30];
	char blank1[256][256], blank2[256][256];
	char* dirname = "Results";
	int i,j,k,l,c;
	int b_arr[easy_ques],m_arr[tot_ques-easy_ques],x,loc;
	time_t t;
	char line[256];
	int bscore = 0, mscore = 0;
	char infoChoice,subChoice,confirm;
	FILE * fp;
  FILE * output;
	char inptr[30],outptr[30];
	mkdir(dirname);
  
home:
	logo_slow();
	info();
getInfoChoice:
	infoChoice = toupper(getch());
	if (infoChoice=='V')
	{
	  // system("cls");
	  // logo_fast();
		// info();
		displayscore();
		getch();
		system("cls");
	  logo_slow();
		info();
		goto getInfoChoice;
	}
	else if (infoChoice=='Q'){
	system("cls");
	exit(1);
	}
	else if (infoChoice=='H')
	{
		help();
		getch();
		system("cls");
	  logo_slow();
		info();
		goto getInfoChoice;
	}

else if(infoChoice=='S'){
getPname:
	system("cls");
	logo_fast();
	printf("\n\nPlease enter your name : ");
	gets(pname);
	if(strcmp(pname,"") == 0){
		printf("\033[1;31m");
		printf("\nPlease enter your name to begin !!!");
		getch();
		printf("\033[0m");
	goto getPname;
	}
	
getSubChoice:
	system("cls");
	logo_fast();
	printf("\n\nHello %s .... let's choose a subject :-\n\n A. RMP\n B. MCP\n C. Android\n D. Game Programming\n E. iOS\n\n Enter your choice : ",pname);
	subChoice = toupper(getch());
	// scanf("%c",&subChoice);
	if(subChoice=='A'){
		char **pathOut = rmp(); 
    strcpy(inptr,pathOut[0]);
    strcpy(outptr,pathOut[1]);
		for (i = 0; i<2; i++) { 
        free(pathOut[i]); 
    } 
    free(pathOut); 
  }
	else if(subChoice=='B'){
		char **pathOut = mcp(); 
    strcpy(inptr,pathOut[0]);
    strcpy(outptr,pathOut[1]);
		for (i = 0; i<2; i++) { 
        free(pathOut[i]); 
    } 
    free(pathOut); 
  }
	else if(subChoice=='C'){
		char **pathOut = android(); 
    strcpy(inptr,pathOut[0]);
    strcpy(outptr,pathOut[1]);
		for (i = 0; i<2; i++) { 
        free(pathOut[i]); 
    } 
    free(pathOut); 
  }
	else if(subChoice=='D'){
		char **pathOut = game(); 
    strcpy(inptr,pathOut[0]);
    strcpy(outptr,pathOut[1]);
		for (c = 0; c<2; c++) { 
        free(pathOut[c]); 
    } 
    free(pathOut); 
  }
	else if(subChoice=='E'){
		char **pathOut = ios();
    strcpy(inptr,pathOut[0]);
    strcpy(outptr,pathOut[1]);
		for (i = 0; i<2; i++) { 
        free(pathOut[i]); 
    } 
    free(pathOut); 
  }
	else{
		printf("\033[1;31m");
		printf("\n Please choose correct option !!!\n ");
		system("pause");
		printf("\033[0m");
		// getch();
		goto getSubChoice;
	}

	fp = fopen(inptr,"r");
  output = fopen(outptr,"w");
  if(fp == NULL)
  {
  printf("\n\n\n \t\t\t Question File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
	printf("\n\n\n \t\t\t Result File Can't Be CREATED \t\t\t \n\n\n");
	}
	
	system("cls");
	logo_fast();
	printf("\n\n\n\n You are about to enter Basic Round !!!\n\n 1. Press any key to Enter.\n 2. Press 'B' to go Back.");
	confirm = toupper(getch());
	if(confirm=='B'){
		goto getSubChoice;
	}
	else{
		k = 0;
		for (i = 0; i < easy_ques; i++) // to store starting line of each easy ques in file
		{
			b_arr[i] = 10 * i + 1; 
		}
		for (j = 0; j < easy_ques; j++)
		{ 
		logo_fast();
		loc = j;

		for (i = b_arr[j]; i < b_arr[loc]; i++)
		{
		fgets(blank1[k],sizeof(blank1[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)  // get lines for every question
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
				printf("\033[1;36m");
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  printf("\033[0m");
			  fprintf(output,"Q%d) %s",j+1,line);
			}
			
				if(i==2)
				{
					// fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,size);
			
				if(i == 4)
			strncpy(option2,line,size);
			
				if(i == 5)
			strncpy(option3,line,size);
			
				if(i == 6)
			strncpy(option4,line,size);	
	 	
			if (i >1 && i<=7)
			{
				printf("\033[1;34m");
				printf("%s",line);
				printf("\033[0m");
			}
			if (i == 8)
			strncpy(correct,line,size);	
				
			if (i == 9)
			strncpy(category,line,30);
		}

		ask_ans(c_option, option1, option2, option3, option4, correct, category,output,&bscore);
		
		if(j!=2)
		{
			
		if (m_arr[loc] + 10 < m_arr[3 * (j + 1)])
		  {  
			for (i = m_arr[loc] + 10; i < m_arr[3 * (j + 1)]; i++)
			{
			fgets(blank1[k],sizeof(blank1[k]),fp);
				k++;
			}
		  }
		}
		
		system("cls");
	}
		if(bscore < 2){
			logo_fast();
			printf("\033[1;31m");
			printf("\n\n\n\n You failed to score enough points, please try again !!! \n\n Attempted score: %d/3\n\n\n\n",bscore);
			printf("\033[0m");
			printf(" Press any key to go to Homepage....");
			getch();
			goto home;
		}
		else
		{
			logo_fast();
			printf("\n\n\n\n Congratulations!! Basic round cleared.\n\n Attempted score: %d/3 \n\n\n\n",bscore);
			printf(" Press any key to enter Main Round.....");
			getch();

			for (i = 3; i < tot_ques; i++) // to store starting line of each hard ques in file
			{
				m_arr[i-3] = 10 * i + 1; 
			}
			for (j = 0; j < hard_ques; j++)
			{ 
				logo_fast();
				srand((unsigned)time(&t)); // initialize random generator
				x = rand() % 3; // number between 0 to 2
				loc = (3 * j) + x; // number between 0 to 26

				for (i = m_arr[3 * j]; i < m_arr[loc]; i++)
				{
				fgets(blank2[k],sizeof(blank2[k]),fp);
				k++;
				}

				for (i = 1; i <= 10; i++)  // get lines for every question
				{
				fgets(line,sizeof(line),fp);	
				if(i==1)
				{
					printf("\033[1;36m");
					printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
					printf("\033[0m");
					fprintf(output,"Q%d) %s",j+4,line);
				}
				
					if(i==2)
					{
						// fputs(line,output);	
					}
					
					if(i == 3)
				strncpy(option1,line,size);
				
					if(i == 4)
				strncpy(option2,line,size);
				
					if(i == 5)
				strncpy(option3,line,size);
				
					if(i == 6)
				strncpy(option4,line,size);	
			
				if (i >1 && i<=7)
				{
					printf("\033[1;34m");
					printf("%s",line);
					printf("\033[0m");
				}
				if (i == 8)
				strncpy(correct,line,size);	
					
				if (i == 9)
				strncpy(category,line,30);
			}

			
			ask_ans(c_option, option1, option2, option3, option4, correct, category,output,&mscore);
			
			if(j!=9)
			{
				
			if (m_arr[loc] + 10 < m_arr[3 * (j + 1)])
				{  
				for (i = m_arr[loc] + 10; i < m_arr[3 * (j + 1)]; i++)
				{
				fgets(blank2[k],sizeof(blank2[k]),fp);
					k++;
				}
				}
			}
			
			
			system("cls");
		}
			}

		if(mscore < 7){
			logo_fast();
			printf("\033[1;31m");
			printf("\n\n\n\n You failed to score enough points, please try again !!! \n\n Attempted score: %d/10\n\n\n\n",mscore);
			printf("\033[0m");
			printf(" Press any key to go to Result page....");
			getch();
		}

		else{
			logo_fast();
			printf("\n\n\n\n Congratulations!! Main round cleared.\n\n Attempted score: %d/10 \n\n\n\n",mscore);
			printf(" Press any key to go to Result page....");
			getch();
		}
		

	}

	fprintf(output,"\n\t\t\t\t\t\t\t +-----------------------------------------------+\n\t\t\t\t\t\t\t |                  Score Card                   |\n\t\t\t\t\t\t\t |-----------------------+-----------------------|\n\t\t\t\t\t\t\t |      Basic Round      |      Main Round       |\n\t\t\t\t\t\t\t +-----------------------|-----------------------+\n\t\t\t\t\t\t\t |          %d/3          |         %d/10          |\n\t\t\t\t\t\t\t +-----------------------+-----------------------+",bscore,mscore);

	// fprintf(output,"\n##################################\n# Your basic score :-\n#\n# %d out of 3 in Basic\n#\n##################################",bscore);
	// fprintf(output,"\n# Your main score :-\n#\n# %d out of 10 in Main\n#\n##################################\n\n\n",mscore);
	
	fclose(fp);
	
	fclose(output);
	system("cls");
	printf("\033[1;31m");
	logo_slow();
	output = fopen(outptr,"r");
	printf("\n");
	while(fgets(line,sizeof(line),output))
	{
		printf(" %s",line);
	}
	printf("\033[0m\n");
	fclose(output);
	printf("\033[1;35m");
	printf("\n Press any key to restart.......");
	getch();
	printf("\033[0m\n");
	system("cls");
	goto home;
}
else
	{
		printf("\033[1;31m");
		printf("\n\n\t\t  Please press the right key!!!!\n\n\t\t  ");
		system("pause");
		printf("\033[0m");
		system("cls");
		logo_slow();
		info();
		goto getInfoChoice;
	}
}