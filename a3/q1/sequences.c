#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char op[4];
    int val;

} Operation;


int main(int argc, char *argv[]) {
    if(argc < 2){
        return 1;
    }

    int capacity = 10;
    int count = 0;
    Operation *history = malloc(sizeof(Operation)*capacity);

    

    long x = atoi(argv[1]);

    char input[10];
    while (scanf("%s", input) != EOF){
        
        if (strcmp(input, "n") == 0){
        long temp = x;
            for (int i = 0; i < count; i++){
                if(strcmp(history[i].op, "add") == 0){
                    temp += history[i].val;
                }
                else if(strcmp(history[i].op, "sub") == 0){
                    temp -= history[i].val;
                }
                else if(strcmp(history[i].op, "mul") == 0){
                    temp *= history[i].val;
                }
                else if(strcmp(history[i].op, "div") == 0){
                    temp /= history[i].val;
                }

            }
        x = temp;
        printf("%ld\n", x);

        } else{
            if (count == capacity){
            capacity *= 2;
            history = realloc(history, sizeof(Operation)*capacity);
            }
            strcpy(history[count].op, input);

            if (scanf("%d", &history[count].val) == 1){
                count++;
            }
        }

    } 
    free(history);

    return 0;



}