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
    char c1, c2, c3;
    
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
                printf("String: \"");
                for (int i = 0; i < sstring[index].length; i++){
                    printf("%c", sstring[index].string[i]);
                }
                printf("\"\n");
                printf("Length: %d\n", sstring[index].length);
                printf("Capacity: %d\n", sstring[index].capacity);
            }
            break;

        case 'a':
            scanf(" %c", &c);
            if (c >= 'a' && c <= 'd'){
                int index = c - 'a';
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
        
        case 'c':
            scanf(" %c %c %c", &c1, &c2, &c3);
            int index1 = c1 - 'a';
            int index2 = c2 - 'a';
            int index3 = c3 - 'a';
            struct target temp;
            temp.length = 0;
            temp.capacity = 4;
            temp.string = malloc(4 * sizeof(char)); 
            
            for (int i = 0; i < sstring[index2].length; i++){
                append(&temp, sstring[index2].string[i]);
            }
            for (int i = 0; i < sstring[index3].length; i++){
                append(&temp, sstring[index3].string[i]);
            }
            sstring[index1].length = 0;
            free (sstring[index1].string);
            sstring[index1] = temp;
            break;
            
        }
        
        
            
    }
}

