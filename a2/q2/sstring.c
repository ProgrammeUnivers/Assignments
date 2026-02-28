#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct target {
    char *string;
    unsigned int length;
    unsigned int capacity;
};


void append(struct target *s, char c){
    
    if (s->length >= s->capacity){
        s->capacity *= 2;
        s->string = realloc(s->string, s->capacity * sizeof(char));
    }

    s->string[s->length] = c;
    s->length++;

}

int main() {
    char command;
    char c;
    
    struct target sstring[4];
    for (int i = 0; i < 4; i++){
        sstring[i].length = 0;
        sstring[i].capacity = 4;
        sstring[i].string = malloc(sstring[i].capacity * sizeof(char));
    }


    while(scanf(" %c", &command) != EOF) {
        if (command == 'q') {
            break;
        }

        switch (command){
        case 'r':
            
            scanf(" %c", &c);
            if (c >= 'a' && c <= 'd'){
                int index = c - 'a';
                sstring[index].length = 0;
                scanf(" %c", &c);
                if (c == '"') {
                    c = getchar();
                    while(c != '"'){
                        append(&sstring[index], c);
                        c = getchar();
                    }
                }
                else {
                    while(c != '\n' && c != EOF && c != ' ' && c != '\t' && c != '\r' && c != '\f' && c != '\v' && c != '\f'){
                        append(&sstring[index], c);
                        c = getchar();
                    }

                }
            }
            break;
        case 'p':
            scanf(" %c", &c);
            if (c >= 'a' && c <= 'd'){
                int index = c - 'a';
                for (int i = 0; i < sstring[index].length; i++){
                    printf("%c", sstring[index].string[i]);
                }
                printf("\n");
            
            }
            break;

        case 'd':
            scanf(" %c", &c);
            if (c >= 'a' && c <= 'd'){
                int index = c - 'a';
                printf("String: \" ");
                for (int i = 0; i < sstring[index].length; i++){
                    printf("%c", sstring[index].string[i]);
                }
                printf("\"\n");
                printf("Length: %d\n", sstring[index].length);
                printf("Capacity: %d\n", sstring[index].capacity);

        case 'a':
            scanf(" %c", &c);
            if (c >= 'a' && c <= 'd'){
                int index = c - 'a';
                for (int i = 0; i < sstring[index].length; i++){
                    printf("String: %c\n", sstring[index].string[i]);
                }
                printf("Length: %d\n", sstring[index].length);
                printf("Capacity: %d\n", sstring[index].capacity);
        
        case 'c':
                scanf(" %c", &c);
                if (c >= 'a' && c <= 'd'){
                int index = c - 'a';
                sstring[index].length = 0;
                scanf(" %c", &c);
                if (c == '"') {
                    c = getchar();
                    while(c != '"'){
                        append(&sstring[index], c);
                        c = getchar();

        }
    }
}

