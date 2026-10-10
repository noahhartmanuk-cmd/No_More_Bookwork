#include <stdio.h>
#include <string.h>

void help();

int main(void) {
    char cmd_list[10][10] = {
        {"h"},
    };
    void (*cmd_func_list[10])(void) = {&help,};
    printf("Yo,welcome to No_More_Bookwork, the only way to completely slow down bookwork checks in Sparx\n");
    char cmd[100];
    while(1) { 
        printf("Enter Cmd ('h' for help):");
        scanf("%s", cmd);
        for(int i = 0; i < sizeof(cmd_list)/sizeof(cmd_list[0]); i++){
            if(!strcmp(cmd, cmd_list[i])) {
                cmd_func_list[i]();
                break;
            }
        }
    }
    return 0;
}

void help(void) {
    printf("Hi, This is where I will put the most usefull commands\n");
}