#include <stdio.h>
#include <string.h>

void help(void);

void hello(void);

int main(void) {
    struct Command {
        const char *name; 
        void (*fnptr)(void);
    }; 
    struct Command commands[] = {
        {"h", help},
        {"hello", hello}
    };
    printf("Yo,welcome to No_More_Bookwork, the only way to completely slow down bookwork checks in Sparx\n");
    char cmd[100];
    while(1) { 
        printf("Enter Cmd ('h' for help): ");
        scanf("%s", cmd);
        for(int i = 0; i < sizeof(commands)/sizeof(commands[0]); i++){
            if(!strcmp(cmd, commands[i].name)) {
                commands[i].fnptr();
                break;
            }
        }
    }
    return 0;
}

void help(void) {
    printf("Hi, This is where I will put the most usefull commands\n");
}

void hello(void) {
    printf("Why hello to you too, such a curtious gesture!\n");
}