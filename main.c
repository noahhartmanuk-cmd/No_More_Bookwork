#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaring functions such that they can be referenced in main
void help(void);
void hello(void);
void quit(void);
void change_save_dir(void);

//struct definition kept global such that functions other than main can access
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

int num_commands = sizeof(commands)/sizeof(commands[0]);

//changed only by quit to break main while loop
int running = 1;

int main(void) {
    char cmd[100];

    //if a command is recognised to be in commands found = 1
    int found = 0;

    printf("Hey there, how y' doing, welcome to No_More_Bookwork, the only way to completely slow down bookwork checks in Sparx\n");

    while(running) {

        printf("Enter Cmd ('h' for help): ");
        scanf("%99s", cmd);

        for(int i = 0; i < num_commands; i++){
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
    for(int i = 0; i < num_commands; i++) {
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

void change_save_dir(void) { //note: don't touch this function and it will work : ) 
    char new_path[200];
    char path[200];
    char *home = getenv("HOME");    //No I will not add Windows support yet

    if(home == NULL) {
        exit(2);
    }   //apparently getenv("HOME") can return NULL (maybe if running as root(because who isnt loging their bookwork as root))?

    snprintf(path, sizeof(path), "%s/.bookwork/.save_dir_file.txt", home);

    printf("%s\n", path);

    FILE* file = fopen(path, "r");

    if(file ==NULL) {
        printf("Cannot access ~/.bookwork/.save_dir_file.txt");
        exit(1);
    }

    fgets(new_path, sizeof(new_path), file);
    fclose(file);   //yes, I know what you are thinking and I hate it too

    printf("Please enter new save directory (current save directory is '%s' (press k to keep)): ", new_path);
    scanf("%99s", new_path);

    if(strcmp(new_path, "k")) {
        FILE* file = fopen(path, "w");  //I repeat, I hate it too
        if(file == NULL) {
            exit(1);
        } else {
            fprintf(file, "%s", new_path);
            fclose(file);
        }
    }
    
}