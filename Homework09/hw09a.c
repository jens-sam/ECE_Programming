#include <stdio.h>
#include <string.h>


int main() {
    char fox[] = "The quick brown fox jumps over the lazy dog!";

    // length of string
    int len;
    len = strlen(fox);
    printf("The string is %d characters long\n", len);

    // index of the letter z
    int z_index;
    char *z;
    z = strchr(fox, 'z');
    z_index = z - fox;
    printf("The letter z is at index %d\n", (int) z_index);

    // using strtok and while loop
    //char input[strlen(fox)+1];
    //strcpy(input, fox);

    char *token = strtok(fox, " ");
    int count = 0;
    while(token != NULL){
        count++;
        //finding the third word
        if(count == 3) {
            printf("The third word is %s\n", token);
            //break;
        }
        // find jumps and print the word following it
        if (strcmp(token, "jumps") == 0) {
            token = strtok(NULL, " ");
            printf("The word after jumps is %s\n", token);
            break;
        }
        token = strtok(NULL, " ");

    }

    // creating a new sentence and concatenating it onto the old sentence
    char fox_two[100] = "The quick brown fox jumps over the lazy dog!";
    char mary[50] = "Mary had a little lamb.";

    strcat(fox_two, "  ");
    char *con_sent = strcat(fox_two, mary);

    printf("%s\n", con_sent);



    // print the new string followed by a newline
    // The quick brown fox jumps over the lazy dog!  Mary had a little lamb.

    return 0;
}
