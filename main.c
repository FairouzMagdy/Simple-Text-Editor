#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Function Prototypes
void gotoxy(int column, int line);
void textattr(int i);
void drawLineHorizontal(int col, int row, int hLength, int color);
int countWords(char* str);

int main()
{
    int size, row = 0, col = 0, cursor = 0;
    char ch;

    // 1) Take size of string from the user
    printf("Enter size of string: ");
    scanf("%d", &size);
    system("cls");

    // 2) Draw a horizontal line of specified length to act as input area
    drawLineHorizontal(col, row, size, 0x74);

    // 3) Build Dynamic Array for Character Storage
    char* ptr = (char*)malloc(size * sizeof(char));
    if (ptr != NULL) {
        // Take user input, character by character
        for(int i = 0; i < size; i++) {
            ch = _getch();
            if (ch == 13)  // Enter key to break input
                break;
            ptr[i] = ch;
            gotoxy(col + i, row);
            printf("%c", ch);
        }

        ptr[size] = '\0';  // Null-terminate the string
        cursor = size - 1;  // Start cursor at end of input

        // 4) Allow Manipulation of Text
        while (1) {
            gotoxy(col + cursor, row);
            ch = _getch();

            switch (ch) {
            case -32:  // Extended key (e.g., arrow keys)
                ch = _getch();
                switch (ch) {
                case 71:  // Home key to move cursor to start
                    cursor = 0;
                    break;
                case 80:  // Down key to convert character to lowercase
                    if (ptr[cursor] >= 'A' && ptr[cursor] <= 'Z') {
                        ptr[cursor] += 32;
                        gotoxy(col + cursor, row);
                        printf("%c", ptr[cursor]);
                    }
                    break;
                case 72:  // Up key to convert character to uppercase
                    if (ptr[cursor] >= 'a' && ptr[cursor] <= 'z') {
                        ptr[cursor] -= 32;
                        gotoxy(col + cursor, row);
                        printf("%c", ptr[cursor]);
                    }
                    break;
                case 75:  // Left arrow key to move cursor left
                    if (cursor > 0)
                        cursor -= 1;
                    break;
                case 77:  // Right arrow key to move cursor right
                    if (cursor < size - 1)
                        cursor += 1;
                    break;
                }
                break;
            case 13:  // Enter key to submit text and calculate words
                printf("\n\n%s", ptr);
                printf("\nNumber of words: %d", countWords(ptr));
                break;
            default:  // Regular character input to replace at cursor position
                ptr[cursor] = ch;
                gotoxy(col + cursor, row);
                printf("%c", ptr[cursor]);
                break;
            }
        }

        free(ptr);  // Free dynamically allocated memory
    }

    return 0;
}

// Function to set cursor position on the console
void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), coord
    );
}

// Function to set text color attribute
void textattr(int i) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
}

// Function to draw a horizontal line of specified length and color
void drawLineHorizontal(int col, int row, int hLength, int color) {
    textattr(color);
    gotoxy(col, row);
    for (int i = 0; i < hLength; i++) {
        printf(" ");
    }
    textattr(0x07);  // Reset to default color
}

// Function to count words in a string, separated by spaces, tabs, or newlines
int countWords(char* str) {
    int count = 0;
    int inWord = 0;

    while (*str != '\0') {
        if (*str != ' ' && *str != '\t' && *str != '\n') {
            if (inWord == 0) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
        str++;
    }

    return count;
}
