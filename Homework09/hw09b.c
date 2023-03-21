#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {

    char filename[80];
    char search_word[80];
    char replace_word[80];

    // enter a filename and file handle it
    if (argc < 2) {
        printf("Please enter a filename:");
        fgets(filename, sizeof(filename), stdin);
        strtok(filename, "\n");
    } else {
        strncpy(filename, argv[1], sizeof(filename));

    }

    // enter a search word
    printf("Please enter a word to search for:");
    scanf("%s", search_word);

    // enter a replace word
    printf("Please enter a word to replace it with:");
    scanf("%s", replace_word);

    // open and read file
    FILE *find = fopen(filename, "r");
    if (find == NULL) {
        printf("File not found\n");
        return -1;
    }

    // replacing extension with .out
    char *p_ext = strrchr(filename, '.');
    if (p_ext != NULL) {
        *p_ext = '\0';
    }
    strcat(filename, ".out");

    // Open the output for writing
    FILE *fout = fopen(filename, "w");
    if (fout == NULL) {
        printf("Error creating output file\n");
        return -1;
    }

    char line[80];
    int count = 0;
  
  // search through to replace search word with replace word
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
        fprintf(fout, "%s", line);
    }

    fclose(find);
    fclose(fout);
    //printf("Output file created: %s\n", filename);

    printf("The word %s was found %d times\n", search_word, count);

    return 0;
}
