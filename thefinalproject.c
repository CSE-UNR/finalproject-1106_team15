//Authors: Ethan Araki and Adam Jackson
//Date: 4/29/2024
//Purpose: Final Group Project

#include <stdio.h>

#define C 100
#define R 100

void displayMenu(int *choice1, int *choice2);
void displayMenu2(int *choice2, char image[][C], int row, int col, char fileName[]);
void loadImage(char image[][C], int row, int col, char fileName[]);
void displayImage(char image[][C], int row, int col, char fileName[]);
void writeImageToFile(char image[][C], int row, char fileName[]);

void cropImage(char image[][C], int row, int col);
void dimImage(char image[][C], int row, int col, char fileName[]);
void brightenImage(char image[][C], int row, int col);
void rotateImage(char image[][C], int row, int col);

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
    printf("Goodbye!");
}

// Function for second menu choices
void displayMenu2(int *choice2, char image[][C], int row, int col, char fileName[]) {
    do {
        printf("***ENTER NUMBER FOR CHOICE***\n");
        printf("1. Crop\n");
        printf("2. Dim\n");
        printf("3. Brighten\n");
        printf("4. Rotate\n");
        printf("\n");
        printf("Choose from one of the options above\n(Or enter 0 to return to the main menu): ");
        scanf("%d", choice2); // Update choice2 directly

        switch (*choice2) { // Use *choice2 to access its value
            case 1:
                cropImage(image, row, col);
                break;
            case 2:
                dimImage(image, row, col, fileName); // Pass fileName to dimImage
                break;
            case 3:
                brightenImage(image, row, col);
                break;
            case 4:
                rotateImage(image, row, col);
                break;
            case 0:
                return; // Exit the function to return to the main menu
            default:
                printf("Invalid Option: \n");
                break;
        }
    } while (*choice2 != 0); // Use *choice2 to check its value
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
    for (row = 0; row < R && fgets(image[row], C, pf1) != NULL; row++) {
        for (col = 0; image[row][col] != '\n' && image[row][col] != '\0'; col++) {
        }
        image[row][col] = '\0';
    }
    for (int i = 0; i < row; i++) {
        printf("%s\n", image[i]);
    }
    fclose(pf1);
}

void cropImage(char image[][C], int row, int col) {
    // Placeholder code for cropping image
    printf("\nImage cropped.\n\n");
}

void dimImage(char image[][C], int row, int col, char fileName[]) {
    // Edit the text file to transform characters
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // Transform characters
            switch (image[i][j]) {
                case '.':
                    image[i][j] = ' ';
                    break;
                case 'o':
                    image[i][j] = '.';
                    break;
                case 'O':
                    image[i][j] = 'o';
                    break;
                case '0':
                    image[i][j] = 'O';
                    break;
                // Leave spaces unchanged
                case ' ':
                    break;
                default:
                    break;
            }
        }
    }
    
    //displayImage(image, row, col, fileName);
    
    printf("\nImage dimmed.\n\n");

    // Write modified image content back to file
    writeImageToFile(image, row, fileName);
}

void writeImageToFile(char image[][C], int row, char fileName[]) {
    FILE *pf1 = fopen(fileName, "w");
    for (int i = 0; i < row; i++) {
        fprintf(pf1, "%s\n", image[i]);
    }
    fclose(pf1);
}

void brightenImage(char image[][C], int row, int col) {
    // Placeholder code for brightening image
for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // Transform characters
            switch (image[i][j]) {
                case ' ':
                    image[i][j] = '.';
                    break;
                case '.':
                    image[i][j] = 'o';
                    break;
                case 'o':
                    image[i][j] = 'O';
                    break;
                case 'O':
                    image[i][j] = '0';
                    break;
                // Leave spaces unchanged
                case ' ':
                    break;
                default:
                    break;
            }
        }
    }
    
    //displayImage(image, row, col, fileName);
    
    printf("\nImage brightened.\n\n");

    // Write modified image content back to file
    writeImageToFile(image, row, fileName);
}
	

void rotateImage(char image[][C], int row, int col) {
    // Placeholder code for rotating image
    printf("\nImage rotated.\n\n");
}

	
	
	
	
