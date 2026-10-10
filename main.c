#include <stdio.h>
#include <string.h>

void help(void);

void hello(void);

void quit(void);

struct Command {
    const char *name; 
    void (*fnptr)(void);
    const char *usage;
};

struct Command commands[] = {
    {"h", help, "h  -Shows this help message\n"},
    {"hello", hello, ""},
    {"q", quit, "q  -Exits the programe\n"},
};

int running = 1;

int main(void) {
    printf("Yo,welcome to No_More_Bookwork, the only way to completely slow down bookwork checks in Sparx\n");

    char cmd[100];
    int found = 1;

    while(running) { 
        printf("Enter Cmd ('h' for help): ");
        scanf("%99s", cmd);
        for(int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++){
            if(!strcmp(cmd, commands[i].name)) {
                commands[i].fnptr();
                found = 1;
                break;
            }
            if(!found) {printf("Unknown Command! %s\n", cmd);};
        }
    }
    return 0;
}

void help(void) {
    for(int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++) {
        printf(commands[i].usage);
    }
}



void hello(void) {
    printf("Why hello to you too, such a curtious gesture!\n");
}

void quit(void) {
    printf("Goodbye, for now\n");
    running = 0;
}