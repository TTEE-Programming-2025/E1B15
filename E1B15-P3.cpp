#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define SIZE 9
#define BOOKED 10

char seat[SIZE][SIZE];		// Main seat array.
char temp[SIZE][SIZE];		// Temporary array used for seat selection.

// Initialize all seats to '-', indicating they are not booked.
void initSeats(char seat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seat[i][j] = '-';
}
// Display the current seat status.
void showSeats(char seat[SIZE][SIZE]) {
    system("cls");
    printf("\\123456789\n");
    for (int i = SIZE - 1; i >= 0; i--) {	// Display the seats from bottom to top.
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seat[i][j]);
        }
        printf("\n");
    }
    printf("Press any key to return to the main menu...\n");
    getch();
}
// Randomly book some seats, using '\*' to indicate booked ones.  
void randomBooking(char seat[SIZE][SIZE]) {
    int count = 0;
    while (count < BOOKED) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (seat[r][c] != '*') {
            seat[r][c] = '*';
            count++;
        }
    }
}
// Automatically arrange consecutive seats with computer assistance.
void computerAssign(char seat[SIZE][SIZE]) {
    int n, i, j;
    int found = 0; // Used to record whether suitable seats were successfully found.

    // Prompt the user to enter the number of seats needed (1¡V4).
    printf("How many seats do you need? (1¡V4)¡G");
    scanf("%d", &n);

    // Handle the cases where the seat request is for 1 to 3 seats.
    if (n >= 1 && n <= 3) {
        for (i = 0; i < SIZE && found == 0; i++) {
            for (j = 0; j <= SIZE - n; j++) {
                // Check if there are `n` consecutive positions starting from `seat[i][j]` that are all '-' (available).
                if (seat[i][j] == '-' &&
                    (n < 2 || seat[i][j+1] == '-') &&
                    (n < 3 || seat[i][j+2] == '-')) {
                    
                    // Pre-mark the reserved seats as '@'.
                    if (n >= 1) seat[i][j] = '@';
                    if (n >= 2) seat[i][j+1] = '@';
                    if (n >= 3) seat[i][j+2] = '@';

                    found = 1; // Indicates that a suitable position has been found.
                    break;     // Break out of the inner loop.
                }
            }
        }
    } 
    // If 4 seats are required.
    else if (n == 4) {
        // First, try to find 4 consecutive available seats in a single row.
        for (i = 0; i < SIZE && found == 0; i++) {
            for (j = 0; j <= SIZE - 4; j++) {
                if (seat[i][j] == '-' && seat[i][j+1] == '-' &&
                    seat[i][j+2] == '-' && seat[i][j+3] == '-') {

                    // Mark 4 consecutive horizontal seats as '@'.
                    seat[i][j] = seat[i][j+1] = seat[i][j+2] = seat[i][j+3] = '@';
                    found = 1;
                    break;
                }
            }
        }

        // If no horizontal 4 consecutive seats are found, try to find a 2x2 block (two seats on each of two adjacent rows).
        if (found == 0) {
            for (i = 0; i < SIZE - 1 && found == 0; i++) {
                for (j = 0; j < SIZE - 1; j++) {
                    if (seat[i][j] == '-' && seat[i][j+1] == '-' &&
                        seat[i+1][j] == '-' && seat[i+1][j+1] == '-') {
                        
                        // Mark the four positions of the 2x2 block as '@'.
                        seat[i][j] = seat[i][j+1] = seat[i+1][j] = seat[i+1][j+1] = '@';
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    // If a suitable position is found successfully.
    if (found) {
        showSeats(seat); // Display the current seat status (including reserved '@' seats).
        char ok;
        printf("Are you satisfied with this arrangement?(y/n)¡G");
        scanf(" %c", &ok); // Note: The leading space is to ignore the newline character from the previous input.

        if (ok == 'y') {
            // User is satisfied, convert '@' to confirmed booking '\*' seats.
            for (i = 0; i < SIZE; i++)
                for (j = 0; j < SIZE; j++)
                    if (seat[i][j] == '@') seat[i][j] = '*';
        } else {			// Not satisfied, revert '@' back to available '-' seats.
            for (i = 0; i < SIZE; i++)
                for (j = 0; j < SIZE; j++)
                    if (seat[i][j] == '@') seat[i][j] = '-';
        }
    } else {
        // No consecutive available seats found that meet the requirement.
        printf("Unable to find %d consecutive available seats.\n", n);
        system("pause");
    }
}
// User manually enters seat selection.
void chooseSeats(char seat[SIZE][SIZE]) {
    char ch;                     // Used to receive each character entered by the user.
    int row = 0, col = 0, state = 0;  // `row` and `col` store the parsed seat coordinates, and `state` indicates the parsing state (0 = waiting for row, 1 = waiting for column, 2 = waiting for comma).
    char input[50];             // Used to store the entire input string (e.g., "1-2,3-4").
    int index = 0;              // Current parsing position.

    // Initialize the `temp` seating chart to '-' (available).
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            temp[i][j] = '-';

    printf("Please enter seats (format: 1-2,2-9), press Enter to finish¡G\n");

    // Use `getche()` to read user input until Enter (ASCII 13) is pressed.
    while ((ch = getche()) != 13)
        input[index++] = ch;
    input[index] = '\0'; // Append '\0' at the end of the string.

    index = 0;
    // Start parsing the input string.
    while (input[index] != '\0') {
        // Processing numeric character (1¡V9).
        if (input[index] >= '1' && input[index] <= '9') {
            if (state == 0) {             // Waiting for the row input.
                row = input[index] - '1'; // Convert to index (row = 1 ¡÷ 0).
                state = 1;                // Waiting for the col (column) input.
            }
            else if (state == 1) {        // Waiting for the col (column) input.
                col = input[index] - '1';
                state = 2;                // Waiting for a comma next.
            }
        }
        else if (input[index] == '-') {
            // The '-' should appear between row and col, so the state must be 1.
            if (state != 1) {
                printf("\nInvalid format!\n");
                system("pause");
                return;
            }
        }
        else if (input[index] == ',') {
            // A comma ',' should appear after a complete coordinate pair (row-col).
            if (state != 2 || row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
                printf("\nInvalid format or coordinates!\n");
                system("pause");
                return;
            }

            // Check if the seat is already booked or has been selected more than once.
            if (seat[row][col] == '*' || temp[row][col] == '@') {
                printf("\nSeat \[%d,%d] is already booked or duplicated!\n", row+1, col+1);
                system("pause");
                return;
            }

            temp[row][col] = '@'; // Temporarily store the selected seats.
            state = 0;            // Reset status to prepare for processing the next set of coordinates.
        }
        else {
            // If an invalid character is encountered.
            printf("\nInvalid character!\n");
            system("pause");
            return;
        }
        index++;
    }

    // Process the last set of coordinates (if the user doesn't enter a comma, end input).
    if (state == 2 && row >= 0 && row < SIZE && col >= 0 && col < SIZE && seat[row][col] != '*')
        temp[row][col] = '@';
    else {
        printf("\nInvalid format or seat already booked!\n");
        system("pause");
        return;
    }

    // Apply the selection results from `temp` to `seat` (change to '@' status).
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (temp[i][j] == '@')
                seat[i][j] = '@';

    showSeats(seat); // Display the current seating chart (including selected '@' seats).

    // After the user reviews, convert '@' to the confirmed booking symbol '*'.
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (seat[i][j] == '@')
                seat[i][j] = '*';
}
// Ask the user whether to exit the program.
void askToExit() {
    char confirm;
    while (1) {
        printf("Continue? (y/n): ");
        scanf(" %c", &confirm);
        if (confirm == 'y') {
            return; // Return to the main menu.  
        } else if (confirm == 'n') {
            printf("Thank you for using the system. Program terminated.\n");
            exit(0); // Exit the program.
        } else {
            printf("Invalid input, please enter 'y' or 'n'.\n");
        }
    }
}
// Main Program   
int main() {
    char password[5];
    int count = 0;
    int inputTimes = 0;
    char Menu;
    char seat[SIZE][SIZE];

    srand(time(NULL));

    // Cover screen  
    printf("|--------------------------------------------|\n");
    printf("| ********  **       **  **    **  *******   |\n");
    printf("|    **     **       **  **    **  **        |\n");
    printf("|    **     **       **  **    **  **        |\n");
    printf("|    **     **       **  **    **  **  ****  |\n");
    printf("|    **     **       **  **    **  **    **  |\n");
    printf("|    **     **       **  **    **  **    **  |\n");
    printf("|    **      **     **   **    **  **    **  |\n");
    printf("|    **       *******     ******    ******   |\n");
    printf("|--------------------------------------------|\n");                             
    printf("|--------------------------------------------|\n");  
    printf("|                                            |\n");
    printf("|                E1B15µ£µXµq                 |\n");
    printf("|                                            |\n");
    printf("|          Programming Assignment 3          |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");
    printf("|                                            |\n");
    printf("|   Press any key to continue the program.   |\n");
    printf("|                                            |\n");
    printf("|--------------------------------------------|\n");

    getch();
    system("cls");

    while (count < 3) {
        printf("Please enter a 4-digit password¡G");
        for (int i = 0; i < 4; i++) {
            password[i] = getch();
            printf("*");
        }
        password[4] = '\0';
        inputTimes++;

        printf("\nThe password you entered is¡G%s\n", password);

        if (password[0] == '2' && password[1] == '0' &&
            password[2] == '2' && password[3] == '5') {
            printf("Password correct! Press any key to enter the main menu.\n");
            getch();
            break;
        } else {
            printf("\aIncorrect password, please try again.\n");
            count++;
            if (count == 3) {
                printf("\n Entered incorrectly three times, program terminated.\n");
                printf("You have entered the password %d times in total.\n", inputTimes);
                system("pause");
                return 0;
            }
        }
    }

	initSeats(seat);		 // Call the subroutine to initialize seats.  
    randomBooking(seat);	 // Randomly pre-book some seats.  

    // Main menu. 
    while (1) {
        system("cls");
        printf("|-------------[Booking  System]----------|\n");
        printf("|                                        |\n");
        printf("|          a.  Available  seats          |\n");
        printf("|                                        |\n");
        printf("|          b.  Arrange  for  you         |\n");
        printf("|                                        |\n");
        printf("|          c.  Choose  by  yourself      |\n");
        printf("|                                        |\n");
        printf("|          d.  Exit                      |\n");
        printf("|                                        |\n");
        printf("|----------------------------------------|\n");
        printf("Please enter an option¡G");
        scanf(" %c", &Menu);

        switch (Menu) {
            case 'a':
                showSeats(seat);
                break;
            case 'b':
                computerAssign(seat);
                break;
            case 'c':
            	chooseSeats(seat);
                break;
            case 'd':
                askToExit();
                exit(0);
            default:
                printf("Invalid option, please enter again.\n");
                system("pause");
        }
    }

    return 0;
}

