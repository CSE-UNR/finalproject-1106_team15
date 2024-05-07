//Authors: Ethan Araki and Adam Jackson
//Date: 4/29/2024
//Purpose: Final Group Project

#include <stdio.h> 

#define C 100
#define R 100


void displayMenu(int choice1, int choice2);
void displayMenu2(int choice2);
void loadImage(char image[][C], int row, int col, char fileName[]);
void displayImage(char image[][C], int row, int col, char fileName[]);

int main(){
	int choice1, choice2;
	
	
	//display first menu choices
	displayMenu(choice1, choice2);
	
	
	
	return 0;
}

//function for first menu choices
void displayMenu(int choice1, int choice2){
	int row = 0, col;
	char image[R][C];
	char fileName[R];
	do{
		printf("***ERINSTAGRAM***\n");
		printf("1. Load image\n");
		printf("2. Display image\n");
		printf("3. Edit image\n");
		printf("4. Exit\n");
		printf("\n");
		printf("Choose from one of the options above: ");
		scanf("%d", &choice1);
		
		//display second menu
		if(choice1 == 3){
			displayMenu2(choice2);
		}
		else if(choice1 == 1){
		        loadImage(image, row, col, fileName);
		}
		else if(choice1 == 2){
			displayImage(image, row, col, fileName);
		}
		else{
			printf("Invalid Option: \n");
		}
	
	
	}while(choice1 != 4);
	printf("Goodbye!");
}

//function for second menu choices
void displayMenu2(int choice2){
	
		printf("***ENTER NUMBER FOR CHOICE***\n");
		printf("1. Crop\n");
		printf("2. Dim\n");
		printf("3. Brighten\n");	
		printf("4. Rotate\n");
		printf("\n");
		printf("Choose from one of the options above: ");
		scanf("%d", &choice2);

		
	
	

}
void loadImage(char image[][C], int row, int col, char fileName[]){
	
	
	printf("What is the name of the image file: ");
	scanf("%s", fileName);
	
	
	FILE *pf1 = fopen(fileName,"r");
	
	if(fileName == NULL){      
		printf("Unable to open file.\n");
	}
	else{
		
		printf("\n");
		printf("Successfully loaded image!\n");
		printf("\n");
		
	}
			
		
		fclose(pf1);
	
}
	
		
			

void displayImage(char image[][C], int row, int col, char fileName[]){
	
	FILE *pf1 = fopen(fileName,"r");
	
	
	for(row = 0; row < R && fgets(image[row], C, pf1) != NULL; row++){
			for(col = 0; image[row][col] != '\n' && image[row][col] != '\0'; col++){	
			
			}
			image[row][col] = '\0';			
	}
	
	for(int i = 0; i < row; i++){
	
				printf("%s\n", image[i]);
		}
	fclose(pf1);
}
		
	
	
	
	
	
	
	


