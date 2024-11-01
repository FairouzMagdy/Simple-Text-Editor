# Simple-Text-Editor

Text Input with Cursor Manipulation and Word Count

Description:
This C program allows users to enter a string of a specified length, displays it on a horizontal line in the console, and enables cursor-based manipulation, including:

    Moving the cursor left and right with arrow keys.
    Changing character cases with up and down keys.
    Moving to the start of the string with the home key.

Upon pressing the Enter key, the program outputs the modified string and counts the number of words.

How to Run the Program:

    Compile the code with a C compiler (e.g., gcc).
    Run the compiled program.
    Enter the desired string length.
    Type the string; press Enter to switch to edit mode.
    Use the following controls to edit:
        Left Arrow: Move cursor left.
        Right Arrow: Move cursor right.
        Up Arrow: Convert character at the cursor to uppercase.
        Down Arrow: Convert character at the cursor to lowercase.
        Home Key: Move cursor to the beginning of the string.
    Press Enter to display the final string and word count.

Functions Explained:

    gotoxy: Moves the cursor to a specific position on the console.
    textattr: Changes console text color.
    drawLineHorizontal: Draws a line of spaces to display the text input area.
    countWords: Counts words in a string, considering any non-space-separated sequence of characters as a word.

Platform Compatibility:
This code is intended to work on Windows systems because it uses Windows-specific libraries (windows.h).
