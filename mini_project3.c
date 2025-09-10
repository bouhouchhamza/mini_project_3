#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


char positive_k[4][20] = {"happy","good","great","awesome",};
char negative_k[4][20] = {"sad", "bad", "angry", "upset",};
char neutral_k [5][20] = {"hello", "hi", "help", "thanks", "ok"};

char positive_r[3][100] = {"Hi Great to hear that","That's wonderful","Awesome keep it up"};
char negative_r[3][100] = {"Oh no Hope things get better soon.","I'm sorry to hear that.","Stay strong better days are coming"};
char neutral_r[3][100] = {"Hello! How can I help you","Sure! What do you want to talk about","You're welcome"};

int contains_k(char input[],char keywords[][20],int size){

    for(int i = 0 ; i < size; i++){
       if (strstr(input, keywords[i]) != NULL){
          return 1;
       }
    }

      return 0;

}

void choose_r(char responses[][100],int size, char output[]){

     int index = rand() % size ;
     strcpy(output, responses[index]);

}


int main(){

char input[200];
char bot_r[100];
srand(time(NULL));

printf(" Chatbot started! (type 'exit' to quit,)\n\n");



while (1) {

printf("you: ");
fgets(input, 200, stdin);
input[strcspn(input,"\n")] = 0;

if (strcmp(input, "exit") == 0) {
            printf("Bot: Goodbye!\n");
            break;
        } 
        strcpy(bot_r, "Hmm, I didn't quite get that. Can you rephrase?");

        if (contains_k(input, positive_k, 5)) {
            choose_r(positive_r, 3, bot_r);
        } else if (contains_k(input, negative_k, 5)) {
            choose_r(negative_r, 3, bot_r);
        } else if (contains_k(input, neutral_k, 5)) {
            choose_r(neutral_r, 3, bot_r);
        }

        printf("Bot: %s\n", bot_r);
    }

    return 0;
}


































