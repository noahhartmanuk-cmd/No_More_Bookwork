#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void help(void);

void hello(void);

void quit(void);

void change_save_dir(void);

struct Command {
    const char *name; 
    void (*fnptr)(void);
    const char *usage;
};

struct Command commands[] = {
    {"h", help, "h  -Shows this help message\n"},
    {"hello", hello, ""},
    {"q", quit, "q  -Exits the programe\n"},
    {"cs", change_save_dir, "cs -Changes where bookwork files are saved\n"},
};

int running = 1;

int main(void) {
    char cmd[100];
    int found = 0;

    printf("Hey there, how y' doing, welcome to No_More_Bookwork, the only way to completely slow down bookwork checks in Sparx\n");

    while(running) { 
        printf("Enter Cmd ('h' for help): ");
        scanf("%99s", cmd);
        for(int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++){
            if(!strcmp(cmd, commands[i].name)) {
                commands[i].fnptr();
                found = 1;
                break;
            }
        }
        if(!found) {printf("Unknown Command! %s\n", cmd);};
    }
    return 0;
}

void help(void) {
    for(int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++) {
        printf(commands[i].usage);
    }
}



void hello(void) {
    printf("Hiya to you too!\n");
}

void quit(void) {
    printf("See you later!\n");
    running = 0;
}

void change_save_dir(void) {
    char buff[200];
    char path[200];
    char *home = getenv("HOME");

    //printf(home);

    snprintf(path, sizeof(path), "%s/.bookwork/.save_dir_file.txt", home);

    printf("%s\n", path);

    FILE* file = fopen(path, "w");

    if(file ==NULL) {
        printf("Cannot access ~/.bookwork/.save_dir_file.txt");
    }

    fgets(buff, sizeof(buff), file);
    printf("Please enter new save directory (current save directory is '%s' (press k to keep)): ", buff);
    scanf("%99s", buff);

    if(strcmp(buff, "k")) {
        fprintf(file, "%s", buff);
    }
    fclose(file);
}