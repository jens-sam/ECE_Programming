#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char filename[80];
    char search_word[80];
    char replace_word[80];

    // if args was used, use this code instead
    // enter a filename and file handle it
    /*if (argc < 2) {
        printf("Please enter a filename:");
        fgets(filename, sizeof(filename), stdin);
        strtok(filename, "\n");
    } else {
        strncpy(filename, argv[1], sizeof(filename));

    }*/


    printf("Please enter a filename: ");
    scanf("%s", filename);

    // enter a search word
    printf("Please enter a word to search for: ");
    scanf("%s", search_word);

    // enter a replace word
    printf("Please enter a word to replace it with: ");
    scanf("%s", replace_word);

    // open and reading file
    int count = 0;
    FILE *find = fopen(filename, "r");
    if (find == NULL) {
        printf("File not found\n");
        return -1;
    }

    char line[80];
    
    // searching for number of times word is in file
    while (fgets(line, sizeof(line), find)) {
        char *ptr = strstr(line, search_word);
        while (ptr != NULL) {
            count++;
            ptr = strstr(ptr + 1, search_word);
        }
    }
    fclose(find);

    // print out how many times word was found
    printf("The word %s was found %d times\n", search_word, count);

    // replacing extension with .out
    char *p_ext = malloc(strlen(filename) + 5);
    strcpy(p_ext, filename);
    char *ext = strrchr(p_ext, '.');
    if (ext == NULL) {
        strcat(filename, ".out");
    } else {
        strcpy(ext, "out.");
    }


    // Open the output for writing
    find = fopen(filename, "w");
    if (find == NULL) {
        printf("Error creating output file\n");
        return 1;
    }

        FILE *infile = fopen(filename, "r");
        FILE *outfile = fopen("raven.out", "w");

        if (infile == NULL || outfile == NULL) {
            printf("Error opening file\n");
        }

    //int count = 0;
        while (fgets(line, sizeof(line), find)) {
            char *p = strstr(line, search_word);
        while (p != NULL) {
            count++;
            char temp[80];
            strcpy(temp, p + strlen(search_word));
            strcpy(p, replace_word);
            strcat(p, temp);
            p = strstr(p + strlen(replace_word), search_word);
        }
        fprintf(outfile, "%s", line);
    }

    fclose(infile);
    fclose(outfile);
    //printf("Output file created: %s\n", filename);



    return 0;
}
