#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaring functions such that they can be referenced in main
void help(void);
void hello(void);
void quit(void);
void change_save_dir(void);
void start(void);

void get_path_to_path_file(void);

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
    {"s", start, "s  -Starts a bookwork session\n"},
};

const int num_commands = sizeof(commands)/sizeof(commands[0]);

//changed only by quit to break main while loop
int running = 1;
char path_to_dir[100];

struct letter_def {
    char letter[1];
    int number;
};

struct letter_def letters[] = {
    {"a", 0},
    {"b", 1},
    {"c", 2},
    {"d", 3},
    {"e", 4},
    {"f", 5},
    {"g", 6},
    {"h", 7},
    {"i", 8},
    {"j", 9},
    {"k", 10},
    {"l", 11}
};

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

void get_path_to_path_file(void) {
    char path[100];
    char *home = getenv("HOME");    //No I will not add Windows support yet

    if(home == NULL) {
        exit(2);
    }   //apparently getenv("HOME") can return NULL (maybe if running as root(because who isnt loging their bookwork as root))?

    snprintf(path, sizeof(path), "%s/.bookwork/.save_dir_file.txt", home);

    //printf("%s\n", path);

    FILE* file = fopen(path, "r");

    if(file ==NULL) {
        printf("Cannot access ~/.bookwork/.save_dir_file.txt");
        exit(1);
    }

    fgets(path_to_dir, sizeof(path_to_dir), file);
    fclose(file);
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
    char new_path[100];
    char path[100];

    get_path_to_path_file();

    printf("Please enter new save directory (current save directory is '%s' (press k to keep)): ", path_to_dir);
    scanf("%99s", new_path);

    if(strcmp(new_path, "k")) {
        char *home = getenv("HOME");
        if(home == NULL) {
            exit(2);
        }   //apparently getenv("HOME") can return NULL (maybe if running as root(because who isnt loging their bookwork as root))?

        snprintf(path, sizeof(path), "%s/.bookwork/.save_dir_file.txt", home);

        //printf("%s\n", path);
        //exit(1);

        FILE* file = fopen(path, "w");

        if(file ==NULL) {
            printf("Cannot access ~/.bookwork/.save_dir_file.txt");
            exit(1);
        }
        fprintf(file, "%s", new_path);
        fclose(file);
    }
    
}

void start(void) {
    FILE* file;
    char path[100];
    char full_path[100];
    char file_name[100];
    char work[20][10];

    printf("Please enter the name of the bookwork you want to edit('n' to create a new bookwork file): ");
    scanf("%99s", file_name);
    
    if(!strcmp(file_name, "n")) {
        char new_name[100];

        printf("Please enter new bookwork file name: ");
        scanf("%99s", new_name);

        get_path_to_path_file();

        snprintf(path, sizeof(path), "%s%s.bookwork", path_to_dir, new_name);

        file = fopen(path, "wb");

        if(file == NULL){
            exit(1);
        }

        fclose(file);

        file = fopen(path, "rb");

        if(file == NULL){
            exit(1);
        }

        printf("Successfully Created new bookwork file!\n");
    } else {
        get_path_to_path_file();

        snprintf(full_path, sizeof(full_path), "%s%s.bookwork", path_to_dir, file_name);

        file = fopen(full_path, "rb");

        if(file == NULL){
            exit(1);
        }
    }
    
}