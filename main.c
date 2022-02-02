#include <stdio.h>
#include <string.h>

#define COL  18
#define ROW  15

// Process the words
void processWords(char const *input, int len, char dest_arr[ROW][COL]){
    int wordStart = 0;
    int numWord = 0;
    char temp[50];
    for (int i = 0; i <= len; i++){
        if(input[i] == ' ' || i == len){
            // Iterate through the word.
            for (int y = wordStart; y < i; y++){
                strncat(dest_arr[numWord], &input[y],1);
            }
            // End of word
            numWord++;
            // Preparing for next word
            wordStart = i+1;
        }
    }
}

// Copy word to 2D array
int countWords(char const *input, int len){
    int numWord = 0;
    for (int i = 0; i <= len; i++){
        if(input[i] == ' ' || i == len){
            // End of word
            numWord++;
        }
    }
    return numWord;
}

int formatWords(char inputArray[ROW][COL], int lineLength, int startIndex, int wordCount, int *outputSpaces){
    int numWords = 0;
    int endIndex = 0;
    int i = startIndex;

    while(lineLength>=0 && i < wordCount && (lineLength - (int)(strlen(inputArray[i])) >= 0)) {
        lineLength -= (int)(strlen(inputArray[i]));
        numWords++;
        i++;
    }
    endIndex = i - 1;
    lineLength += (int)strlen(inputArray[endIndex]);
    *outputSpaces = lineLength;

    return numWords;
}

void printLine(char dest_arr[ROW][COL],int startIndex,int numWords,int numSpaces){
    int space = numSpaces / (numWords -1);
    for (int x = 0; x < numWords; x++){
        printf("%s",dest_arr[x+startIndex]);
        printf("%*c", space, ' ');
    }
    printf("\n");
}

int main() {
    // Input
    char paragraph[] = "I am here to learn C programming. This is my first assignment. Wish me luck!";

    // Length of input
    size_t size = strlen(paragraph);

    // Counts number of words.
    int wordCount = countWords(paragraph,(int) size);

    // Create 2D array based on wordCount
    char words[ROW][COL]={0};

    // Process input
    processWords(paragraph, (int) size, words);

    int numSpaces = 0;
    int numWords = 0;
    numWords = formatWords(words,50,0,wordCount,&numSpaces);
    printLine(words,0,numWords,numSpaces);
    numWords = formatWords(words,50,11,wordCount,&numSpaces);
    printLine(words,11,numWords,numSpaces);

    numWords = formatWords(words,35,0,wordCount,&numSpaces);
    printLine(words,0,numWords,numSpaces);
    numWords = formatWords(words,35,10,wordCount,&numSpaces);
    printLine(words,10,numWords,numSpaces);
    numWords = formatWords(words,35,15,wordCount,&numSpaces);
    printLine(words,15,numWords,numSpaces);

    numWords = formatWords(words,20,0,wordCount,&numSpaces);
    printLine(words,0,numWords,numSpaces);
    numWords = formatWords(words,20,6,wordCount,&numSpaces);
    printLine(words,6,numWords,numSpaces);
    numWords = formatWords(words,20,10,wordCount,&numSpaces);
    printLine(words,10,numWords,numSpaces);
    numWords = formatWords(words,20,13,wordCount,&numSpaces);
    printLine(words,13,numWords,numSpaces);

    return 0;
}
