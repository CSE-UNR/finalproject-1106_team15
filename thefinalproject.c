//Authors: Ethan Araki and Adam Jackson
//Date: 4/29/2024
//Purpose: Final Group Project

#include <stdio.h>

#define C 25
#define R 25

void displayMenu(int *choice1, int *choice2);
void displayMenu2(int *choice2, char image[][C], int row, int col, char fileName[]);
void loadImage(char image[][C], int row, int col, char fileName[]);
void displayImage(char image[][C], int row, int col, char fileName[]);

void writeImageToFile(char image[][C], int row, int col, char fileName[]);

void writeCroppedImageToFile(char image[][C], int startX, int startY, int endX, int endY, char fileName[]);

void cropImage(char image[][C], int row, int col, char fileName[]);
void dimImage(char image[][C], int row, int col, char fileName[]);
void brightenImage(char image[][C], int row, int col, char fileName[]);
void rotateImage(char image[][C], int *row, int *col, char fileNme[]);

int main() {
    int choice1, choice2;

    // Display first menu choices
    displayMenu(&choice1, &choice2);

    return 0;
}

// Function for first menu choices
void displayMenu(int *choice1, int *choice2) {
    int row = 0, col;
    char image[R][C];
    char fileName[R];
    do {
        printf("***ERINSTAGRAM***\n");
        printf("1. Load image\n");
        printf("2. Display image\n");
        printf("3. Edit image\n");
        printf("4. Exit\n");
        printf("\n");
        printf("Choose from one of the options above: ");
        scanf("%d", choice1); // Update choice1 directly

        // Display second menu
        if (*choice1 == 3) { // Use *choice1 to access its value
            displayMenu2(choice2, image, row, col, fileName); // Pass fileName to displayMenu2
        } else if (*choice1 == 1) {
            loadImage(image, row, col, fileName);
        } else if (*choice1 == 2) {
            displayImage(image, row, col, fileName);
        } else if (*choice1 != 4) { // Add condition to check if choice1 is not 4
            printf("Invalid Option: \n");
        }
    } while (*choice1 != 4); // Use *choice1 to check its value
    printf("Goodbye!\n");
}

// Function for second menu choices
void displayMenu2(int *choice2, char image[][C], int row, int col, char fileName[]) {
        printf("***ENTER NUMBER FOR CHOICE***\n");
        printf("1. Crop\n");
        printf("2. Dim\n");
        printf("3. Brighten\n");
        printf("4. Rotate\n");
        printf("\n");
        printf("Choose from one of the options above\n");
        scanf("%d", choice2); // Update choice2 directly

        switch (*choice2) { // Use *choice2 to access its value
            case 1:
                cropImage(image, row, col, fileName);
                break;
            case 2:
                dimImage(image, row, col, fileName); // Pass fileName to dimImage
                break;
            case 3:
                brightenImage(image, row, col, fileName);
                break;
            case 4:
                rotateImage(image, &row, &col, fileName);
                break;
            case 0:
                return; // Exit the function to return to the main menu
            default:
                printf("Invalid Option: \n");
                break;
        }
}

// Placeholder functions for image manipulation
void loadImage(char image[][C], int row, int col, char fileName[]) {
    printf("What is the name of the image file: ");
    scanf("%s", fileName);
    FILE *pf1 = fopen(fileName, "r");
    if (pf1 == NULL) {
        printf("Unable to open file.\n");
    } else {
        printf("\n");
        printf("Successfully loaded image!\n");
        printf("\n");
    }

    // Read the image content into the image array
    for (row = 0; row < R && fgets(image[row], C, pf1) != NULL; row++) {
        for (col = 0; image[row][col] != '\n' && image[row][col] != '\0'; col++) {
        }
        image[row][col] = '\0';
    }

    fclose(pf1);
}

void displayImage(char image[][C], int row, int col, char fileName[]) {
    FILE *pf1 = fopen(fileName, "r");
    int newlines = 0, columns = 0, firstNewline = 0, c;
    while(c = fgetc(pf1)){
    	if(c == EOF){
    		break;
    	}
    	if(firstNewline == 0){
    		columns++;
	}
	if(c == '\n'){
		newlines++;
		firstNewline = 1;
	}
    }
    
    
    for (row = 0; row < newlines && fgets(image[row], columns, pf1) != NULL; row++) {
        for (col = 0; image[row][col] != '\n' && image[row][col] != '\0'; col++) {
        }
        image[row][col] = '\0';
    }

   		for (row = 0; row < newlines; row++) {
			for (col = 0; col < columns; col++) {
				switch(image[row][col]){
           				case '1':
           					image[row][col] = '.';
           					break;
           			
         				case '2':
           				
           					image[row][col] = 'o';
           					break;
          				case '3':
           
           					image[row][col] = 'O';
						break;
					case '4':
         				
         					image[row][col] = '0';
    			   			break;
    			   		case '0':
         					image[row][col] = ' ';
         					break;
         				default:
         					break;

    			       }
				printf("%c", image[row][col]);
			
			}	
			printf("\n");	
		
		}	
    
    for (int i = 0; i < row; i++) {
        printf("%s\n", image[i]);
    }

    fclose(pf1);
	printf("\n");
}


void cropImage(char image[][C], int row, int col, char fileName[]) {
    int startX, startY, endX, endY;

    
    printf("Enter Rows for Cropping (For Example: 1 5): ");
    scanf("%d %d", &startX, &endX);
    printf("Enter Column for Cropping(For Example: 1 5) : ");
    scanf("%d %d", &startY, &endY);

    
    if (startX < 0 || startY < 0 || endX >= R || endY >= C || startX >= endX || startY >= endY) {
        printf("Invalid cropping coordinates.\n");
        return;
    }

    
    endX = (endX >= R) ? (R - 1) : endX;
    endY = (endY >= C) ? (C - 1) : endY;

    
  
    printf("\nImage Cropped:\n\n");
   
    for (int i = startX; i <= endX; i++) {
        for (int j = startY; j <= endY; j++) {
            
            printf("%c", image[i][j]);
        } 
        printf("\n\n");
    }
    
    writeCroppedImageToFile(image, startX, startY, endX, endY, fileName);
    
}


void brightenImage(char image[][C], int row, int col, char fileName[]) {
    // Edit the text file to transform characters
    
    for (row = 0; row < R; row++) {
        for (col = 0; col < C; col++) {
           if(image[row][col] == '.'){
           	image[row][col] = 'o';
           }
           else if(image[row][col] == 'o'){
           	image[row][col] = 'O';
           }
           else if(image[row][col] == 'O'){
           	image[row][col] = '0';
	   }
           else if(image[row][col] == ' '){
         	image[row][col] = '.';
       	   }
      }
    
   	 
    }
    image[row][col] = '\0';
      
      
      for (row = 0; row < R; row++) {	
	for(col = 0; col < C; col++){
        	printf("%c", image[row][col]);
    	}
   		printf("\n");
   	 image[row][col] = '\0';
    }
    
    printf("\nImage brightened.\n\n");

    // Write modified image content back to file
    writeImageToFile(image, row, col, fileName);

}


void dimImage(char image[][C], int row, int col, char fileName[]) {
   
    for (row = 0; row < R; row++) {
        for (col = 0; col < C; col++) {
           if(image[row][col] == '.'){
           	image[row][col] = ' ';
           }
           else if(image[row][col] == 'o'){
           	image[row][col] = '.';
           }
           else if(image[row][col] == 'O'){
           	image[row][col] = 'o';
	   }
           else if(image[row][col] == '0'){
         	image[row][col] = 'O';
       	   }
      }
    
   	 
    }
    image[row][col] = '\0';
      
      
      for (row = 0; row < R; row++) {	
	for(col = 0; col < C; col++){
        	printf("%c", image[row][col]);
    	}
   		printf("\n");
   	 image[row][col] = '\0';
    }
    
    printf("\nImage dimmed.\n\n");

    // Write modified image content back to file
    writeImageToFile(image, row, col, fileName);
}



void rotateImage(char image[][C], int *row, int *col, char fileName[]) {
    // Create a temporary array to store the rotated image
    char temp[C][R];

    // Iterate through each element of the original image
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            // Rotate the element by swapping rows and columns
            temp[j][*row - i - 1] = image[i][j];
        }
    }

    // Update row and col to reflect the new dimensions after rotation
    int tempRow = *row;
    *row = *col;
    *col = tempRow;

    printf("\nImage rotated:\n\n");

    // Display the rotated image
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            printf("%c", temp[i][j]);
        }
        printf("\n");
    }

    // Write modified image content back to the original array
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) {
            image[i][j] = temp[i][j];
        }
    }

    // Write modified image content back to file
    writeImageToFile(image, *row, *col, fileName);
}




void writeImageToFile(char image[][C], int row, int col, char fileName[]) {
    
	char choice3, fileName2[21];
	printf("Would you like to save?(y/n): ");
	scanf(" %c", &choice3);
  
	if(choice3 == 'y'){
		
		
		printf("What is the name of the image file you would like to save to?: ");
   		scanf("%s", fileName2);
   		printf("\n");
		
		FILE *pf2 = fopen(fileName2, "w");
		
		for (row = 0; row < R; row++) {
			for (col = 0; col < C; col++) {
				switch(image[row][col]){
           				case '.':
           					image[row][col] = 1;
           					break;
           			
         				case 'o':
           				
           					image[row][col] = 2;
           					break;
          				case '0':
           
           					image[row][col] = 4;
						break;
					case 'O':
         				
         				image[row][col] = 3;
    			   			break;
    			   		default:
         				image[row][col] = 0;
         					break;

    			   	}
				fprintf(pf2, "%d", image[row][col]);
			}	
				
			fprintf(pf2, "\n");
		}	
			
			fclose(pf2);
	}
	else{
		printf("\n");
	}
	
	
	
} 


void writeCroppedImageToFile(char image[][C], int startX, int startY, int endX, int endY, char fileName[]) {
    
	char choice3, fileName2[21];
	printf("Would you like to save?(y/n): ");
	scanf(" %c", &choice3);
  
	if(choice3 == 'y'){
		
		
		printf("What is the name of the image file you would like to save to?: ");
   		scanf("%s", fileName2);
   		printf("\n");
		
		FILE *pf2 = fopen(fileName2, "w");
		
		for (int i = startX; i <= endX; i++) {
			for (int j = startY; j <= endY; j++) {
				switch(image[i][j]){
           				case '.':
           					image[i][j] = 1;
           					break;
           			
         				case 'o':
           				
           					image[i][j] = 2;
           					break;
          				case '0':
           
           					image[i][j] = 4;
						break;
					case 'O':
         				
         				image[i][j] = 3;
    			   			break;
    			   		default:
         				image[i][j] = 0;
         					break;

    			   	}
				fprintf(pf2, "%d", image[i][j]);
			}	
				
			fprintf(pf2, "\n");
		}	
			
			fclose(pf2);
	}
	else{
		printf("\n");
	}
	
	
	
} 
