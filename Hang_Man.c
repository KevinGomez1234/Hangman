#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

	void updateHangman();
	char *chooseRandomWord();
	
	int main(void)
	{
		//Pointer to the random word.
		char *randomWord = chooseRandomWord();
		char *dashedLines;
		char choice;
		int sizeOfRandomWord;
		//tries 
		int incorrect = -1;
		int correct;
		//1 if correct 0 if incorrect
		int correctBoolean = 0;
		//Getting the size of our word
		while(randomWord [sizeOfRandomWord] != '\n')
		{	
			sizeOfRandomWord++;
		}
		//Dashed Lines 
		dashedLines = (char*) malloc(sizeOfRandomWord * sizeof(char));
		for(int j=0;j<=sizeOfRandomWord-1;j++)
		{
			dashedLines[j] = '_';
		}
		printf("Welcome to Hang Man\n----------------|\n");
		printf("\n%s\n", &dashedLines[0]);
		while(incorrect!=7)
		{
			printf("\nEnter a letter: ");
			scanf(" %c", &choice);
			for(int i = 0;i<sizeOfRandomWord;i++)
			{
				if(randomWord[i]==choice && !(choice==dashedLines[i]))
				{
					dashedLines[i] = choice;
					correctBoolean = 1;
					printf("\nThat's correct!\n");
					correct++;
				}
				else if (choice == dashedLines[i])
				{
					printf("\nYou already picked that!\n");
					correctBoolean = 1;
				}
			}
			if(correctBoolean==0)
			{
				printf("\nThat's not correct!\n");
				incorrect++;
			}
			correctBoolean = 0;
			//shows the Hangman
			updateHangman(incorrect);
			//Shows the dashed lines
			printf("\n%s\n", &dashedLines[0]);
			//Checks win
			if(correct==sizeOfRandomWord)
			{
				printf("\nThe word was: %s\n", &randomWord[0]);
				printf("Congratulations, You Have Won Hang Man!\n");
				break;
			}
			if(incorrect==7){
				printf("\nThe word was: %s\n", &randomWord[0]);
			}
		}
		return 0;
	}
//Cases of Hang Man 
void updateHangman(int counter)
{
	switch(counter)
	{
		case 0:
			printf("----------------|\n");
			printf("\t\tO\n");
		break;
		case 1: 
			printf("----------------|\n");
			printf("\t\tO\n");
			printf("\t\t|\n");
		break;
		case 2:
			printf("----------------|\n");
			printf("\t\tO\n");
			printf("\t\t|\n");
			printf("\t\t|");
		break;
		case 3:
			printf("----------------|\n");
			printf("\t\tO\n");
			printf("\t\t|\n");
			printf("\t\t|");
			printf("\\");
		break;
		case 4:
			printf("----------------|\n");
			printf("\t\tO\n");
			printf("\t\t|\n");
			printf("\t\t|");
			printf("\\");
			printf("\b\b\b/|\\\n");
		break;
		case 5:
			printf("----------------|\n");
			printf("\t\tO\n");
			printf("\t\t|\n");
			printf("\t\t|");
			printf("\\");
			printf("\b\b\b/|\\\n");
			printf("\t\t|");
		break;
		case 6:	
			printf("----------------|\n");
			printf("\t\tO\n");
			printf("\t\t|\n");
			printf("\t\t|");
			printf("\\");
			printf("\b\b\b/|\\\n");
			printf("\t\t|");
			printf("\n\t\t \\");
		break;
		case 7:
			printf("----------------|\n");
			printf("\t\tO\n");
			printf("\t\t|\n");
			printf("\t\t|");
			printf("\\");
			printf("\b\b\b/|\\\n");
			printf("\t\t|");
			printf("\n\t\t \\");
			printf("\b\b\b/ \\");
			printf("\n\tGAME OVER!");
		break;
		default: 
			printf("----------------|\n");
		break;
	}
}
//Opens a file called Words.txt and selects a random line from the file. Returns a char pointer to the word
	char *chooseRandomWord()
	{
		FILE *fPointer;
		char randomWord[100];
		int count,randomNumber;
		char *word;
		srand (time(NULL));
		fPointer = fopen("Words.txt", "r");
		//Open file and count the lines within the file
		if (fPointer != 0)
		{
			while(feof(fPointer)==0)
			{
				if(fgets(randomWord, 100, fPointer))
				count++;
			}
		}
		else
			printf("Error File Not Found");
		//Generate a random number in between 0 and number of lines in the file. 
		randomNumber = rand() % (count+1);
		//reset buffer
		fPointer = fopen("Words.txt", "r");
		//select a random word and store it in the buffer
		for(int i = 0; i<=randomNumber-1;i++)
		{
			fgets(randomWord, 100, fPointer);
		}
		//Allocate space for the word
		word = (char*) malloc(strlen(randomWord)*sizeof(char));
		//store the word 
		strcpy(word, randomWord);
		return word;
	}



