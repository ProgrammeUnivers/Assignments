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
                    while(getchar() != '"'){
                    scanf(" %c", &c);
                    append(&sstring[index], c);
                    }
                }
                else {
                    while(getchar() != '\n'){
                    scanf(" %c", &c);
                    append(&sstring[index], c);
                    }

                }
            }
            break;
        case 'p':

        
            
        }
    
    }




}